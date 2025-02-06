#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
const int INF = 0x7f7f7f7f;

struct ability
{
    int i, j, value;
    bool operator<(const ability& other) const { // value 기준으로 내림차순 정렬 (최대 힙)
        return value < other.value; 
    }
};

int n, m, a[1004][1004];
priority_queue<ability> pq; // {학급 indx, 학생 index, 능력치}
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> a[i][j];
        }
        sort(a[i], a[i] + m, greater<int>()); // 내림차순 정렬
    }

    int mn = INF, mx = 0;
    for (int i = 0;i < n;i++) {
        pq.push({ i, 0, a[i][0] });
        // 최댓값, 최솟값 저장
        mn = min(mn, a[i][0]);
        mx = max(mx, a[i][0]);
    }
    ans = mx - mn;
    while (true) {
        ability cur = pq.top(); // 최댓값 정보
        int nxtVal = a[cur.i][cur.j + 1];
        pq.pop();
        pq.push({ cur.i, cur.j + 1, nxtVal }); // 현재 학급의 다음 학생 push
        mx = pq.top().value; // pq의 top이 최댓값이 됨
        mn = min(mn, nxtVal); // 현재 최솟값과 다음 삽입 값 nxtVal 중 최솟값 존재
        ans = min(ans, mx - mn); // 능력치 차이값 중 최솟값 저장

        if (cur.j + 1 >= m) break;
    }
    cout << ans << "\n";

    return 0;
}

/*

67 43 16 12
68 48 17 7
77 54 15 14

67 68 77 -> 10
67 68 54 -> 14
67 48 54 -> 19
43 48 54 -> 11
43 48 15 -> 33
43 17 15 -> 28
16 17 15 -> 2
16 7 15 -> 9
12 7 15 -> 8
12 7 14 -> 7

*/