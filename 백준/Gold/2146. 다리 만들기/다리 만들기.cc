#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;

int n;
int a[104][104];
int visited[104][104];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
queue <pair<int, int>> q;
int land_idx = 1;
int len = 100000;

void init_visited() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
}

void init_q() {
    while (!q.empty()) {
        q.pop();
    }
}

void landMark(int y, int x) {
    a[y][x] = land_idx;
    visited[y][x] = 1;
    q.push({ y,x });

    while (!q.empty()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
            if (visited[ny][nx])continue;
            if (a[ny][nx] != 1)continue;

            a[ny][nx] = land_idx;
            visited[ny][nx] = 1;
            q.push({ ny,nx });
        }
    }
}

void findBridge(int y, int x) {
    land_idx = a[y][x];
    visited[y][x] = 1;
    q.push({ y,x });

    while (!q.empty()) {
        tie(y, x) = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = dy[k] + y;
            int nx = dx[k] + x;

            if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
            if (visited[ny][nx])continue;
            if (a[ny][nx] == land_idx)continue;
            if (a[ny][nx] != 0) {
                len = min(len, visited[y][x] - 1);
                /*cout << "\n";
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cout << visited[i][j] << " ";
                    }
                    cout << "\n";
                }*/
                return;
            }

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny,nx });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0)continue;
            if (visited[i][j])continue;

            landMark(i, j);
            land_idx++;
        }
    }

    /*cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }*/

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0)continue;

            init_visited();
            init_q();
            findBridge(i, j);
        }
    }

    cout << len << "\n";

    return 0;
}
