#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;

struct virus {
    int s, sort, y, x; // 시간 초, 종류, y좌표, x좌표
    bool operator<(const virus& v) const { // pq 조건
        return tie(s, sort, y, x) > tie(v.s, v.sort, v.y, v.x);
    }
};

int n, k, s, x, y;
int d[204][204];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
priority_queue<virus> pq;

void go() { // bfs
    while (!pq.empty()) {
        virus v = pq.top(); // 시간 초, 바이러스 종류 순으로 정렬되어 top에 위치한다
        pq.pop();

        if (v.s >= s) break; // s초가 지나면 break

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + v.y;
            int nx = dx[i] + v.x;

            if (ny < 1 || nx < 1 || ny >= n + 1 || nx >= n + 1) continue;
            if (d[ny][nx] != 0) continue;

            pq.push({ v.s + 1, v.sort, ny, nx });
            d[ny][nx] = v.sort;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
            if (d[i][j] != 0) {
                pq.push({ 0,d[i][j],i,j });
            }
        }
    }
    cin >> s >> x >> y;

    go();
    cout << d[x][y] << "\n";

    return 0;
}