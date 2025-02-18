#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <deque>
#define X first
#define Y second
using namespace std;
// using ll = long long;
// const int INF = 0x3f3f3f3f;
const int INF = 0x7f7f7f7f;

int n, k, l, a, b, x;
bool apple[104][104], snake[104][104];
char c;
vector<pair<int, char>> v; // {x초, C: 왼쪽90도 / D: 오른쪽90도}
deque<pair<int, int>> dq;
int dy[] = { 0,1,0,-1 }, dx[] = { 1,0,-1,0 }; // 동, 남, 서, 북
int headDir = 0;
int ans;

bool go(int y, int x) {
    if (dq.empty()) return false;
    if (snake[y][x]) return false; // 자기자신 몸과 부딪힌 경우
    snake[y][x] = true; // 몸길이 늘리기
    dq.push_front({ y,x }); // head 저장
    if (!apple[y][x]) { // 사과가 없다면
        snake[dq.back().X][dq.back().Y] = false; // 꼬리가 위치한 칸을 비우기
        dq.pop_back(); // tail 삭제
    }
    else apple[y][x] = false; // 사과가 있으면 사과 없어지고 꼬리 움직이지 않음
    return true;
}

void changeHeadDir(char dir) {
    if (dir == 'D') { // 오른쪽90도 회전
        headDir += 1;
        if (headDir > 3) headDir = 0;
    }
    else if (dir == 'L') { // 왼쪽90도 회정
        headDir -= 1;
        if (headDir < 0) headDir = 3;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> n;
    cin >> k;
    while (k--) {
        cin >> a >> b;
        apple[a][b] = true;
    }
    cin >> l;
    while (l--) {
        cin >> x >> c;
        v.push_back({ x,c });
    }

    bool flag = true;
    dq.push_front({ 1,1 }); // 시작할때 뱀은 맨위 맨좌측에 위치
    for (auto spin : v) { // 뱀 방향 전환 시간 동안
        int sec = spin.X;
        char dir = spin.Y;
        for (int s = ans;s < sec;s++) {
            ans++;
            int ny = dy[headDir] + dq.front().X;
            int nx = dx[headDir] + dq.front().Y;
            if (ny < 1 || nx < 1 || ny >= n + 1 || nx >= n + 1) { // 벽에 부딪힌 경우
                flag = false; break;
            }
            if (!go(ny, nx)) { // 자기자신의 몸과 부딪힌 경우
                flag = false; break;
            }
        }
        if (flag == false) break;
        changeHeadDir(dir); // X초 후 방향 변환
    }
    while (flag) { // 뱀의 방향 변환 끝난 후
        ans++;
        int ny = dy[headDir] + dq.front().X;
        int nx = dx[headDir] + dq.front().Y;
        if (ny < 1 || nx < 1 || ny >= n + 1 || nx >= n + 1)break;
        if (!go(ny, nx)) break;
    }
    cout << ans << "\n";

    return 0;
}