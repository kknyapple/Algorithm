#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;

int n, m;
char a[54][54];
int visited[54][54];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
string str;
int tmp, ans;

void init() {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            visited[i][j] = 0;
        }
    }
}

void go(int y, int x) {
    visited[y][x] = 1;
    queue <pair<int, int>> q;
    q.push({ y,x });

    while (!q.empty()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0;i < 4;i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx]) continue;
            if (a[ny][nx] == 'W') continue;

            q.push({ ny, nx });
            visited[ny][nx] = visited[y][x] + 1;
            tmp = max(tmp, visited[ny][nx]); // 최단거리 업데이트
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        cin >> str;
        for (int j = 0;j < m;j++) {
            a[i][j] = str[j];
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (a[i][j] == 'L') { // 육지인 곳일 때
                init();
                go(i, j); // (y,x)에서 다른 육지로 갈 수 있는 최단 거리 구하기
                ans = max(tmp, ans); // 최단거리 중 가장 긴 시간
            }
        }
    }
    cout << ans - 1 << "\n";

    return 0;
}