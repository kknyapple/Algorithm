#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <deque>
#include <set>
#define X first
#define Y second
#define INF 1e18
using namespace std;
typedef long long ll;

int n, m;
int a[54][54];
vector<pair<int, int>> v;
pair<int, int> virus[14];
int visited[54][54];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int ans = 987654321;

void init(){
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            visited[i][j] = 0;
        }
    }
}

bool isSpread() {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (!visited[i][j] && a[i][j] != 1) return false;
        }
    }
    return true;
}

int bfs() {
    int y = 0, x = 0;
    int res = 1; // visited = 1로 시작
    init();
    
    queue<pair<int, int>>q;
    for (int i = 0;i < m;i++) { // 바이러스 방문 처리 및 큐에 넣기
        visited[virus[i].X][virus[i].Y] = 1;
        q.push({ virus[i].X, virus[i].Y });
    }

    while (!q.empty()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0;i < 4;i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (visited[ny][nx]) continue;
            if (a[ny][nx] == 1) continue;
            q.push({ ny, nx });
            visited[ny][nx] = visited[y][x] + 1;
            res = max(res, visited[ny][nx]);
        }
    }
    return res;
}

void selectV(int cnt, int start) { // 바이러스 놓기
    if (cnt == m) {
        int tmp = bfs() - 1; // 바이러스 퍼뜨린 시간
        if(isSpread()) ans = min(ans, tmp); // 모든 칸에 바이러스가 있으면 최소 시간 저장
        return;
    }
    for (int i = start;i < v.size();i++) {
        virus[cnt] = { v[i].X, v[i].Y };
        selectV(cnt + 1, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                v.push_back({ i,j });
            }
        }
    }
    
    selectV(0, 0);
    if (ans == 987654321)cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}