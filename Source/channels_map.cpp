#include "channels_map.h"

void map_channels(int *strip, int *apv_config, int second_chamber_present)
{
    //=============================================================
    // Variable second_chamber_present is either 0 or 1.
    //
    // apv_Config is an array with one or two elements.
    //
    // Each element represents a chamber and is a five digit number
    // with unique digits from 0 to 4, inclusive.
    // Index of digit points to a physical connector
    // according to the following table.
    //
    // Digit = 1 -> R3
    // Digit = 2 -> APHI
    // Digit = 3 -> R4
    // Digit = 4 -> BPHI
    // Digit = 5 -> R12
    //=============================================================
    // strip equal to -1 means empty channel 
    //=============================================================

    std::cout << " ---------- Generating Channels-to-Strip Map ---------- " << std::endl;

    for( int k = 0 ;  k < second_chamber_present + 1 ; ++k )
    {
        for( int i = 0 ; i < 5 ; ++i )
        {
            int digit = ( apv_config[k] / ( int( TMath::Power(10,4-i) ) ) ) % 10;
            std::cout << "mapping " << i << " to " << digit  << std::endl;
            for( int j = 0 ; j < 128 ; ++j )
            {
                switch( digit )
                {
                    case 1:
                        strip[j+128*(i+5*k)] = channel_To_Strip_R3(j);
                        break;
                    case 2:
                        strip[j+128*(i+5*k)] = channel_To_Strip_APHI(j);
                        break;
                    case 3:
                        strip[j+128*(i+5*k)] = channel_To_Strip_R4(j);
                        break;
                    case 4:
                        strip[j+128*(i+5*k)] = channel_To_Strip_BPHI(j);
                        break;
                    case 5:
                        strip[j+128*(i+5*k)] = channel_To_Strip_R12(j);
                        break;
                }
                std::cout << i << " " << j << " : " << strip[j+128*(i+5*k)] << std::endl;
            }
        }
    }

    std::cout << " ---------- Channels-to-Strip Map Generated ---------- " << std::endl;

    return; 
}

int channel_To_Strip_R12(int i)
{
	// Mapping function for R1R2 -- APV2
	//
	// If the strip is empty or the mapping is bad, a default value -1 is returned
	
	int ieven = 1 - ( i % 2 ) ;
	
	if ( i < 0 || i > 127 )
    {   
        //std::cout << "R12 matching called incorrectly" << i << std::endl;
        return -1;	//Default -1 Empty
    }

	if ( ieven )
	{
		if ( i == 0 ) 
            return -1;		// Default -1 Empty even
	}
	else
	{
		if ( i >= 43 ) 
            return -1;	// Default -1 Empty odd
	}
	
    int str;	
	if ( ieven )
	{
		str = 22 + (i-2)/2 ;
	}
	else
	{
		str = 1 + (41-i)/2 ;
	}
	
	if ( str < 1 || str > 84 )
	{
        std::cout << "APV2 Transformation Error " << std::endl;
        return -1;
	}
	else
	{
		return str;	
	}
}

int channel_To_Strip_R3(int i)
{
	// Mapping function for R3 -- APV1
	//
	// The function takes the (ich) int as an argument and return an ich2istr_1 int.
	// If the strip is empty or the mapping is bad, a default value -1 is returned
	// 
	// After a check on whether (ich) value is odd or even, and in the range [0,127]
	// If the value is odd, and in the range [1,127], the default value -1 is returned, it only keeps even (ich)
	// The above statement seems weird, ask Kostas.
	
	// Depending on whether the remaining channels are odd or even, a mapping is applied, and a final test for transformation error is applied
	// The resulting (ich) mapping is returned as (ich2istr_1)
	
	
	int ieven = 1 - ( i % 2 );
	
	if ( i < 0 || i > 127 )	
        return -1 ; // Default value -1, it's empty


	
	if ( ieven == 1 )
	{
		if ( i == 0 )
        {
            std::cout << "R3 matching called incorrectly" << std::endl;
            return -1;
        }
    }
	else 
	{
		if ( i >= 1 && i <= 117)	
            return -1;
		
		// Probably redundant
		if ( i == 127 )	
            return -1;
	}
	
    int str;
	if ( ieven )
	{
		str = 85 + ( i - 2 ) / 2 ;
	}
	else
	{
		str = 151 - ( i - 119 ) / 2 ;
	}


	if ( str < 85 || str > 151 )
	{
        std::cout << "R3 Transformation Error " << i << str << std::endl;
        return -1;
	}
	else
	{
		return str;
	}
}

