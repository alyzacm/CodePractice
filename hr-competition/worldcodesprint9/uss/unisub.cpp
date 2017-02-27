// https://www.hackerrank.com/contests/world-codesprint-9/challenges/weighted-uniform-string
// Jan 28 2017

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int calculateWeight(string s){
    char c = s.at(0);
    int x = c;
    x = x - 96;
    int size = s.size();
    x = x * size;
    return x;

}

int main(){
    string s;
    cin >> s;
    int size = s.size();
    char c = '0';


    stringstream ss;
    ss << c;
    string sub;
    ss >> sub;

    map<int, int> weights;

        
    for(int i = 0; i < size; i++){
        if(c != s.at(i)){
            c = s.at(i); 
            stringstream ss;
            ss << c;
            ss >> sub;  
        }
        else{
            sub += s.at(i);

        }
        int weight = calculateWeight(sub);
        weights[weight]++;

    }
    
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;
        if(weights.find(x) == weights.end()){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }



    return 0;
}