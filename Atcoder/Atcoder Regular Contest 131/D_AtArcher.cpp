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

int score(vec<int> &r, vec<int> &s, int st, int d, int n){
    int total = 0;
    for(int i=0;i<n;i++){
        int lb = lower_bound(r.begin(), r.end(), abs(st))-r.begin();
        if(lb==0) total+=s[0];
        else total+=s[lb-1];
        st-=d;
        if(st<0 && abs(st)>r[r.size()-1]) break;
    }
    return total;
}

int peak(vec<int> &r, vec<int> &s, int l_, int r_, int d, int n){
    int m=(l_+r_)/2;
    int s1 = score(r,s,m,d,n);
    if(m-1<l_){
        // int s2=score(r,s,m+1,)
    }
}
void solve(){
    int n,m,d; cin>>n>>m>>d;
    vec<int> r(m+1),s(m);
    for(int &i:r) cin>>i;
    for(int &i:s) cin>>i;
    // int l_=0,r_=r[m];
    for(int i=r[m];i>=0;i--){
        cout<<"start: "<<i<<" score: "<<score(r,s,i,d,n)<<endl;
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