#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;

int n, m, a[104][104];
int visited[104][104];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int ans;

void init_visited() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
}

int go(int y, int x) {
    int cnt = 0;
    visited[y][x] = true;
    queue <pair<int, int>> q;
    q.push({ 0,0 });

    while (!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (a[ny][nx] == 0 && visited[ny][nx]) continue;

            visited[ny][nx]++;
            if (a[ny][nx] == 1) { // 치즈 칸
                if (visited[ny][nx] == 2) { // 4변 중에서 적어도 2변 이상이 실내온도의 공기와 접촉한 것
                    a[ny][nx] = 0; // 치즈 없애기
                    cnt++; // 녹은 치즈 개수 세기
                }
            }
            else {
                q.push({ ny, nx });
            }
            
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while (true) {
        init_visited();
        if (go(0, 0) == 0) break; // 더 이상 치즈가 없을 때
        ans++;
    }
    cout << ans << "\n";

    return 0;
}