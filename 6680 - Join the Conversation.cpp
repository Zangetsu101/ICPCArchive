#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <queue>
#include <stack>

#define endl "\n"
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b)
#define pf printf
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define all(c) c.begin(),c.end()
#define ms(a,c) memset(a,c,sizeof(a))
#define tr(c,i) for(decltype((c).begin()) i=(c).begin();i!=(c).end();i++)
#define trr(c,i) for(decltype((c).rbegin()) i=(c).rbegin();i!=(c).rend();i++)

using namespace std;

#define N 50001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int dp[N],last[N];
map<string,int> mp;
map< pii , pii > seq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    while(cin>>n)
    {
        string name,line;
        char ch,l;
        int cnt=1,v;
        for(int i=1;i<=n;i++)
        {
            cin>>name;
            v=mp[name];
            if(!v)
                v=mp[name]=cnt++;
            getline(cin,line);
            stringstream ss(line);
            l=' ';
            while(ss.get(ch))
            {
                if(ch=='@'&&l==' ')
                {
                    ss.putback(ch);
                    string temp;
                    ss>>temp;
                    temp.push_back(':');
                    if(temp!=name)
                    {
                        int t=mp[temp];
                        if(!t)
                            continue;
                        if(dp[t]+1>dp[v])
                            dp[v]=dp[t]+1,last[v]=i,seq[pii(i,v)]=pii(last[t],t);
                    }
                }
                l=ch;
            }
            if(!dp[v])
                dp[v]=1,last[v]=i;
        }
        int ans=0,mx=0;
        for(int i=1;i<cnt;i++)
        {
            if(dp[i]>mx)
                mx=dp[i],ans=i;
        }
        stack<int> res;
        pii temp=pii(last[ans],ans);
        while(temp.first)
            res.push(temp.first),temp=seq[temp];
        cout<<mx<<endl;
        while(!res.empty())
            cout<<res.top()<< ' ',res.pop();
        cout<<endl;
        mp.clear();
        seq.clear();
        ms(dp,0);
        ms(last,0);
    }
    return 0;
}
/*
6
@Petr: Leaving for #NEERC tomorrow!
@Roman: This #NEERC is going to be awesome!
@Stone_in_forest: Nothing happened today.
@NEERCNews: @Petr Don’t forget an umbrella :)
@Lydia: @NEERCNews cares about @Petr - so cute ^ ^
@Lydia: @Lydia @NEERCNews @Petr it won’t be raining though!
*/

