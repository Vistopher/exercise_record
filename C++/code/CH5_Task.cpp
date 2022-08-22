//5.16
//不明白为什么有bug ，输出始终为0；帆帆说要教我算法相关
#include <iostream>
using namespace std;

int main() {
	cout << "Enter 2 intergers.\n";
	int a, b, d, i;
	cin >> a, b;

	if (a < b)
		d = a;
	else
		d = b;

	for ( i = d; i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			break;
		}
	}
	cout << "The maximum divisor is " << i;
	return 0;
}

//5.27
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	const int N = 10000;
	for (int i = N; i <= 10 * N; i += N) {
		double sum = 0.0, pi;
		for (int k = 1; k <= (2 * i - 1); k += 2) {
			sum += pow(-1, ((k + 1) / 2 + 1)) / k;
		}
		pi = 4 * sum;
		cout << "The value of pi by " << i << " is " << pi << endl;
	}

	return 0;
}

//5.45
//帆帆说是简单数论
#include <iostream>
using namespace std;
int main() {
	int count = 0;
	for (int i = 1; i <= 7; i++) {
		for (int j = i + 1; j <= 7; j++) {
			cout << i << "\t" << j << endl;
			count++;
		}
	}
	cout << "The total number of all combinations is " << count;

	return 0;
}

//5.49
//经典最长公共序列初级版
#include <iostream>
#include <string>
using namespace std;
int main() {
	string s1, s2, s3 = " ";

	cout << "Enter s1: ";
	getline(cin, s1);
	cout << "Enter s2: ";
	getline(cin, s2);

	int a = s1.length() - 1;
	int b = s2.length() - 1;
	int c ;
	if (a < b)
		c = b;
	else
		c = a;

	for (int i = 0; i <= c; i++) {
		if (s1[i] == s2[i]) {
			s3 += s1[i];
		}	else
			break;
	}
	if (s3 == " ")
		cout << s1 << " and " << s2 << " have no common prefix." << endl;
	else
		cout << "The common prefix is " << s3;
	return 0;
}

//5.50
//可用后期数据结构解决（栈的基本思想）
#include <iostream>
#include <string>
using namespace std;
int main() {
	cout << "Enter a string: ";
	string s1;
	getline(cin, s1);

	string s2 = " ";
	for (int i = 0; i < s1.length(); i++) {
		s2 = s1[i] + s2;
	}
	cout << "The reversed string is " << s2;

	return 0;
}

//5.54
//帆帆口中的简单题
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdio>
using namespace std;

int main() {
	srand(time(0));
	string str;
	for (int i = 0; i < 100; i++)
		str.push_back(char(rand() % 128));

	ofstream makeFile;
	makeFile.open("countletter.txt");
	makeFile << str << endl;
	makeFile.close();

	ifstream readFile;
	readFile.open("countletter.txt");
	string data;
	readFile >> data;
	readFile.close();

	int numberOfLetter = 0;
	for (int i = 0; i < str.length(); i++)
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
			numberOfLetter++;

	cout << "countletter.txt文件中字母的个数为：" << numberOfLetter << endl;

	return 0;
}

//5.57
//帆帆说是简单题
#include <iostream>
#include <string>
using namespace std;

int main() {
	string password;
	cout << "Please put in a password: ";
	cin >> password;

	int numberOfDigit = 0;
	int numberOfLetter = 0;
	int numberOfOthers = 0;

	if (password.length() >= 8) {
		for (int i = 0; i < password.length(); i++) {

			if (password[i] >= '0' && password[i] <= '9')
				numberOfDigit++;

			else if (password[i] >= 'a' && password[i] <= 'z' || password[i] >= 'A' && password[i] <= 'Z')
				numberOfLetter++;

			else {
				numberOfOthers++;
				break;
			}
		}

		if (numberOfOthers == 0 && numberOfDigit >= 2 && numberOfLetter > 0) {
			cout << "valid password";
			return 0;
		} else {
			cout << "invalid password";
			return 0;
		}
	} else
		cout << "invalid password";

	return 0;
}

//5.31格式化输出
#include <iostream>
#include <string>
using namespace std;

int main() {
	const int NUMBER_OF_DAYS_A_WEEK = 7;

	int year;
	int weekday;
	cout << "请输入年份和当年的一月一日是星期几：";
	cin >> year >> weekday;
	cout << endl;

	int fristDayOfMonth;
	int month_num;

	string month_str[12] = { "January", "February", "March", "April",
	                         "May", "June", "July", "August", "September",
	                         "October", "November", "December"
	                       };

	int DayNumberOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		DayNumberOfMonth[1] = 29;
	else
		DayNumberOfMonth[1] = 28;

	int dayNumber = 0;

	for (month_num = 0; month_num < 12; month_num++) {
		dayNumber = 0;
		switch (month_num) {
			case 12:
				dayNumber += 31;
			case 11:
				dayNumber += 30;
			case 10:
				dayNumber += 31;
			case 9:
				dayNumber += 30;
			case 8:
				dayNumber += 31;
			case 7:
				dayNumber += 31;
			case 6:
				dayNumber += 30;
			case 5:
				dayNumber += 31;
			case 4:
				dayNumber += 30;
			case 3:
				dayNumber += 31;
			case 2:

				if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
					dayNumber += 29;
				else
					dayNumber += 28;
			case 1:
				dayNumber += 31;
				break;
defaule:
				break;
		}

		cout << "\t\t" << month_str[month_num] << "  " << year << endl;

		cout << "Sun" << "\t" << "Mon" << "\t" << "Tue" << "\t" << "Wed" << "\t" << "Thu" << "\t" << "Fri" << "\t" << "Sat" <<
		     endl;

		int i;
		int flagOfLine = 0;
		fristDayOfMonth = (dayNumber + weekday) % 7;


		for (i = 0; i < fristDayOfMonth % NUMBER_OF_DAYS_A_WEEK; i++) {
			cout << " " << "\t";
			flagOfLine++;
		}


		for (int j = 1; j <= DayNumberOfMonth[month_num]; j++) {
			cout << j << "\t";
			flagOfLine++;

			if (flagOfLine == NUMBER_OF_DAYS_A_WEEK) {
				cout << "\n" << endl;
				flagOfLine = 0;
			}
		}
		cout << "\n\n";
	}
	return 0;
}