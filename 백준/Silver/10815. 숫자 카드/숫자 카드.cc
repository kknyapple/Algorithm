#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, t;
int a[500004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        if (binary_search(a, a + n, t)) cout << "1 ";
        else cout << "0 ";
    }

    return 0;
}
