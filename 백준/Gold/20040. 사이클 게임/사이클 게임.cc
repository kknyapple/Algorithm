#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;

int n, m;
int p[1000004];
int a, b;
int ans;

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

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        p[i] = -1;
    }

    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        // 사이클이 완성되지 않고, 유니온이 불가능하다면
        if (ans == 0 && !merge(a, b)) ans = i; // 사이클이 완성된 차례 저장
    }
    cout << ans << "\n";

    return 0;
}