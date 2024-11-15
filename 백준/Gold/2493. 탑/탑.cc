#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<memory.h>
#include<stack>
using namespace std;

stack<int> st;
int n, a[500004], ret[500004];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && a[st.top()] < a[i]) {
			ret[st.top()] = i + 1;
			st.pop();
		}

		st.push(i);
	}

	for (int i = 0; i < n; i++) cout << ret[i] << " ";
	cout << "\n";

	return 0;
}
