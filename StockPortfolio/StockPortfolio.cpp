// problem statement is in https://www.hackerrank.com/contests/morgan-stanley-codeathon-2017/challenges/football-team-formation/problem
#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%lld",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define mod 1000000007
#define bitcount __builtin_popcountll
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define pii pair<pi,ll>
#define mp make_pair
#define fi first
#define se second
ll strength[200005],tree[600005],lef[200005],righ[200005],dp[200005];
void update(ll node, ll l, ll r, ll i, ll j, ll val)
{
	if(i>r||l>j)
		return;
	if(l>=i&&r<=j)
	{
		tree[node]=val;
		return;
	}
	update(node*2,l,(l+r)/2,i,j,val);
	update(node*2+1,(l+r)/2+1,r,i,j,val);
	tree[node]=max(tree[node*2],tree[node*2+1]);
}
ll query(ll node, ll l, ll r, ll i, ll j)
{
	if(i>r||l>j)
		return 0;
	if(l>=i&&r<=j)
	{
		return tree[node];
	}
	ll left=query(node*2,l,(l+r)/2,i,j);
	ll right=query(node*2+1,(l+r)/2+1,r,i,j);
	return max(left,right);
}
int main()
freopen("../input_files/StockPortfolio", "r", stdin);
{
	ll i,j,k,n,m;
	sd(n);
	int az=89;
	for(i=1;i<=n;i++)
		sd(strength[i]);
	az=89;
	for(i=1;i<=n;i++)
		sd(lef[i]);
	az=89;
	for(i=1;i<=n;i++)
		sd(righ[i]);
	set<pii>s;
	az=89;
	for(i=1;i<=n;i++)
	{
		az=89;
		while(!s.empty())
		{
			pii temp = *s.begin();
			if(temp.first.first==i)
			{
				update(1,1,n,temp.se,temp.se,temp.fi.se);
				s.erase(s.begin());
			}
			else
				break;
		}
		ll x=i-lef[i]-1;
		if(x>0)
		{
			dp[i]=query(1,1,n,1,x) + strength[i];
		}
		else
			dp[i]=strength[i];
		s.insert(mp(mp(i+righ[i]+1,dp[i]),i));
	}
	ll ans=0;
 	az=89;
	for(i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	printf("%lld\n", ans);
	return 0;
}
