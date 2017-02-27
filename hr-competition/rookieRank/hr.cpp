// https://www.hackerrank.com/contests/rookierank-2/challenges/hackerrank-in-a-string
// Feb 11 2017

// #include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

bool subsequence(string s){
	string hr = "hackerrank";
	int size = s.size();
	if(size < 10){
		return false;
	}
	int h = 0;
	for(int i = 0; i < size && h < 10; i++){
		if(s.at(i) == hr.at(h)){
			h++;
		}
	}
	return h == 10;
}

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        if(subsequence(s)){
        	cout << "YES" << endl;
        }
        else{
        	cout << "NO" << endl;
        }
    }
    return 0;
}