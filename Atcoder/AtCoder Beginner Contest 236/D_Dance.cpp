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
//0000
int mx_fun(vec<vec<int>> &a, int idx, vec<bool> &chosen, int n, int curr){
    if(idx==2*n) return curr;
    if(chosen[idx]){
        return mx_fun(a,idx+1,chosen,n,curr);
    }
    chosen[idx]=true;
    int ans=0;
    for(int i=idx+1;i<2*n;i++){
        if(chosen[i]) continue;
        chosen[i]=true;
        int temp = mx_fun(a,idx+1,chosen,n,a[idx][i]^curr);
        chosen[i]=false;
        ans = max(ans,temp);
    }
    chosen[idx]=false;
    return ans;
}

void solve(){
    int n; cin>>n;
    vec<vec<int>> a(2*n,vec<int>(2*n));
    for(int i=0;i<2*n-1;i++){
        for(int j=i+1;j<2*n;j++){
            cin>>a[i][j];
        }
    }
    vec<bool> chosen(2*n, false);
    cout<<mx_fun(a,0,chosen,n,0)<<endl;
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