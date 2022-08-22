# 分支语句
## 知识点

#### bool数据类型
* 关系运算符
![[Pasted image 20220805150742.png]]
* 布尔变量：保存布尔值的变量
```cpp
bool lightson = true;//声明布尔型变量并赋初值为true
```
* "true"显示为1，“False"显示为0
```cpp
cout<<(4<5);//显示输出为1，因为4<5是true
cout<<(4>5);//显示输出为0，因为4>5是false
```
* 非零数值赋予一个bool变量，非0值为true, 0代表false
```cpp
bool b1 = -1.5;//Same as bool b1 = true
bool b2 = 0;//Same as bool b2 = false
bool b3 = 1.5;//Same as boo b3 = true
```

#### if语句
![[Pasted image 20220805151827.png]]
![[Pasted image 20220805151848.png]]

#### 双分支的 if_else语句
![[Pasted image 20220805152001.png]]
![[Pasted image 20220805152016.png]]
通常，如果只有一条语句，外面一层大括号可以省略。

#### 嵌套的if语句和多分支的if语句
![[Pasted image 20220805152205.png]]

#### 常见错误和陷阱
* 错误1：忘记必须括号
![[Pasted image 20220805152546.png]]
* 错误2：if行错误的分号
![[Pasted image 20220805152639.png]]
* 错误3：错误使用=代替==
* 错误4：布尔值的冗余测试
![[Pasted image 20220805152854.png]]
* 错误5：else位置歧义
![[Pasted image 20220805153029.png]]
else子句通常和同一程序段中最近的if子句配套
* 错误6：两个浮点值的相等性测试
浮点数有限制的精度，涉及浮点数的计算会导致舍入误差
，通常在比较两个double值的时候把$\epsilon$设置为$10^{-14}$, 比较两个float值的时候把$\epsilon$设置为$10^{-7}$
![[Pasted image 20220805153838.png]]
* 陷阱1：简化布尔变量赋值
![[Pasted image 20220805153955.png]]
* 陷阱2：避免在不同分支中的相同语句
![[Pasted image 20220805154044.png]]
* 陷阱3：整数值可以被用作布尔值
![[Pasted image 20220805154211.png]]


#### 生成随机数
* rand( )函数获得随机整数
* 种子（seed)控制随机数，默认情况下种子的值为1
* srand(seed)改变种子的值，time(0)使每次种子的值都不相同
* 生成一定区间的随机整数
    1. 确定区间形式
    2. 算出区间长度
    3. 写出生成随机整数表达式
    eg1.区间（m,n）:
          1.确定区间【m+1, n-1】
          2.区间长度：（n-1)-(m+1)+1 = n-m-1
          3.表达式：rand()%(n-m-1)+m+1
    eg2.区间【m,n) :
          1.确定区间：【m,n-1】
          2.区间长度：n-1-m+1 = n-m
          3.表达式：rand()%(n-m)+m
    eg3.区间（m,n]:
          1.确定区间：【m+1，n】
          2.区间长度：n-(m+1)+1 = n-m
          3.表达式：rand()%(n-m)+(m+1)
    eg4.区间【m,n】：
          1.确定区间：【m,n】
          2.区间长度：n-m+1
          3.表达式：rand()%(n-m+1)+m
* 举例：
![[Pasted image 20220805160310.png]]
```cpp
#include<iostream>
#include<ctime>//for time function
#include<cstlib>//for rand and srand function
using namespace std;
int main(){
	//1.Generate 2 random single_digit intergers
	srand(time(0));
	int number1 = rand()%10;
	int number2 = rand()%10;

	//2.If number1<number2, swap number1 with number2
	if(number1 < number2){
		int temp = number1;
		number1 = number2;
		number2 = temp;
	}

	//3.Prompt the student to answer "What is number1 - number2?"
	cout<<"What is "<<number1<<" - "<<number2<<" ? ";
	int answer;
	cin>answer;

	//4.Grade the answer and display the result
	if(number1-number2==answer){
		cout<<"You are correct";
	}
	else
		cout<<"Your answer is wrong."<<number1<<" - "<<
		number2<<" should be "<<(number1-number2)<<endl;
	return 0;
}
```

