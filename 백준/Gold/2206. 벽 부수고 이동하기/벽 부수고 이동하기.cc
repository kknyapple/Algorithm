#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
char a[1004][1004];
string s;
int visited[1004][1004][2];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };

int go(int y, int x) {
    queue <pair<pair<int, int>,int>> q;
    visited[y][x][0] = 1;
    q.push({ { y,x },0 });

    while (!q.empty()) {
        int isBroken = q.front().second;
        tie(y, x) = q.front().first;
        q.pop();

        if (y == n - 1 && x == m - 1) return visited[n - 1][m - 1][isBroken];

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            // if (visited[ny][nx]) continue;
            if (a[ny][nx] == '1' && !isBroken) {
                visited[ny][nx][1] = visited[y][x][0] + 1;
                q.push({ { ny,nx }, 1 });
            }
            else if (a[ny][nx] == '0' && visited[ny][nx][isBroken]==0) {
                visited[ny][nx][isBroken] = visited[y][x][isBroken] + 1;
                q.push({ { ny,nx }, isBroken });
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    cout<<go(0, 0);

    return 0;
}