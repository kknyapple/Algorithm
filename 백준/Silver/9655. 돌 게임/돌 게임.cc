#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;

int n;
bool d[1004]; // SK가 이기는 경우 -> true

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> n;

    // i-1, i-3 번째에 CY가 가져가면 i번째에 SK가 이김
    d[1] = true; d[3] = true;
    for (int i = 4;i <= n;i++) {
        if (d[i - 1] == false || d[i - 3] == false) d[i] = true;
    }
    
    if (d[n] == true) cout << "SK" << "\n";
    else cout << "CY" << "\n";

    return 0;
}