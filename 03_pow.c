#include <stdio.h>
#include <math.h>

int main (void)
{
  double y, x;
  int a;
  a = scanf ("%lf%lf", &y, &x);       
  printf ("%lf\n", pow(y, x)); 
  return 0;
}
