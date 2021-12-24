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
int par(vec<int> &p, int x){
    if(p[x]==x) return x;
    return p[x]=par(p,p[x]);
}

void solve(){
    int q; cin>>q;
    vec<int> p(1e6);
    for(int i=0;i<1e6;i++) p[i]=i;
    vec<int> idxs(1e6,-1);
    int sz=1e6;
    int idx=0;
    while(q--){
        int c; cin>>c;
        if(c==1){
            int x; cin>>x;
            idxs[idx++]=x;
        }
        else{
            int x,y; cin>>x>>y;
            p[x]=
            
            y;
        }
    }
    for(int i=0;i<idx;i++){
        cout<<par(p,idxs[i])<<" ";
    }
    cout<<endl;
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