#### 逻辑运算符
![[Pasted image 20220805161601.png]]
![[Pasted image 20220805161628.png]]

警示：
![[Pasted image 20220805161704.png]]

#### Switch语句
* 语法
*![[Pasted image 20220805162159.png]]
* 遵循规则
![[Pasted image 20220805162229.png]]

#### 条件表达式
* 语法
![[Pasted image 20220805162324.png]]
* 举例
![[Pasted image 20220805162405.png]]

#### 运算符优先级和结合律
* 优先级
![[Pasted image 20220805162554.png]]
* 结合律
除赋值运算符外所有二元运算符都是左边结合
![[Pasted image 20220805162851.png]]

#### 调试

## 习题
#### T1
题目：
![[Pasted image 20220805162022.png]]
代码：
```cpp
*#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	srand(time(0));
	int number_1 = rand() % 100;
	int number_2;
	int a = number_1 / 10;
	int b = number_2 / 10;
	int c = number_1 % 10;
	int d = number_2 % 10;
	cin >> number_2;
	if (number_1 == number_2) {
		cout << "You'll gain $10000." << endl;
	} else if  (a == d && c == b) {
		cout << "You'll gain $3000." << endl;
	} else if (!((a != b && a != d) && (c != b && c != d))) {
		cout << "You'll gain $1000." << endl;
	}

	return 0;
}
```

#### T2
题目：
![[Pasted image 20220805163145.png]]
代码：
```cpp
*#include <iostream>
#include <cmath>
using namespace std;
int main() {
	cout << "Enter a, b, c" << endl;
	double a, b, c;
	cin >> a >> b >> c ;
	double d = pow(b, 2) - 4 * a * c;

	if (d > 0) {
		double e = (b + pow(d, 0.5)) / (2 * a);
		double f = (b - pow(d, 0.5)) / (2 * a);
		cout << e << " " << f << endl;
	} else if (d == 0) {
		double g = (0 - b + pow(d, 0.5)) / (2 * a);
		cout << g << endl;
	} else
		cout << "The equation has no real roots." << endl;

	return 0;
}
```
练习出错点：把e和f放到了第一个if循环之前

#### T3
题目：
![[Pasted image 20220805163318.png]]
代码：
```cpp
#include <iostream>
using namespace std;

int main() {
	cout << "Enter two intergers." << endl;
	int a, b;
	cin >> a >> b;
	switch (bool (a % b)) {
		case 0:
			cout << a << " is divisible by " << b;
			break;
		case 1:
			cout << a << " is not divisible by " << b;
			break;
			return 0;
	}
```
关键点：尝试用switch 代替if_else语句

#### T4
题目：
![[Pasted image 20220805163517.png]]
代码：
```cpp
#include <iostream>
using namespace std;
int main() {
	cout << "Enter a,b,c,d,e,f." << endl;
	double a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	double g = a * d - b * c;
	if (g != 0) {
		double x = (e * d - b * f) / g;
		double y = (a * f - e * c) / g;
		cout << "x is " << x << ", y is " << y << endl;
	} else
		cout << "The equation has no solution." << endl;

	return 0;
}
```
关键点：简单的if_else语句，适当简化代码（变量g的出现)

#### T5
题目：
![[Pasted image 20220805163806.png]]
代码：
```cpp
#include <iostream>
using namespace std;

int main()
{
	cout << "请输入月份和年份：" << endl;
	int month = 0, year = 0;
	cin >> month >> year;

	cout << year << "年" << month << "月有";
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:cout << 31; break;
	case 4:
	case 6:
	case 9:
	case 11:cout << 30; break;
	case 2:if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)cout << 29;//判断是否为闰年
		  else cout << 28;break;
	default:
		break;
	}
	cout << "天" << endl;

	return 0;
}
```
关键点：switch 与  if_else条件语句的结合

