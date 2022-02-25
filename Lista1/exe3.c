#include <stdio.h>
void main (void)
{
 int x,y,z;
 x=y=10;
printf("Apos x=y=10, x=%d, y=%d\n", x, y);
 z=++x;
printf("Apos z=++x, z=%d, x=%d\n", z, x);
 x=-x;
printf("Apos x=-x, x=%d\n", x);
 y++;
printf("Apos y++, y=%d\n", y);
 x=x+y-(z--);
printf("Apos x=x+y-(z--):\n");
printf("x %d \ny %d \nz %d\n",x,y,z);
}
