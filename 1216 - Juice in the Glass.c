#include<stdio.h>
#include<math.h>
int main()
{
    int t,i=1,r1,r2,h,p;
    double x,ar,e;
    scanf("%d",&t);
    while (i<=t)
    {
    scanf("%d %d %d %d",&r1,&r2,&h,&p);
    e=(r1-r2)*(double)p/h;
     x= r2 + e;
    ar=1/3.0*p*(x*x+x*r2+r2*r2)*acos(-1);
    printf("Case %d: %lf\n",i,ar);
 
    i++;
    }
    return 0;
}
 