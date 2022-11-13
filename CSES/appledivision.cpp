#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;

int minDiff = INT_MAX;
vector<int> weights;
ll totalWeight = 0;
vector<int> subset; //subset stores indexes of apples

void searchDifferences(int k) {
	if (k == weights.size()) {
		ll b1 = 0;
		for (int x : subset) {
			b1 += weights[x];
		}
		minDiff = (minDiff < abs((totalWeight - b1) - b1)) ? minDiff : abs((totalWeight - b1) - b1);
	}
	else {
		searchDifferences(k + 1);
		subset.push_back(k);
		searchDifferences(k + 1);
		subset.pop_back();
	}
}

int main() {
	int n; cin >> n;
	while (n--) {
		int p; cin >> p;
		weights.push_back(p);
	}
	for (int x : weights) {
		totalWeight += x;
	}
	searchDifferences(0);
	cout << minDiff;
}
