#include <iostream>

using namespace std;

bool divisibleby(int n){
    while( n != 0 ){
        if( n%4 == 0 || n%7 == 0){
            if(n%4 == 0)
                n/=4;
            else
                n/=7;
        }
        else
            return false;
    }
    return true;
}

bool consists_of(int n){
    int t;
    while( n != 0 ){
        t=n%10;
        if( t != 4 || t != 7)
            return false;
        n/=10;
    }
    return true;
}
int main()
{
    cout << consists_of(13);
    int t, a, b, cnt;
    bool f, g;
    cin >> t;
    for( int i = 1 ; i <= t ; i++ ){
        cin >> a >> b;
        cnt=0;
        for( int k = a ; k <= b ; k++ ){
            f = divisibleby(k);
            g = consists_of(k);
            if( f || g )
                cnt++;
        }
        cout << "Case " << i << ": " << cnt << "\n";
    }
    return 0;
}
