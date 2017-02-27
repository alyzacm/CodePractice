// https://www.hackerrank.com/contests/rookierank-2/challenges/migratory-birds
// Feb 11 2017

#include <iostream>
#include <map>

using namespace std;

int main(){
	int n;
	cin >> n;

	map<int,int> birds;
	int types;
	for(int i = 0; i < n; i++){
		cin >> types;
		birds[types]++;
	}

	int cur_max = 0;
	int type_max = 0;
	for(auto it = birds.cbegin(); it!=birds.cend(); it++){
		if(it->second > cur_max){
			type_max = it->first;
			cur_max = it->second;
		}
	}
	cout << type_max << endl;
	return 0;
}