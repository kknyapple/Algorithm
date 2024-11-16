#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
//const int INF = 0x3f3f3f3f;

int n;
vector<int> v;
int num;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (v.empty() || v.back() < num) {
            v.push_back(num);
        }
        else {
            *lower_bound(v.begin(), v.end(), num) = num;
        }
    }
    cout << v.size();

    return 0;
}