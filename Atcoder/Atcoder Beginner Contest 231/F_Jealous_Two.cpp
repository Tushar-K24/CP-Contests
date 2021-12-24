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

int _mergeSort(vec<int> arr, int temp[], int left, int right);
int merge(vec<int> arr, int temp[], int left, int mid, int right);

int mergeSort(vec<int> arr, int array_size)
{
	int temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}
int _mergeSort(vec<int> arr, int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left) {
		mid = (right + left) / 2;
		inv_count += _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);
		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

int merge(vec<int> arr, int temp[], int left, int mid,
		int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left; /* i is index for left subarray*/
	j = mid; /* j is index for right subarray*/
	k = left; /* k is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid - i);
		}
	}
	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}
//==============================================================================
bool my_compare(pair<int,int> p1, pair<int,int> p2){
    if(p1.first>p2.first) return false;
    if(p1.first==p2.first) return p1.second>p2.second;
    return true;
}
void solve(){
    int n; cin>>n;
    vec<pair<int,int>> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>p[i].second;
    }
    sort(p.begin(),p.end(),my_compare);
    for(int i=0;i<n;i++) cout<<p[i].first<<" ";
    cout<<endl;
    for(int i=0;i<n;i++) cout<<p[i].second<<" ";
    cout<<endl;
    vec<int> a(n);
    for(int i=0;i<n;i++){
        a[i]=p[i].second;
    }
    cout<<n+mergeSort(a,n)<<endl;;
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