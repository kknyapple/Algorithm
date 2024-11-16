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

int n, m;
int a, b, w;
vector<pair<int, int>> adj[1004];
int d[1004], pre[1004];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }
    while (m--) {
        cin >> a >> b >> w;
        adj[a].push_back({ w,b });
        pre[b] = a;
    }
    cin >> a >> b;
    

    d[a] = 0;
    pq.push({ d[a], a });
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (d[cur.second] != cur.first)continue;
        for (auto nxt : adj[cur.second]) {
            if (d[nxt.second] > d[cur.second] + nxt.first) {
                d[nxt.second] = d[cur.second] + nxt.first;
                pq.push({ d[nxt.second], nxt.second });
                pre[nxt.second] = cur.second;
            }
        }
    }

    cout << d[b] <<"\n";
    int cnt = 1;
    vector <int> v;
    /*for (int i = 1; i <= n; i++) {
        cout << pre[i] << " ";
    }*/
    int tmp=0;
    while (1) {
        v.push_back(b);
        if (tmp == a) break;
        cnt += 1;
        tmp = pre[b];
        b = tmp;
    }

    cout << cnt << "\n";

    reverse(v.begin(), v.end());
    for (auto k : v) {
        cout << k << " ";
    }

    return 0;
}