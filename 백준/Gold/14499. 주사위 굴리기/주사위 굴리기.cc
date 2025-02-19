#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <deque>
#define X first
#define Y second
#define INF 1e18
using namespace std;
typedef long long ll;

struct Dice
{
    int up, back, right, left, front, bottom;
};

int n, m, a, b, k, dir;
int d[24][24];
Dice dice;
int dy[] = { 0,0,0,-1,1 }, dx[] = { 0,1,-1,0,0 }; // 1:동, 2:서, 3:북, 4:남
pair<int, int> pos; // {y,x}

void move() {
    if (d[pos.X][pos.Y] == 0) { // 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사
        d[pos.X][pos.Y] = dice.bottom;
    }
    else { // 이동한 칸에 쓰여 있는 수가 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 됨
        dice.bottom = d[pos.X][pos.Y];
        d[pos.X][pos.Y] = 0;
    }
}

bool isInner() {
    int ny = dy[dir] + pos.X;
    int nx = dx[dir] + pos.Y;
    if (ny < 0 || nx < 0 || ny >= n || nx >= m) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> pos.X >> pos.Y >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];
        }
    }
    while (k--) {
        cin >> dir;
        if (!isInner()) continue; // 이동 불가능하면 명령 무시
        pos.X += dy[dir];
        pos.Y += dx[dir];

        if (dir == 2) {
            int tmp = dice.up;
            dice.up = dice.right;
            dice.right = dice.bottom;
            dice.bottom = dice.left;
            dice.left = tmp;
        }
        else if (dir == 1) {
            int tmp = dice.up;
            dice.up = dice.left;
            dice.left = dice.bottom;
            dice.bottom = dice.right;
            dice.right = tmp;
        }
        else if (dir == 4) {
            int tmp = dice.up;
            dice.up = dice.back;
            dice.back = dice.bottom;
            dice.bottom = dice.front;
            dice.front = tmp;
        }
        else if (dir == 3) {
            int tmp = dice.up;
            dice.up = dice.front;
            dice.front = dice.bottom;
            dice.bottom = dice.back;
            dice.back = tmp;
        }

        move();
        cout << dice.up << "\n";
    }


    return 0;
}