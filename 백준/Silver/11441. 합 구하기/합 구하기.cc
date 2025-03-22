#include <iostream>
#define X first
#define Y second
#define INF 1e18
using namespace std;
typedef long long ll;

int n, m;
int num, a, b;
int d[100004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        d[i] = d[i - 1] + num;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << d[b] - d[a - 1] << "\n";
    }

    return 0;
}