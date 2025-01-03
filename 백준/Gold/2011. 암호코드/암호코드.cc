#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <set>
using namespace std;
using ll = long long;
const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

const ll mod = 1000000;
string str;
ll d[5004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> str;

    if (str[0] == '0') {
        cout << 0 << "\n";
        return 0;
    }

    d[0] = 1; d[1] = 1;
    for (int i = 2;i <= str.length();i++) { // str[0]을 d[1]로 한다
        if (str[i - 1] != '0') { // 0일 때 알파벳 없음
            d[i] += d[i - 1];
        }
        
        int tmp = (str[i - 2] - '0') * 10 + (str[i - 1] - '0');
        if (str[i - 2] != '0' && tmp >= 10 && tmp <= 26) { // 01 안나오게 조건 추가
            d[i] = (d[i] + d[i - 2]) % mod;
        }
    }
    cout << d[str.length()]<< "\n";

    return 0;
}

/*

2    5    1          1                4
B    BE   BEA        BEAA             BEAAD
     Y(" " + Y(25))  YA   YAA         YAAD
                     BEK(BE + K(11))  BEKD
                     YK(Y + K(11))    YKD
                                      BEAN(BEA + N(14))
                                      YAN(YA + N(14))

*/