#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, s;
pair<int, int> a[54];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    cin >> s;

    for (int i = 0; i < n && s > 0; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n && j <= i + s; j++) {
            if (a[j].first > a[maxIdx].first) {
                maxIdx = j;
            }
        }

        if (maxIdx == i) continue;

        int p = maxIdx - i;
        s -= p;

        for (int j = maxIdx; j > i; j--) {
            swap(a[j], a[j - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i].first << " ";
    }

    return 0;
}
