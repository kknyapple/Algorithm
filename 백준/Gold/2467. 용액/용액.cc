#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a[100004];
int s = 2000000004;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int l = 0, r = n - 1;
    int res1 = l, res2 = r;
    while (l < r) {
        int sum = a[l] + a[r];
        // cout << sum << " " << s << "\n";
        if (abs(sum) < s) {
            s = abs(sum);
            res1 = l;
            res2 = r;
            if (sum < 0) l++;
            else r--;
        }
        else if (sum == 0) {
            res1 = l;
            res2 = r;
            break;
        }
        else {
            if (sum < 0)l++;
            else r--;
        }
    }

    cout << a[res1] << " " << a[res2] << "\n";

    return 0;
}
