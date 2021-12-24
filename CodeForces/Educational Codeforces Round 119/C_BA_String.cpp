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

void sol_rec(vec<int> &lexi, string &s, int n, int k, int x, int idx){
    if(idx==n) return;
    if(x==0){
        for(int i=idx;i<n;i++){
            if(s[i]!='*') cout<<s[i];
        }
        return;
    }
    int next_max=idx+1;
    for(int i=idx+1;i<n;i++){
        if(lexi[i]!=1){
            next_max=i;
            break;
        }
    }
    int cnt=(x-1)/lexi[next_max];
    for(int i=0;i<cnt;i++) cout<<"b";
    for(int i=idx+1;i<n;i++){
        if(s[i]!='*') cout<<s[i];
        else{
            idx=i;
            break;
        }
    }
    cout<<"\nrem: "<<x-lexi[next_max]*cnt<<endl;
    // sol_rec(lexi,s,n,k,x-lexi[next_max]*cnt,idx);
}
void solve(){
    int n,k,x; cin>>n>>k>>x;
    string s; cin>>s;
    vec<int> lexi(n+1,1);
    int prev=1;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='*'){
            lexi[i]=prev*k + lexi[i+1];
        }
        else{
            prev=prev*lexi[i+1];
        }
    }
    int idx=0;
    for(int i=n-1;i>=0;i--){
        if(lexi[i]>=x){
            idx=i;
            break;
        }
    }
    for(int i=0;i<n;i++) cout<<lexi[i]<<" ";
    cout<<endl;
    cout<<idx<<endl;
    for(int i=0;i<idx;i++){
        if(s[i]!='*') cout<<s[i];
    }
    sol_rec(lexi,s,n,k,x,idx);
    cout<<endl;
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