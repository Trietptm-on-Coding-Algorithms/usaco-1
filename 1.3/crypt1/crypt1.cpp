/*
ID: gamer371
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

// max checks: 10**5 (100,000)

bool check(int a, int b, int c, int d, int e, vector<int>& valid) {
	// debugging...
	// cout << a << " " << b << " " << c << " " << d << " " << e << endl;

	/*
	  * * * num1
   x    * * num2
    -------
      * * * mul1
    * * *   mul2
    -------
    * * * * prod

    */
	int num1 = 100 * a + 10 * b + c;
	int num2 = 10 * d + e;

	int mul1 = num1 * e;
	int mul2 = num1 * d;

	int prod = num1 * num2;

	ostringstream numbers("");
	numbers << mul1 << mul2 << prod;
	string tocheck = numbers.str();


	int tocheck_len = tocheck.size();
	if (tocheck_len != 10)
		return 0;


	for (int i = 0; i < tocheck_len; ++i) {
		int cur_char = (int) tocheck[i] - '0';
		if (find(valid.begin(), valid.end(), cur_char) == valid.end()) {
			return 0;
		}
	}

	return 1;
}

int solve(vector<int>& digits) {
	int num_solutions = 0;
	int digits_length = digits.size();

	for (vector<int>::iterator a = digits.begin(); a != digits.end(); ++a) {
		for (vector<int>::iterator b = digits.begin(); b != digits.end(); ++b) {
			for (vector<int>::iterator c = digits.begin(); c != digits.end(); ++c) {
				for (vector<int>::iterator d = digits.begin(); d != digits.end(); ++d) {
					for (vector<int>::iterator e = digits.begin(); e != digits.end(); ++e) {
						if (check(*a, *b, *c, *d, *e, digits))
							num_solutions++;
					}
				}
			}
		}
	}

	return num_solutions;
}

int main() {
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");

	int N;
	vector<int> digits;

	fin >> N;
	for (int i = 0; i < N; ++i) {
		int tmp;
		fin >> tmp;
		digits.push_back(tmp);
	}

	int num_solutions = solve(digits);
	cout << num_solutions << endl;
	fout << num_solutions << endl;
	
	fout.close();

	return 0;
}
