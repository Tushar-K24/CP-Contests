//Author: Tushar Khanduri
#include<iostream>
#include<vector>
#include<unordered_map>
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
        if(n==0) return 1;
        if(x==0) return 0;
        int ans=1;
        while(n>0){
            if(n&1) ans*=x;
            x*=x;
            n=n>>1;
        }
        return ans;
    }

    int pow(int x, int n, int m){
        if(n==0) return 1;
        if(x==0) return 0;
        int ans=1;
        while(n>0){
            if(n&1) ans=(ans*x)%m;
            x=(x*x)%m;
            n=n>>1;
        }
        return ans;
    }
    
    int modinv(int x, int p){
        return pow(x,p-2,p);
    }

}Math;
//=============================================================================
const int mod = 1e9 + 7;
bool bfs(vec<unordered_map<int,int>> &adj,vec<int> &pvisited, int n, int root){
    vec<int> visited(n+1,0);
    queue<int> q;
    q.push(root);
    visited[root]=1;
    pvisited[root]=1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto i:adj[x]){
            if(visited[i.first]){
                if(adj[i.first][x]) return false;
                return true;
            }
            if(pvisited[i.first]) return false;
            visited[i.first]=1;
            pvisited[i.first]=1;
            q.push(i.first);
        }
    }
    return false;
}

int bfs_(vec<unordered_map<int,int>> &adj, vec<int> &pvisited, int n, int root){
    vec<int> visited(n+1,0);
    queue<int> q;
    q.push(root);
    visited[root]=1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto i:adj[x]){
            if(pvisited[i.first] && !visited[i.first]) return 0;
            if(!visited[i.first]){
                pvisited[i.first]=1;
                visited[i.first]=1;
                q.push(i.first);
            }
        }
    }
    return 1;
}

int cnt_comp(vec<unordered_map<int,int>> &adj, int n){
    int comp=0;
    vec<int> visited(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            comp+=bfs_(adj,visited,n,i);
        }
    }
    return comp;
}

int cycles(vec<unordered_map<int,int>> &adj, int n){
    vec<int> pvisited(n+1,0);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!pvisited[i]){
            cnt += bfs(adj,pvisited,n,i);
        }
    }   
    return cnt;
}

void solve(){
    int n,m; cin>>n>>m;
    vec<unordered_map<int,int>> adj(n+1);
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        adj[i][x]++;
    } 
    int cnt  = cycles(adj,n);
    int comp = cnt_comp(adj,n);
    // cout<<cnt<<" "<<comp<<endl;
    int ans = (Math.pow(m,comp,mod)*Math.pow(m-2,cnt,mod))%mod;
    ans = (ans*Math.pow(m-1,n- cnt - comp,mod))%mod;
    cout<<ans<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc=1;
    cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}