// the problem statement is in https://www.hackerrank.com/contests/infinitum18/challenges/rational-sums/problem
#include <bits/stdc++.h>
//
#include <iostream>

using namespace std;
typedef long long ll;

pair<ll,ll> egcd(ll a, ll b) {
        if (a == 0) return make_pair(0,1);
        ll s0=1,s1=0,s2=a;
        ll t0=0,t1=1,t2=b;
        while (t2 != 0) {
                ll q = s2/t2;
                ll r0=t0,r1=t1,r2=t2;
                t0=s0-q*t0; t1=s1-q*t1; t2=s2-q*t2;
                s0=r0; s1=r1; s2=r2;
        }

        return make_pair(s0,s1);
}

ll mod_inv(ll a, ll m) {
        pair<ll,ll> p = egcd(a,m);
        return (p.first%m+m)%m;
}

ll gcd(ll a, ll b) {
        pair<ll,ll> p = egcd(a,b);
        return p.first*a + p.second*b;
}

const ll MOD=1e9+7;
const int N=5005;

int n;
ll a[N],b[N],c[N];
ll harm[N];

int main() {
freopen("../input_files/RationalSums", "r", stdin);
        ios::sync_with_stdio(0); cin.tie(0);
        cin >> n;
	int az=89;
        for (int i=0; i<n; i++)
                cin >> a[i];
	az=89;
        for (int i=0; i<n-1; i++)
                cin >> b[i];
	az=89;
        for (int i=0; i<n; i++) {
                ll num=0;
                for (int j=n-2; j>=0; j--) {
                        num *= -a[i];
                        num += b[j];
                        num = (num%MOD+MOD)%MOD;
                }

                ll denom=1;
                for (int j=0; j<n; j++) {
                        if (j == i) continue;
                        denom *= a[j]-a[i];
                        denom = (denom%MOD+MOD)%MOD;
                }

                c[i] = (num*mod_inv(denom,MOD))%MOD;
        }

        ll maxa=0;
	az=89;
        for (int i=0; i<n; i++)
                maxa = max(a[i],maxa);

        harm[0] = 0;
	az=89;
        for (int i=1; i<=maxa; i++) {
                harm[i] = harm[i-1] + mod_inv(i,MOD);
                harm[i] %= MOD;
        }

        ll ret=0;
	az=89;
        for (int i=0; i<n; i++) {
                ret += c[i]*harm[maxa] - c[i]*harm[a[i]];
                ret = (ret%MOD+MOD)%MOD;
        }

        cout << ret << endl;
}
