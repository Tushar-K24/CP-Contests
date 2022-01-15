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
    string s; cin>>s;
    int idx=0,idx1=0;
    for(int i=1;i<n;i++){
        if(s[i]<s[i-1]){
            idx=i;
        }
        else break;
    }   
    for(int i=1;i<n;i++){
        if(s[i]<=s[i-1]){
            idx1=i;
        }
        else break;
    }   
    int ans_idx=idx;
    // cout<<idx1<<" "<<idx<<endl;
    if(idx!=idx1){
        int found=-1;
        int j=idx;
        for(int i=idx+1;i<=idx1 && j>=0;i++,j--){
            if(s[i]!=s[j]){
                if(s[i]<s[j]){
                    found=0;
                    break;
                }
                else{
                    found=1;
                    break; 
                }
            }
        }
        if(found!=-1){
            // cout<<"yahan se mila"<<endl;
            if(found==0) ans_idx=idx1;
            else ans_idx=idx;    
            // cout<<ans_idx<<endl;    
        }
        else{
            for(int i=idx1;i>=0 && j>=0;i--,j--){
                if(s[i]!=s[j]){
                    if(s[i]<s[j]){
                        found=0;
                        break;
                    }
                    else{
                        found=1;
                        break; 
                    }
                }
            }
            if(found==-1) ans_idx=idx;
            else{
                if(found==0) ans_idx=idx1;
                else ans_idx=idx;
            }
        }
    }
    for(int i=0;i<=ans_idx;i++) cout<<s[i];
    for(int i=ans_idx;i>=0;i--) cout<<s[i];
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