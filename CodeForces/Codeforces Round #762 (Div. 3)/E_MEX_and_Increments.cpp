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
    map<int,int> mp;
    stack<int> st;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        mp[x]++;
    }   
    int prev=0;
    bool possible=true;
    for(int i=0;i<=n;i++){
        if(!possible){
            cout<<-1<<" ";
            continue;
        }
        if(mp[i]==0){
            cout<<prev<<" ";
            if(st.empty()){
                possible=false;
            }
            else{
                int val = st.top();
                prev+=i-val;
                mp[val]--;
                if(mp[val]==1) st.pop();
            }
        }
        else{
            if(mp[i]>1) st.push(i);
            cout<<prev+mp[i]<<" ";
        }
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