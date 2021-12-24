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

int distance(vec<int> &a, int k){
    int n=a.size();
    int i=n-1;
    int dist=0;
    while(i-k+1>0){
        dist+=2*a[i];
        i-=k;
    }
    if(i>=0){
        dist+=2*a[i];
    }
    return dist;
}

void solve(){
    int n,k; cin>>n>>k;
    vec<int> a(n);
    for(int &i:a) cin>>i;
    vec<int> neg, pos;
    for(int i=0;i<n;i++){
        if(a[i]<0) neg.pb(abs(a[i]));
        else pos.pb(a[i]);
    }   
    sort(a.begin(),a.end());
    sort(neg.begin(),neg.end());
    sort(pos.begin(),pos.end());
    int d1=distance(pos,k);
    int d2=distance(neg,k);
    if(d1==0){
        cout<<d2-abs(a[0])<<endl;
    }     
    else if(d2==0){
        cout<<d1-a[n-1]<<endl;
    }
    else{
        int ans=d1+d2 - max(abs(a[0]),a[n-1]);
        cout<<ans<<endl;
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