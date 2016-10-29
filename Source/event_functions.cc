#include "event_functions.h"


double linear_interp(double y, double x1, double y1, double x2, double y2)
{
    int b = ( y2 - y1 )/( x2 - x1 );
    int a = y2 - b * x2;
    int x = ( y - a ) / b;
    return x;
}

int find_crossing_index(double *charge, int max_index, int direction, double percentage)
{
    int index = max_index;
    while(1)
    {
        if(charge[index] < percentage*charge[max_index]) 
            break;
        index += direction;
    }
    return index;
}

double charge_sum(double *charge)
{
    double charge_sum = 0;
    for(int i = 0 ; i < 27; i++)
        charge_sum+=charge[i];
    return charge_sum;
}

double charge_sum_square(double *charge)
{
    double charge_sum_square = 0;
    for(int i = 0 ; i < 27; i++)
        charge_sum_square+=charge[i]*charge[i];
    return charge_sum_square;
}







