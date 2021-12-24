//Author: Tushar Khanduri
#include<iostream>
#include<vector>
#include<unordered_map>
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
unordered_map<char,int> vowels;

int score(string &s, string &p, char rep, int n){
    int moves=0;
    for(int i=0;i<n;i++){
        if(s[i]==p[i]) continue;
        else{
            if(s[i]=='?'){
                if(p[i]==rep) continue;
                if(vowels[p[i]]==vowels[rep]) moves+=2;
                else moves++; 
            }
            else if(p[i]=='?'){
                if(s[i]==rep) continue;
                if(vowels[s[i]]==vowels[rep]) moves+=2;
                else moves++;
            }
            else{
                if(vowels[s[i]]==vowels[p[i]]) moves+=2;
                else moves++;
            }
        }
    }
    return moves;
}

void solve(){
    int n; cin>>n;
    vowels['a']=1;
    vowels['e']=1;
    vowels['i']=1;
    vowels['o']=1;
    vowels['u']=1;
    string s, p; cin>>s>>p;
    int mn=1e7;
    for(char c='a';c<='z'; c++){
        mn = min(mn,score(s,p,c,n));
    }
    cout<<mn<<endl;
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