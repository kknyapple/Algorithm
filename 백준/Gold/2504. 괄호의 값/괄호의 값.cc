#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
#include <stack>
using namespace std;

string s;
stack <char> st;
int res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	int tmp = 1;
	char prev = ' ';
	for (char a : s) {
		if (a == '(') {
			st.push(a);
			tmp *= 2;
		}
		else if (a == '[') {
			st.push(a);
			tmp *= 3;
		}
		else if (!st.empty()) {
			if (a == ')' && st.top() == '(') {
				if (prev == '(') res += tmp;
				st.pop();
				tmp /= 2;
			}
			else if (a == ']' && st.top() == '[') {
				if (prev == '[')res += tmp;
				st.pop();
				tmp /= 3;
			}
		}
		else {
			cout << 0 << "\n";
			return 0;
		}
		prev = a;
	}

	if (!st.empty()) res = 0;

	cout << res << "\n";
	
	return 0;
}