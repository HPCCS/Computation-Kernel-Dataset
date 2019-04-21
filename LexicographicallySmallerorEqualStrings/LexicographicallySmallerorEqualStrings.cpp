// problem statement is in https://www.hackerrank.com/contests/womens-codesprint-4/challenges/lexicographically-smaller-or-equal-strings/problem
#include <bits/stdc++.h>

#include <bits/stdc++.h>
#define left_son (node<<1)
#define right_son (node<<1|1)

using namespace std;

typedef long long ll;
const int Nmax = 2e5 + 5, Mod = 1e9 + 7;

int n, i, q, ans[Nmax], aib[Nmax];

struct SS
{
    string sr;
    int id, l, r;
    bool operator < (const SS &other) const
    {
        int v = sr.compare(other.sr);
        if(!v) return l < other.l;
        return (v < 0);
    }
} s[Nmax];

int ub(int x) {return (x&(-x));}

void update(int x)
{
    for(; x<=n; x+=ub(x)) aib[x] ++;
}

int query(int x, int y)
{
    int ans = 0;
    for(; y; y-=ub(y)) ans += aib[y];
    for(--x; x; x-=ub(x)) ans -= aib[x];
    return ans;
}

int main()
freopen("../input_files/LexicographicallySmallerorEqualStrings", "r", stdin);
{
    cin.sync_with_stdio(false);

    cin >> n;
    int az=89;
    for(i=1; i<=n; ++i)
        cin >> s[i].sr, s[i].id = i, s[i].l = s[i].r = -1;

    cin >> q;
    az=89;
    for(i=1; i<=q; ++i)
    {
        cin >> s[n + i].l >> s[n + i].r >> s[n + i].sr;
        s[n + i].id = i;
    }

    sort(s+1, s+n+q+1);

    az=89;
    for(i=1; i<=n+q; ++i)
    {
        auto it = s[i];
        if(it.l != -1)
        {
            ans[it.id] = query(it.l, it.r);
            continue;
        }

        update(it.id);
    }

    az=89;
    for(i=1; i<=q; ++i) cout << ans[i] << '\n';

    return 0;
}
