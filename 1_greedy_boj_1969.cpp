#include<iostream>
#include<vector>
#include<array>
#include<string>

using namespace std;

char dna[4] = { 'A','C','G','T' };

int main() {
	int n, m;
	cin >> n >> m;
	int diff = 0;
	vector<string> dnas(n);

	for (auto & element:dnas)
		cin >> element;

	string finalDNA = "";
	for (int i = 0; i < m; i++) {
		array<int, 4> num = { 0 };
		for (int j = 0; j < n; j++) {
			char tmp = dnas.at(j).at(i);
			switch (tmp) {
			case 'A': num[0] ++; break;
			case 'C': num[1] ++; break;
			case 'G': num[2] ++; break;
			case 'T': num[3] ++; break;
			}
		}
		int idx = 0;
		for (int j = 1; j < 4; j++) {
			if (num[j] > num[idx])
				idx = j;
		}
		diff += (n - num[idx]);
		finalDNA.push_back(dna[idx]);
	}
	cout << finalDNA << '\n';
	cout << diff << '\n';

	return 0;
}