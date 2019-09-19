#include<iostream>
#include<array>
#include<algorithm>

using namespace std;


int main() {
	array<int, 8>arr;

	for (auto&element : arr)
		cin >> element;

	int flag = 0; //1:ascending, 2:descending, 3: mixed
	int count = 0;

	for (int i=0;i<arr.size();i++){
		if (i == 0) {
			if (arr.at(i) == 1) flag = 1;
			else if (arr.at(i) == 8) flag = 2;
			else {
				flag = 3; break;
			}
		}
		else {
			if (flag == 1) {
				if (arr.at(i) == arr.at(i - 1) + 1) continue;
				count += 1;
			}
			else {
				if (arr.at(i) == arr.at(i - 1) - 1) continue;
				count += 1;
			}
		}
	}
	if (count > 0) flag = 3;

	if (flag == 1)
		cout << "ascending\n";
	else if (flag == 2)
		cout << "descending\n";
	else
		cout << "mixed\n";

	return 0;
}