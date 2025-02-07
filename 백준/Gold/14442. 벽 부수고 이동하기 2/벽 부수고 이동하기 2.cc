#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
const int INF = 0x7f7f7f7f;

struct Point
{
    int y, x, wall, dis;
};

int n, m, k;
string str;
int a[1004][1004];
bool visited[1004][1004][14]; // (y,x) 좌표에 오기까지 n개의 벽을 부숨
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int ans = INF;

void go(int y, int x) { // bfs
    int wall = 0; int dis = 1;
    visited[y][x][wall] = true;
    queue <Point> q;
    q.push({ y,x,wall, dis });

    while (!q.empty()) {
        y = q.front().y;
        x = q.front().x;
        wall = q.front().wall;
        dis = q.front().dis;
        q.pop();

        if (y == n - 1 && x == m - 1) {
            ans = dis;
            return;
        }

        for (int i = 0;i < 4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx][wall]) continue;
            if (a[ny][nx] == 1) { // 벽일 때
                if (wall < k) {
                    q.push({ ny, nx, wall + 1, dis + 1 }); // 부순 벽 개수 증가, 거리 증가
                    visited[ny][nx][wall] = true;
                    continue;
                }
                else continue;
            }
            q.push({ ny, nx, wall, dis+1 }); // 거리 증가
            visited[ny][nx][wall] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> n >> m >> k;
    for (int i = 0;i < n;i++) {
        cin >> str;
        for (int j = 0;j < m;j++) {
            a[i][j] = str[j] - '0';
        }
    }
    go(0, 0);

    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}