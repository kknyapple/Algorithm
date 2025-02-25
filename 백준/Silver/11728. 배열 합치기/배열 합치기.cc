#include <iostream>
#define X first
#define Y second
#define INF 1e18
using namespace std;
typedef long long ll;

int n, m;
int a[1000004], b[1000004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for (int i = 0;i < m;i++) {
        cin >> b[i];
    }

    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < n + m;i++) {
        if (idx2 == m) {
            cout << a[idx1] << " ";
            idx1++;
        }
        else if (idx1 == n) {
            cout << b[idx2] << " ";
            idx2++;
        }
        else if (a[idx1] <= b[idx2]) {
            cout << a[idx1] << " ";
            idx1++;
        }
        else {
            cout << b[idx2] << " ";
            idx2++;
        }
    }
    cout << "\n";

    return 0;
}