int channel_To_Strip_R4(int i)
{
	// Mapping function for R4 -- APV4
	//
	// The function takes the (ich) int as an argument, and returns a (ich2istr_4) int
	// If the strip is empty or the mapping is bad, a default value -1 is returned

	int ieven = 1 - ( i % 2 );
	
	if ( i < 0 || i > 127 ) 
    {
        //std::cout << "R4 matching called incorrectly" << std::endl;
        return -1; 
    }

	if ( ieven )
	{
		if ( i == 0 )
        {
            //std::cout << "R4 matching called incorrectly" << std::endl;
            return -1; 
        }
	}
	else
	{
		if ( i >= 47 && i <= 77 ) 
            return -1; // Default -1 Empty odd
		if ( i == 127) 
            return -1; // Default -1 Empty odd
	}
	
	int str;
	if ( ieven )
	{
		str = 175 + ( i - 2 ) / 2;
	}
	else
	{
		if ( i <= 45 ) 
            str = 174 - ( i - 1 ) / 2;
		else if ( i >=79 ) 
            str = 261 - ( i - 79 ) / 2;		
	}
	
	if ( str < 152 || str > 261 )
	{
        std::cout << "R4 Transformation Error " << i <<  str << std::endl;
        return -1;
	}
	else
	{
		return str; 
	}
}

int channel_To_Strip_APHI(int i)
{
	// Mapping function for APHI -- APV3
	//
	// The function takes the (ich) int as an argument, and returns a (ich2istr_3) int
	// If the strip is empty or the mapping is bad, a default value -1 is returned

	int ieven = 1 - ( i % 2 );
	
	if ( i <= 0 || i == 2 || ( ieven == 0 && i <= 71) || i > 127 )
	{
        //std::cout << "Mapping Error -- APHI " << i << std::endl ;
		return -1;
	}
	
    int str;
	if ( ieven )
	{
		str = 92 + ( i - 4 ) / 2 ;
	}
	else
	{
		str = 181 - ( i - 73 ) / 2 ;
	}
	
	if ( str < 91 || str > 181 )
	{
        std::cout << "APV3 Transformation Error " << std::endl;
        return -1;
	}
	else
	{
		return str;
	}
	
}

int channel_To_Strip_BPHI( int i )
{
	// Mapping function for BPHI -- APV0
	//
	// The function takes the (ich) int as an argument, and returns a (ich2istr_0) int
	// If the strip is empty or the mapping is bad, a default value -1 is returned
	// 
	// First if statement is used to determine whether (ich) is even with the (ieven) variable
	// Second if statement uses some test cases to determine possible Mapping Errors. These cases are
	// If (ich) < 0, If (ich) is both even AND larger-or-equal than 57, If (ich) is larger than 127
	//
	// Third and four If statements map the (ich) to an (istr) value, depending on whether they are odd or even
	//
	// Fifth and final If statement prints a warning if the (istr) value is not between 1 and 91.
	// If (istr) is found to be in the specified range, it is returned as (ich2istr_0)
	//
	
	int ieven = 1 - ( i % 2);
	
	if ( i <= 0 || ( ieven == 0 && i >= 57 ) || i > 129 || i > 127 )
	{
        //std::cout << "Mapping Error -- BPHI " << i << std::endl ;
		return -1;
	}
	
    int str;
	if ( ieven )
	{
		str = 28 + i / 2 ;
	}
	else
	{
		str = 28 - ( i - 1 ) / 2 ;
	}

	if ( str < 1 || str > 91 )
	{
        std::cout << "APV0 Transformation Error " << i << str << std::endl;
        return -1;
	}	
	else
	{
		return str;
	}
}

