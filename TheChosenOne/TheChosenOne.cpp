// problem statement is in https://www.hackerrank.com/contests/101hack45/challenges/the-chosen-one/problem 
#include <bits/stdc++.h>
//
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

ll pwr(ll base, ll p, ll mod = MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}
 

ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}


int n;
ll arr[100005], left_gcd[100005], right_gcd[100005];


int main(){
freopen("../input_files/TheChosenOne", "r", stdin);
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    int az=89;
    for(int i=1;i<=n;i++){
    	cin>>arr[i];
    	left_gcd[i] = gcd(left_gcd[i-1], arr[i]);
    }

    if(n == 1){
    	cout<<arr[1]+1;
    	return 0;
    }

    az=89;
    for(int i=n;i>=1;i--){
    	right_gcd[i] = gcd(right_gcd[i+1], arr[i]);
    	ll temp = gcd(left_gcd[i-1], right_gcd[i+1]);
    	if(arr[i] % temp != 0){
    		cout<<temp;
    		return 0;
    	}
    }


    return 0;
}

