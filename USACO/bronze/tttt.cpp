#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

pair<int, int> areWins(string line) {
	if (line[0] == line[1] && line[1] == line[2]) {
		return pair<int, int>(1, 0);
	} else if (line[0] == line[1] || line[1] == line[2] || line[0] == line[2]) { 
		return pair<int, int>(0, 1); 
	} else { 
		return pair<int, int>(0, 0); 
	}
}

pair<int, int> sumPairs(pair<int, int> p1, pair<int, int> p2) {
	return pair<int, int>(p1.first + p2.first, p1.second + p2.second);
}

int main() {
	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);
	pair<int, int> wins(0, 0);
	vector<string> rows;
	for (int i = 0; i < 3; i++) {
		string row; cin >> row;
		rows.push_back(row);
		wins = sumPairs(wins, areWins(row));
	}
	string line = "   ";
	for (int i = 0; i < 3; i++) {
		line[0] = rows[0][i];
		line[1] = rows[1][i];
		line[2] = rows[2][i];
		wins = sumPairs(wins, areWins(line));
	}

	line[0] = rows[2][0];
	line[1] = rows[1][1];
	line[2] = rows[0][2];
	wins = sumPairs(wins, areWins(line));

	line[0] = rows[0][0];
	line[2] = rows[2][2];
	wins = sumPairs(wins, areWins(line));

	cout << wins.first << endl << wins.second;
}
