// https://codeforces.com/problemset/problem/1336/C
// C. Kaavi and Magic Spell

#include<bits/stdc++.h>
using namespace std;
#define opt ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int lli;
typedef pair<lli,lli > plli;
typedef vector<lli>    vlli;
typedef vector<plli >  vplli;
typedef vector<string> vs;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define sz() size()
#define lb lower_bound
#define ub upper_bound
#define inf 1e15
#define mod 1000000007
#define mod5 1000000005
#define rep(i,a,b) for(i=a;i<b;i++)
#define run(i,a,b) for(i=a;i!=b;i++)
#define all(v)     v.begin(),v.end()
#define nl cout<<"\n"

// v[i][j]  number of seq with string of length i starting from index j

int main()
{
    string s,t;
    cin>>s>>t;
    lli n,m,i,j,ans=0,h=998244353;
    n=s.sz();
    m=t.sz();

    vector<vlli> v(n+1);
    rep(i,1,n+1) v[i].assign(n+1-i,0);


    for(i=0;i<v[1].sz();i++)
    {
        if(i>=m) v[1][i]=2;
        else if(t[i]==s[0]) v[1][i]=2;
    }

    for(i=1;i<n;i++)
    {
        for(j=0;j<v[i].sz();j++)
        {
            if(v[i][j]!=0)  // to see if this can extend string to next length
            {
                if(j+i<n)  // if less than n we need to compare next character t[j+i] with character s[i] being added
                {
                    if((j+i<m&&s[i]==t[j+i])||(j+i>=m)) v[i+1][j]=(v[i+1][j]+v[i][j])%h;
                }
                if(j!=0) // to add at front
                {
                    if(j-1>=m) v[i+1][j-1]=(v[i+1][j-1]+v[i][j])%h;
                    else if(s[i]==t[j-1]) v[i+1][j-1]=(v[i+1][j-1]+v[i][j])%h;
                }
            }
        }
        if(i>=m) ans=(ans+v[i][0])%h;
    }
    ans=(ans+v[n][0])%h;
    cout<<ans<<endl;
}

