#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
const int INF = 0x3f3f3f3f;

int v, e;
int a, b, c;
int d[404][404];
int ans = INF;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> v >> e;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            d[i][j] = INF;
        }
    }
    for (int i = 1; i <= v; i++) {
        d[i][i] = 0;
    }
    while (e--) {
        cin >> a >> b >> c;
        d[a][b] = c;
    }

    // 플로이드 워셜
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
            }
        }
    }

    // 두 정점의 사이클 최솟값 계산 (ex. 1->3 + 3->1 하면 사이클의 도로 길이 합이 나온다)
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i == j) continue; // 0 제외
            if (d[i][j] != INF && d[j][i] != INF) ans = min(ans, d[i][j] + d[j][i]); // INF이면 사이클이 아니다
        }
    }

    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}
