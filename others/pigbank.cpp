#include<iostream>
#include <cstdio>

using namespace std;

#define INF 1000001

int dp[10005];

int main()
{
    int t,e,f,n;
    scanf("%d",&t);
    while(t--)
    {
        int p[505],w[505];
        scanf("%d %d %d",&e,&f,&n);dp[0]=0;
        for(int i=1;i<=10000;i++)dp[i]=INF;
        for(int i=0;i<n;i++)
            scanf("%d %d",&p[i],&w[i]);
        for(int i=1;i<=f-e;i++)
            for(int j=0;j<n;j++)
                if(w[j]<=i and dp[i-w[j]]+p[j]<dp[i])
                    dp[i]=dp[i-w[j]]+p[j];
        if(dp[f-e]==INF)cout << "This is impossible." << endl;
        else cout << "The minimum amount of money in the piggy-bank is " << dp[f-e] << "." << endl;
    }

    return 0;
}
