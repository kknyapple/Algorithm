#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
const int INF = 0x3f3f3f3f;

int n, m;
int a[204][204], b[204][204];
int s, e;
int ans[2004];


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = INF;
            b[i][j] = INF;
        }
    }
    while (m--) {
        cin >> s >> e;
        a[s][e] = 1;
        b[e][s] = 1;
    }

    // 단방향 그래프에서 노드가 연결 되어 있으면 크기 비교 가능
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int res1 = 0; // 정방향으로 갈 수 있는 노드 개수 저장
        int res2 = 0; // 역방향으로 갈 수 있는 노드 개수 저장
        for (int j = 1; j <= n; j++) { // 계산된 거리가 있으면 해당 노드는 크기 비교 가능
            if (a[i][j] < INF) res1++; 
            if (b[i][j] < INF) res2++;
        }
        cout << (n - 1) - (res1 + res2) << "\n";
    }

    return 0;
}