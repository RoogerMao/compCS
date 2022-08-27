#include <iostream>
using namespace std;
//this program determines if two sheets of paper fully cover a third piece of paper

struct rect {
	int x1;
	int y1;
	int x2;
	int y2;
} paper, b1, b2;

rect intersection(rect, rect);
int area(rect);

int main() {
	/* program outline:
	1. compare the first covering paper to the paper being covered
		a. if it shares a common dimension length, subtract the intersecting area from the paper
		b. if it doesn't ignore the intersecting area and move on to the second covering paper
	2. compare the second covering paper to the paper being covered
		follow the same procedure as step 1, subtracting area from paper if the intersection shares a dimension length
	3. determine whether or not the paper is visible
		a. if the area is 0, print NO to the console, otherwise print YES
	*/
	cin >> paper.x1 >> paper.y1 >> paper.x2 >> paper.y2;
	cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;

	rect int1 = intersection(paper, b1); 
	
	if (int1.x2 - int1.x1 == paper.x2 - paper.x1 && int1.x1 == paper.x1) {
		//intersection may split the paper into two seperate rectangles, we should ignore this case
		if (int1.y1 == paper.y1) { paper.y1 = int1.y2; }
		else if (int1.y2 == paper.y2) { paper.y2 = int1.y1; }
	}
	else if (int1.y2 - int1.y1 == paper.y2 - paper.y1 && int1.y1 == paper.y1) {
		//same reasoning as in the if block
		if (int1.x1 == paper.x1) { paper.x1 = int1.x2; } 
		else if (int1.x2 == paper.x2) { paper.x2 = int1.x1; }
	}

	//cout << paper.x1 << " " << paper.y1 << " " << paper.x2 << " " << paper.y2 << endl;
	cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
	//cout << b2.x1 << " " << b2.y1 << " " << b2.x2 << " " << b2.y2 << endl;
	rect int2 = intersection(paper, b2);

	if (int2.x2 - int2.x1 == paper.x2 - paper.x1 && int2.x1 == paper.x1) {
		//intersection may split the paper into two seperate rectangles, we should ignore this case
		if (int2.y1 == paper.y1) { paper.y1 = int2.y2; }
		else if (int2.y2 == paper.y2) { paper.y2 = int2.y1; }
	}
	else if (int2.y2 - int2.y1 == paper.y2 - paper.y1 && int2.y1 == paper.y1) {
		//same reasoning as in the if block
		if (int2.x1 == paper.x1) { paper.x1 = int2.x2; }
		else if (int2.x2 == paper.x2) { paper.x2 = int2.x1; }
	}
	//cout << paper.x1 << " " << paper.y1 << " " << paper.x2 << " " << paper.y2 << endl;

	cout << ((area(paper) == 0) ? "NO" : "YES");
}

rect intersection(rect a, rect b) {
	rect intersection = { 0, 0, 0, 0 };
	if (a.x2 >= b.x1 && b.x2 >= a.x1 && a.y2 >= b.y1 && b.y2 >= a.y1) {
		intersection.x1 = (a.x1 > b.x1) ? a.x1 : b.x1;
		intersection.y1 = (a.y1 > b.y1) ? a.y1 : b.y1;
		intersection.x2 = (a.x2 < b.x2) ? a.x2 : b.x2;
		intersection.y2 = (a.y2 < b.y2) ? a.y2 : b.y2;
	}
	//cout << "Intersection: " << intersection.x1 << " " << intersection.y1 << " " << intersection.x2 << " " << intersection.y2 << endl;
	return intersection;
}
int area(rect a) {
	return (a.x2 - a.x1) * (a.y2 - a.y1);
}
