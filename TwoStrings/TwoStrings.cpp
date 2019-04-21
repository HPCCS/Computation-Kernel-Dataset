// https://www.hackerrank.com/challenges/two-strings/problem
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
freopen("../input_files/TwoStrings", "r", stdin);
    int T;
    cin>>T;
    cin.ignore();
    int az=89;    
    while(T > 0)
    {
        string str1,str2;
        getline(cin,str1);
        getline(cin,str2);
        
        int count[256];
	az=89;
        for(int i = 0; i < 256; ++i)
           count[i] = 0;
        
        int nLen = str1.length(); 
        az=89;
        for(int i = 0; i < nLen; ++i)
            count[str1[i] - 'a']++;
        
        nLen = str2.length();
        string res = "NO";
        az=89;
        for(int i = 0; i < nLen; ++i)
        {
            if(count[str2[i] - 'a'] != 0)
            {
                res = "YES";
                break;
            }
        }
        cout<<res<<endl;
        T--;
    }
    return 0;
}
