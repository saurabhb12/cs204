#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;


using namespace std;

string multiply (string s1, string s2)
{
    lli x= s1.size();
    lli y=s2.size();
    if(x==0 || y==0)
    {
        return "0";
    }
    //Define an answer vector of length l1+l2 to store size//
    vector <lli> answer(x+y, 0);
    lli i1=0;
    lli i2=0;
    for(lli i=x-1; i>=0; i--)
    {
        lli num1= s1[i]-'0';
        lli carry=0;
        i2=0;
        for(lli j=y-1; j>=0; j--)
        {
            lli num2= s2[j]-'0';
            lli sum= num1*num2 + answer[i1+i2]+carry;
            carry= sum/10;
            answer[i1+i2]= sum%10;
            i2++;
        }
        if(carry)
        {
            answer[i1+i2]= answer[i1+i2] + carry;
        }
        i1++;

    }
    //Discarding those indexes which are zero in answer at last//
    lli i= answer.size()-1;
    while(i>=0 and answer[i]==0)
    {
        i--;
    }
    if(i==-1)
    {
        return "0";
    }
    string s="";
    while(i>=0)
    {
        s.push_back(answer[i]+'0');
        i--;
    }
    return s;

}

/*CODE BEGINS*/
int main()
{
    lli t;
    cin>> t;
    for(lli i=0; i<t; i++)
    {
        string a, b;
        cin>>a >>b;
        string r= multiply(a, b);
        cout<<r <<endl;
    }

}
