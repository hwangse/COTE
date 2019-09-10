#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main() {
	string str;
	cin >> str;

	int res=0;
	int len = str.length();
	bool flag = false; // minus appearing flag
	string str_num="";

	for (int i = 0; i < len; i++) {
		char tmp = str.at(i);

		if (tmp == '-') {
			int num = atoi(str_num.c_str());
			//cout << "num : " << num << '\n';
			if (flag)
				res -= num;
			else
				res += num;
			flag = true;
			str_num = "";
		}
		else if (tmp == '+') {
			int num = atoi(str_num.c_str());
			//cout << "num : " << num << '\n';
			if (flag)
				res -= num;
			else
				res += num;
			str_num = "";
		}
		else if (i == len - 1) {
			str_num = str_num + str.at(len - 1);
			int num = atoi(str_num.c_str());
			//cout << "num : " << num << '\n';
			if (flag)
				res -= num;
			else
				res += num;
		}
		else {
			str_num = str_num + str.at(i);
		}
	}
	cout << res << '\n';

	return 0;
}