#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
struct cow{
	int start, end, buckets;
};
vector<cow> cows;

int bucketsNeeded(int time) {
	int bucketsNeeded = 0;
	for (int i = 0; i < cows.size(); i++) {
		if (cows[i].start <= time && time <= cows[i].end) { bucketsNeeded += cows[i].buckets; }
	}
	return bucketsNeeded;
}

int main() {
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);
	int n; cin >> n;
	int maxBuckets = 0;
	cows.resize(n);

	for (int i = 0; i < n; i++) {
		cow a; 
		cin >> a.start >> a.end >> a.buckets;
		cows.push_back(a);
	}

	for (int i = 1; i <= 1000; i++) {
		int buckets = bucketsNeeded(i);
		if (buckets > maxBuckets) { maxBuckets = buckets; }
	}

	cout << maxBuckets;
}
