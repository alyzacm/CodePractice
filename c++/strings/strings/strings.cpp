/* Jan 24 2017
 * https://www.hackerrank.com/challenges/c-tutorial-strings
 * Input: two strings, a and b, separated by a new line
 * Output: first line print length_a length_b separated by space
 *		   second line print the concatenation of a and b (a + b)
 *   	   third line print a' and b' (a' and b' are same as a and b 
 *			but first letters are exchanged) 
 *
 * Sample Input:
 * abcd
 * ef
 *
 * Sample Output:
 * 4 2
 * abcdef
 * ebcd af
 */

#include <iostream>
#include <string>
using namespace std;

int main(){
	string s1, s2;
	cin >> s1;
	cin >> s2;
	string s3 = s1 + s2;

	int size1 = s1.size();
	int size2 = s2.size();

	char c1 = s1[0];
	s1[0] = s2[0];
	s2[0] = c1;

	cout << size1 << " " << size2 << endl;
	cout << s3 << endl;
	cout << s1 << " " << s2 << endl; 


	return 0;
}