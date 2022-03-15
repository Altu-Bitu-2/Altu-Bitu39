#include <iostream>
#include <vector>

using namespace std;

vector<int> arr(3, 0);

void checkT();
void turnClock1();
void turnClock2();
void showClock();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int q;
	for (int i = 0; i < 3; ++i) {
		cin >> arr[i];
	}
	cin >> q;

	for (int i = 0; i < q; ++i) {
		checkT();
	}

	return 0;
}

void checkT() {
	int T;
	cin >> T;

	switch (T)
	{
	case 1:
		turnClock1();
		break;
	case 2:
		turnClock2();
		break;
	case 3:
		showClock();
		break;
	default:
		break;
	}
}

void turnClock1() {
	long c, total;
	cin >> c;
	total = 3600 * arr[0] + 60 * arr[1] + arr[2] + c;

	arr[0] = total / 3600;
	arr[1] = (total % 3600) / 60;
	arr[2] = total % 60;

	while (arr[0] > 23)
		arr[0] -= 24;
}

void turnClock2() {
	long c, total;
	cin >> c;
	total = 3600 * arr[0] + 60 * arr[1] + arr[2] - c;

	arr[0] = total / 3600;
	arr[1] = (total % 3600) / 60;
	arr[2] = total % 60;

	if (arr[2] < 0) {
		arr[2] += 60;
		arr[1] -= 1;
	}
	if (arr[1] < 0) {
		arr[1] += 60;
		arr[0] -= 1;
	}
	while (arr[0] < 0)
		arr[0] += 24;
}

void showClock() {
	for (int i = 0; i < 3; ++i) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}