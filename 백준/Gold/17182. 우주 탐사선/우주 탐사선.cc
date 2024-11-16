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

int n, k, ans=INF;
int ori[14][14];
int d[14][14], nxt[14][14];
bool visited[14];

void go(int cnt, int cur, int sum) {
    if (cnt == n) {
        ans = min(sum, ans);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        go(cnt + 1, i, sum+ d[cur][i]);
        visited[i] = false;
       
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/

    visited[k] = true;
    go(1, k, 0);

    cout << ans << "\n";

    return 0;
}