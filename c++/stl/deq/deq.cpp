// https://www.hackerrank.com/challenges/deque-stl
// Feb 11 2017
// INCOMPLETE

#include <iostream>
#include <deque>

using namespace std;

void printKMax(int arr [], int n, int k){
	int max; 
	deque<int> deq;
	int j;
	for(int i = 0; i < n - k + 1; i++){
		max = 0;
		for(j = 0; j < k; j++){
			
			if(arr[i + j] > max){
				max = arr[i+ j];
			}
		}
		deq.push_back(max);
	}
	while(!deq.empty()){
		cout << deq.front() << " ";
		deq.pop_front(); 
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t > 0){
		int n, k;
		cin >> n >> k;
		int i;
		int arr[n];
		for(i = 0; i < n; i++){
			cin >> arr[i];
		}
		printKMax(arr, n, k);
		t--;
	}
	return 0;
}