#include <bits/stdc++.h>
using namespace std;

vector<int> minpath(int source, int n, const unordered_map<int, list<pair<int, int>>> &adj)
{
    vector<int> dis(n, INT_MAX);
    set<pair<int, int>> s;

    s.insert(make_pair(0, source));

    dis[source] = 0;

    while (!s.empty())
    {
        auto top = *(s.begin());
        int nodeDistance = top.first;
        int node = top.second;
        s.erase(s.begin());

        for (auto i : adj.at(node))
        {
            if (dis[i.first] > i.second + nodeDistance)
            {
                auto record = s.find(make_pair(dis[i.first], i.first));
                if (record != s.end())
                {
                    s.erase(record);
                }

                dis[i.first] = i.second + nodeDistance;
                s.insert(make_pair(dis[i.first], i.first));
            }
        }
    }

    return dis;
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    // Subtract 1 to align with vector indices  

    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        pair<int, int> p = make_pair(v, w);
        pair<int, int> p2 = make_pair(u, w);
        adj[u].push_back(p);
        adj[v].push_back(p2);
    }

    vector<int> ans = minpath(0, n, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == INT_MAX)
        {
            cout << "INF ";
        }
        else
        {
            cout << "Shortest distance from base to node: " << i  << " = "<< ans[i] << endl;
        }
    }

    return 0;
}
