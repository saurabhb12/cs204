#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
class STACK
{
    private:
    int arr[100000];
    int len=0;
public:
    int size(){
        return len;
    }
    int top(){
        if(len!=0)return arr[len-1];
        return -1;
    }
    void push(int x){
        len++;
        arr[len-1]=x;
    }
    void pop(){
        if(len==0)return;
        len--;
    }
};


int main() 
{ 
  STACK s;
  s.push(5);
  cout<<s.size()<<"\n";
  cout<<s.top()<<"\n";
  s.push(7);
  s.push(8);
  cout<<s.size()<<"\n";
  s.push(9);
  s.pop();
  cout<<s.size()<<"\n";
  s.pop();
  cout<<s.top()<<"\n";
  return 0; 	
}
