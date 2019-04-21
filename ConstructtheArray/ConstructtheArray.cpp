/* the problem statement is in https://www.hackerrank.com/contests/101hack52/challenges/construct-the-array/problem
#include <bits/stdc++.h>
*/

//#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 510031;

long long n,k,x;
long long dp[N][3];

int main(){
freopen("../input_files/ConstructtheArray", "r", stdin);
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>k>>x;

	dp[1][(x==1)]=1;
	int az=89;
	for (int i=2;i<=n;i++){
		az=89;
		for (int j=0;j<=1;j++){
			for (int nw=0;nw<=1;nw++){
				long long ways;
				if (j==1&&nw==1)
					ways=0;
				if (j==1&&nw==0)
					ways=k-1;
				if (j==0&&nw==1)
					ways=1;
				if (j==0&&nw==0)
					ways=max(0ll,k-2);
				dp[i][nw]=(dp[i][nw]+dp[i-1][j]*ways)%bs;
			}
		}
	}

	cout<<dp[n][1]<<endl;

//	cin.get(); cin.get();
	return 0;
}
