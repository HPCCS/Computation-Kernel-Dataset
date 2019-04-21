// problem statemetn is in 
#include <bits/stdc++.h>

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isAnagramOfPalindrome(string s)
{
    int ch[256] = {0};
    int nLen = s.length();
    int nCountOfOdd = 0;
    
    for(int i = 0 ; i < nLen; i++)
    {
        int nAscii = static_cast<int>(s[i]);
        ++ch[nAscii];
    }
    
    for(int i = 0 ; i <= 255 ; i++)
    {
        if(ch[i] & 1 == 1)
            if(nCountOfOdd == 1)
                return false;
            else
                nCountOfOdd = 1;
    }
    return true;
}

int main() {
freopen("../input_files/GameOfThrones1", "r", stdin);
   
    string s;
    cin>>s;
     
    bool flag = isAnagramOfPalindrome(s);
    if(flag==false)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}

