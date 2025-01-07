#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;

int r, c, hr, hc;
char world[1004][1004];
char ans[1004][1004];
bool visited[1004][1004];
string str;
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };

void init() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans[i][j] = '#';
        }
    }
}

void go(int y, int x, char alp) { // dfs
    visited[y][x] = true;
    ans[y][x] = '.'; // 볼 수 있는 칸 표시
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if (visited[ny][nx]) continue;
        if (world[ny][nx] == alp) { // 같은 영역에 있을 때
            go(ny, nx, alp);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> r >> c;
    init(); // '#'로 초기화
    for (int i = 0; i < r; i++) {
        cin >> str;
        for (int j = 0; j < c; j++) {
            world[i][j] = str[j];
        }
    }
    cin >> hr >> hc;
    cin >> str;
    hr -= 1; hc -= 1; // 입력이 (1, 1) 시작이므로 1 빼주기

    for (char dir : str) {
        if (dir == 'U') hr -= 1; // 상
        else if (dir == 'D') hr += 1; // 하
        else if (dir == 'L') hc -= 1; // 좌
        else if (dir == 'R') hc += 1; // 우
        else if (dir == 'W') go(hr, hc, world[hr][hc]); // 와드
    }
    ans[hr][hc] = '.'; // 최종 위치
    for (int i = 0; i < 4; i++) { // 최종 위치 상하좌우 시야 확보
        int ny = dy[i] + hr;
        int nx = dx[i] + hc;

        ans[ny][nx] = '.';
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}