#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
const int INF = 0x7f7f7f7f;

int n, a[100004];
int ans = INF;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n); // 정렬

    // 투포인터
    int l = 0, r = n - 1;
    while (l < r) {
        int sum = a[l] + a[r];
        if (sum == 0) { // 특성값이 0일 때 0 출력
            ans = 0;
            break;
        }
        else if (sum > 0) {
            r--;
        }
        else l++;

        if (abs(ans) > abs(sum)) ans = sum; // 0의 가장 가까운 특성값 저장
    }
    cout << ans << "\n";

    return 0;
}