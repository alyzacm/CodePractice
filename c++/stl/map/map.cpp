// https://www.hackerrank.com/challenges/cpp-maps
// Feb 6 2017

#include <map>
#include <iostream>

using namespace std;

int main(){
	map<string, int> grades;
	int n, query, grade;
	string student;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> query;
		cin >> student;
		if(query == 1){
			cin >> grade;
			grades[student]+=grade;
		}
		else if(query == 2){
			grades.erase(student);
		}
		else if(query == 3){
			cout << grades[student] << endl;
		}

	}

	return 0;
}