#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <deque>
#define X first
#define Y second
#define INF 1e18
using namespace std;
typedef long long ll;

string str;
char alp;
int q;
int l, r;
int d[26][200004]; // [alp][str_idx] 알파벳이 idx까지 몇개 있는지 누적합

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> str;
    cin >> q;
    for (int i = 0; i < str.size(); i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            if (i == 0 && j == str[0]) d[j - 'a'][i] = 1;
            else if (j == str[i]) d[j - 'a'][i] = d[j - 'a'][i - 1] + 1;
            else d[j - 'a'][i] = d[j - 'a'][i - 1];
        }
    }

    while (q--) {
        cin >> alp >> l >> r;
        int ans = 0;
        if (l == 0)ans = d[alp - 'a'][r];
        else ans = d[alp - 'a'][r] - d[alp - 'a'][l - 1];
        cout << ans << "\n";
    }

    return 0;
}

/*

for (int i = 0; i < 26; i++) {
    cout << char('a' + i) << "\n";
    for (int j = 0; j < str.size(); j++) {
        cout << d[i][j] << " ";
    }
    cout << "\n";
}

*/
