#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
using ll = long long;
// const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

int n, m;
int a[504][504], d[504][504];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };

int go(int y, int x) {
    if (y == m - 1 && x == n - 1) return 1; // 도착 지점

    if (d[y][x] == -1) { // 방문하지 않은 지점일 때
        d[y][x] = 0;
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
            if (a[y][x] > a[ny][nx]) {
                d[y][x] += go(ny, nx); // 경로 누적
            }
        }
    }
    
    return d[y][x];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            d[i][j] = -1;
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    }
    go(0, 0);

    cout << d[0][0] << "\n";

    return 0;
}