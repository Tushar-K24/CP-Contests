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

void solve(){
    int h,w,k; cin>>h>>w>>k;
    int x1,x2,y1,y2; cin>>x1>>y1>>x2>>y2;
    int moves=0;
    if(k==1){
        if((x1==x2)&&(y1==y2)) moves=0;
        else if((x1==x2)||(y1==y2)) moves=1;
        else moves=0;
    }
    else if(k==2){
        if((x1==x2)&&(y1==y2)) moves = (h+w-1)%mod;
        else if(x1==x2) moves=h-2;
        else if(y1==y2) moves=w-2;
        else moves=2;
    }
    else if(k==3){
        moves=(h+w-1)%mod;
        if((x1==x2)&&(y1==y2)) moves = (moves*((h+w-2)%mod));
        else if((x1==x2)||(y1==y2)) moves = (moves*((2*h + 2*w - 3)%mod))%mod;
        else moves = ((h+w-1))%mod;
    }
    else{
        moves=Math.pow((h+w-1)%mod,k-2,mod);
        moves = (moves*((2*h + 2*w - 3)%mod))%mod;
    }
    cout<<moves<<endl;
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