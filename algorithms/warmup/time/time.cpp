/* https://www.hackerrank.com/challenges/time-conversion
* Feb 3 2017
* Sample Input 07:05:45PM hh:mm:ssAM or hh:mm:ssPM
* Sample Output 29:05:45
*
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void convertTime(string time){
	string hour = time.substr(0,2);
	string min = time.substr(3, 2);
	string sec = time.substr(6, 2);
	string period = time.substr(8, 2);


	int h;
	if(period == "PM"){
		string newTime = time.substr(2,6);
		if(hour != "12"){
			h = stoi(hour);
			h += 12;
			cout << h << newTime << endl;
		}
		else{
			cout << hour << newTime << endl;
		}

	}
	else if(period == "AM"){
		string newTime = time.substr(2,6);
		if(hour == "12"){
			hour = "00";
		}

		cout << hour << newTime << endl;
	}

}

int main(){
    string time;
    while(cin >> time){
	    convertTime(time);
	}
    return 0;
}
