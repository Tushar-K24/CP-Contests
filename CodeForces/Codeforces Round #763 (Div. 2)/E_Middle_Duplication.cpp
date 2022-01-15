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
#define ff first
#define ss second

bool sol_rec(vec<pair<int,int>> &tree, vec<char> &letters, vec<int> &levels, int root, int &k, bool f){
    int l=tree[root].ff;
    int r=tree[root].ss;
    if(l && r){
        bool p = sol_rec(tree, letters, levels, l, k, f);
        cout<<letters[root];
        if(p){
            cout<<letters[root];
        }
    }
    else if(l){
        bool p = sol_rec(tree, letters, levels, l, k, f);
        cout<<letters[root];
        if(p){
            cout<<letters[root];
        }
    }
    else if(r){
        cout<<letters[root];

    }
}
void solve(){
    int n,k; cin>>n>>k;
    vec<char> letters(n+1);
    for(int i=1;i<=n;i++) cin>>letters[i];
    vec<pair<int,int>> tree(n+1);
    for(int i=1;i<=n;i++){
        int l,r; cin>>l>>r;
        tree[i]={l,r};
    }
    // initializing levels
    vec<int> level(n+1);
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        int l = tree[x].ff, r = tree[x].ss;
        if(l){
            level[l]=level[x]+1;
            q.push(l);
        } 
        if(r){
            level[r]= level[x]+1;
            q.push(r);
        }
    }
    sol_rec()
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