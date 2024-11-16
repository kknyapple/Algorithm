#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int n, a, b; 
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> a >> b;

    

    // n을 고려하지 않고 제일 간단하게 조건 만족시키기
    for (int i = 1; i < a; i++) {
        v.push_back(i);
    }
    v.push_back(max(a, b));
    for (int i = b - 1; i > 0; i--) {
        v.push_back(i);
    }

    if (v.size() > n) {  // 조건이 만족이 안되는 경우
        cout << -1 << endl;
    }
    else {
        cout << v[0] << " ";
        for (int i = 0; i < n - v.size(); i++) {  // 
            cout << 1 << " ";
        }
        for (int i = 1; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }


    return 0;
}