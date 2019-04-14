#include<stdio.h>
int main()
{
    int i,n,a;
    scanf("%d",&n);
    for( i = 1 ; i <= n ; i++ )
    {
        scanf("%d",&a);
        if( a > 10 )
            printf("%d %d\n",a-10,a-(a-10));
        else
            printf("%d %d\n",0,a);
    }
    return 0;
}