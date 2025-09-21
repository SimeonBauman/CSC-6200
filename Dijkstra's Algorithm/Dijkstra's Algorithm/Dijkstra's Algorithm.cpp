#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

vector<vector<vector<int>>> CreateGraph(const vector<vector<int>>& edges, int n) {
    vector<vector<vector<int>>> graph(n);
    for (const auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }
    return graph;
}

int GetVertexCount(const vector<vector<int>>& edges) {
    int i = -1;
    for (const auto& e : edges) i = max(i, max(e[0], e[1]));
    return i + 1;
}

pair<vector<int>, vector<int>> dijkstra(int n, const vector<vector<int>>& edges, int num) {
    vector<vector<vector<int>>> graph = CreateGraph(edges, n);

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> j;
    vector<int> distance(n, INT_MAX);
    vector<int> parent(n, -1);

    distance[num] = 0;
    j.push({ 0, num });

    while (!j.empty()) {
        int u = j.top()[1];
        int du = j.top()[0];
        j.pop();

        if (du != distance[u]) continue; 

        for (const auto& nbr : graph[u]) {
            int v = nbr[0], w = nbr[1];
            if (distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                parent[v] = u;
                j.push({ distance[v], v });
            }
        }
    }
    return make_pair(distance, parent);
}

vector<int> findPath(int src, int tgt, const vector<int>& parent) {
    vector<int> path;
    if (tgt < 0 || tgt >= (int)parent.size()) return path;
    for (int cur = tgt; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
        if (cur == src) break;
    }
    if (path.empty() || path.back() != src) return {}; 
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 9},
        {1, 2, 3},
        {1, 3, 8},
        {2, 4, 7},
        {3, 4, 4}
    };

 
    int n = GetVertexCount(edges);

    int start, goal;
    cout << "Enter start node (0-" << n - 1 << "): ";
    if (!(cin >> start)) return 0;
    cout << "Enter end node (0-" << n - 1 << "): ";
    if (!(cin >> goal)) return 0;

    if (start < 0 || start >= n || goal < 0 || goal >= n) {
        cerr << "Error: node out of range.\n";
        return 1;
    }

    pair<vector<int>, vector<int>> res = dijkstra(n, edges, start);
    vector<int> dist = res.first;
    vector<int> parent = res.second;

    if (dist[goal] == INT_MAX) {
        cout << "No path exists from " << start << " to " << goal << ".\n";
        return 0;
    }

    vector<int> path = findPath(start, goal, parent);

    cout << "Shortest path cost from " << start << " to " << goal << " = " << dist[goal] << "\n";
    cout << "Path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i] << (i + 1 < path.size() ? " -> " : "\n");
    }


    cout << "All distances from " << start << ": ";
    for (size_t i = 0; i < dist.size(); ++i) {
        if (dist[i] == INT_MAX) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}
