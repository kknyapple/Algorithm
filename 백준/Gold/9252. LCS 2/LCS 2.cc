#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

string a, b;
string str;
int d[1004][1004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> a;
    cin >> b;
    int a_len = a.length(), b_len = b.length();
    for (int i = 1; i <= a_len; i++) {
        for (int j = 1; j <= b_len; j++) {
            if (a[i - 1] == b[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }

    int tmp = d[a_len][b_len];
    int i = a_len, j = b_len;
    while (true) {
        if (i != 0 && tmp == d[i - 1][j]) {
            i--;
        }
        else if (j != 0 && tmp == d[i][j - 1]) {
            j--;
        }
        else {
            str += a[i - 1];
            i--; j--;
            tmp = d[i][j];
        }

        if (i == 0 && j == 0) break;
    }
        

    cout << d[a_len][b_len] << "\n";
    for (int i = str.length() - 1; i >= 0; i--) {
        cout << str[i];
    }

    return 0;
}
