#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;


using namespace std;

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
