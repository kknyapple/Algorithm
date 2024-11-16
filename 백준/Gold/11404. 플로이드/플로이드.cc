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
int a, b, c;
int d[104][104];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = INF;
        }
    }
    while (m--) {
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b],c);
    }
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF) d[i][j] = 0;
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}