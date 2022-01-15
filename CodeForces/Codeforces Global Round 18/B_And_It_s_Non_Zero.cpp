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
vec<vec<int>> pref(2e5+1,vec<int>(30,0));

void solve(){
    int l,r; cin>>l>>r;
    int bits[30];
    for(int i=0;i<30;i++){
        bits[i]=pref[r][i]-pref[l-1][i];
    }   
    int mx=bits[0];
    for(int i=0;i<30;i++){
        mx=max(mx,bits[i]);
    }
    cout<<r-l-mx+1<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc=1;
    cin>>tc;
    for(int i=1;i<=2e5;i++){
        for(int j=0;j<30;j++){
            pref[i][j]=pref[i-1][j];
            if(i&(1<<j)) pref[i][j]++;
        }
    }
    /*for(int i=0;i<10;i++){
        for(int j=0;j<30;j++) cout<<pref[i][j]<<" ";
        cout<<endl;
    }*/
    while(tc--){
        solve();
    }
    return 0;
}