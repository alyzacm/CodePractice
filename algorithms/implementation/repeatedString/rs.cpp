// https://www.hackerrank.com/challenges/repeated-string
// Feb 26 2017

#include <iostream>
using namespace std;

long countA(string s, int n){
	long a_count = 0;
	for(int i = 0; i < n; i++){
		if(s.at(i) == 'a'){
			a_count++;
		}
	}
	return a_count;
}

int main(){
	string s;
	cin >> s;
	long n;
	cin >> n;

	int size = s.size();
	if(size > n){
		cout << countA(s, n) << endl;
	}
	else{
		long d = n / size;
		long r = n % size;

		long count_a = countA(s, size);
		long count_a_remainder = countA(s, r);
		long result = d * count_a;
		result += count_a_remainder;

		cout << result << endl;
	}



	
	



	return 0;
}