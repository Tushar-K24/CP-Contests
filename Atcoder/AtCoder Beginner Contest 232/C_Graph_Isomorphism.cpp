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

void dfs(vec<vec<int>> &toy, vec<int> &visited, int node){
    for(int i:toy[node]){
        if(!visited[i]){
            visited[i]=1;
            dfs(toy,visited,i);
        }
    }
}

int cc(vec<vec<int>> &toy){
    int n=toy.size();
    vec<int> visited(n);
    int cnt=0;
    for(int i=1;i<n;i++){
        if(!visited[i]){
            cnt++;
            visited[i]=1;
            dfs(toy,visited,i);
        }
    }
    return cnt;
}

void printgraph(vec<vec<int>> &toy){
    int n=toy.size();
    for(int i=0;i<n;i++){
        cout<<i<<": ";
        for(int j:toy[i]) cout<<j<<" ";
        cout<<endl;
    }
}

void solve(){
    int n,m; cin>>n>>m;
    vec<vec<int>> toy1(n+1),toy2(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        toy1[u].pb(v);
        toy1[v].pb(u);
    }  
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        toy2[u].pb(v);
        toy2[v].pb(u);
    }  
    // printgraph(toy1);
    // printgraph(toy2);
    int cc1 = cc(toy1);
    int cc2 = cc(toy2);
    if(cc(toy1)!=cc(toy2)){
        cout<<"No"<<endl;
        return;
    }
    vec<int> a(n),b(n);
    for(int i=1;i<=n;i++) a[i-1]=(int)toy1[i].size();
    for(int i=1;i<=n;i++) b[i-1]=(int)toy2[i].size();
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            cout<<"No"<<endl;
            return;
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