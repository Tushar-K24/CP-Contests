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

int dist(int x,int y, int x1, int y1){
    int eud = (y-y1)*(y-y1) + (x-x1)*(x-x1);
    return eud;
}

void solve(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;   
    //dy(2y-sy) = -dx(2x-sx)
    int dx = x2-x1;
    int dy = y2-y1;
    int x = (x1+x2)/2;
    int y = (y1+y2)/2;
    int sx=x1+x2;
    int sy=y1+y2;
    if(dy<0){
        dy*=-1;
        dx*=-1;
    }
    if(dy==0){
        if(sx%2==0){
            for(int i=0;i<5;i++){
                int d1 = dist(x1,y1,sx/2,sy/2 + i);
                int d2 = dist(x2,y2,sx/2,sy/2 + i);
                if((d1==5) && (d2==5)){
                    cout<<"Yes"<<endl;
                    return;
                }
            }
        }
        cout<<"No"<<endl;
        return;
    }
    for(int i=0;i<5;i++){
        int nx = x+i;
        int ny = -dx*(2*nx - sx);
        if(ny%dy) continue;
        ny/=dy;
        ny+=sy;
        if(abs(ny)&1) continue;
        ny/=2;
        int d1=dist(x1,y1,nx,ny);
        int d2=dist(x2,y2,nx,ny);
        if((d1==5)&&(d2==5)){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc=1;
    // cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}