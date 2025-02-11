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

int n, m;
int u, v, w;
int d[204][204];
int nxt[204][204];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    while (m--) {
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
        nxt[u][v] = v;
        nxt[v][u] = u;
    }

    for (int k = 1;k <= n;k++) {
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (d[i][j] == 0) {
                cout << "- ";
                continue;
            }
            cout << nxt[i][j] << " ";
            
        }
        cout << "\n";
    }

    return 0;
}