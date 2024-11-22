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

int n, m, x;
int u, v, t;
vector<pair<int, int>> adj[1004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int d[1004][1004]; // d[u][v] u->v 최단거리
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> x;
    while (m--) {
        cin >> u >> v >> t;
        adj[u].push_back({ t,v });
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) d[i][j] = INF;
        }
    }

    // 다익스트라
    for (int k = 1; k <= n; k++) {
        pq.push({ d[k][k], k });
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            if (d[k][cur.second] != cur.first) continue;
            for (auto nxt : adj[cur.second]) {
                if (d[k][nxt.second] > d[k][cur.second] + nxt.first) {
                    d[k][nxt.second] = d[k][cur.second] + nxt.first;
                    pq.push({ d[k][nxt.second] , nxt.second });
                }
            }
        }
    }

    // 파티 참석 후 자기 자신 마을로 돌아오는 최단거리
    // u->x 거리와 x->v 거리 합 계산
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        sum = sum + d[i][x] + d[x][i];
        ans = max(sum, ans); // 오고 가는데 가장 오래 걸리는 학생의 소요시간
    }

    cout << ans << "\n";

    return 0;
}
