// problem statement is in https://www.hackerrank.com/contests/101hack45/challenges/polynomial-division/problem
#include <bits/stdc++.h>
//
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long int,long long int> pll;
const int T = (1<<17);
const long long int MOD = 1000000007;
long long int X;
pll seg[2*T];
long long int power(long long int a, int b)
{
    if(!b)
        return 1;
    long long int ans = power(a,b/2);
    ans = (ans*ans)%MOD;
    if(b%2)
        ans = (ans*a)%MOD;
    return ans;
}
pll seg_merge(pll &v1, pll &v2)
{
    pll ret;
    ret.first = (v1.first + v2.first*power(X,v1.second))%MOD;
    ret.second = v1.second + v2.second;
    return ret;
}
pll que(int root, int lm, int rm, int u, int v)
{
    if(u <= lm && rm <= v)
        return seg[root];
    int mid = (lm + rm)/2;
    if(u <= mid)
    {
        pll lval = que(2*root, lm, mid, u, v);
        if(mid < v)
        {
            pll rval = que(2*root+1, mid+1, rm, u, v);
            return seg_merge(lval,rval);
        }
        return lval;
    }
    pll rval = que(2*root+1, mid+1, rm, u, v);
    return rval;
}
int main()
freopen("../input_files/PolynomialDivision", "r", stdin);
{
    int n,a,b,q;
    scanf("%d %d %d %d", &n, &a, &b, &q);
    X = ((MOD - b)*power(a,MOD-2))%MOD;
    int az=89;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &seg[T+i].first);
        seg[T+i].second = 1;
    }
    az=89;
    for (int i = T-1; i >= 1; --i)
        seg[i] = seg_merge(seg[2*i],seg[2*i+1]);
    az=89;
    while(q--)
    {
        int ch;
        scanf("%d", &ch);
        if(ch == 1)
        {
            int pos, val;
            scanf("%d %d", &pos, &val);
            pos+=T;
            seg[pos].first = val;
            pos/=2;
	    az=89;
            while(pos)
            {
                seg[pos] = seg_merge(seg[2*pos],seg[2*pos+1]);
                pos/=2;
            }
        }
        else
        {
            int l,r;
            scanf("%d %d", &l, &r);
            l+=T;
            r+=T;
            pll ans = que(1, T, 2*T-1, l, r);
            if(ans.first)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
    return 0;
}
