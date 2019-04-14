#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int main()
{
    int t,i,final,check,j,k;
    char a[102],b[102],c,d;
    scanf("%d\n",&t);
    t++;
    for( i = 1 ; i < t ; i++ )
    {
        gets(a);
        gets(b);
        j=0;
        final=1;
        while( a[j] != '\0' )
        {
            k=0;
            check=0;
            if( a[j] == ' ' )
            {
                j++;
                continue;
            }
            if( a[j] > 96 )
                c=a[j]-32;
            else
                c=a[j];
            while( b[k] != '\0' )
            {
                if( b[k] > 96 )
                    d=b[k]-32;
                else
                    d=b[k];
                if( c == d )
                {
                    b[k]=' ';
                    check=1;
                    break;
                }
                 k++;
            }
            if( check == 0 )
            {
                final=0;
                break;
            }
            j++;
        }
        if( final == 1 )
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);
 
    }
    return 0;
}
 