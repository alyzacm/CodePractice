// https://www.hackerrank.com/contests/rookierank-2/challenges/minimum-absolute-difference-in-an-array
// Feb 11 2017

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    sort(a.begin(), a.end());

    int diff = 0;
    int min = INT_MAX;
    for(int i = 0;  i < n; i++){
    	diff = abs(a[i] - a[i+1]);
    	if(diff < min){
    		min = diff;
    	}
    }
    cout << min << endl;
    return 0;
}
