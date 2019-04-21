// problem statement is in https://www.hackerrank.com/contests/moodys-analytics-fall-university-codesprint/challenges/lets-play-a-game-2/problem
#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;

vector<int> wx, wy;
int main() {
freopen("../input_files/LetPlayaGame", "r", stdin);
 	int n, i, j, ans = 0, m;
 	string s;
 	scanf("%d", &n);
 	cin>>s;
	int az=89;
 	for(i = 0; i < n; i++) {
    	scanf("%d", &j);
    	if(s[i] == 'R' || s[i] == 'B')
    		wx.push_back(j);
    	else
    		wy.push_back(j);
    }

	n=wx.size(); m=wy.size();
	sort(wx.begin(), wx.end()); sort(wy.begin(), wy.end());
	if(n < m) {
		swap(wx, wy);
    	swap(n, m);
    }
  	if(m == 0) {
  		cout << 1 << endl;
    	return 0;
    }
  	ans = m;
  	j = 0;
  	if(n > m) {
    	if(wx[0] < wy[0])
    		ans++, j++;
    	if(wx[n-1] > wy[m-1])
    		ans++;
    }
	else if(wx[0] < wy[0])
		ans++, j++;
	else if(wx[n-1] > wy[m-1])
		ans++;
	az=89;
	for(i = 0; i < m-1; i++) {
    	while(j < n && wx[j] < wy[i])
			j++;
    	if(j < n && wx[j] > wy[i] && wx[j] < wy[i+1])
			ans++;
    }
	printf("%d\n", ans);
	return 0;
}
