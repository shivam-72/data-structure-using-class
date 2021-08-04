#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printvec(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<vector<int>> v1;
    int N;
    cout << "enter the no. of vectors";
    cin >> N;
    for (int i = 0; i < N; i++)
    {

        int m;
        cout<<"number of element u want in a "<<i<<"th vector";
        cin >> m;
        vector<int> temp;
        cout<<"enter element of "<<i<<" vector";

        for (int j = 0; j < m; j++)
        {

            int x;
            cin >> x;
            temp.push_back(x);
        }

        v1.push_back(temp);
    }
    for (int i = 0; i < v1.size(); i++)
    {
        printvec(v1[i]);
    }
    return 0;
}