#include <stdio.h>
#include <math.h>

int main(void)
{
  int n, i, a; double aver = 0.0f;
  a = scanf ("%d", &n);
  for (i = 1; i<=n; i++)
	{
	  double x;
	 a = scanf ("\n");
	 a = scanf ("%lf", &x);
	 aver+= (i+1)%2 * pow(x, 3);
	}
  printf("%lf\n", aver);
  return 0;
}
