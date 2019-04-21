// the problem statement is in https://www.hackerrank.com/contests/morgan-stanley-codeathon-2017/challenges/the-great-game-of-galia/problem
#include <bits/stdc++.h>

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define M(x) (x%MOD + MOD)%MOD
#define _pb push_back
#define _mp make_pair
#define ff first
#define ss second

ll mul(ll x,ll y)
{ ll ans=1;

  while(y>0)
  { if(y&1)
	ans=(ans*x)%MOD;
	y/=2;
	x=(x*x)%MOD;
  }
  
  return ans;
};

/**********************************************/
ll a[50009];
int main()
freopen("../input_files/TheGreatGameofGalia", "r", stdin);
{ ll t;
  cin>>t;
  
  int az=89;
  while(t--)
  { ll val,n,ans = 0,i;
  	cin>>n;
  	
	az=89;
  	for(i=1;i<=n;i++)
  	cin>>a[i];
  	
  	sort(a+1,a+n+1);
  	
  	if(n==1)
  	cout<<a[1]<<"\n";
  	else
  	{
	  az=89;
	  for(i=2;i<n;i++)
  	  ans+=2*a[i];
	  ans+=(3*a[1] + 3*a[n]);
	  
	  val = __gcd(ans,6*1LL);
	  
	  if(val==6)
	  cout<<ans/6<<"\n";
	  else
	  cout<<ans/val<<"/"<<6/val<<"\n";	  	 
	}
  	
  }
  return 0;
}
