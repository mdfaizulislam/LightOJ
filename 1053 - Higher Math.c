#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
int main()
{
    int t,i,a[4],m,n,c,d,swap;
    scanf("%d",&t);
    t++;
    for( i = 1 ; i < t ; i++ )
    {
        scanf("%d %d %d",&a[0],&a[1],&a[2]);
          for (c = 0 ; c < ( 3 - 1 ); c++)
          {
            for (d = 0 ; d < 3 - c - 1; d++)
            {
              if (a[d] > a[d+1]) /* For decreasing order use < */
              {
                swap       = a[d];
                a[d]   = a[d+1];
                a[d+1] = swap;
              }
            }
          }
        m=pow(a[0],2)+pow(a[1],2);
        n=pow(a[2],2);
        if( m == n )
            printf("Case %d: yes",i);
        else
            printf("Case %d: no",i);
                printf("\n");
    }
    return 0;
}