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

void solve(){
    int w,h; cin>>w>>h;
    vec<vec<int>> x(2),y(2);
    for(int i=0;i<2;i++){
        int n; cin>>n;
        for(int j=0;j<n;j++){
            int a; cin>>a;
            x[i].pb(a);
        }
    }   
    for(int i=0;i<2;i++){
        int n; cin>>n;
        for(int j=0;j<n;j++){
            int a; cin>>a;
            y[i].pb(a);
        }
    }   
    int x1 = 0;
    if(x[0].size()>1){
        x1 = (x[0][x[0].size()-1]-x[0][0]);
        if(x[1].size()) x1*=h;
        else{
            x1*=max(y[0][y[0].size()-1],y[1][y[1].size()-1]);
        }
    }
    int x2 = 0;
    if(x[1].size()>1){
        x2 = (x[1][x[1].size()-1]-x[1][0]);
        if(x[0].size()) x2*=h;
        else{
            x2*=(h-min(y[0][0],y[1][0]));
        }
    }
    int y1 = 0;
    if(y[0].size()>1){
        y1 = (y[0][y[0].size()-1]-y[0][0]);
        if(y[1].size()) y1*=w;
        else{
            y1*=max(x[0][x[0].size()-1],x[1][x[1].size()-1]);
        }
    }
    int y2 = 0;
    if(y[1].size()>1){
        y2 = (y[1][y[1].size()-1]-y[1][0]);
        if(y[0].size()) y2*=w;
        else{
            y2*=(w-min(x[0][0],x[1][0]));
        }
    }
    int ans = max(max(x1,x2),max(y1,y2));
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