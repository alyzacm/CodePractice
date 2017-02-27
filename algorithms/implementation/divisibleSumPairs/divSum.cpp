// https://www.hackerrank.com/challenges/divisible-sum-pairs
// Feb 19 2017

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


int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    int sum = 0, count = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            sum = a.at(i) + a.at(j);
            if((sum % k) == 0){
                count++;
            }
        }    
    }
    cout << count << endl;
    return 0;
}