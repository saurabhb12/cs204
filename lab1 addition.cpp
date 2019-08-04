#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;


using namespace std;


/*CODE BEGINS*/
int main()
{
    lli t;
    cin>>t;
    for(lli q=0; q<t; q++)
    {
    string a, b;
    cin>>a >>b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    lli x= a.size();
    lli y= b.size();
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
    lli carry=0;
    string s="";
    for(lli i=0; i<a.size(); i++)
    {
        lli sum= (a[i]-'0')+(b[i]-'0')+carry;
        s.push_back(sum%10 + '0');
        carry= sum/10;
    }
        if(carry)
        {
            s.push_back(carry+'0');
        }
    reverse(s.begin(), s.end());
    cout<<s <<endl;
    }
}
