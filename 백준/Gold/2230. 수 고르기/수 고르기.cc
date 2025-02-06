#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;

int n, m, a[100004];
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    ans = a[n - 1] - a[0]; // 가장 작은 수와 가장 큰 수의 차이

    int l = 0, r = 1;
    while (l <= r && r < n) {
        int diff = a[r] - a[l]; // 두 수의 차이
        if (diff < m) r++;
        else if (diff == m) {
            ans = m;
            break;
        }
        else {
            ans = min(ans, diff); // m이상이면서 가장 작은 차이 저장
            l++;
        }
    }
    cout << ans << "\n";

    return 0;
}