#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;

int a[5][5];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
set<string> ans;

void go(int y, int x, string str) {
    if (str.length() == 6) { //  6자리의 수일 때
        ans.insert(str);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;

        string tmp = str + to_string(a[ny][nx]);
        go(ny, nx, tmp);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            go(i, j, to_string(a[i][j]));
        }
    }

    cout << ans.size() << "\n"; // 서로 다른 여섯 자리의 수들의 개수

    return 0;
}

/*

25개
9*9*9*9*9*9 = 1,000,000 백만

*/