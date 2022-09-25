#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);


	int c[3]; int a[3];
	int b1 = 0, b2 = 1;
	cin >> c[0] >> a[0] >> c[1] >> a[1] >> c[2] >> a[2];
	
	for (int i = 0; i < 100; i++) {
		//calculate pouree bucket content
		int pouree = min(c[b2], a[b1] + a[b2]);

		//calculate pouring bucket content
		a[b1] = max(0, a[b1] + a[b2] - c[b2]);
		a[b2] = pouree;

		//change buckets being poured
		b1 = ++b1 % 3;
		b2 = ++b2 % 3;
	}
	cout << a[0] << '\n';
	cout << a[1] << '\n';
	cout << a[2] << '\n';
	
}
int min(int a, int b) {
	return (a < b) ? a : b;
}
int max(int a, int b) {
	return (a > b) ? a : b;
}
