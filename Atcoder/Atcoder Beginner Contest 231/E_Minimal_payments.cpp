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

int sol(vec<int> &a, int x, int n, bool change){
    if(x==0) return 0;
    int lb = lower_bound(a.begin(),a.end(),x) - a.begin();
    int p1 = INT64_MAX,p2 = INT64_MAX;
    cout<<"for x: "<<x<<endl;
    p1 = x/a[lb-1] + sol(a,x%a[lb-1],n,change);
    if((lb!=n) && (change==false)){
        p2 = 1 + sol(a,a[lb]-x,n,true);
    }
    cout<<p1<<" "<<p2<<endl;
    return min(p1,p2);
}

void solve(){
    int n,x; cin>>n>>x;
    vec<int> a(n);
    for(int &i:a) cin>>i;
    cout<<sol(a,x,n,false)<<endl;
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