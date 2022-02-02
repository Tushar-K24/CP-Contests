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

/*
    hc + xa, dc + (k-x)w
    hm/(dc + (k-x)w) <= (hc+xa)/(dm)

    hc = 25, dc = 4
    hm = 12, dm = 20
    k = 1, w = 1, a = 10
*/
void solve(){
    double hc,dc; cin>>hc>>dc;
    double hm,dm; cin>>hm>>dm;
    int k,w,a; cin>>k>>w>>a;
    dc += k*w;
    bool ok=false;
    for(int i=0;i<=k;i++){
        if(ceil(hm/(dc - i*w)) <= ceil((hc + i*a)/dm)){
            ok=true;
            break;
        }
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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