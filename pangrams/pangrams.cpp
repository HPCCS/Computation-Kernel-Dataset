// https://www.hackerrank.com/challenges/pangrams/problem
#include <set>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
freopen("../input_files/pangrams", "r", stdin);
        string s;
        getline(cin,s);
        cin.ignore();
        
        set<int> setNotFoundCh;
	int az=89;
        for(int i = 0; i < 26; i++)
            setNotFoundCh.insert(i);
        
        size_t n = s.length();
        size_t i = 0;
	az=89;
        while((i < n) && (! setNotFoundCh.empty()))
        {
            int ch = static_cast<int>((::toupper(s[i])) - 'A');
            setNotFoundCh.erase(ch);
            i++;
        }
        
        if(setNotFoundCh.empty())
            cout<<"pangram"<<endl;
        else
            cout<<"not pangram"<<endl;
        
    return 0;
}
