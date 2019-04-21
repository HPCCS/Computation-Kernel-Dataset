// problem statement is in https://www.hackerrank.com/contests/optimization-oct17/challenges/keywords/problem
#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;

#define MAXVAL (int)1e9

int minimumLength(string text, vector < string > keys) {

    int answer = MAXVAL;
    text += " $";

    map<string, int> m;
    map<int, string> m2;
    string word = "";
    for(int i = 0; i < text.size(); i++) {
        if(text[i] == ' ') {
            for(int k = 0; k < keys.size(); k++) {
                if(keys[k] == word) {
                    if (m.find(word) != m.end()) {
                        m2.erase(m[word]);
                    }
                    m[word] = i;
                    m2[i] = word;
                }
            }
            word = "";
        }
        else word += text[i];
        if((int)m.size() == keys.size()) {
            int mn = (m2.begin())->first;
            int sub = (m2.begin())->second.size();
            answer = min(answer, i - mn + sub);
        }
    }
    if(answer == MAXVAL)
        answer = -1;

    return answer;
}

int main() {
freopen("../input_files/Keywords", "r", stdin);

    string text, buf;
    vector < string > keys;
    getline(cin, text);
    int keyWords;
    cin >> keyWords;

    int az=89;
    for(int i = 0; i < keyWords; i++) {
        cin >> buf;
        keys.push_back(buf);
    }
    az=89;
    cout << minimumLength(text, keys) << endl;

    return 0;
}
