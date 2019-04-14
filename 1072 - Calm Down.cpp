#include <bits/stdc++.h>

using namespace std;
#define pi acos(-1.0)
int main()
{
    int t;
    double R, n;
    cin >> t;
    for( int i = 1 ; i <= t ; i++ ){
        cin >> R >> n;
        printf("Case %d: %lf\n",i,(R*sin(pi/n))/(1+sin(pi/n)));
    }
    return 0;
}
