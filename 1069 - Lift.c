#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int t,time,my,lift,c=0;
    scanf("%d",&t);
    while( t-- )
    {
        scanf("%d %d",&my,&lift);
        if( lift > my )
            time=(lift-my)*4;
        else if( my > lift )
            time=( my-lift)*4;
        else
            time=0;
        time+=my*4+19;
        printf("Case %d: %d\n",++c,time);
        time=0;
    }
    return 0;
}