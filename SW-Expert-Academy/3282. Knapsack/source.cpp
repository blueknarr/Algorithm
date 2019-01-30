#include <cstdio>
#include <algorithm>
using namespace std;
 
int t,n,k,v[101],c[101],d[1001][101];
 
int main()
{
    scanf("%d",&t);
    for(int T=1;T<=t;T++)
    {
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d %d",&v[i],&c[i]);
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>=v[j]) d[i][j]=max(d[i][j-1],d[i-v[j]][j-1]+c[j]);
                else d[i][j]=d[i][j-1];
            }
        }
        printf("#%d %d\n",T,d[k][n]);
    }
    return 0;
}