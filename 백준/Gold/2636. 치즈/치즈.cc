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
bool visited[104][104];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int t, ans;

void init_visited() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
}

int go(int y, int x) { // bfs
    int cnt = 0; // 해당 시간에 녹은 치즈칸 개수
    visited[0][0] = true;
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    
    while (!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx]) continue;

            if (a[ny][nx] == 0) {
                visited[ny][nx] = true;
                q.push({ ny, nx });
            }
            else { // 치즈 녹이기
                visited[ny][nx] = true; // 방문 표시로 다시 방문하지 않게 하기
                a[ny][nx] = 0;
                cnt++;
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
        int tmp = go(0, 0);
        
        if (tmp == 0) break;
        else {
            t++;
            ans = tmp; // 현재 녹은 치즈칸 개수 저장
        } 
    }
    
    cout << t << "\n" << ans << "\n";

    return 0;
}