/* https://www.hackerrank.com/contests/world-codesprint-9/challenges/queens-attack-2
 * Jan 28
 * INCOMPLETE
*/

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

void printRow(const vector<char> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }
}

void printBoard(const vector<vector<char> > &v){
    for(int y = 0; y <v.size(); y++){
        for(int x = 0; x < (v.at(y)).size(); x++){
            cout << v.at(y).at(x) << " ";
        }
        cout << endl;
    }
}


void makeBoard(int n, vector<char> &row, vector<vector<char> > &board){
    
    for(int x = 0; x < n; x++){
        row.push_back('-');
    }
    for(int y = 0; y < n; y++){
        board.push_back(row);
    }

}

void addQueen(int rQueen, int cQueen, vector<vector<char> > &board){
    board.at(rQueen).at(cQueen) = 'Q';
}

void addObstacle(int y, int x, vector<vector<char> > &board){
    board.at(y).at(x) = 'X';
}

int checkSpace(int y, int x, vector<vector<char> > &board, int &attacks){
    if(board.at(y).at(x) == '-'){
        board.at(y).at(x) = 'O';
        attacks++;
    }
    else if(board.at(y).at(x) == 'X'){
        // cout << y << " " << x << endl;
        return 1;
    }

    return 0;
}

void countNorth(int rowQ, int colQ, vector<vector<char> > &board, int &attacks){
    if(rowQ == 0){
        return;
    }
    for(int y = rowQ - 1; y >= 0; y --){
        if(checkSpace(y, colQ, board, attacks)){
            return;
        }
    }
}

void countSouth(int rowQ, int colQ, vector<vector<char> > &board, int &attacks, int n){
    
    if(rowQ == n - 1){
        return;
    }

    for(int y = rowQ + 1; y < n; y++){
        if(checkSpace(y, colQ, board, attacks)){
            return;
        }
    }
}

void countEast(int rowQ, int colQ, vector<vector<char> > &board, int &attacks, int n){
    
    if(colQ == n - 1){
        return;
    }

    for(int x = colQ + 1; x < n; x++){
        if(checkSpace(rowQ, x, board, attacks)){
            return;
        }
    }
}

void countWest(int rowQ, int colQ, vector<vector<char> > &board, int &attacks){
    if(colQ == 0){
        return;
    }

    for(int x = colQ - 1; x >= 0; x--){
        if(checkSpace(rowQ, x, board, attacks)){
            return;
        }
    }
}

void countNorthWest(int rowQ, int colQ, vector<vector<char> > &board, int &attacks){
    if(rowQ == 0 || colQ == 0){
        return;
    }
    int y = rowQ - 1;
    int x = colQ - 1;
    for(; y >= 0 && x >= 0; y--, x-- ){        
        if(checkSpace(y, x, board, attacks)){
            return;
        }
    }
}

void countNorthEast(int rowQ, int colQ, vector<vector<char> > &board, int &attacks, int n){
    if(rowQ == 0 || colQ == n - 1){
        return;
    }
    int y = rowQ - 1;
    int x = colQ + 1;
    for(; y >= 0 && x < n; y--, x++){
        if(checkSpace(y, x, board, attacks)){
            return;
        }
    }
}

void countSouthEast(int rowQ, int colQ, vector<vector<char> > &board, int &attacks, int n){
    if(rowQ == n - 1 || colQ == n - 1){
        return;
    }
    int y = rowQ + 1;
    int x = colQ + 1;
    for(; y < n && x < n; y++, x++){
        if(checkSpace(y, x, board, attacks)){
            return;
        }
    }

}

void countSouthWest(int rowQ, int colQ, vector<vector<char> > &board, int &attacks, int n){
    if(rowQ == n - 1 || colQ == 0){
        return;
    }
    int y = rowQ + 1;
    int x = colQ - 1;
    for(; y < n && x >= 0; y++, x-- ){        
        if(checkSpace(y, x, board, attacks)){
            return;
        }
    }
}

int main(){


    vector<vector<char> > board;
    vector<char> row;


    int n;
    int k;
    cin >> n >> k;
    int rQueen;
    int cQueen;
    cin >> rQueen >> cQueen;

    int rowQ = n - rQueen;
    int colQ = cQueen - 1;
    int attacks = 0;

    makeBoard(n, row, board);
    addQueen(rowQ, colQ, board);
    // printBoard(board);

    for(int a0 = 0; a0 < k; a0++){
        int rObstacle;
        int cObstacle;
        cin >> rObstacle >> cObstacle;
        addObstacle(n - rObstacle, cObstacle - 1, board);
    }

    countNorth(rowQ, colQ, board, attacks);
    countSouth(rowQ, colQ, board, attacks, n);
    countEast(rowQ, colQ, board, attacks, n);
    countWest(rowQ, colQ, board, attacks);
    countNorthWest(rowQ, colQ, board, attacks);
    countNorthEast(rowQ, colQ, board, attacks, n);
    countSouthEast(rowQ, colQ, board, attacks, n);
    countSouthWest(rowQ, colQ, board, attacks, n);
    printBoard(board);
    cout << attacks << endl;
    return 0;
}
