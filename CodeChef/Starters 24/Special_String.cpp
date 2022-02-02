//Author: Tushar Khanduri
#include<bits/stdc++.h>
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

int minmoves(string &s, int n, int m, bool started){
    if(n<m) return 1e9+7;
    if(n==0 || m==0) return 0;
    char c = 'a' + m%26 - 1;
    if(started){
        if(s[n-1]==c){
            return minmoves(s,n-1,m-1,started);
        }
        return minmoves(s,n-1,m,started)+1;
    }  
    if(s[n-1]!=c){
        return minmoves(s,n-1,m,started);
    }
    int p1 = minmoves(s,n-1,m,started);
    int p2 = minmoves(s,n-1,m-1,true);
    return min(p1,p2);
}

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int m; cin>>m;
    int ans = minmoves(s,n,m,false);
    if(ans>=n) ans=-1;
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