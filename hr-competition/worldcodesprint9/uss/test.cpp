// Jan28: Testing algorithm to calculate weight

#include <iostream>
#include <string>

using namespace std;

int main(){

	string s = "ddd";
	char c = s.at(0);
	int x = c;
	x = x - 96;
	int size = s.size();
	x = x * size;
	cout << x << endl;
	return 0;
}