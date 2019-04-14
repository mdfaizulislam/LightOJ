#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 100005
#define min(a,b) ((a)<(b)?(a):(b))
int t, n, q;
int arr[MAX];
int tree[3*MAX];
 
void segment_tree(int root, int start, int last){
    if( start == last){
        tree[root] = arr[start];
        return;
    }
 
    int mid = start + ((last-start)>>1);
    int left = 2*root;
    int right = 2*root + 1;
    segment_tree(left, start, mid);
    segment_tree(right, mid+1, last);
    tree[root] = min(tree[left], tree[right]);
}
 
int query(int root, int start, int last, int lower, int upper){
    if( last < lower || start > upper)
        return 1e7;
    if( start >= lower && last <= upper)
        return tree[root];
 
    int mid = start + ((last-start)>>1);
    int left = 2*root;
    int right = 2*root+1;
    int min1 = query(left, start, mid, lower, upper);
    int min2 = query(right, mid+1, last, lower, upper);
    return min(min1, min2);
}
int main()
{
    scanf("%d\n",&t);
    int l, r;
    for(int tc = 1 ; tc <= t ; tc++ ){
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n ; i++ )
            scanf("%d",&arr[i]);
        segment_tree(1,1,n);
 
        printf("Case %d:\n",tc);
        for(int i = 0; i < q ; i++){
            scanf("%d %d",&l,&r);
            printf("%d\n",query(1,1,n,l,r));
        }
    }
    return 0;
}