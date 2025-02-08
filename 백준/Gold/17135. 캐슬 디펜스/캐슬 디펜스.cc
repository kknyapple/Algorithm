#include <bits/stdc++.h>
using namespace std;

int n, m, d;
int a[16][16], ori[16][16];
int isSelected[16];
int visited[16][16];
int dy[] = { 0,-1,0 }, dx[] = { -1,0,1 };
vector<pair<int, int> > v;
int enemy_tmp=0, enemy=0;
int attacked_enemy=0, ans=0;

void initVis() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
}

void copyArray() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = ori[i][j];
        }
    }
}

void go() {
    for (int i = n-1; i >=0; i--) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                if (i + 1 == n) enemy -= 1;
                else a[i + 1][j] = 1;
                a[i][j] = 0;
            }
        }
    }
}

void attack() {
    for (auto k : v) {
        if (a[k.first][k.second] == 1) {
            a[k.first][k.second] = 0;
            enemy -= 1;
            attacked_enemy += 1;
        }
    }
    v.clear();
}

void attackPoint(int y, int x) {
    visited[y][x] = 1;
    queue<pair<int, int> > q;
    q.push({ y,x });

    while (!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx]) continue;
            if (visited[y][x] > d) continue;
            
            if (a[ny][nx] == 1) {
                //cout << ny << " " << nx << "\n";
                v.push_back({ ny, nx });
                return;
            }
            else {
               
                q.push({ ny, nx });
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }
}

void selectArcher(int cnt, int start) {
    if (cnt == 3) {
        copyArray();
        enemy = enemy_tmp;
        attacked_enemy = 0;
        while (true) {
            for (int i = 0; i < 3; i++) {
                initVis();
                attackPoint(n, isSelected[i]);
            }
            attack();
            go();
            if (enemy <= 0) break;
        }
        ans = max(ans, attacked_enemy);
        return;
    }
    for (int i = start; i < m; i++) {
        isSelected[cnt] = i;
        selectArcher(cnt + 1, i+1);
    }
}

int main() {
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ori[i][j];
            if (ori[i][j] == 1) enemy_tmp += 1;
        }
    }
    
    selectArcher(0,0);
    cout << ans << "\n";

    return 0;
}