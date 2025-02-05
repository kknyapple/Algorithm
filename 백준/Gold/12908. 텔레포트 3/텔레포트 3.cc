#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
using ll = long long;
const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

struct point
{
    int x1, y1, x2, y2;
};

int xs, ys, xe, ye;
vector <point> v;
int a, b, c, d;
ll ans = INF;
bool isSelected[10];
vector <int> numbers;

void go(int cnt) {
    if (cnt == 6) {
        numbers.clear();
        for (int i = 0;i < 6;i++) { // 선택된 부분집합 저장
            if (isSelected[i]) numbers.push_back(i);
        }

        // 순열로 텔레포트할 좌표(부분집합) 순서 바꾸기
        do{
            int curX = xs, curY = ys;
            ll sec = 0;
            for (auto it = numbers.begin(); it != numbers.end(); ++it) { // 점프, 텔레포트 하기
                sec += abs(curX - v[*it].x1); // 텔레포트할 좌표로 이동하기(점프)
                sec += abs(curY - v[*it].y1);
                sec += 10; // 텔레포트 시간
                curX = v[*it].x2; // 이동 후 좌표
                curY = v[*it].y2;
                // cout << *it << " "; // 순열 출력
            }
            // 도착지점으로 이동
            sec += abs(curX - xe);
            sec += abs(curY - ye);

            ans = min(ans, sec); // 집에 가는 가장 빠른 시간 저장
        } while(next_permutation(numbers.begin(), numbers.end()));
        
        return;
    }

    // 부분집합으로 텔레포트할 좌표 정하기
    isSelected[cnt] = true;
    go(cnt + 1);
    isSelected[cnt] = false;
    go(cnt + 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> xs >> ys;
    cin >> xe >> ye;
    for (int i = 0;i < 3;i++) {
        cin >> a >> b >> c >> d;
        v.push_back({ a,b,c,d }); // (x1, y1)에서 (x2, y2) 이동
        v.push_back({ c,d,a,b }); // (x2, y2)에서 (x1, y1)로 이동
    }
    go(0);
    cout << ans << "\n";

    return 0;
}