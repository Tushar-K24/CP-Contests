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
#define ff first
#define ss second
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

bool my_compare(pair<char,int> p1, pair<char,int> p2){
    return p1.ss>p2.ss;
}

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    if(n&1){
        cout<<"NO"<<endl;
        return;
    }
    vec<pair<char,int>> f(26);
    for(int i=0;i<26;i++){
        f[i]={char(i+'a'),0};
    }
    for(char c:s){
        f[c-'a'].ss++;
    }       
    sort(f.begin(),f.end(),my_compare);
    if(f[0].ss>n/2){
        cout<<"NO"<<endl;
    }    
    else{
        cout<<"YES"<<endl;
        sort(s.begin(),s.end());
        int ptr=0;
        for(int i=0,j=n-1;i<j;i++,j--){
            if(s[i]==s[j]){
                swap(s[i],s[ptr++]);
            }
        }
        cout<<s<<endl;
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