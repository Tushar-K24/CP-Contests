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
    int n,m; cin>>m>>n;
    vec<vec<int>> table(m,vec<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) cin>>table[i][j];
    }   
    vec<int> gifts(n);
    int mx=0,smx=1;
    int shp=0;
    for(int i=0;i<m;i++){
        int f1=0;
        for(int j=0;j<n;j++){
            if(table[i][j]>table[i][f1]) f1=j;
        }
        int f2=0;
        if(f1==0) f2++; 
        for(int j=0;j<n;j++){
            if(j==f1) continue;
            if(table[i][j]>table[i][f2]) f2=j;
        }
        if(min(table[shp][mx],table[shp][smx])<min(table[i][f1],table[i][f2])){
            mx=f1;
            smx=f2;
            shp=i;
        }
    }
    gifts[mx]=table[shp][mx]; gifts[smx]=table[shp][smx];
    for(int i=0;i<n;i++){
        if(i==mx || i==smx) continue;
        int mx=0;
        for(int j=0;j<m;j++){
            mx=max(table[j][i],mx);
        }
        gifts[i]=mx;
    }
    int ans=gifts[0];
    for(int i:gifts) ans=min(ans,i);
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