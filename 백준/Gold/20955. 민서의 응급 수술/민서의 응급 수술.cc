#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
const int INF = 0x3f3f3f3f;

int n, m;
int u, v;
vector<int> adj[100004];
bool visited[100004];
//int parent[100004];
bool cycle[100004];
int ans;

void go(int cur, int prev) {
    visited[cur] = true;

    for (int nxt : adj[cur]) {
        if (visited[nxt]) {
            if (!cycle[nxt] && nxt != prev) ans++; // 사이클 존재
            continue;
        }
        go(nxt, cur);
    }
    cycle[cur] = true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        go(i, 0);
        ans++; // 트리 개수
    }

    cout << ans - 1 << "\n";

    return 0;
}