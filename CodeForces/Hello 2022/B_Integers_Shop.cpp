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
    int n; cin>>n;
    vec<int> l(n), r(n), c(n);
    for(int i=0;i<n;i++) cin>>l[i]>>r[i]>>c[i];
    int mn = 0, mx=0;
    vec<int> ans(n);
    for(int i=0;i<n;i++){
        if(l[i]<l[mn]){
            mn=i;
        }
        if(r[i]>r[mx]){
            mx=i;
        }
        if(mn==mx){
            if((l[i]==l[mn]) && (r[i]==r[mx])){
                if(c[i]<c[mn]){
                    mn=i;
                    mx=i;
                }
            }
            ans[i]=c[mn];
        }
        else{
            if((l[i]==l[mn]) && (r[i]==r[mx])){
                int c1 = c[mn]+c[mx];
                ans[i]=min(c[i],c1);
                if(c[i]<c[mn]) mn=i;
                if(c[i]<c[mx]) mx=i;
            }
            else{ 
                if(l[i]==l[mn]){
                    if(c[i]<c[mn]){
                        mn=i;
                    }
                }
                else if(r[i]==r[mx]){
                    if(c[i]<c[mx]){
                        mx=i;
                    }
                }
                if((l[mn]==l[mx]) && (r[mn]==r[mx])){
                    ans[i]=min(c[mn],c[mx]);
                }
                else if(l[mn]==l[mx]) ans[i]=c[mx];
                else if(r[mn]==r[mx]) ans[i]=c[mn];
                else ans[i]=c[mn]+c[mx];
            }
        }
        cout<<ans[i]<<endl;
    }   
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