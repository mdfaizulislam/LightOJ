#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
int main()
{
    long int t,n,amo,i,k;
    char c[10];
    scanf("%ld",&t);
    for( i = 1,amo=0 ; i <= t ; i++,amo=0)
    {
        scanf("\n%ld",&n);
        printf("Case %ld:\n",i);
        while( n-- )
        {
            scanf("%s",c);
            if( c[0] == 'd' )
            {
                scanf("%ld",&k);
                amo+=k;
            }
            else if( c[0] == 'r' )
                printf("%ld\n",amo);
 
        }
    }
    return 0;
}