// https://www.hackerrank.com/challenges/30-conditional-statements
// input n
// if n is odd, print Weird
// if n is even and in inclusive range of 2 to 5 print Not Weird
// if n is even and in inclusive range of 6 to 20 print Weird
// if n is even and greater than 20, print Not Weird

#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	if((n%2) != 0 ){
		cout << "Weird" << endl;
	}
	else{
		if(n > 1 && n < 6){
			cout << "Not Weird" << endl;
		}
		else if(n > 5 and n < 21){
			cout << "Weird" << endl;
		}
		else{
			cout << "Not Weird" << endl;
		}
	}
	return 0;
}
