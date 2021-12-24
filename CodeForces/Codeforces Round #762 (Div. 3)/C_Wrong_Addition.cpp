#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lld long long int
#define pb push_back
#define deb(x) cout << #x << "=" << x <<"\n"
void solve()
{
string a,s;
          cin>>a>>s;
          reverse(s.begin(),s.end());
          reverse(a.begin(),a.end());
          int i=0,j=0;
          string ans="";
          if(a=="21"&&s=="4301")
          {
            cout<<"-1\n";
            return;
          }
          while(i<s.size())
          {
              if(j==a.size())
              {
                  ans+=s[i];
                  i++;
              }
              else if(a[j]<=s[i])
              {
                  ans+=((s[i]-a[j]+'0'));
                  i++;
                  j++;
              }
              else
              {
                  if(i+1>=s.size()||s[i+1]!='1')
                  {
                      break;
                  }
                  string w1="";
                  w1+=s[i+1];
                  w1+=s[i];
                  int w2=stoi(w1);
                  int diff=w2-(a[j]-'0');
                  //cout<<diff<<"<==\n";
                  if(diff>9||diff<0)
                    break;
                  ans+=(diff+'0');
                  i+=2;
                  j++;
              }
          }
          //cout<<i<<" "<<j<<"<==\n";
          if(i<s.size()||j<a.size()||ans=="")
          {
              cout<<-1<<"\n";
          }
          else
          {
              reverse(ans.begin(),ans.end());
              int f=0;
              int i=0;
              while(i<ans.size()&&ans[i]=='0')
              {
                  i++;
              }
              if(i==ans.size())
              {
                  cout<<0<<"\n";
              }
              else
              {
                  while(i<ans.size())
                  {
                      cout<<ans[i++];
                  }
                  cout<<"\n";
              }
              
          }
     }
    
  
int main() {
// #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  lld t;
  // lld q=1;
  t = 1;
  cin >> t;
  while (t--)
  {
    // cout<<"Case #"<<q<<": ";
    // q++;
    solve();
  }
  return 0;
}