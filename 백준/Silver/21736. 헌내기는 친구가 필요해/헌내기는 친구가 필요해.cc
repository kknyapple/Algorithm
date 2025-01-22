#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;

string s;
int n, m;
int ix, iy;
char a[604][604];
bool visited[604][604];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int ans;

void go(int y, int x) {
    visited[y][x] = true;
    if (a[y][x] == 'P') ans++;

    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx]) continue;
        if (a[ny][nx] == 'X') continue;

        go(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
            if (a[i][j] == 'I') {
                iy = i;
                ix = j;
            }
        }
    }
    go(iy, ix);

    if (ans == 0) cout << "TT";
    else cout << ans << "\n";

    return 0;
}