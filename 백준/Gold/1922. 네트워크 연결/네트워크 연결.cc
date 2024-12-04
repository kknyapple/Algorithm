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

struct edge
{
    int cost, a, b;
};
bool cmp(edge &a, edge &b) { // cost 오름차순
    return a.cost < b.cost;
}
int n, m, u, v, w;
int p[1004];
vector<edge> adj;
int ans;

// 유니온 파인드
int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return false;

    if (p[x] > p[y]) swap(x, y);
    else if (p[x] == p[y]) p[x]--;
    p[y] = x;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) { // 유니온 파인드를 위한 부모 배열 초기화
        p[i] = -1;
    }
    while (m--) {
        cin >> u >> v >> w;
        adj.push_back({ w,u,v });
    }
    sort(adj.begin(), adj.end(), cmp);

    // 크루스칼
    int cnt = 0;
    for (auto &cur : adj) {
        if (!merge(cur.a, cur.b)) continue; // a, b 유니온
        ans += cur.cost; // 간선 추가
        cnt++; // 정점 추가

        if (cnt == n - 1) break;
    }
    cout << ans << "\n";

    return 0;
}