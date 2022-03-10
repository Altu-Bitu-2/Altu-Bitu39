#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void reverseSort() {
	for (int i = 0; i < 10; ++i) {
		int a, b;
		cin >> a >> b;
		for (a--, b--; b - a > 0; ++a, --b) {
			swap(arr[a], arr[b]);
		}
	}
}

int main() {
	arr.assign(20, 0);
	for (int i = 0; i < 20; ++i) {
		arr[i] = i + 1;
	}

	reverseSort();

	for (int i = 0; i < 20; ++i) {
		cout << arr[i] << ' ';
	}

	return 0;
}