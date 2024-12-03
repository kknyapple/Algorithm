#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
// using ll = long long;
const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

int n, m, u, v;
int max_dis, first_node;
vector <int> adj[20004];
vector <int> ans;
bool visited[20004];

void go() { // bfs로 헛간 거리 계산
    queue <pair<int, int>> q; // {node, dis}
    visited[1] = true;
    q.push({1,0});

    int cur = 0, dis = 0;
    while (!q.empty()) {
        tie(cur, dis) = q.front();
        q.pop();
        for (int nxt : adj[cur]) {
            if (visited[nxt]) continue;
            visited[nxt] = true;
            q.push({nxt, dis + 1});
            if (max_dis == dis + 1) { // 현재 노드 거리와 최대 거리가 같을 때
                ans.push_back(nxt);
                first_node = min(first_node, nxt); // 만약 거리가 같은 헛간이 여러개면 가장 작은 헛간 번호 저장
            }
            else if (max_dis < dis + 1) { // 현재 노드 거리가 최대 거리일 때
                max_dis = dis + 1;
                ans.clear();
                ans.push_back(nxt); // 거리가 같은 헛간 저장
                first_node = nxt;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    go();

    cout << first_node << " " << max_dis << " " << ans.size()<< "\n";

    return 0;
}
