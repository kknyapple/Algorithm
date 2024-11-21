#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
const int INF = 0x3f3f3f3f;

string a, b;
int d[1004][1004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b;
    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < b.length(); j++) {
            if (a[i] == b[j]) d[i + 1][j + 1] = d[i][j] + 1;
            else d[i + 1][j + 1] = max(d[i][j + 1], d[i + 1][j]);
        }
    }
    
    // 부분 수열 찾기
    /*int i = a.length(), j = b.length();
    int tmp = d[i][j];
    string ans = "";
    while (true) {
        if (i != 0 && d[i - 1][j] == tmp) {
            i--;
        }
        else if (j != 0 && d[i][j - 1] == tmp) {
            j--;
        }
        else {
            ans += a[i - 1];
            i--; j--;
            tmp = d[i][j];
        }
        if (i == 0 && j == 0) break;
    }*/
            
    cout << d[a.length()][b.length()] << "\n";

    return 0;
}