#### T6
题目：
![[Pasted image 20220805164219.png]]
代码：
```cpp
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	cout << "scissor(0), rock(1), paper(2):" << endl;
	int computer_number, input_number;
	srand(time(0));
	computer_number = rand() % 3;
	cin >> input_number;

	cout << "The computer is ";
	switch (computer_number) {
		case 0:
			cout << "scissor. ";
			break;
		case 1:
			cout << "rock. ";
			break;
		case 2:
			cout << "paper. ";
			break;
	}

	cout << "You are ";
	switch (input_number) {
		case 0:
			cout << "scissor ";
			break;
		case 1:
			cout << "rock ";
			break;
		case 2:
			cout << "paper ";
			break;
		default:
			cout << "Inputting is wrong.";
			return 0;
	}
	if (
	    (input_number == 0 && computer_number == 2) ||
	    ( input_number == 1 && computer_number == 0 ) ||
	    ( input_number == 2 && computer_number == 1 )) {
		cout << ". You won." << endl;
	}

	else if (input_number == computer_number) {
		cout << "too. It is a draw." << endl;
	} else
		cout << ". You lost." << endl;


	return 0;
}
```
关键点：双重switch 与if_else语句的结合；注意运行样例字符串的表达细节

#### T7
题目：
![[Pasted image 20220805164545.png]]
代码：
```cpp
#include <iostream>
using namespace std;

int main()
{
	cout << "Enter the point's x- and y-coordinates:";
	double x, y;
	cin >> x >> y;

	/*点P在三角形ABC内部，可以通过以下三个条件判断：
		点P和点C在直线AB同侧
		点P和点B在直线AC同侧
		点P和点A在直线BC同侧
	如果以上三个条件同时满足，则点P在三角形ABC内部。*/
//利用程序3-29可以判断点在直线的那一侧
//顺时针遍历三个顶点时，第三个点一定位于剩余两点组成有向线段的右侧
//所以，顺时针时，点P一直要处于有向线段的右侧，点P才在三角形内部

double x0, x1, y0, y1;
//1.点（0.0）指向点（0,100）的有向线段
x0 = 0, y0 = 0, x1 = 0, y1 = 100;
bool flag1 = (x1 - x0) * (y - y0) - (x - x0) * (y1 - y0) < 0;//小于0则位于线段右侧
//2.点（0,100）指向点（200,0）的有向线段
x0 = 0, y0 = 100, x1 = 200, y1 = 0;
bool flag2 = (x1 - x0) * (y - y0) - (x - x0) * (y1 - y0) < 0;
//3.点（200,0）指向点（0,0）的有向线段
x0 = 200, y0 = 0, x1 = 0, y1 = 0;
bool flag3 = (x1 - x0) * (y - y0) - (x - x0) * (y1 - y0) < 0;

if (flag3 && flag2 && flag1)
	cout << "The point is in the triangle" << endl;
else
	cout << "The point is not in the triangle" << endl;

return 0;
}
```
关键点：bool变量与if_else条件语句

#### T8
题目：
![[Pasted image 20220805164813.png]]
![[Pasted image 20220805164826.png]]
代码：
```cpp
#include <iostream>
using namespace std;
int main() {
	double x1, x2, y1, y2, w1, w2, h1, h2;
	cout << "Enter r1's center x-,y-coordinates, width, and height." << endl;
	cin >> x1 >> y1 >> w1 >> h1;
	cout << "Enter r2's center x-,y-coordinates, width, and height." << endl;
	cin >> x2 >> y2 >> w2 >> h2;
	if (((w1 - w2) / 2 <= abs(x1 - x2) < w1 / 2) &&
	        ((h1 - h2) / 2 <= abs(h1 - h2) < h1 / 2) &&
	        w1 > w2 &&
	        h1 > h2) {
		cout << "r2 is inside r1." << endl;
	}

	else if ( ((abs(x1 - x2) <= (w1 + w2) / 2)) &&
	          ((abs(y1 - y2) <= (w1 + w2) / 2))) {
		cout << "r2 overlaps r1." << endl;
	}

	else
		cout << "r2 does not overlap r1." << endl;
	return 0;
}
```
关键点：找准最简单的两种情况（不好表述的情况用else）;
			 多个逻辑运算符美观写法。

