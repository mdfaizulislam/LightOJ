#include <bits/stdc++.h>

using namespace std;
typedef double d;
d triangleRatio(d ab, d ac, d bc, d ad, d r){
    d ae = ad*ac/ab;
    d de = ad*bc/ab;
    d small, large, trapizium;
    d s_s, s_l;
    s_s = (ad + de + ae)*0.5;
    s_l = (ab + bc + ac)*0.5;
    small = sqrt(s_s*(s_s-ae)*(s_s-de)*(s_s-ad));
    large = sqrt(s_l*(s_l-ab)*(s_l-bc)*(s_l-ac));
    trapizium = large-small;
    return small/trapizium;
}

d BS(d ab, d ac, d bc, d r){

    d ad, mid, l=0, h=ab;
    for( int i = 0 ; i < 100 ; i++ ){
        mid = (l+h)*0.5;
        ad = mid;
        if(triangleRatio(ab,ac,bc,ad,r) > r )
            h = mid;
        else
            l = mid;
    }
    return ad;
}
int main()
{
    double ab, bc, ac, r;
    int t;
    scanf("%d", &t);
    for( int i = 1 ; i <= t ; i++){
        scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &r);
        printf("Case %d: %.10lf\n",i,BS(ab,ac,bc,r));
    }
    return 0;
}

/*
    double ab, bc, ac, r;
    int t;
    scanf("%d", &t);
    for( int i = 1 ; i <= t ; i++){
        scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &r);
        printf("Case %d: %.10lf\n",i,sqrt(r)*ab/sqrt(r+1));
    }

*/
