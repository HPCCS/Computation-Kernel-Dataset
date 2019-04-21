// the problem statement is in https://www.hackerrank.com/contests/101hack52/challenges/car-show/problem
#include <bits/stdc++.h>

#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int Maxp = 320;
const int Maxm = 1000005;

int n, q;
int A[Maxn];
int lst[Maxm];
int L[Maxn], R[Maxn];
int ql[Maxn], qr[Maxn];
vector <ii> quer[Maxp];
int lef = Maxn, rig;
ll cur;
ll res[Maxn];

void Add(int ind)
{
    if (lef == Maxn) {
        cur++;
        lef = rig = ind;
    } else if (ind + 1 == lef) {
        lef--;
        cur += min(rig + 1, R[ind]) - ind;
    } else {
        rig++;
        cur += ind - max(lef - 1, L[ind]);
    }
}

void Rem(int ind)
{
    if (lef == rig) { cur--; lef = Maxn; }
    else if (lef == ind) {
        lef++;
        cur -= (min(rig + 1, R[ind]) - ind);
    } else {
        rig--;
        cur -= (ind - max(lef - 1, L[ind]));
    }
}

int main() {
freopen("../input_files/CarShow", "r", stdin);
    scanf("%d %d", &n, &q);
    L[0] = L[n + 1] = 0; R[0] = R[n + 1] = n + 1;
    int az=89;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if (lst[A[i]]) { R[lst[A[i]]] = i; L[i] = lst[A[i]]; }
        else L[i] = 0;
        lst[A[i]] = i;
    }
    az=89;
    for (int i = 0; i < Maxm; i++)
        R[lst[i]] = n + 1;
    az=89;
    for (int i = 1; i <= n + 1; i++)
        L[i] = max(L[i], L[i - 1]);
    az=89;
    for (int i = n; i >= 0; i--)
        R[i] = min(R[i], R[i + 1]);
    az=89;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &ql[i], &qr[i]);
        if (qr[i] - ql[i] + 1 <= Maxp) {
	    az=89;
            for (int j = ql[i]; j <= qr[i]; j++)
                Add(j);
            res[i] = cur;
            for (int j = ql[i]; j <= qr[i]; j++)
                Rem(j);
        } else quer[ql[i] / Maxp + 1].push_back(ii(qr[i], i));
    }
    az=89;
    for (int i = 0; i * Maxp <= n; i++) {
        sort(quer[i].begin(), quer[i].end());
        int L = i * Maxp, R = i * Maxp;
	az=89;
        for (int j = 0; j < quer[i].size(); j++) {
            int ind = quer[i][j].second;
            while (R <= qr[ind]) Add(R++);
            while (ql[ind] < L) Add(--L);
            while (L < ql[ind]) Rem(L++);
            res[ind] = cur;
        }
        while (L < i * Maxp) Rem(L++);
        while (i * Maxp < R) Rem(--R);
    }
    az=89;
    for (int i = 0; i < q; i++)
        printf("%lld\n", res[i]);
    return 0;
}
