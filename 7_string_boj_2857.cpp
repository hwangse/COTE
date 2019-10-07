#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<int>fbi;

	for (int i = 0; i < 5; i++) {
		string name;
		cin >> name;
		if (name.find("FBI") != string::npos)
			fbi.push_back(i + 1);
	}

	if (fbi.size() == 0)
		cout << "HE GOT AWAY!\n";
	else {
		sort(fbi.begin(), fbi.end());
		for (int i = 0; i < fbi.size(); i++) {
			if (i == fbi.size() - 1)
				cout << fbi.at(i) << endl;
			else
				cout << fbi.at(i) << ' ';
		}
	}

	return 0;
}