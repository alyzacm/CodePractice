// https://www.hackerrank.com/challenges/pangrams
// Feb 6 2017

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


void pangram(string s){
    map <char, int> alphabet;
    int size = s.size();
    char c_lower, c;
    for(int i = 0; i < size; i++){
        c = s.at(i);
        if(c != ' '){
	        c_lower = static_cast<char>(tolower(static_cast<unsigned char>(c)));
	        alphabet[c_lower]++;
	    }
    }
    if(alphabet.size() == 26){
    	cout << "pangram" << endl;
    }
    else{
    	cout << "not pangram" << endl;
    }
    
}

int main() {
    string s;
    getline(cin,s);
    pangram(s);
    return 0;
}
