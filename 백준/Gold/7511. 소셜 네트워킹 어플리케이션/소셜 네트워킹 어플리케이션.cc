#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

int t, n, k;
int a, b;
int m, u, v;
int p[1000004];

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

    cin >> t;
    for (int test = 1; test <= t;test++) {
        cout << "Scenario " << test << ":\n";
        cin >> n;
        cin >> k;
        for (int i = 0; i < n; i++) {
            p[i] = -1;
        }
        for (int i = 0; i < k; i++) {
            cin >> a >> b;
            merge(a, b);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            if (find(u) == find(v)) cout << "1\n";
            else cout << "0\n";
        }
        cout<<"\n";
    }


    return 0;
}