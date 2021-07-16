#include<iostream>
#include<stack>
using namespace std;
int main(){
   stack<int>s1;
   s1.push(30);
   s1.push(40);
   s1.push(20);
   cout<<s1.top();
   s1.pop();
   cout<<s1.top();
   cout<<s1.empty();
   cout<<s1.size();



   return 0;
}
