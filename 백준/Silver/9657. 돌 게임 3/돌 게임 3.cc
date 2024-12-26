#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
const int INF = 0x7f7f7f7f;

int n;
bool d[1004]; // SK가 이기는 경우 -> true

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    // i-1, i-3, i-4 번째에 CY가 가져가면 i번째에 SK가 마지막 돌을 가져감 -> SK 승
    d[1] = true; d[3] = true; d[4] = true;
    for (int i = 5; i <= n; i++) {
        if (d[i - 1] == false || d[i - 3] == false || d[i - 4] == false) d[i] = true;
    }

    if (d[n] == true) cout << "SK";
    else cout << "CY";

    return 0;
}