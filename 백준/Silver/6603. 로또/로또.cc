#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int k, a[15];
int numbers[10];
bool selected[15];

void go(int cnt, int prev) {
    if (cnt == 6) {
        for (int i = 0; i < 6; i++) {
            cout << numbers[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < k; i++) {
        if (selected[i] == true) continue;
        if (a[i] < prev) continue;

        numbers[cnt] = a[i];
        selected[i] = true;
        go(cnt + 1, a[i]);
        selected[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        for (int i = 0; i < k; i++) {
            selected[i] = false;
        }

        cin >> k;
        if (k == 0) break;

        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }
 
        go(0,0);
        cout << "\n";
    }

    return 0;
}
