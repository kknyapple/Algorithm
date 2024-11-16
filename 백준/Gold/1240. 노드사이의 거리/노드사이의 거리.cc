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
int u, v, w;
vector <pair<int, int>> adj[1004]; // (노드, 거리)
bool visited[1004];
int ans;

void go(int cur, int des, int sum) {
    // cout << cur << " ";
    visited[cur] = true;
    if (ans) return;
    if (cur == des) {
        ans = sum;
        return;
    }

    for (auto nxt : adj[cur]) {
        if (visited[nxt.first]) continue;
        go(nxt.first, des, sum + nxt.second);
    }
}

void init() {
    ans = 0;
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        init();
        go(u, v, 0);
        cout << ans << "\n";
    }

    return 0;
}