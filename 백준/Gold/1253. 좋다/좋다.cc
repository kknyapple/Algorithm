#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int n, a[2004];
bool b[2004];
int res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int s = lower_bound(a, a + n, a[i] + a[j]) - a;
            int e = upper_bound(a, a + n, a[i] + a[j]) - a;

            // cout << s << " " << e << "\n";

            for (int k = s; k < e; k++) {
                if (b[k]) break;
                if (k == i || k == j) continue;
                b[k] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[i]) {
            res++;
            // cout << a[i] << "\n";
        }
    }

    cout << res << "\n";

    return 0;
}
