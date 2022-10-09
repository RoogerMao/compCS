//solution from USACO site by Brian Dean
//http://usaco.org/current/data/sol_traffic_bronze_feb19.html
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	//file i/o
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);

	//create arrays to store information
	int N, A[100], B[100];
	string T[100];

	//read in values
	for (int i = 0; i < N; i++) { cin >> T[i] >> A[i] >> B[i]; }

	//find ranges at the start
	int a = -999999, b = 999999;

	//find ranges at the start
	for (int i = n - 1; i >= 0; i--) {
		//decrease ranges if possible given new info
		if (T[i] == "none") {
			a = max(a, A[i]); b = min(b, B[i]);
		}
		//assume largest possible ranges after on and off ramps
		//switch since you're going backwards
		if (T[i] == "off") {
			a += A[i]; b += B[i];
		}
		if (T[i] == "on") {
			a -= B[i]; b -= A[i]; a = max(0, a);
		}
	}

	//find ranges at the end
	a = -999999, b = 999999;
	for (int i = 0; i < N; i++) {
		//decrease ranges if possible given new info
		if (T[i] == "none") {
			a = max(a, A[i]); b = min(b, B[i]);
		}
		//assume largest possible ranges after on and off ramps
		if (T[i] == "on") {
			a += A[i]; b += B[i];
		}
		if (T[i] == "off") {
			a -= B[i]; b -= A[i];
		}
	}

	cout << a << " " << b << endl;
}

