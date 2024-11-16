#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

int n;
set <string> s;
string a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (b == "enter") s.insert(a);
		else s.erase(a);
	}

	vector <string> v;
	for (auto k : s) v.push_back(k);
	sort(v.begin(), v.end(), greater<string>());
	// reverse(v.begin(), v.end());
	for (auto k : v) cout << k << "\n";

	return 0;
}
