#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
const int INF = 0x3f3f3f3f;

int n, m;
int a, b;
int d[104][104];
int ans, mn = INF;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
    while (m--) {
        cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += d[i][j];
        }
        if (mn > sum) {
            mn = sum;
            ans = i;
        }
    }

    cout << ans << "\n";

    return 0;
}