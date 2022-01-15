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

#define ff first
#define ss second

void solve(){
    int n; cin>>n;
    vec<pair<int,int>> ranges(n);
    map<pair<int,int>,int> mp;
    for(int i=0;i<n;i++){
        cin>>ranges[i].ff>>ranges[i].ss;
        mp[ranges[i]]++;
    }
    for(auto i:ranges){
        int d=i.ff;
        for(int j=i.ff;j<=i.ss;j++){
            if(i.ff==j){
                if(mp[{j+1,i.ss}]){
                    d=j;
                    break;
                }
            }
            if(i.ss==j){
                if(mp[{i.ff,j-1}]){
                    d=j;
                    break;
                }
            }
            if(mp[{i.ff,j-1}] && mp[{j+1,i.ss}]){
                d=j;
                break;
            }
        }
        cout<<i.ff<<" "<<i.ss<<" "<<d<<endl;
    }
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