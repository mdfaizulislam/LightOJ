#include<stdio.h>
#include <math.h>
#define PI (2*acos(0.0))
double bcos(double a,double b,double c)
{
    return acos((a*a+b*b-c*c)/(2*a*b));
}
double area(double a,double b,double c)
{
    double ans;
    ans=(a+b+c)/2;
    return sqrt(ans*(ans-a)*(ans-b)*(ans-c));
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for( i=1;i<=t;i++)
    {
        double r1,r2,r3;
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        double a,b,c,result;
        a=r1+r2;
        b=r2+r3;
        c=r3+r1;
        result=area(a,b,c);
        result=result-bcos(a,c,b)/2*r1*r1;
        result=result-bcos(a,b,c)/2*r2*r2;
        result=result-bcos(c,b,a)/2*r3*r3;
        printf("Case %d: %lf\n",i,result);
    }
    return 0;
}