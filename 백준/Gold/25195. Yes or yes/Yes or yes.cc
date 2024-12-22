#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
const int INF = 0x7f7f7f7f;

int n, m;
vector<int> adj[100004];
int u, v;
int visited[100004];
bool flag;

void go(int cur) {
    visited[cur] = 1;
    for (int nxt : adj[cur]) {
        if (visited[nxt] != 0) continue;
        go(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cin >> u;
    for (int i = 0; i < u; i++) {
        cin >> v;
        visited[v] = 2;
    }

    if(visited[1] != 2) go(1);

    for (int i = 1; i <= n; i++) {
        // leaf node이고(해당 노드로 시작하는 간선이 0개) 
        // 해당 노드를 방문 했다면 곰곰이를 만나지 않고 이동하는 방법이 존재
        if (adj[i].size() == 0 && visited[i] == 1) flag = true;
    }

    if (flag) cout << "yes" << "\n"; // 곰곰이를 만나지 않고 이동하는 방법이 존재
    else cout << "Yes" << "\n"; // 어떻게 이동하더라도 팬클럽 곰곰이를 만나게 됨

    return 0;
}