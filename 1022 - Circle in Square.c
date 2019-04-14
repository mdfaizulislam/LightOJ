#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main()
{
    long int t,c=0;
    double circle,n,square;
    scanf("%ld",&t);
    while( t-- )
    {
        scanf("%lf",&n);
        circle=n*n*2*acos(0.0);
        n=2*n;
        square=n*n;
        printf("Case %ld: %.2lf\n",++c,square-circle);
    }
    return 0;
}
 