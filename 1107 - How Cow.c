#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    long int t,c=0,x1,x2,y1,y2,M,p,q;
    scanf("%ld",&t);
    while( t-- )
    {
        scanf("%ld %ld %ld %ld",&x1,&y1,&x2,&y2);
        scanf("%ld",&M);
        printf("Case %ld:\n",++c);
        while( M-- )
        {
            scanf("%ld %ld",&p,&q);
            if( (p >= x1 && p <= x2 ) && ( q >= y1 && q <= y2 ) )
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}