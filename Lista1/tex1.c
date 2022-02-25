#include <stdio.h>
void main (void)
{
	int i,j,k;
	i=j=k=1;
	i+=j+++3*k;
	printf ("\n%d",i);
}
