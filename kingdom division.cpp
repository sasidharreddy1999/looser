// question : number of ways to colour a tree using two colours such that every node has
// atleast one neighbour of same colour

// fs(i): number of ways to colour subtree from i assuming node i is already safe
// fns(i): no of ways to colour subtree from i assuming node i is not safe

// safe means already there is one neighbour of same colour

// fs(i)=(fs(1)+fns(1))(fs(2)+fns(2)).....(fs(j)+fns(j)). assuming j children
// fns(i)=fs(i)-fns(1).fns(2).fns(3).......fns(j).


#include <bits/stdc++.h>

using namespace std;
#define lli long long int
#define mod 1000000007

lli vis[100005]={0};
vector<vector<int> > v(100005);
lli powi(lli a,lli b)
{
    if(b==0) return 1;
    else if(b%2==0) return powi((a*a)%mod,b/2);
    else return (a*powi((a*a)%mod,b/2))%mod;
}

// fun(i) uses dfs approach
// fun(i) returns pair(fs(i),fns(i))
pair<lli,lli> fun(lli i)
{
    vis[i]=1;
    lli j=1,k=1,x,y;
    pair<lli,lli> p;
    for(x=0;x<v[i].size();x++)
    {
        y=v[i][x];
        if(vis[y]==0) {p=fun(y); j=(j*(p.first+p.second))%mod; k=(k*(p.second))%mod;}
    }
    k=(j-k+mod)%mod;
    return make_pair(j,k);
}
int kingdomDivision(int n, vector<vector<int>> roads) {

    lli i;
    for(i=0;i<roads.size();i++)
    {
        v[roads[i][0]].push_back(roads[i][1]);
        v[roads[i][1]].push_back(roads[i][0]);
    }
    pair<lli,lli> p;
    p=fun(1);
    return (2*p.second)%mod;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> roads(n-1);
    for (int i = 0; i < n-1; i++) {
        roads[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> roads[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int result = kingdomDivision(n, roads);
    fout << result << "\n";
    fout.close();
    return 0;
}

// another approach overview
// f(i,0) : no of ways of colouring subtree i with children from 0 to j-1
// f(i,0) : can be expressed using f(i,1)..so on
