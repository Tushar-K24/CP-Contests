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
    int a,b; cin>>a>>b;
    int x1=0, x2=0;
    //case 1: add to b
    bool set=false;
    int idx=0;
    for(int i=20;i>=0;i--){
        int bit = 1<<i;
        if(set){
            if(bit&b) x2-=bit;
            if(bit&a) x2+=bit;
        }
        else{
            if(bit&a){
                if((bit&b)==0){
                    idx=i;
                    set=true;
                    x2=bit;
                }
            }
        }
    } 
    int a2=x2;
    if(a!=b+x2) a2++;

    //case 2: add to a
    int temp=idx;
    for(int i=idx;i<=20;i++){
        int bit = 1<<i;
        if(bit&b){
            if((bit&a)==0){
                temp=i;
                x1=bit;
                break;
            }
        }
    }
    for(int i=temp-1;i>=0;i--){
        int bit = 1<<i;
        x1-=(bit&a);
    }
    int a1 = x1;
    if(a+x1 != b) a1++;

    
    cout<<min(a1,a2)<<endl;
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