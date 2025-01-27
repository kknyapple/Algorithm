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
// const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

int n, m;
int e, plan;
int tmp;
int p[204];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (p[v] < p[u]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> e;
            if (e == 1) merge(i, j); // i, j가 연결되어 있을 때
        }
    }
    // plan이 모두 연결되어 있으면 목적 달성 가능
    for (int i = 0; i < m; i++) {
        cin >> plan;
        if (i == 0) tmp = find(plan);
        else {
            if (tmp != find(plan)) { // 모든 plan의 부모가 같지 않을 때
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES" << "\n";

    return 0;
}