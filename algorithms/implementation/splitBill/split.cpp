// https://www.hackerrank.com/challenges/bon-appetit
// Feb 26 2017

#include <iostream>
#include <vector>

using namespace std;

void bonAppetit(int price, int charged){
	int actual = price / 2;
	if(actual == charged){
		cout << "Bon Appetit" << endl;
	}
	else{
		int result = charged - actual;
		cout << result << endl;
	}
}

int main(){
	int n, k, price, charged;
	int sum = 0;
	// vector<int> v;

	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> price;
		if(i != k ){
			sum+= price;
		}
	}
	cin >> charged;
	bonAppetit(sum, charged);

	return 0;
}