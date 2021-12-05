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

bool valid(int h, int w, int x, int y){
    return x>=0 && x<h && y>=0 && y<w;
}

void solve(){
    int h,w; cin>>h>>w;
    vec<vec<int>> grid(h, vec<int>(w,0));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char c; cin>>c;
            if(c!='.'){
                grid[i][j]=c-'0';
            }
        }
    }
    int dx[]={-1,0,1,0};
    int dy[]={0,-1,0,1};
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(grid[i][j]==0){
                int x=0;
                for(int k=0;k<4;k++){
                    if(valid(h,w,i+dx[k],j+dy[k]) && grid[i+dx[k]][j+dy[k]]){
                        int val=grid[i+dx[k]][j+dy[k]];
                        x|=(1<<val);
                    }
                }                
                int c = 1;
                while(c<6){
                    if(x&(1<<c)) c++;
                    else break;
                }
                grid[i][j]=c;
            }
        }
    }
    for(auto i:grid){
        for(int j:i) cout<<j;
        cout<<endl;
    }
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