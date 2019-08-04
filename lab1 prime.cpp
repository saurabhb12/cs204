#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;


using namespace std;
string add(string a, string b)
{
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
    return s;


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
bool small(string a, string b)
{
    lli l1= a.size();
    lli l2= b.size();
    if(l1<l2)
    {
        return 1;
    }
    else if(l1>l2)
    {
        return 0;
    }
    else
    {
        for(lli i=0; i<l1; i++)
        {
            if(a[i]<b[i])
            {
                return 1;
            }
            if(a[i]>b[i])
            {
                return 0;
            }
        }
        return 0;
    }
}
bool lessoreq(string a, string b)
{
    lli l1= a.size();
    lli l2= b.size();
    if(l1<l2)
    {
        return 1;
    }
    else if(l1>l2)
    {
        return 0;
    }
    else
    {
        for(lli i=0; i<l1; i++)
        {
            if(a[i]<b[i])
            {
                return 1;
            }
            if(a[i]>b[i])
            {
                return 0;
            }
        }
        return 1;
    }
}
string subtract(string a, string b)
{

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
        string ass="0";
        return ass;
    }
    else
    {
        //Taking a substring from first non zero digit to the end of answer//
        string answer= s.substr(index, a.length()-index);
        return answer;
    }


}

string remainder(string a, string b)
{
    if(small(a, b))
    {
        string zero="0";
        return zero;
    }
    else
    {
        string r= a.substr(0, b.size());
        if(small(r, b))
        {
            r= r+a[b.size()];
        }
        lli ass= r.size();
        while(1)
        {
            lli i=0;
            while(lessoreq(b, r))
            {
                r= subtract(r, b);
                if(r=="0")
                {
                    r="";
                }
                i++;
            }
        if(ass>=a.size())
        {
            break;
        }
        r= r+ a[ass];
        ass++;
        if(r=="0")
        {
            r="";
        }
        while(small(r, b) && ass<a.size())
        {
            r= r+a[ass];
            ass++;
            if(r=="0")
            {
                r="";
            }
        }
    }
    if(r.size()==0)
    {
        return "0";
    }
    return r;
    }
}

/*CODE BEGINS*/
int main()
{
    lli t;
    cin>> t;
    for(lli i=0; i<t; i++)
    {
        string s;
        cin>> s;
        if(s=="2")
        {
            cout<<"Number is Prime" <<endl;
        }
        else
        {
        string num="2";
        lli si= s.size();
        lli checksize= si/2+1;
        lli flag=0;
        while(num.size()<=checksize && small(num, s))
        {
            if(remainder(s, num)=="0")
            {
                flag=1;
                break;
            }

            num= add(num, "1");

        }
        if(flag)
        {
            cout<< "Number is not prime" <<endl;
        }
        else
        {
            cout<< "Number is prime" <<endl;
        }

        }

    }

}
