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
    tree[root] = tree[left] + tree[right];
}
 
int query(int root, int start, int last, int lower, int upper){
    if( last < lower || start > upper)
        return 0;
    if( start >= lower && last <= upper)
        return tree[root];
 
    int mid = start + ((last-start)>>1);
    int left = 2*root;
    int right = 2*root+1;
    int min1 = query(left, start, mid, lower, upper);
    int min2 = query(right, mid+1, last, lower, upper);
    return min1+min2;
}
 
void update(int root, int start, int last, int index, int newValue) {
    if (index > last || index < start)  // if out of bound
        return;
    if (start >= index && last <= index) {  // if in bound
        tree[root] += newValue;
        return;
    }
    // else on part of the bound
    int left = 2 * root;
    int right = 2 * root + 1;
    int mid = start + ((last - start) >> 1);
    update(left, start, mid, index, newValue);
    update(right, mid + 1, last, index, newValue);
    tree[root] = tree[left] + tree[right];
}
 
int give(int root, int start, int last, int index){
    if( index < start || index > last)
        return 0;
    if(start >= index && last <= index){
        int t = tree[root];
        tree[root] = 0;
        //update(1,1,n,index, 0);
        return t;
    }
    int left = 2 * root;
    int right = 2 * root + 1;
    int mid = start + ((last - start) >> 1);
    int v1 = give(left, start, mid, index);
    int v2 = give(right, mid+1, last, index);
    tree[root] = tree[left]+tree[right];
    return v1+v2;
}
 
int main()
{
    scanf("%d\n",&t);
    int l, r, type, value;
    for(int tc = 1 ; tc <= t ; tc++ ){
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n ; i++ )
            scanf("%d",&arr[i]);
        segment_tree(1,1,n);
 
        printf("Case %d:\n",tc);
        for(int i = 0; i < q ; i++){
            scanf("%d",&type);
            switch(type){
                case 1:
                    scanf("%d",&l);
                    printf("%d\n",give(1,1,n,l+1));
                    break;
            case 2:
                    scanf("%d %d",&l,&value);
                    update(1,1,n,l+1,value);
                    break;
            case 3:
                    scanf("%d %d",&l,&r);
                    printf("%d\n",query(1,1,n,l+1,r+1));
                    break;
            }
        }
    }
    return 0;
}