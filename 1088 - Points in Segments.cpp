#include <bits/stdc++.h>

using namespace std;
int arr[100001];
int freq[100001];
int main()
{

    int t;
    //cin >> t;
    scanf("%d",&t);
    int mx, mn, n, q;
    for( int i = 1 ; i <= t ; i++ ){
        cin >> n >> q;
        for( int j = 0 ; j < n ; j++ )
        {
            //cin >> arr[j];
            scanf("%d",&arr[j]);
            freq[j]=j+1;
        }
        //cout << "Case " << i << ":\n";
        printf("Case %d:\n",i);
        mn = arr[0];
        mx = arr[n-1];
        int lower, higher;
        for( int j = 0 ; j < q ; j++ ){
            //cin >> lower >> higher;
            scanf("%d %d",&lower,&higher);
            //mn = lower < mn ? mn : lower;
            //mx = higher > mx ? mx : higher;

            if( lower < mn && higher < mn ){
                cout << "0\n";
                continue;
            }
            if( lower > mx && higher > mx ){
                cout << "0\n";
                continue;
            }

            int l=0, h=n-1, mid;
            int lo, hi;
            while( l <= h ){
                mid = l+(h-l)*0.5;
                if( arr[mid] >= lower )
                {
                    lo = mid;
                    h = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            l = 0, h = n-1;

            while( l <= h ){
                mid = l+(h-l)*0.5;
                if( arr[mid] <= higher ){
                    hi = mid;
                    l = mid+1;
                }
                else{
                    h = mid-1;
                }
            }
            //cout << freq[hi]-freq[lo]+1 << "\n";
            printf("%d\n",freq[hi]-freq[lo]+1);
        }
    }

    return 0;
}
