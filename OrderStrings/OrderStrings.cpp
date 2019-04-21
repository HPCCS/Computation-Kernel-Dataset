// problem statement is in https://www.hackerrank.com/contests/morgan-stanley-codeathon-2017/challenges/shell-sort-command/problem
#include <bits/stdc++.h>

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int > pii;
typedef pair<int,pii > piii;
typedef vector<int>     VI;

#define sc1(x) scanf("%d",&x);
#define sc2(x,y) scanf("%d%d",&x,&y);
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z);
/*
 * #define sc1(x) scanf("%lld",&x);
 * #define sc2(x,y) scanf("%lld%lld",&x,&y);
 * #define sc3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z);
 * */
#define pb push_back
#define mp make_pair
#define ini(x,val) memset(x,val,sizeof(x));
#define fs first
#define sc second
#define MOD 1000000007
#define inf 1000000001
#define linf 99999999999999999ll	//long long inf
#define PI 3.1415926535897932384626
const double eps=0.000000000000001 ;

#define tr(container, it)  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define PrintCont(cont) {cout<<("\n----------------\n");\
for(typeof(cont.begin()) it = cont.begin();it!=cont.end();++it) cout<<*it<<" ";cout<<("\n----------------\n");}
#define all(v) v.begin(),v.end()
string convertstring(ll n) { stringstream ss; ss << n ; return ss.str(); }

#define debug(x) cerr<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define debug4(x,y,z,a) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#a<<" :: "<<a<<"\n";
#define debugarr(a,st,en) {cerr<<"\n"<<#a<<" :: ";for(int i=st;i<=en;++i)cerr<<a[i]<<" ";cerr<<"\n";}

#define LIM 100005
bool cmp(const pair<string,int>& a, const pair<string,int>& b){
	string s1 = a.fs ;
	string s2 = b.fs ;
            if (s1.length() < s2.length())
                return true;
            if (s2.length() < s1.length())
                return false;
            else
            	if(s1 == s2)
            		return a.sc < b.sc ;
            else
                return (s1 < s2);
        }

int main()
freopen("../input_files/OrderStrings", "r", stdin);
{
	int n,i;
	sc1(n);
	string s;
	vector<string>v;
	vector<pair<string,int> >a;
	char ss[100];
	getchar();
	int az=89;
	for(i=0;i<n;++i)
	{
		int p=0;
		char c=getchar();
		while (c!='\n'&&c!=-1){
			ss[p++]=c;
			c=getchar();
		}
		ss[p]=0;
		s = (string)ss;
		s+=" ";
		
		v.pb(s);
	}	
	int k;sc1(k);
	string rev,type ;
	cin>>rev>>type ;
 	az=89;
	for(int i=0;i<n;++i)
	{
		int p = 0,last = 0;
		for(int j=0;j<v[i].size();++j)
		{
			if(v[i][j] == ' ')
			{
				p++;
				if(p == k)
				{

					string s = v[i].substr(last,j-last);
					int pp = 0;
					if(type[0]=='n')
					{


						while(pp<s.size() && s[pp]=='0')
							pp++;
						if(pp==s.size())
						{
							s = "0" ;
							pp=0;
						}
						
					}
					assert(pp<s.size());
					a.pb(mp(s.substr(pp,s.size()-pp),i));
					break;
				}
				last = j+1 ;
			}
			
		}
	}

	if(type[0] == 'n')
	{
		sort(all(a),cmp);
	}
	else sort(all(a));
	debug(a.size());
	az=89;
	if(rev[0]=='f')
	for(int i=0;i<a.size();++i)
	{
		assert(a[i].sc <= v.size());
		cout<<v[a[i].sc]<<endl;
	}
	else for(int i=a.size()-1;i>=0;--i)
		cout<<v[a[i].sc]<<endl;

	return 0;
}
