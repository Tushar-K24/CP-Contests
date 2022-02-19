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
    string s1, s2;
    cin>>s1>>s2;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    int a_ptr=0,b_ptr=n-1;
    int a_rev=n-1,b_rev=0;
    vec<char> res(2*n);
    int idx=0,r_idx=2*n-1;
    bool alice=true;
    while(idx<=r_idx){
        if(alice){
            // cout<<"Alice turn: ";
            if(s1[a_ptr]<s2[b_ptr]){
                // cout<<"placed "<<s1[a_ptr]<<" at "<<idx<<endl;
                res[idx++]=s1[a_ptr++];
            }
            else{
                // cout<<"placed "<<s1[a_rev]<<" at "<<r_idx<<endl;
                res[r_idx--]=s1[a_rev--];
            }
            alice=false;
        }
        else{
            // cout<<"Bob turn: ";
            if(s2[b_ptr]>s1[a_ptr]){
                // cout<<"Placed "<<s2[b_ptr]<<" at "<<idx<<endl;
                res[idx++]=s2[b_ptr--];
            }
            else{     
                // cout<<"placed "<<s2[b_rev]<<" at "<<r_idx<<endl;
                res[r_idx--]=s2[b_rev++];
            }
            alice=true;
        }
    }
    for(char c:res) cout<<c;
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