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
const int mod=998244353;
void solve(){
    int n; cin>>n;
    vec<int> digits;
    digits.pb(0);
    digits.pb(0);
    int pow = 10;
    for(int i=2;i<19;i++){
        int s = pow - pow/10;
        int temp = s+1;
        if(s&1) temp/=2;
        else s/=2;
        s%=mod;
        temp%=mod;
        s*=temp;
        digits.pb(s%mod);
        pow*=10;
    }
    for(int i=1;i<19;i++) digits[i]=(digits[i]+digits[i-1])%mod;
    int cnt=0;
    int x=1;
    while(x<=n){
        x*=10;
        cnt++;
    }
    x/=10;
    int ans = digits[cnt];
    int rem = n-x + 1;
    int temp = rem+1;
    if(rem&1) temp/=2;
    else rem/=2;
    rem%=mod;
    temp%=mod;
    ans+=(rem*temp)%mod;
    ans%=mod;
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