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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define ll long long
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
vec<int> moves_(1001,1e9+7);

void update(){
    moves_[1]=0;
    moves_[2]=1;
    for(int i=2;i<1001;i++){
        for(int j=1;j<=i/2 + 1;j++){
            int idx = i + i/j;
            if(idx>1000) continue;
            moves_[idx]=min(moves_[idx],moves_[i]+1);
        }
    }
}

void solve(){
    int n,k; cin>>n>>k;
    // k = min(k,12005ll);
    vec<int> b(n), c(n);
    for(int &i:b) cin>>i;
    for(int &i:c) cin>>i;
    int dp[2][k+1];
    for(int i=0;i<=n;i++){
        int moves=0;
        int x=i%2;
        if(i) moves = moves_[b[i-1]];
        for(int j=0;j<=k;j++){
            if(i==0) dp[x][j]=0;
            else{
                if(moves<=j){
                    dp[x][j] = max(dp[1-x][j],dp[1-x][j-moves] + c[i-1]); 
                }
                else{
                    dp[x][j] = dp[1-x][j];
                }
            }
        }
    }
    cout<<dp[n%2][k]<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc=1;
    cin>>tc;
    update();
    while(tc--){
        solve();
    }
    return 0;
}