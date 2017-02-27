// October 2016
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

void findPairs(const vector<int> &v, int n){
    map<int, int> socks;
    for(int i = 0; i < n; i++){
        socks[v.at(i)]++;
    }
    int numPairs = 0;
    for(map<int,int>::iterator it = socks.begin(); it != socks.end(); it++){
        if(it->second >= 2){
            numPairs += (it->second / 2);
        }   
    }
    cout << numPairs << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> c(n);
    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }
    findPairs(c, n);
    

    return 0;
}
