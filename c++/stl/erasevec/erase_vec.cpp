// https://www.hackerrank.com/challenges/vector-erase
// Feb 6 2017

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    vector<int> v;
    int num;
    int x, a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }
    cin >> x >> a >> b;
    v.erase(v.begin() + x-1);
    v.erase(v.begin() + a-1, v.begin() + b-1);


    int size =  v.size(); 
    cout << size << endl;
    
    for(int i = 0; i < size; i++){
        cout << v.at(i) << " "; 
    }

    return 0;
}
