#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
#define X first
#define Y second
using namespace std;

const int INF = 0x7f7f7f7f;

int n, m, u, v, w;
int d[50004];
vector<pair<int, int>> adj[50004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        cin >> u >> v >> w;
        adj[u].push_back({ w,v });
        adj[v].push_back({ w,u });
    }
    for (int i = 2;i <= n;i++) {
        d[i] = INF;
    }
    // 다익스트라
    pq.push({ 0,1 });
    while (!pq.empty()) {
        auto cur = pq.top(); // {dis, node}
        pq.pop();
        if (d[cur.Y] != cur.X) continue;
        for (auto nxt : adj[cur.Y]) { // nxt->{w, node}
            if (d[nxt.Y] <= d[cur.Y] + nxt.X)continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({ d[nxt.Y], nxt.Y });
        }
    }
    cout << d[n] << "\n";

    return 0;
}