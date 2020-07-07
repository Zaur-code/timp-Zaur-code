#include <stdio.h>
#include <math.h>

int main(void)
{
  int n, i, a; double aver = 0.0f;
  a = scanf ("%d", &n);
  for (i = 0; i<n; i++)
	{
	  int x;
	 a = scanf ("\n");
	 a = scanf ("%d", &x);
	 aver+= x;
	}
  aver/= n;
  printf("%lf\n", aver);
  return 0;
}

