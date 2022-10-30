#include <iostream>
#include <cstdio>
#include <array>
using namespace std;
typedef long long ll;

array<int, 26> lettersInWord(string word) {
	array<int, 26> letters{ 0 };
	for (int i = 0; i < word.length(); i++) {
		letters[word[i] - 'a']++;
	}
	return letters;
}

array<int, 26> unionLetters(array<int, 26> w1, array<int, 26> w2) {
	array<int, 26> joint{ 0 };
	for (int i = 0; i < 26; i++) {
		joint[i] = max(w1[i], w2[i]);
	}
	return joint;
}

array<int, 26> sumArrays(array<int, 26> w1, array<int, 26> w2) {
	array<int, 26> sum{ 0 };
	for (int i = 0; i < 26; i++) {
		sum[i] = w1[i] + w2[i];
	}
	return sum;
}

int main() {
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);
	int n; cin >> n;
	array<int, 26> totalLetters{ 0 }, w1Letters{ 0 }, w2Letters{ 0 };
	for (int i = 0; i < n; i++) {
		string w1, w2; cin >> w1 >> w2;
		w1Letters = lettersInWord(w1);
		w2Letters = lettersInWord(w2);
		totalLetters = sumArrays(unionLetters(w1Letters, w2Letters), totalLetters);
	}

	for (int i = 0; i < 26; i++) {
		cout << totalLetters[i] << endl;
	}
}
