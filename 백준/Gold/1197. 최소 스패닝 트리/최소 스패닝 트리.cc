#include <iostream>
#include <string>
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
bool cmp(edge& a, edge& b) { // cost 오름차순
    return a.cost < b.cost;
}

int v, e, a, b, c;
int p[10004];
vector<edge> adj;
int ans;

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

    cin >> v >> e;
    for (int i = 1; i <= v; i++) { // 유니온 파인드를 위한 부모 배열 초기화
        p[i] = -1;
    }
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        adj.push_back({ c,a,b });
    }
    sort(adj.begin(), adj.end(), cmp);

    int cnt = 0;
    for (auto& cur : adj) {
        if (!merge(cur.a, cur.b)) continue; // a, b 유니온
        ans += cur.cost; // 최소 스패닝 트리 가중치
        cnt++; // 정점 개수 추가

        if (cnt == v - 1) break;
    }
    cout << ans << "\n";

    return 0;
}