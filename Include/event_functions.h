#ifndef __event_functions_h__
#define __event_functions_h__

double linear_interp(double y, double x1, double y1, double x2, double y2);
int find_crossing_index(double *charge, int max_index, int direction, double percentage);
double charge_sum(double *charge);
double charge_sum_square(double *charge);

#endif //__event_functions_h__
