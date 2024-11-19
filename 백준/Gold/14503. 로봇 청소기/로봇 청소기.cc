#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
//const int INF = 0x3f3f3f3f;

int n, m, a[54][54];
int r, c;
int d; // 0: 북쪽, 1: 동쪽, 2: 남쪽, 3:서쪽
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int ans;

void go(int r, int c) {
    while (true) {
        if (a[r][c] == 0) {
            ans++; // 청소
            a[r][c] = 2; // 청소 완료 표시
        }

        bool flag = true;
        for (int i = 0; i < 4; i++) {
            int ny = r + dy[i];
            int nx = c + dx[i];

            if (a[ny][nx] != 0) continue;
            flag = false; break;
        }
        if (flag == true) { // 모든 면이 0이 아닐 때, 후진
            if (d == 0) r++;
            else if (d == 1) c--;
            else if (d == 2) r--;
            else if (d == 3) c++;

            if (a[r][c] == 1) return; // 후진할 곳이 벽일 때 정지
        }
        else { // 청소할 곳이 있을 때
            while (true) {
                if (d == 0) {
                    d = 3; // 반시계 방향으로 회전
                    if (a[r][c - 1] == 0) { // 회전 후 앞쪽 칸이 청소되지 않은 곳일 때
                        c--; // 한 칸 전진
                        break;
                    }
                }
                else if (d == 1) {
                    d = 0;
                    if (a[r - 1][c] == 0) {
                        r--;
                        break;
                    }
                }
                else if (d == 2) {
                    d = 1;
                    if (a[r][c + 1] == 0) {
                        c++;
                        break;
                    }
                }
                else if (d == 3) {
                    d = 2;
                    if (a[r + 1][c] == 0) {
                        r++;
                        break;
                    }
                }
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    go(r, c);
    cout << ans << "\n";

    return 0;
}
