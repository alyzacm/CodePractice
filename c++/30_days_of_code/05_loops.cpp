// https://www.hackerrank.com/challenges/30-loops
// Input: n 
// Output: first 10 multiples of n in the form of
// n x 1 = n

#include <iostream>
using namespace std;

int main(){

	int n;
	cin >> n;

	for(int i = 1; i < 11; i++){
		cout << n << " x " << i << " = " << n*i << endl;
	}
	return 0;
}

