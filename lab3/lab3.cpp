#include<bits/stdc++.h> 
using namespace std; 
bool check(string expr) 
{ 
    stack<char> s; 
    char x; 
    int count=0;
    for (int i=0; i<expr.length(); i++) 
    { 
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{' || expr[i]=='<') 
        { 
            s.push(expr[i]); 
            continue; 
        } 
        if(expr[i]=='|')
        {
            count++;
            if(count%2==1)
            {
                s.push(expr[i]);
            }
        }

        if (s.empty()) 
           return false; 
  
        switch (expr[i]) 
        { 
        case ')': 

            x = s.top(); 
            s.pop(); 
            if (x=='{' || x=='[' || x=='<' || x=='|') 
                return false; 
            break; 
  
        case '}': 
            x = s.top(); 
            s.pop(); 
            if (x=='(' || x=='[' || x=='<' || x=='|') 
                return false; 
            break; 
  
        case ']': 
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{' || x== '<' || x=='|') 
                return false; 
            break; 

            
        case '>': 
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{' || x== '[' || x=='|') 
                return false; 
            break; 


        case '|':
             if(count%2==0)
             {
                x= s.top();
                s.pop();
                if(x=='(' || x=='[' || x=='{' || x=='<')
                {
                    return false;
                }
             }
             break;
        } 
    } 
    return (s.empty()); 
} 
  
int main() 
{ 
    int n;
    cin>> n;
    for(int i=0; i<n; i++)
    {
        string e;
        cin>> e;
        if(check(e))
        {
            cout<< "YES" <<endl;
        }
        else 
        {
            cout<< "NO" <<endl;
        }
    }
} 
