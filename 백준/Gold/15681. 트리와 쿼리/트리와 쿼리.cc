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

int n, r, q;
int u, v;
vector <int> adj[100004];
int p[100004];
bool visited[100004];

int go(int cur) {
    visited[cur] = true;
    // cout << cur << " ";
    int cnt = 1;
    for (int nxt : adj[cur]) {
        if (visited[nxt]) continue;
        //p[nxt] += go(nxt);
        cnt+=go(nxt);
    }
    p[cur] = cnt;

    return cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    go(r);
    // cout << "\n";
    for (int i = 0; i < q; i++) {
        cin >> u;
        cout << p[u] << "\n";
    }
    /*for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }*/

    return 0;
}