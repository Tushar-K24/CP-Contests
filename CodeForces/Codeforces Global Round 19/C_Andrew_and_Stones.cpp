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
    1 2 3 4 5 1

    1 0 4 2 6 1
*/

int cal_moves(int n){
    if(n==1) return 2;
    if(n==0) return 1;
    return cal_moves(n-2) + 2;
}

void solve(){
    int n; cin>>n;
    vec<int> a(n);
    int moves=0;
    int odds=0;
    for(int &i:a) cin>>i;
    for(int i=1;i<n-1;i++){
        if(a[i]&1){
            odds++;
        }
    }
    if(odds+2 == a.size()){
        cout<<-1<<endl;
        return;
    }
    for(int i=1;i<n-1;i++){
        moves+=(a[i]+1)/2;
    }
    cout<<moves<<endl;
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