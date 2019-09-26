#include<iostream>
#include<array>
#include<string>

using namespace std;


array<char, 10> numbers;

string maxNum = "0";
string minNum = to_string(9876543210);

void brute_force(string exp, int k,int count,int current,array<bool,10> visited) {
	if (count == k + 1) {
		for (int i = 0; i < k ; i++) {
			char op = exp.at(i);
			char a = numbers[i]; char b = numbers[i + 1];
			if ((op == '<' && a < b) || (op == '>' && a > b)) continue;
			else return;
		}
		string numStr;
		for (int i = 0; i < k + 1; i++)
			numStr.push_back(numbers[i]);
		
		if (numStr > maxNum) maxNum.assign(numStr);
		if (numStr <minNum) minNum.assign(numStr);

		return;
	}
	if (current > 9) return;

	for (int i = 0; i < 10; i++) {
		if (visited[i]) continue;
		visited[i] = true; numbers[count] = i+'0';
		brute_force(exp, k, count + 1, current + 1,visited);
		visited[i] = false;
	}
}


int main() {
	int k;
	string exp;
	array<bool, 10> visited = { false };

	cin >> k;
	exp.resize(k);
	for (int i = 0; i < k; i++) 
		cin >> exp.at(i);
	
	brute_force(exp, k, 0, 0,visited);
	
	cout << maxNum << '\n';
	cout << minNum << '\n';

	return 0;
}