#include<stdio.h>
int main()
{
    long t,i,r,n,a;
    scanf("%ld",&t);
    for( i = 1 ; i <= t ; i++ )
    {
        scanf("%ld",&n);
        a=n;
        r=0;
        while( n != 0 )
        {
            r=r*10+n%10;
            n/=10;
        }
        if( a == r )
            printf("Case %ld: Yes\n",i);
        else
            printf("Case %ld: No\n",i);
    }
    return 0;
}