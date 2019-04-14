#include<stdio.h>
 
int main() {
    int n, caseno = 0, cases;
    long long used[10001];
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%lld %lld %lld %lld %lld %lld %d", &used[0],&used[1],&used[2],&used[3],&used[4],&used[5],&n);
        for( int i = 6; i <= n ; i++ )
            used[i]=(used[i-1]+used[i-2]+used[i-3]+used[i-4]+used[i-5]+used[i-6])%10000007;
        printf("Case %d: %lld\n", ++caseno, used[n] % 10000007);
    }
    return 0;
}
 