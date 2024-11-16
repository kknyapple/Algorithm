#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
using ll = long long;
// const int INF = 0x7f7f7f7f;
const int INF = 0x3f3f3f3f;

int v, e, k;
int d[20005];
vector<pair<int, int>> adj[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> v >> e;
    cin >> k;
    for (int i = 1; i <= v; i++) {
        d[i] = INF;
    }

    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w,v });
    }

    d[k] = 0;
    pq.push({ d[k], k });
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (d[cur.second] != cur.first) continue;
        for (auto nxt : adj[cur.second]) {
            if (d[nxt.second] > d[cur.second] + nxt.first) {
                d[nxt.second] = d[cur.second] + nxt.first;
                pq.push({ d[nxt.second], nxt.second });
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (d[i] == INF)cout << "INF\n";
        else cout << d[i] << "\n";
    }

    return 0;
}