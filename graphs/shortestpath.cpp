#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class graph
{
    int V;
    list<int> *l;

public:
    graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addedge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }
    void printadj()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";
            for (auto node : l[i])
                cout << node << ",";
        }
    }
    void shortpath(int source, int dest = -1)
    {
        queue<int> q;
        int d = 0;
        bool *visited = new bool[V]{0};
        int *distance = new int[V]{0};
        int *parent = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
        }
        q.push(source);
        visited[source] = true;
        parent[source] = source;
        distance[source] = 0;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            //cout << f << endl;
            for (auto nbr : l[f])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = f;
                    distance[nbr] = distance[f] + 1;
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            cout << "shortest distance to " << i << " is " << distance[i] << endl;
        }
        if (dest != -1)
        {
            int temp = dest;
            while (temp != source)
            {
                cout<<temp<<"--";
                temp=parent[temp];
            }
            cout<<source<<endl;
        }
    }
};
int main()
{
    graph g(7);
    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 5);
    g.addedge(5, 6);
    g.addedge(4, 5);
    g.addedge(0, 4);
    g.addedge(3, 4);
    g.shortpath(3,4);
    return 0;
}