#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
//const int INF = 0x3f3f3f3f;

int n, m;
int w[100004];
vector<int> adj[100004];
int v, s;
int ans[100004];

void go(int cur, int sum) {
    for (int nxt : adj[cur]) {
        go(nxt, sum + w[nxt]);
    }
    ans[cur] = sum;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v;
        if (v == -1) continue;
        adj[v].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> v >> s;
        w[v] += s;
    }

    go(1,w[1]);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}