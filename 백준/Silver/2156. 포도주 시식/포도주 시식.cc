#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
// using ll = long long;
const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

int n, x;
int a[10004];
int d[10004];
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    d[1] = a[1];
    d[2] = a[1] + a[2];

    for (int i = 3; i <= n; i++) {
        d[i] = max({ a[i] + a[i - 1] + d[i - 3], a[i] + d[i - 2], d[i - 1]});
    }

    cout << d[n] << "\n";

    return 0;
}