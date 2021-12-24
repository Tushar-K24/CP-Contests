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
int max_moves(vec<vec<int>> &dp, vec<string> &grid, int h, int w, int r, int c){
    if(r==h || c==w) return 0;
    if(grid[r][c]=='#') return 0;
    if(dp[r][c]!=-1) return dp[r][c];
    int p1 = max_moves(dp,grid, h, w, r+1, c);
    int p2 = max_moves(dp,grid, h, w, r, c+1);
    return dp[r][c]=max(p1,p2)+1;
}

void solve(){
    int h,w; cin>>h>>w;
    vec<string> grid(h);
    vec<vec<int>> dp(h+1,vec<int>(w+1,-1));
    for(int i=0;i<h;i++) cin>>grid[i];
    cout<<max_moves(dp,grid,h,w,0,0)<<endl;   
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