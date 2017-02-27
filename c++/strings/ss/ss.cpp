/* Jan 24 2017
 * https://www.hackerrank.com/challenges/c-tutorial-stringstream
 * Input format: one line consists of n integers separated by commas
 * Output Format: Print the integers after parsing it
 * 
 * Sanple Input: 
 * 23,4,56
 * 
 * Sample Output:
 * 23
 * 4
 * 56
 */

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> parseInts(string str) {
	
	stringstream ss(str);
	vector<int> v;
	int num;
	char ch;

	while(ss >> num){
		v.push_back(num);
		ss >> ch;
	}
	return v;
}

int main(){
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);

	for(int i = 0; i < integers.size(); i++){
		cout << integers.at(i) << endl;
	}

	return 0;
}