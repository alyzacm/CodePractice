// https://www.hackerrank.com/challenges/cpp-sets
// Feb 11 2017

#include <iterator>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;

    set<int> st;
    int type, x;
    for(int i = 0; i < n; i++){
    	cin >> type;
    	cin >> x;
    	if(type == 1){
    		st.insert(x);
    	}
    	else if(type == 2){
    		st.erase(x);
    	}
    	else if(type == 3){   
    		set<int>::iterator it = st.find(x);
    		if(it != st.end()){
    			cout << "Yes" << endl;
    		}
    		else{
    			cout << "No" << endl;
    		}
    	}
    }
    return 0;
}
