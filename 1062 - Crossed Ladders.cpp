#include <bits/stdc++.h>

using namespace std;
double precision=0.000001;
int main()
{
    int t;
    double x, y, c, h1, h2, h, wide, low, high;
    cin >> t;
    for(int i = 1 ; i <= t ; i++){
        cin >> x >> y >> c;
        low = 0;
        high = x > y ? x : y;
        for(int j = 0 ; j < 50 ; j++){
            wide = (low+high)*0.5;
            h1 = sqrt(x*x-wide*wide);
            h2 = sqrt(y*y-wide*wide);
            h = (h1*h2)/(h1+h2);
            if( h >= c )
            {
                low = wide;

            }
            else
                high = wide;
        }
        printf("Case %d: %.10lf\n",i,wide);
    }
    return 0;
}
