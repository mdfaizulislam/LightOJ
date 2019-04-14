#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct pack
{
    char name[22];
    int length;
    int height;
    int width;
};
int main()
{
    int t,n,i,max=0,min=0,c=0,tem1,tem2;
    scanf("%d",&t);
    while( t-- )
    {
        scanf("%d",&n);
        struct pack b[n+1];
        for( i = 0 ; i < n ; i++ )
        {
            scanf("%s %d %d %d",&b[i].name,&b[i].length,&b[i].width,&b[i].height);
        }
        min= tem1= tem2= b[0].length * b[0].width * b[0].height;
        for( i = 0, max=0, min=0 ; i < n ; i++ )
        {
            if( (b[i].length * b[i].width * b[i].height) > tem1 )
            {
                max=i;
                tem1=b[i].length * b[i].width * b[i].height;
            }
 
            if( (b[i].length * b[i].width * b[i].height) <= tem2 )
                {
                    min=i;
                    tem2=b[i].length * b[i].width * b[i].height;
                }
        }
        if( tem1 != tem2 )
            printf("Case %d: %s took chocolate from %s\n",++c,b[max].name,b[min].name);
        else
            printf("Case %d: no thief\n",++c);
    }
    return 0;
}
 