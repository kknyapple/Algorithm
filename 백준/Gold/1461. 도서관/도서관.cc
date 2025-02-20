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

int n, m, num;
vector <int> pos, neg; // a: 양수좌표, b: 음수좌표
int ans, absMax;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > 0) pos.push_back(num);
        else neg.push_back(num);
    }
    // 절댓값이 큰 수부터 정렬
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());
    
    // 절댓값이 가장 큰 수 찾기
    if (!pos.empty()) absMax = max(absMax, pos[0]);
    if (!neg.empty()) absMax = max(absMax, -neg[0]);

    // m번째 마다 책을 두러 가야됨
    for (int i = 0; i < pos.size(); i += m) {
        ans += pos[i];
    }
    for (int i = 0; i < neg.size(); i += m) {
        ans -= neg[i];
    }
    
    // ans * 2: 왕복, -absMax: 책을 모두 제자리 놔둔 후 다시 돌아올 필요 없음
    ans = ans * 2 - absMax;
    cout << ans << "\n";

    return 0;
}