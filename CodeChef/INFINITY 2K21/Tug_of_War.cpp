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

int mx(vec<int> &a, int s){
    int mx=s;
    for(int i=s;i<a.size();i++){
        if(a[mx]<=a[i]) mx=i;
    }
    return mx;
}

int f(vec<int> &a, int s, int x){
    int cnt=0;
    for(int i=s;i<a.size();i++){
        if(a[i]==x) cnt++;
    }
    return cnt;
}

int numbers_needed(vec<int> &opp, vec<int> &same, int s, int n, int m){
    if(s==n) return 0;
    int mx_idx = mx(opp,s);
    int cnt1 = f(opp,s,opp[mx_idx]);
    int cnt2 = 0;
    if(same[m-1]>opp[mx_idx]) return 0;
    for(int i=m-1;i>=0;i--){
        if(same[i]==same[m-1]) cnt2++;
        else break;
    }
    if(cnt2>cnt1) return 0;
    return numbers_needed(opp,same,s+mx_idx+1,)
}

void solve(){
    int n,m; cin>>n>>m;
    vec<int> opp(n),same(m);
    for(int  &i:opp) cin>>i;
    for(int &i:same) cin>>i;
    sort(same.begin(),same.end(), greater<int>());
    int s1=0,s2=0;
    bool possible=true;
    while(s1<n || s2<m){
        if(same[s2]>opp[s1]) s1++;
        else if(same[s2]==opp[s1]){s1++; s2++;}
        else{
            possible=false;
            break;
        }
    }
    if(!possible){
        cout<<"NO"<<endl;
        return;
    }
    else{
        cout<<"YES"<<endl;
        reverse(same.begin(),same.end());
        // sol_rec();
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