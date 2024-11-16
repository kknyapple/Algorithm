#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int n, a[10004];
ll res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // 같은 숫자가 여러개 존재할 수 있기 때문에 lower_bound, upper_bound 사용
            res += (upper_bound(a + j + 1, a + n, (a[i] + a[j]) * (-1)) - a) - (lower_bound(a + j + 1, a + n, (a[i] + a[j]) * (-1)) - a);
        }
    }

    cout << res << "\n";

    return 0;
}
