#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);

	int n, m, length, velocity;
	int over = 0, difference;
	int offset = 0;
	int limits[100];
	int speeds[100];

	cin >> n >> m;

	//array containing limits
	for (int i = 0; i < n; i++) {
		cin >> length >> velocity;
		for (int j = 0; j < length; j++) { limits[offset] = velocity; offset++; }
	}

	//array containing speeds
	offset = 0;
	for (int i = 0; i < m; i++) {
		cin >> length >> velocity;
		for (int j = 0; j < length; j++) { speeds[offset] = velocity; offset++; }
	}

	for (int i = 0; i < 100; i++) {
		difference = speeds[i] - limits[i];
		over = (difference > over) ? difference : over;
	}

	cout << over;
}
