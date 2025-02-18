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
// typedef long long ll;

int n, a, b;
vector<pair<int, int>> v; // {end, start} end >= start
int ans; // 최대 20억

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> a >> b;
        if (a < b) swap(a, b);
        v.push_back({ a, b });
    }
    sort(v.begin(), v.end(), greater<>()); // 내림차순 정렬

    int pre_st = v[0].Y, pre_en = v[0].X;
    ans += pre_en - pre_st;
    for (int i = 0;i < v.size();i++) {
        if (i == 0) continue;
        int st = v[i].Y, en = v[i].X;
        if (en <= pre_st) ans += en - st; // 겹치지 않으면 ans+=길이
        else {
            int tmp = pre_st - st;
            if (tmp <= 0) {
                pre_en = en; // end 값만 저장
                continue;
            }
            else ans += tmp; // 겹치고 이전start가 현재 start 보다 뒤에 있을 때 ans+=(이전start - 현재start)
        }
        pre_st = st; pre_en = en;
    }
    cout << ans << "\n";

    return 0;
}