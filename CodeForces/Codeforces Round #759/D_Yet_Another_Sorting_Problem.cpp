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
map<int,set<int>> mp;

int max(vec<int> &a, int n){
    return *((mp.rbegin()->second).rbegin());
}

bool check(vec<int> &a, int n){
    if(n==1) return true;
    if(n==2) return a[0]<=a[1];
    int mx = max(a,n);
    if(mx==n-1) return check(a,n-1);
    else if(mx==n-2){
        for(int i=1;i<3;i++) mp[a[n-i]].erase(n-i);
        mp[a[n-3]].insert(n-2);
        mp[a[n-1]].insert(n-3);
        if(mp[a[n-2]].empty()) mp.erase(a[n-2]);
        int x=a[n-3];
        a[n-3]=a[n-1];
        a[n-1]=a[n-2];
        a[n-2]=x;
        return check(a,n-1);
    }
    mp[a[n-1]].erase(n-1);
    mp[a[n-2]].erase(n-2);
    mp[a[mx]].erase(mx);
    mp[a[n-2]].insert(mx);
    mp[a[n-1]].insert(n-2);
    if(mp[a[mx]].empty()) mp.erase(a[mx]); 
    int x=a[n-1];
    a[n-1]=a[mx];
    a[mx]=a[n-2];
    a[n-2]=x;
    return check(a,n-1);
}
void solve(){
    mp.clear();
    int n; cin>>n;
    vec<int> a(n);
    for(int &i:a) cin>>i;
    for(int i=0;i<n;i++){
        mp[a[i]].insert(i);
    }
    if(check(a,n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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