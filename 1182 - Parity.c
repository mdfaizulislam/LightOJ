#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int t,c,n,i;
    scanf("%d",&t);
    for( i = 1 ; i <=t ; i++ )
    {
         scanf("%d",&n);
         c=0;
         while( n != 0 )
         {
             c+=n%2;
             n/=2;
         }
         if( c%2 == 0 )
            printf("Case %d: even\n",i);
         else
            printf("Case %d: odd\n",i);
     }
    return 0;
}
 