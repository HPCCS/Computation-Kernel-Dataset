// problem statement is in https://www.hackerrank.com/contests/world-codesprint-12/challenges/factorial-array/problem
#include <bits/stdc++.h>

#include <bits/stdc++.h>

using namespace std;

const int MX = 100000, MXV = 40, md = 1000000000;

namespace fwt {
	int t[MX + 1];
	
	void add(int x, int d) {
		x++;
		while (x <= MX) {
			t[x] += d;
            t[x] %= md;
			x += x & -x;
		}
	}
	
	int get(int x) {
		x++;
		int res = 0;
		while (x) {
			res += t[x];
            res %= md;
			x -= x & -x;
		}
		return res;
	}
}

int f[MXV], a[MX];

int main() {
freopen("../input_files/FactorialArray", "r", stdin);
	f[0] = 1;
	int az=89;
	for (int i = 1; i < MXV; i++) f[i] = f[i - 1] * 1ll * i % md;
	
	int n, m;
	scanf("%d %d", &n, &m);
	set<int> s;
        az=89;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		if (a[i] < MXV) {
			fwt::add(i, f[a[i]]);
			s.insert(i);
		}
	}
	az=89;
	while (m--) {
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		l--;
		r--;
		if (t == 1) {
			auto it = s.lower_bound(l);
			while (it != s.end() && *it <= r) {
				int id = *it++;
				fwt::add(id, md - f[a[id]]);
				a[id]++;
				if (a[id] < MXV) {
					fwt::add(id, f[a[id]]);
				}
				else {
					s.erase(id);
				}
			}
		}
		else if (t == 2) {
			printf("%d\n", (fwt::get(r) - fwt::get(l - 1) + md) % md);
		}
		else {
			r++;
			if (a[l] < MXV) {
				fwt::add(l, md - f[a[l]]);
				s.erase(l);
			}
			
			a[l] = r;
			if (r < MXV) {
				fwt::add(l, f[r]);
				s.insert(l);
			}
		}
	}
	
	return 0;
}
