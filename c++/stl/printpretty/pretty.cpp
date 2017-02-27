// https://www.hackerrank.com/challenges/prettyprint
// Feb 11 2017
// INCOMPLETE

#include <iostream>
#include <iomanip> 
#include <math.h>
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		int a = floor(A);
		cout << hex << a << endl;
	}
} 