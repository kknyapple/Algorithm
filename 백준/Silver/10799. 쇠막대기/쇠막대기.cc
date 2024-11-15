#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
#include <stack>
using namespace std;

string s;
stack <char> st;
int flag = 1;
int res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	for (char a : s) {
		if (a == '(') {
			st.push(a);
			flag = 1;
		}
		else {
			st.pop();

			if (flag == 1) res += st.size();
			else res += 1;

			flag = 0;
		}
	}

	cout << res << "\n";
	
	return 0;
}