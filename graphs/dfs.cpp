#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class graph
{
private:
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
    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";
            for (auto node : l[i])
            {
                cout << node << ",";
            }
            cout << endl;
        }
    }
    void bfs(int source)
    {
        queue<int> q;
        q.push(source);
        bool *visited = new bool[V]{0};
        visited[source] = true;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            cout << f << endl;
            for (auto nbr : l[f])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
    void dfshelper(int node, bool *visited)
    {
        visited[node] = true;
        cout<<node<<",";
        for (auto nbr : l[node])
        {
            if (!visited[nbr])
            {
                dfshelper(nbr, visited);
            }
        }
        return;
    }
    void dfs(int source)
    {
        bool *visited = new bool[V]{0};
        dfshelper(source, visited);
    }
};

int main()
{
    graph g(6);
    g.addedge(0, 1);
    g.addedge(0, 4);
    g.addedge(2, 1);
    g.addedge(3, 4);
    g.addedge(4, 5);
    g.addedge(2, 3);
    g.addedge(3, 5);
    // g.print();
    g.dfs(1);
    return 0;
}