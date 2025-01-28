#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
#include <map>
using namespace std;

int t, f;
string a, b;
map <string, int> num; // 자식 개수
map <string, string> mp; // 부모

string find(string x) {
    if (mp[x] == x) return x;
    return mp[x] = find(mp[x]);
}

bool merge(string u, string v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    mp[v] = u;
    num[u] += num[v];
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> f;

        num.clear();
        mp.clear();
        for (int i = 0; i < f; i++) {
            cin >> a >> b;
            if (mp.count(a) == 0) {
                mp.insert({ a,a });
                num.insert({ a,1 }); // 자식 개수 저장
            }
            if (mp.count(b) == 0) {
                mp.insert({ b,b });
                num.insert({ b,1 });
            }
            merge(a, b); // 연결되면 a, b 부모 같음
            cout << num[find(a)] << "\n";
        }
    }

    return 0;
}