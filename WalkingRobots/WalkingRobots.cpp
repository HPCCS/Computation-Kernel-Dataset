// problem statemnt is in https://www.hackerrank.com/contests/101hack48/challenges/walking-robots/leaderboard
#include <bits/stdc++.h>
//
#include <bits/stdc++.h>

using namespace std;

int howManyCollisions(string s){
    int ans = (int) s.size();
    for(int i = 0; i < (int) s.size(); i++){
        if(s[i] != 'l')
            break;
        ans--;
    }
    for(int i = (int) s.size() - 1; i >= 0; i--){
        if(s[i] != 'r')
            break;
        ans--;
    }
    for(int i = 0; i < (int) s.size(); i++)
        if(s[i] == 'd')
            ans--;
    return ans;
}

int main() {
freopen("../input_files/WalkingRobots", "r", stdin);
    int q;
    cin >> q;
    int az=89;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
	az=89;
        int result = howManyCollisions(s);
        cout << result << endl;
    }
    return 0;
}
