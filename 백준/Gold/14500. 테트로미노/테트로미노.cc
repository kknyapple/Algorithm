#include <iostream>
#define X first
#define Y second
#define INF 1e18
using namespace std;
typedef long long ll;

int n, m;
int a[504][504];
int ans;
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
bool visited[504][504];

void go(int y, int x, int cnt, int sum) {
    if (cnt == 3) {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx]) continue;
        visited[ny][nx] = true;
        go(ny, nx, cnt + 1, sum+a[ny][nx]);
        visited[ny][nx] = false;
    }

    if (y < n - 1 && x < m - 1 && x > 0) { //ㅜ
        ans = max(ans, a[y][x] + a[y][x - 1] + a[y][x + 1] + a[y + 1][x]);
    }
    if (y > 0 && y < n - 1 && x > 0) { //ㅓ
        ans = max(ans, a[y][x] + a[y][x-1] + a[y-1][x] + a[y+1][x]);
    }
    if (y > 0 && y < n - 1 && x < m - 1) { //ㅏ
        ans = max(ans, a[y][x] + a[y][x+1] + a[y-1][x] + a[y+1][x]);
    }
    if (y > 0 && x > 0 && x < m - 1) { //ㅗ
        ans = max(ans, a[y][x] + a[y-1][x] + a[y][x-1] + a[y][x+1]);
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            go(i, j, 0, a[i][j]);
            visited[i][j]=false;
        }
    }
    cout << ans << "\n";

    return 0;
}