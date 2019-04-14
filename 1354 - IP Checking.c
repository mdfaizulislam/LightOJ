#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
int main()
{
    int t,i,j,k,increment,ans,la,lb,c,n,p[4],q[4],o;
    char a[37],b[37];
   // freopen("in.txt","r",stdin);
    scanf("%d",&t);
    t++;
   for( i = 1 ; i < t ; i++ )
   {
       scanf("%s %s",a,b);
       la=strlen(a)-1;
       lb=strlen(b)-1;
       for( j = la,n=0,increment=1,c=0 ; j > -1 ; j--  )
       {
           if( a[j] == '.' || j == 0 )                            //192.168.0.100
           {                                            //11000000.10101000.00000000.11001000
               if( j == 0 )
               {
                   k=a[j]-48;
                    n+=k*increment;
                    p[c]=n;
               }
               else
                    p[c]=n;
               n=0;
               increment=1;
               c++;
           }
           else
           {
                k=a[j]-48;
                n+=k*increment;
                increment*=10;
           }
       }
       for( j = lb,increment=0,ans=0,c=0 ; j > -1 ; j-- )
       {
           if( b[j] == '.' || j == 0 )                         //11000000.10101000.00000000.11001000
           {
               if( j == 0 )
               {
                o=b[j]-48;
                if(  o == 1 )
                   {
                       n=pow(2,increment);
                       ans+=n;
                       q[c]=ans;
                   }
                   else
                        q[c]=ans;
               }
               else
                    q[c]=ans;
               ans=0;
               increment=0;
               c++;
           }
           else
           {
                o=b[j]-48;
                if(  o == 1 )
                   {
                       n=pow(2,increment);
                       ans+=n;
                   }
                   increment++;
           }
 
       }
       if( p[0]==q[0] && p[1]==q[1] && p[2]==q[2] && p[3]==q[3])
        printf("Case %d: Yes\n",i);
       else
        printf("Case %d: No\n",i);
   }
    return 0;
}