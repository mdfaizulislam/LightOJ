#include<stdio.h>
    int main()
    {
        int j,n,k=1;
        long long int i,a[1002],sum;
        scanf("%d",&j);
        while (k<=j)
        {
            scanf("\n%d",&n);
            sum=0;
            for(i=1;i<=n;i++)
                scanf("%lld",&a[i]);
            for(i=1;i<=n;i++)
            {
                if( a[i] > 0 )
                sum=sum+a[i];
            }
 
            printf("Case %d: %lld\n",k,sum);
 
            k++;
        }
        return 0;
    }
 
