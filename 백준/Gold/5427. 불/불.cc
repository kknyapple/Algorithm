#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define X first
#define Y second
using namespace std;

int t, n, m;
char a[1004][1004];
string str;
queue<pair<int, int>> q;
int sang_y, sang_x;
int visited[1004][1004], visited2[1004][1004];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int ans;

void init() {
    ans = 0;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            visited[i][j] = 0;
            visited2[i][j] = 0;
        }
    }
    
    while (!q.empty()) {
        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> m >> n;
        init();
        for (int i = 0;i < n;i++) {
            cin >> str;
            for (int j = 0;j < m;j++) {
                a[i][j] = str[j];
                if (a[i][j] == '*') { // 불 위치 q에 삽입 및 방문 처리
                    q.push({ i,j });
                    visited[i][j] = 1;
                }
                else if (a[i][j] == '@') { // 상근 위치 저장
                    sang_y = i;
                    sang_x = j;
                }
            }
        }

        // 불 bfs
        int y, x;
        while (!q.empty()) {
            tie(y, x) = q.front(); q.pop();
            for (int i = 0;i < 4;i++) {
                int ny = dy[i] + y;
                int nx = dx[i] + x;
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (visited[ny][nx]) continue;
                if (a[ny][nx] == '#') continue;
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ ny, nx });
            }
        }

        // 상근 bfs
        q.push({ sang_y, sang_x });
        visited2[sang_y][sang_x] = 1;
        while (!q.empty() && ans == 0) { // ans가 정해지면 break
            tie(y, x) = q.front(); q.pop();
            for (int i = 0;i < 4;i++) {
                int ny = dy[i] + y;
                int nx = dx[i] + x;
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) { // 빌딩 탈출
                    ans = visited2[y][x];
                    break;
                }
                if (visited2[ny][nx]) continue;
                if (a[ny][nx] == '#') continue;
                if (visited[ny][nx] && visited[ny][nx] <= visited2[y][x] + 1) continue; // 상근이가 해당 위치 도달하는 시간 < 불이 해당 위치 도달하는 시간인 경우만 상근이 이동 가능
                visited2[ny][nx] = visited2[y][x] + 1;
                q.push({ ny, nx });
            }
        }

        if (ans == 0) cout << "IMPOSSIBLE" << "\n";
        else cout << ans << "\n";
    }

    return 0;
}
/*

1
3 3
...
.@.
...
ans: 2

*/