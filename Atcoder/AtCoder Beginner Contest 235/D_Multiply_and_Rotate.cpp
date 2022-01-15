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
vec<vec<int>> dp(1e6,vec<int>(2,-2));

int sol_dp(int a,int n, int rot){
    if(n==1) return 0;
    // cout<<"n: "<<n<<endl;
    if(dp[n][rot]!=-2){
        return dp[n][rot];
    }
    int &p=dp[n][rot];
    p=-1;
    if(n%a==0){
        p=sol_dp(a,n/a,0);
        if(p!=-1) p++;
    }
    // cout<<"p after a's division: "<<p<<endl;
    if(rot) return p;
    int l = 0;
    int temp=n;
    while(temp){
        l++;
        temp/=10;
    }
    int pw=Math.pow(10,l-1);
    for(int i=1;i<l;i++){
        int x=n%pw;
        x*=10;
        x+=n/pw;
        if(x%10==0) break;
        n=x;
        temp=sol_dp(a,n,1);
        // cout<<"for n: "<<n<<" our temp_soln: "<<temp<<endl;
        if(temp==-1) continue;
        temp+=i;
        if(p==-1) p=temp;
        else p=min(p,temp);
    }
    return p;
}
void solve(){
    int a, n; cin>>a>>n;
    cout<<sol_dp(a,n,false)<<endl;   
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