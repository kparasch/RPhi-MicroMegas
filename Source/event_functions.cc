#include "event_functions.h"


double linear_interp(double y, double x1, double y1, double x2, double y2)
{
    int b = ( y2 - y1 )/( x2 - x1 );
    int a = y2 - b * x2;
    int x = ( y - a ) / b;
    return x;
}
