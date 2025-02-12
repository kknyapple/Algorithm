#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define X first
#define Y second
using namespace std;

const int INF = 0x3f3f3f3f;

int t, n, m;
int u, v, w;
int personNum, pos[204];
int d[204][204];
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n >> m;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                if (i != j) d[i][j] = INF;
            }
        }
        while (m--) {
            cin >> u >> v >> w;
            d[u][v] = w;
            d[v][u] = w;
        }
        cin >> personNum;
        for (int i = 0;i < personNum;i++) {
            cin >> pos[i];
        }

        // 플로이드 워셜
        for (int k = 1;k <= n;k++) {
            for (int i = 1;i <= n;i++) {
                for (int j = 1;j <= n;j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        int mx_tmp = INF; // 이동 거리 최소값 저장
        for (int k = 1;k <= n;k++) { // 모임 장소 정하기
            int tmp = 0; // 이동 거리의 총합
            for (int i = 0;i < personNum;i++) {
                tmp += d[k][pos[i]];
            }
            if (mx_tmp > tmp) { // 이동 거리가 최소일 때
                mx_tmp = tmp;
                ans = k; // 모임 장소 저장
            }
        }
        cout << ans << "\n";
    }

    return 0;
}