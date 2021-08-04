#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    string name;
    list<string> nbrs;

    node(string name)
    {
        this->name = name;
    }
};
class graph
{
    unordered_map<string, node *> m;

public:
    graph(vector<string> cities)
    {
        for (auto city : cities)
        {
            m[city] = new node(city);
        }
    }
    void addedge(string x, string y, bool undir = false)
    {
        m[x]->nbrs.push_back(y);
        if (undir)
        {
            m[y]->nbrs.push_back(x);
        }
    }
    void printadj()
    {
        for (auto citypair : m)
        {
            auto city = citypair.first;
            node *Node = citypair.second;
            cout << city << "-->";
            for (auto nbr : Node->nbrs)
            {
                cout << nbr << ",";
            }

            cout << endl;
        }
    }
    void bfs(int source){
    
    }
};

int main()
{
   
    vector<string> citi = {"Dehli", "London", "paris", "newyork"};
    graph g(citi);
    g.addedge("Dehli", "London");
    g.addedge("newyork", "London");
    g.addedge("Dehli", "paris");
    g.addedge("paris", "newyork");
    g.printadj(); ;
    return 0;
}