// https://www.hackerrank.com/challenges/30-operators
//calculate total meal cost
//input:
//
// 12.00 - mealCost
// 20 - tipPercent
// 8 - taxPercent

#include <cmath>
// #include <math.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	double mealCost;
	int tipPercent;
	int taxPercent;

	cin >> mealCost >> tipPercent >> taxPercent;

	double tip = (mealCost * tipPercent) / 100;
	double tax = (mealCost * taxPercent) / 100;
	double total = mealCost + tip + tax;
	int totalCost = static_cast<int>(round(total));
	// cout << tip << " " << tax << " " << cost << endl;
	cout << "The total meal cost is " << totalCost << " dollars.\n"; 


	return 0;
}