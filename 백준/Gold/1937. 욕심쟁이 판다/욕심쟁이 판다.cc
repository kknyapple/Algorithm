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
// const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

int n;
int a[504][504], d[504][504];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int cur_max = 0;
// bool visited[504][504];
int ans;

int go(int y, int x) {
    // if (visited[y][x] == true) return d[y][x];
    // visited[y][x] = true;
    if (d[y][x] != 0) return d[y][x]; // 이미 지나간 좌표면 해당 값 반환

    d[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (a[y][x] < a[ny][nx]) {
            d[y][x] = max(d[y][x], go(ny, nx) + 1); // 다른 루트와 현재 루트 비교
        }
    }
    return d[y][x];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, go(i, j));
        }
    }
    cout << ans << "\n";

    return 0;
}