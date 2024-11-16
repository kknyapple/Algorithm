#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;

int n, m;
//int a[54][54];
int party_people, real_people;
int party[54];
vector <int> real;
vector <int> a[54];
int parent[54];
int res;

int find_p(int x) {
    if (x != parent[x]) return parent[x] = find_p(parent[x]);
    else return parent[x];
}
// x와 y를 같은 그룹으로 만들어줌
void mer(int x, int y) {
    int px = find_p(parent[x]);
    int py = find_p(parent[y]);
    if (px != py) {
        if (px < py)
            parent[py] = parent[px];
        else
            parent[px] = parent[py];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    cin >> real_people;
    int t;
    for (int i = 1; i <= real_people; i++) {
        cin >> t;
        parent[t] = 0;
    }
    int par;
    for (int i = 1; i <= m; i++) {
        cin >> party_people;
        for (int j = 1; j <= party_people; j++) {
            cin >> t;
            a[i].push_back(t);
            if (j == 1) par = t;
            else {
                mer(par, t);
            }
            
        }
    }

    res = m;
    if (real_people == 0) {
        cout << res << "\n";
        return 0;
    }
    
    for (int i = 1; i <= m; i++) {
        for (auto k : a[i]) {
            if (find_p(parent[k])==0) {
                res--;
                break;
            }
        }
    }

    cout << res << "\n";

    return 0;
}
