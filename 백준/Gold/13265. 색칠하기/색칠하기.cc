#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
using ll = long long;
// const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

int t, n, m, x, y;
vector<int> graph[1004];
int visited[1004]; // 1: color1, 2: color2

bool go() { // bfs
    queue<pair<int, bool>> q; // {node, color}

    for (int i = 1; i <= n; i++) { // 모든 노드 확인
        if (visited[i] == 0) {
            q.push({ i, false });
            visited[i] = 1;
        }

        while (!q.empty()) {
            int cur = q.front().first;
            bool color = q.front().second;
            q.pop();

            for (int nxt : graph[cur]) {
                if (!visited[nxt]) {
                    q.push({ nxt, !color });
                    visited[nxt] = !color + 1;
                }
                else { // 이미 색칠된 곳이라면
                    if (visited[nxt] != !color + 1) { // 2가지 색상으로 칠할 수 있는지 확인
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            graph[i].clear();
            visited[i] = 0;
        }
        while (m--) {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        if (go() == false) cout << "impossible" << "\n";
        else cout << "possible" << "\n";
    }

    return 0;
}