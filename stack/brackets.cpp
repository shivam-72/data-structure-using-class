#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<char>s;
    string s1;
    s1="{a+[b-(c*d)]+g}";
    for(int i=0;i<s1.length();i++){
        if( s1[i]=='{'||s1[i]=='(' || s1[i]=='[')
        {
            s.push(s1[i]);
        }
    }
    return 0;
}