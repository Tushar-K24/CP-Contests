//Author: Tushar Khanduri
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cmath>
#include<string>
#include<bitset>
#include<algorithm>
#define int long long
#define endl "\n"
#define pb push_back
#define vec vector
using namespace std;

//==============================================================================
class Math{
    public:
    int gcd(int a, int b){
        if(b==0)
            return a;
        return gcd(b,a%b);
    }

    int lcm(int a, int b){
        return a*(b/gcd(a,b));
    }

    void set_sieve(vector<bool> &sieve, int n){
        for(int i=2;i*i<=n;i++)
            if(sieve[i])
                for(int j=i*i;j<=n;j+=i)
                    sieve[j]=false;
    }

    int pow(int x, int n){
        int ans=1;
        while(n>0){
            if(n&1) ans*=x;
            x*=x;
            n=n>>1;
        }
        return ans;
    }

    int pow(int x, int n, int m){
        int ans=1;
        while(n>0){
            if(n&1) ans=(ans*x)%m;
            x=(x*x)%m;
            n=n>>1;
        }
        return ans;
    }
    
    int modinv(int x, int p){
        return pow(x,p-2);
    }

}Math;
//=============================================================================
void dfs(vec<vec<int>> &adj, vec<int> &visited, int node, int &cnt){
    visited[node]=1;
    if(adj[node].size()==1) cnt++;
    if(adj[node].size()==0) cnt+=2;
    for(int i:adj[node]){
        if(!visited[i]){
            dfs(adj,visited,i,cnt);
        }
    }
}

void solve(){
    int n,m; cin>>n>>m;
    vec<vec<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(adj[i].size()>2){
            cout<<"No"<<endl;
            return;
        }
    }
    vec<int> visited(n+1);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            int cnt=0;
            dfs(adj,visited,i,cnt);
            if(cnt!=2){
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc=1;
    // cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}