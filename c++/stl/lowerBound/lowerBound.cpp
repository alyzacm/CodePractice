// https://www.hackerrank.com/challenges/cpp-lower-bound
// Feb 8 2017

#include <iterator>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int num, q;
    int result;
    for(int i = 0; i < n; i++){
    	cin >> num;
    	v.push_back(num);
    }
    cin >> q;
    for(int i = 0; i < q; i++){
    	cin >> num;
    	vector<int>::iterator low = lower_bound(v.begin(), v.end(), num);
        if(v[low-v.begin()] == num){
            cout << "Yes " << (low - v.begin() + 1) << endl;

        }
        else{
            cout << "No " << (low - v.begin() + 1) << endl;
        }
    }
    return 0;
}
