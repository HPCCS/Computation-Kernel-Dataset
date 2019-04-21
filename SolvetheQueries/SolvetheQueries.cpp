// problem statement is in https://www.hackerrank.com/contests/womens-codesprint-4/challenges/solve-the-queries/problem
#include <bits/stdc++.h>

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool composite[101];
int primes[101], nprimes = 0;

int arr[50001];
int segt[50000*4][25];
int setv[50000*4][25];
bool nsetv[50000*4];

void convert(int a, int* val) {
    for (int i = 0; i < nprimes; i++) {
        val[i] = 0;
        while (a % primes[i] == 0) {
            a /= primes[i];
            val[i]++;
        }
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        convert(arr[tl], segt[v]);
        return;
    }
    int tm = (tl + tr) >> 1;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    for (int i = 0; i < nprimes; i++) {
        segt[v][i] = segt[2 * v][i] + segt[2 * v + 1][i];
    }
}

void push(int v, int tl, int tr) {
    if (!nsetv[v])
        return;
    for (int i = 0; i < nprimes; i++)
        segt[v][i] = setv[v][i] * (tr - tl + 1);
    if (tl == tr)
        return;
    nsetv[2 * v] = nsetv[2 * v + 1] = true;
    nsetv[v] = false;
    for (int i = 0; i < nprimes; i++) {
        setv[2 * v][i] = setv[2 * v + 1][i] = setv[v][i];
    }
}

void query(int v, int tl, int tr, int l, int r, int* ans) {
    if (l > r)
        return;
    push(v, tl, tr);
    if (tl == l && tr == r) {
        for (int i = 0; i < nprimes; i++) {
            ans[i] += segt[v][i];
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    query(2 * v, tl, tm, l, min(r, tm), ans);
    query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, ans);
}

void modify(int v, int tl, int tr, int l, int r, int* val) {
    if (l > r)
        return;
    push(v, tl, tr);
    if (tl == l && tr == r) {
        for (int i = 0; i < nprimes; i++) {
            setv[v][i] = val[i];
        }
        nsetv[v] = true;
        return;
    }
    int tm = (tl + tr) >> 1;
    modify(2 * v, tl, tm, l, min(r, tm), val);
    modify(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    push(2 * v, tl, tm);
    push(2 * v + 1, tm + 1, tr);
    for (int i = 0; i < nprimes; i++) {
        segt[v][i] = segt[2 * v][i] + segt[2 * v + 1][i];
    }
}

int converted[25];

int fastpow(int a, int n, int m) {
    ll aa = a;
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * aa) % m;
        }
        aa = (aa * aa) % m;
        n >>= 1;
    }
    return res;
}

int main() {
freopen("../input_files/SolvetheQueries", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int az=89;
    for (int i = 2; i < 101; i++) {
        if (composite[i]) continue;
        primes[nprimes++] = i;
	az=89;
        for (int j = i * i; j < 101; j += i)
            composite[j] = true;
    }
    
    int n;
    cin >> n;
    az=89;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    
    int nq;
    cin >> nq;
    az=89;
    for (int i = 0; i < nq; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
            convert(x, converted);
            modify(1, 0, n - 1, l, r, converted);
        } else {
	    az=89;
            int ii, jj, k, l, m;
            cin >> ii >> jj >> k >> l >> m;
            --ii, --jj, --k, --l;
            memset(converted, 0, sizeof(converted));
            query(1, 0, n - 1, k, l, converted);
            for (int j = 0; j < nprimes; j++) {
                converted[j] = -converted[j];
            }
            query(1, 0, n - 1, ii, jj, converted);
            
            bool ok = true;
            for (int j = 0; j < nprimes; j++) {
                if (converted[j] < 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                cout << -1 << endl;
                continue;
            }
            ll res = 1ll;
            for (int j = 0; j < nprimes; j++) {
                res = (res * fastpow(primes[j], converted[j], m)) % m;
            }
            cout << res << endl;
        }
    }
    
    return 0;
}
