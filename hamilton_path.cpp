#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adjlist;
vector<int> path;
vector<bool> vis;
int V;

bool hasEdge(int u, int v) {
    for (int x : adjlist[u]) {
        if (x == v) return true;
    }
    return false;
}

bool solve(int u, int cnt) {
    if (cnt == V) {
        return hasEdge(u, path[0]);
    }

    for (int v : adjlist[u]) {
        if (!vis[v]) {
            vis[v] = true;
            path.push_back(v);

            if (solve(v, cnt + 1)) return true;

            vis[v] = false;
            path.pop_back();
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        V = 5;

        adjlist = {
            {1,3},
            {0,2,3,4},
            {1,4},
            {0,1,4},
            {1,2,3}
        };

        vis.assign(V, false);
        path.clear();

        path.push_back(0);
        vis[0] = true;

        if (solve(0, 1)) {
            for (int v : path) cout << v << " ";
            cout << path[0] << endl;
        } else {
            cout << "No Hamiltonian Cycle\n";
        }
    }
}
