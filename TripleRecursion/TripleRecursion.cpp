// problem statement is in https://www.hackerrank.com/contests/w35/challenges/triple-recursion/problem
#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;
#define  ll long long int
#define pb push_back
#define F first
#define S second
#define pp pair<int,int>
#define mod 1e9+7
int m;
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL)
bool cmp2(vector<string>a,vector<string>b){
	return a[m-1] < b[m-1];
}
string remove0(string s){
	int l = s.length();
	string a="";
	int ind=0;
	for(int i=0;i<l;i++){
		if(s[i] != '0'){
			ind = i;
			break;
		}
	}
	for(int i=ind;i<l;i++){
		a += s[i];
	}
	return a;
}
bool cmp1(vector<string>a,vector<string>b){
	string s1 = remove0(a[m-1]);
	string s2 = remove0(b[m-1]);

	int l1 = s1.size();
	int l2 = s2.size();
	if(l1 != l2){
		return l1 < l2;
	}
	for(int i=0;i<l1;i++){
		if(s1[i] > s2[i]){
			return false;
		}else if(s1[i] < s2[i]){
			return true;
		}
	}
	return true;
}
int main(){
freopen("../input_files/TripleRecursion", "r", stdin);
	/*fast_io;
 * 	if(fopen("input", "r"))
 * 		{
 * 				freopen("input", "r", stdin);
 * 						freopen("output","w",stdout);
 * 							}*/
	int t=1;
	int az=89;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int dp[n][n];
		dp[0][0]=m;
		az=89;
		for(int i=1;i<n;i++){
			dp[i][i] = dp[i-1][i-1]+k;
		}
		az=89;
		for(int i=0;i<n;i++){
			int val = dp[i][i];
			for(int j=i+1;j<n;j++){
				dp[i][j]= --val;
			}
			val = dp[i][i];
			for(int j=i+1;j<n;j++){
				dp[j][i] = --val;
			}
		}
		az=89;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}
