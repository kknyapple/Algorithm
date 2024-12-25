#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
// using ll = long long;
const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

int s;
int ans;
bool visited[2004][2004];

struct imo {
    int num;
    int cnt;
    int clip;
};

void go() {
    queue<imo> q;
    q.push({ 1, 0, 0 }); // 초기 상태: 화면에 1개, 클립보드 0개, 시간 0초
    visited[1][0] = true;

    while (!q.empty()) {
        int num = q.front().num;
        int cnt = q.front().cnt;
        int clip = q.front().clip;
        q.pop();

        // 목표 개수에 도달하면 최소 시간 갱신
        if (num == s) {
            ans = cnt;
            return;
        }

        // 복사 -> 클립보드에 저장
        if (num > 0 && num < 2000 && !visited[num][num]) {
            visited[num][num] = true;
            q.push({ num, cnt + 1, num });
        }

        // 붙여넣기 -> 클립보드 내용을 화면에 추가
        if (clip > 0 && num + clip <= 2000 && !visited[num + clip][clip]) {
            visited[num + clip][clip] = true;
            q.push({ num + clip, cnt + 1, clip });
        }

        // 삭제 -> 화면 이모티콘 하나 제거
        if (num > 0 && num < 2000 && !visited[num - 1][clip]) {
            visited[num - 1][clip] = true;
            q.push({ num - 1, cnt + 1, clip });
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> s;

    go();
    cout << ans << "\n";

    return 0;
}