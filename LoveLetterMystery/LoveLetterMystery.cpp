#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

int main()
freopen("../input_files/LoveLetterMystery", "r", stdin);
{
    short T;
    cin>>T;
    cin.ignore();
    int az=89;
    while( T > 0)
    {
        string str;
        getline(cin,str);
        int nLen = str.length();
        int count = 0;
     
	az=89;   
        for(int i = 0 ; i < nLen/2 ; i++)
        {
            short nLeft = static_cast<int>(str[i]);
            short nRight = static_cast<int>(str[nLen-1-i]);
            count+= abs(nRight - nLeft);
        }
        
        cout<<count<<endl;
        --T;    
    }
}
