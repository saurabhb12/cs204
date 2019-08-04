#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;

#define pb push_back
#define popb pop_back()
#define pf push_front
#define popf pop_front()
#define si size()
#define be begin()
#define en end()
#define all(v) v.be, v.en
#define le length()
#define mp make_pair
#define mt make_tuple
#define F first
#define S second

#define forz(i, n) for (int i = 0; i < n; i++)
#define bui(i, m, n) for (int i = m; i < n; i++)
#define rforz(i, n) for (int i = n - 1; i >= 0; i--)
#define mui(i, m, n) for (int i = n - 1; i >= m; i--)
#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)
#define parity(n) __builtin_parity(n)
#define ctz(n) __builtin_ctz(n)
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define maxe *max_element
#define mine *min_element
#define mod 1000000007
#define mod2 998244353
#define kira ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl

#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define osetlli tree<lli, null_type,less<lli>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
#define ofk order_of_key
#define fbo find_by_order

using namespace std;

/*STD fucntions*/
lli power(lli x,lli y,lli p)
{
    lli res=1;
    x=x%p;
    while(y>0)
    {
        if(y&1)
            res=(res*x)%p;
        //y must be even now
        y=y>>1; //y=y/2
        x=(x*x)%p;
    }
    return res;
}
lli gcd(lli a, lli b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
lli lcm(lli a, lli b)
{ return a * b / gcd(a, b); }
lli modi(lli a,lli m)
{
// fermat little thm where m is prime
return power(a,m-2,m);
}
bool compare(string s1, string s2)
{
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    if(s1<s2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
/*CODE BEGINS*/
int main()
{
    string a, b;
    cin>>a >>b;
    //Reversing both strings//
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    lli x= a.size();
    lli y= b.size();
    //Appending zeros to make size of both equal//
    if(x>y)
    {
        for(lli i=0; i<x-y; i++)
        {
            b=b+"0";
        }
    }
        if(y>x)
    {
        for(lli i=0; i<y-x; i++)
        {
            a=a+"0";
        }
    }
    //Making strings such that b needs to be subtracted from a using compare function//
    if(compare(a, b)==0)
    {
        swap(a, b);
    }
    string s="";
    lli carry=0;
    for(lli i=0; i<a.length(); i++)
    {
        lli d= (a[i]-'0')-(b[i]-'0')-carry;
        if(d<0)
        {
            s.push_back(d+10+'0');
            carry=1;
        }
        else
        {
            s.push_back(d+'0');
            carry=0;
        }
    }
    reverse(s.begin(), s.end());
    lli index=-1;
    //Checking for first non-zero digit so that zeros till the first nonzero digit in the answer are discarded//
    for(lli i=0; i<s.length(); i++)
    {
        if(s[i]!='0')
        {
            index= i;
            break;
        }
    }
    //If no index found that means that answer is zero//
    if(index==-1)
    {
        cout<<"0";
    }
    else
    {
        //Taking a substring from first non zero digit to the end of answer//
        string answer= s.substr(index, a.length()-index);
        cout<< answer;
    }

}
