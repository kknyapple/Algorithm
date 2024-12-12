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

int n, w;
int a, b, c;
int cost[304];
int p[304];
vector<tuple <int, int, int>> adj;
int ans;

void p_init() {
    for (int i = 0;i <= n;i++) {
        p[i] = -1;
    }
}

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
    for (int i = 1;i <= n;i++) {
        cin >> c;
        adj.push_back({ c,0,i });
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> c;
            adj.push_back({ c,i,j });
        }
    }
    sort(adj.begin(), adj.end());

    p_init();
    // 크루스칼
    int cnt = 0;
    for (auto& cur : adj) {
        tie(c, a, b) = cur;
        if (!merge(a, b)) continue;
        ans += c; // a, b 논을 연결하는데 드는 비용
        cnt += 1;

        if (cnt == n) break; // (0 ~ n) 정점이기 때문에 (n-1)개가 아니라 n개 간선이 연결 되었을 때 break
    }

    cout << ans << "\n";

    return 0;
}