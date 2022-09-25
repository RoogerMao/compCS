#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);

	int h, w, k; cin >> h >> w >> k;
	string line;
	string out;

	for (int i = 0; i < h; i++) {
		cin >> line;
		for (int m = 0; m < k; m++) {
			for (int j = 0; j < w; j++) {
				for (int l = 0; l < k; l++) {
					out += line[j];
				}
			}
			out += '\n';
		}
	}

	cout << out;
}
