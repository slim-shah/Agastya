//Slim_Shah
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define F first
#define S second
const ll MOD = 1e9+7;
int P[101];
ll fact[101];
vector<int> out;
vector<int>lex;
void P_gen(int n,int index,int m)
{
    int pr=0,k=0;
    out.clear();
    lex.clear();
    for(k=0;k<n;k++)
    {
        lex.pb(k+1);
    }
   for (k = 0; k < n; ++k)
   {   pr = index / fact[n - 1 - k];
       index = index % fact[n - 1 - k];
       out.pb(pr);
   }

    for(k=0;k<n;k++)
    {
        pr=out.at(k);
        P[k]=lex.at(pr);
        lex.erase(lex.begin()+pr);
    }
    pr=0;
   for(int i=0;i<n;i++)
          cout<<P[i]<<" ";
    cout<<endl;
     pr++;
    while(next_permutation(P,P+n) && pr<m)
    {

        for(int i=0;i<n;i++)
          cout<<P[i]<<" ";

        cout<<endl;
       pr++;
       }
}

int main()
{   fact[0]=1;
    for(int i=1;i<=100;i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
    }

  int t,n,index,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>index>>m;
        P_gen(n,index,m);
        cout<<endl;
    }
return 0;}

