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
const int mod = 998244353;

int sol(int n, int m, int cnt, int lim, int idx){
    if(idx==n) return 1;
    if(cnt>3) return 0;
    int ans=0;
    if(cnt<3){
        for(int i=lim+1;i<=m;i++){
            ans+=sol(n,m,cnt+1,lim,idx+1);
            ans%=mod;
        }
    }
    for(int i=1;i<=lim;i++){
        ans+=sol(n,m,1,i,idx+1);
        ans%=mod;
    }
    return ans;
}

void solve(){
    int n,m; cin>>n>>m;  
    int ans=0;
    for(int i=1;i<=m;i++){
        ans+=sol(n,m,1,i,1);
        ans%=mod;
    } 
    cout<<ans<<endl;
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