#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <string>
using namespace std;
using ll = long long;

int n;
string s;
vector <string> v;

bool cmp(const string& a, const string& b) {
	if (a.size() == b.size()) {
		int a_sum = 0;
		int b_sum = 0;

		for (auto aa : a) {
			if (aa >= '1' && aa <= '9') {
				a_sum += aa - '0';
			}
		}
		for (auto bb : b) {
			if (bb >= '1' && bb <= '9') {
				b_sum += bb - '0';
			}
		}

		if (a_sum == b_sum) {
			for (int i = 0; i < a.size(); i++) {
				if (a[i] == b[i]) {
					continue;
				}
				return a[i] < b[i];
			}
		}
		return a_sum < b_sum;
	}
	return a.size() < b.size();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), cmp);

	for (auto ss : v) {
		cout << ss << "\n";
	}

	return 0;
}
