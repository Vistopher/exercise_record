# 程序设计基础
## 知识点

#### 数值类型及其运算
* 三种整数：短整型short、整型int、长整型long; 三种浮点类型：单精度浮点型float、双精度浮点型double、扩展双精度浮点型long double
![[Pasted image 20220728160118.png]]
![[Pasted image 20220728160146.png]]
* $<limits>$头文件中定义的INT_MAX、INT_MAX、LONG_MIN、LONG_MAX、FLT_MIN、FLT_MAX、DBL_MIN、DBL_MAX等常量
* 1.23456$*$ $10^{-2}$可以写为1.23456E-2
* 数值运算符
 ![[Pasted image 20220728155927.png]]
* 指数运算符:pow(a,b) = $a^b$
* 运算符优先级：1.括号 2.乘法、除法、取余 3.加减法
* 自增自减运算符
![[Pasted image 20220728160608.png]]
![[Pasted image 20220728160632.png]]

#### 数值类型转换
* 整数赋值给浮点型变量，浮点数赋值给整数变量（小数部分被截取）
```cpp
int i = 34.7; //i becomes 34
double j = i; //j becomes 34
double g = 34.3; //g becomes 34.3
int j = g; //j is now 34
```
* 转换运算符
```cpp
cout<<static_cast<int>(1.7); //显示结果为1
cout<<static_cast<double>(1)/2; //显示结果为0.5，因为1一开始被转换成了1.0
cout<<static_cast<int>(11.234*100)/100.0; //保留两位小数
```

#### 常见错误
* 整数溢出（变量被赋予过大数值）；下溢错误（浮点数太小不能被储存，C++将它近似为0）


## 习题
### T1
给出当前时间【time(0)返回格林尼治标准时间1970年1月1日00:00:00至当前时刻所流逝的秒数】
```cpp
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	int totaltime = time(0);
	int currentsecond = totaltime % 60;
	int totalminite = totaltime / 60;
	int currentminite = totalminite % 60;
	int totalhour = totalminite / 60;
	int currenthour = totalhour % 24;
	cout << "Current time is" << " " << currenthour << " " << currentminite << " " << currentsecond << endl;
	return 0;
}
```

### T2
计算给定金额的货币数量：输入double型值的总金额，输出报告按顺序列出等价的最大数量的一美元、二角五分、一角、五美分和一美分的货币，使得得出结果的货币数量最小。
int main() {
	cout << "Enter an amount in double, for example 11.56:";
	double amount;
	cin >> amount;
```cpp
#include <iostream>
using namespace std;

int main() {
	cout << "Enter an amount in double, for example 11.56:";
	double amount;
	cin >> amount;

	int remainingAmount = static_cast<int>(amount * 100);
	int numberOfOneDollars = remainingAmount / 100;
	remainingAmount = remainingAmount % 100;
	int numberOfOneQuarters = remainingAmount / 25;
	remainingAmount = remainingAmount % 25;
	int numberOfNickles = remainingAmount / 5;
	remainingAmount = remainingAmount % 5;
	int numberOfPennies = remainingAmount;
	cout << "Your Amount " << amount << " consists of " << endl <<
	     " " << numberOfOneDollars << " dollars" << endl <<
	     " " << numberOfOneQuarters << " quarters" << endl <<
	     " " << numberOfNickles << " nickles" << endl <<
	     " " << numberOfPennies << " pennies" << endl;

	return 0;
}
```
	
### T3
输入一个0-999的整数，输出该整数各个位置上的数值的总和。
```cpp
#include<iostream>
using namespace std;
int main() {
	cout << "Enter a number between 0 and 1000" << endl;
	int x;
	cin >> x;
	int number_1 = x / 100;
	x = x % 100;
	int number_2 = x / 10;
	x = x % 10;
	int number_3 = x;
	cout << "The sum of the digits is " << number_1 + number_2 + number_3 << endl;
	return 0;
}
```

### T4
（几何：三角形的面积）编写程序，提示用户输入三角形的三个顶点（x1，y1），（x2，y2），（x3，y3），输出它的面积。计算三角形的公式为

s = （side1 + side3 + side3）/2
$$area = \sqrt{(s(s-side1)(s-side2)(s-side3)}$$

```cpp
#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
	cout << "Enter three points for a triangle;";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
 
	double side1 = pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
	double side2 = pow(pow(x1 - x3, 2) + pow(y1 - y3, 2), 0.5);
	double side3 = pow(pow(x3 - x2, 2) + pow(y3 - y2, 2), 0.5);
	double s = (side1 + side2 + side3) / 2;
 
	double area = pow(s * (s - side1) * (s - side2) * (s - side3), 0.5);
	cout << "The area of the triangle is " << area;
 
	return 0;
}
```
分析：学会输入公式





