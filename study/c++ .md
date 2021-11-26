# c++

- 引用
- 引用在定义时必须初始化。

```cpp
#include<iostream>
using namespace std;

int main(){
    int a1 = 100,a2 = 200;
    int& b = a1;
    b = a2;
    cout<<b<<","<<a1<<endl;
    return 0;
}
//输出 200，200
```

- 可以建立引用得引用；

### new和delete的使用

```cpp
int* p = new int(2);
int* p2 = new int(3);
```

### enum枚举类型

```cpp
enum ESex{
    ESex_male,
    ESex_famale
};

enum ESex{ESex_male,ESex_famale};
```

### 结构体类型

```cpp
struct Student
{
    string name; //string类型使用到头文件#include<string>
    int num;
    ESex sex;
    int age;
};

```

### inline 内联

![https://cdn.nlark.com/yuque/0/2020/png/1399983/1594534258246-a01acf9d-c248-4d46-a02e-e2d92621d42e.png](https://cdn.nlark.com/yuque/0/2020/png/1399983/1594534258246-a01acf9d-c248-4d46-a02e-e2d92621d42e.png)

```cpp
inline int MAX_NUM(int x,int y){
    return x>y?x:y;
}
```

### 构造函数

- 会在对象被建立后自动调用，

### 拷贝构造函数

```cpp
#include<iostream>
#define PI 3.14
using namespace std;

class Circle
{
public:
	Circle();
	Circle(double R);
	~Circle();
	Circle(const Circle &c);
	double Circumference();
	void setR(double R);

private:
	double R;
};

Circle::Circle()
{
	R = 0;
}

Circle::Circle(double R)
{
	this->R = R;
}

Circle::~Circle()
{

	cout << "~Circle()" << endl;
}
//拷贝构造函数
Circle::Circle(const Circle& c)
{
	//将传入的 所有属性拷贝到c上。
	R = c.R;
}

double Circle::Circumference()
{
	double cf = 2 * PI * R;
	return cf;
}

void Circle::setR(double R) {
	this->R = R;
}

int main() {

	Circle* c = new Circle(10);
	Circle* b = new Circle();
	Circle a;

	b->setR(20);
	double bf = b->Circumference();
	Circle* s  =new Circle(*c);
	double sf = s->Circumference();
	double cf = c->Circumference();
	cout << cf <<endl;
	system("pause"); //可用来暂停窗口
	cout << bf << endl;
	cout << sf << endl;
	delete c;
	delete b;
	return 0;

}
```

### 构造函数调用规则

- 如果用户定义有参构造函数，c++不在提供 默认无参构造函数，但是会提供拷贝构造函数
- 如果用户定义拷贝构造函数，c++不在提供其他构造函数。

### 深拷贝与浅拷贝

- 浅拷贝：简单赋值操作
- 深拷贝：在堆区重新开辟内存，进行拷贝操作

```cpp
person::person(const person& p)
{
	cout << "拷贝构造函数的调用" << endl;

	this->age = p.age;
	//this->heigth = p.heigth;  编译器默认拷贝函数实现的代码
	//深拷贝操作

	this->heigth = new int(*p.heigth);
}
in
```

### 函数重载

- 重载函数的参数个数、参数类型、参数顺序三者必要有一个不相同。返回值类型可相同也可不相同。

### 析构函数

- 与构造函数相反，在对象生命周期结束后被调用。
- 全局变量和static类型的变量，在程序退出后析构函数才被调用。
- new操作符动态的创建了一个对象，只有当delete进行释放后，析构函数才会被调用。

### 指针

地址传递

```cpp
int main() {
	int a = 1, b = 2;
	swap(&a, &b);

	cout << a << " " << b << " "<<endl;
	return 0;
}
//由于形参不改变实参
void swap(int* x, int* y) {
	int t = *x;
	*x = *y;
	*y = t;
}
```

### 指针数组冒泡排序

```cpp
#include<iostream>

using namespace std;

void bubbleSort(int *arr,int len);

int main() {
	int arr[] = { 2,4,7,3,7,31,8,4,5,7 };

	int len = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, len);

	for (int i = 0; i < len; i++) {
		cout << *(arr+i) << endl;
	}
	return 0;
}

void bubbleSort(int* arr, int len)
{
	int t;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j+1]) {
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

```

### 结构体数组

```cpp
struct Student s[5] =
	{
		{"张三",18,80},
		{"李四", 20, 78},
		{"林青霞",34,86},
		{"沈长生", 22, 88},
		{"沈重", 32, 88},
	};
```

### 结构体指针

```cpp
Student* p = s;
for (int i = 0; i < 5; i++){

		cout << "姓名：" << (p + i)->name << "\tage:" << (p + i)->age << "\tscore:" << (p + i)->score << endl;
	}
```

### 嵌套结构体以及地址传递

```cpp
#include<iostream>
#include<string>

using namespace std;

struct Student
{
	string name;
	int age;
	int score;

};

struct teacher
{
	int id;
	string name;
	int age;
	Student *stu;
};

int main()
{
	struct Student s[5] =
	{
		{"张三",18,80},
		{"李四", 20, 78},
		{"林青霞",34,86},
		{"沈长生", 22, 88},
		{"沈重", 32, 88},
	};

	teacher t = { 1102,"wangwu",46,s};

	cout << t.age << "\t" << t.id << "\t" << t.name << "\t" << t.stu[2].name << endl; //或者(t.stu+2)->name
	/*for (int i = 0; i < 5; i++){

		cout << "姓名：" << (p + i)->name << "\tage:" << (p + i)->age << "\tscore:" << (p + i)->score << endl;
	}*/

	/*for (int i = 0; i < 5; i++) {
		cout << "姓名：" <<s[i].name<< "\tage:"<<s[i].age<<"\tscore:"<<s[i].score<<endl;
	}
	*/
	return 0;

}
```

### 不要返回局部变量的地址

```cpp
int* function();

int main() {

	int* p = function();

	cout << *p << " " << p<<endl;//第一次编译器会保留局部变量的值 第二次就不再保留
	cout << *p << " " << p;

	return 0;

}

int* function()
{
	int a = 10;
	return &a;
}
结果：
10 00D7FA00
2041686416 00D7FA00
```

### 初始化列表

- 作用：c++提供初始化列表语法，用来初始化属性
- 语法`构造函数（）：属性1（值），属性2（值）。。。{}`
- 示例：

```cpp
Person(string name, string pName):m_Name(name),m_Phone(pName)
	{
		cout << "person带参构造" << endl;
	}
```

### 类对象作为类成员

```cpp
#include<iostream>
#include<string>
using namespace std;
class Phone {
public:
	string m_PName;
	Phone(string pName) {
		m_PName = pName;
		cout << "Phone带参构造" << endl;
	}
	/*Phone() {
		cout << "Phone无参构造" << endl;
	}*/
};
class Person {

public:
	string m_Name;

	Phone m_Phone;
	//Phone m_Phone = pName; == Phone m_Phone = Phone(pName);
	Person(string name, string pName):m_Name(name),m_Phone(pName)
	{
		cout << "person带参构造" << endl;
	}
	/*Person(string name, string pName)
	{
		m_Name = name;
		m_Phone = Phone(pName);
		cout << "person带参构造" << endl;
	}*/
};
int main() {
	Person p("张胜男", "iphone"); //"iphone"存在于p.m_Phone类中
	cout << p.m_Name << "拿着：" << p.m_Phone.m_PName << endl;
	return 0;
}
```

### 静态成员

### 静态成员变量

1. 所有对象都共享同一份数据
2. 编译阶段就分配内存
3. 类内声明，类外初始化操作
4. 不属于某个对象上，所有对象都共享一份数据。
5. 所以有两种访问方式
6. 通过对象访问
7. 通过类名访问

```cpp
class animal
{
public:
	static int a;
};
int animal::a = 100;
int main() {
	animal x;
	x.a = 120;
	animal y;
	cout << "x.a:" << x.a << endl;
	cout << "y.a:" << y.a << endl;
	cout << "animal::a" << animal::a << endl;
	return 0;
}//结果 120 120
```

### 静态成员函数

1. 所有对象共享同一个函数
2. 静态成员函数只能访问静态成员变量

```cpp
class animal
{
public:
	static int a;
	static void setB(int bb);
	static int getB();
private:
	static int b;

};
int animal::a = 100;
int animal::b = 200;
int main() {
	animal x;
	x.a = 120;
	animal y;
	x.setB(220);

	cout << "x.a:" << x.a << endl;
	cout << "y.a:" << y.a << endl;
	cout << "animal::a" << animal::a << endl;
	cout << "-------------------" << endl;
	cout << "x.b: " << x.getB() << endl;
	cout << "y.b: " << y.getB() << endl;
	return 0;
}

void animal::setB(int bb)
{
	b = bb;
}

int animal::getB()
{
	return b;
}
```

- 成员变量和函数是分开存储的，成员变量存储在类中，空类占一个字节内存

### this指针

用途：

- 当形参和成员变量同名时，可用this来区分。
- 在类的非静态成员函数中返回对象本身可用 return *this；

```cpp
class person {
public:
	int age;

	person(int age) {
		this->age = age;
	}

	person& personAddAge(int age)
	{
		this->age += age;
		return *this;
	};
};
int main() {

	person p1(18);
	p1.personAddAge(2).personAddAge(4);//链式编程思想
	cout << p1.age << endl;
	return 0;
}

```

- 返回需要用引用来调用

### const修饰

```cpp
	void showClassAge() const{  //const person *const this
		if (this == NULL)
			return;
		//m_Name = "liuxunzi";
		//m_Age = 100;
		cout << m_Name<<" "<< m_Age << endl;

	}
```

### mutable 修饰

- 特殊变量，即使在常函数中也可修改这个值，加关键字mutable

```cpp
class person {

public:
	int m_Age;
	mutable string m_Name;
	void showClassName() {

		cout << "this is 'person' class!" << endl;
	}

	void showClassAge() const{  //const person *const this
		if (this == NULL)
			return;
		m_Name = "liuxunzi";
		//m_Age = 100;
		cout << m_Name<<" "<< m_Age << endl;

	}
};
```

### 常对象

- 使用const修饰对象，变成常对象。

```cpp
const person* p = new person();

	p->showClassAge();
```

- 常对象只能掉用常函数

```cpp
const person* p = new person();
	//p->m_Age = 100;
	p->m_Name = "hello";
	p->showClassAge();
```

- 常对象指针指向不能修改

### 友元

- 友元的三种实现，

### 全局函数做友元

```cpp
class Building {
	friend void goodGay(Building* b);
public:
	string m_SittingRoom;//客厅
	Building() {
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
private:
	string m_BedRoom;//卧室

};

void goodGay(Building *b) {

	cout << "GoodGay正在访问" << b->m_BedRoom << endl;
	cout << "GoodGay正在访问" << b->m_SittingRoom << endl;
}

int main() {

	Building* b = new Building();
	Building bb;
	goodGay(b);
	goodGay(&bb);
	return 0;
}
```

### 类做友元

```cpp
class Building{
	friend class GodGay;
public:
	Building();
	string m_SittingRoom;
private:
	string m_Bedroom;
};

class GodGay{

public:
	GodGay();
	void visit();
	Building* b;
};

GodGay::GodGay()
{
	b = new Building();
}

void GodGay::visit() {

	cout << "好基友正在访问：" << b->m_SittingRoom << endl;
	cout << "好基友正在访问：" << b->m_Bedroom << endl;

}

Building::Building() {
	m_SittingRoom = "客厅";
		m_Bedroom = "卧室";
}

int main() {
	GodGay* g = new GodGay();
	g->visit();

	return 0;
}
```

### 成员函数做友元

### 运算符重载

### 1.重载+

1. 成员函数

```cpp
#include<iostream>

using namespace std;
class person
{
	friend person addPerson(person A, person B);
public:
	person();
	person(int a,int b);
	~person();
	void show();
	person operator+(person& p);
private:
	int m_a;
	int m_b;

};
person::person()
{
}

person::~person()
{
}
person::person(int a, int b) {
	m_a = a;
	m_b = b;
}
void person::show()
{
	cout << "m_a: " << m_a << " m_b: " << m_b << endl;
}
person person::operator+(person& p)
{
	person pp;
	pp.m_a = this->m_a + p.m_a;
	pp.m_b = this->m_b + p.m_b;
	return pp;
}
int main() {
	person A(12, 12);
	person B(22, 22);
	person P;
	P = A+B;
	P.show();
	A.show();
	return 0;
}
```

1. 全局函数

```cpp
#include<iostream>

using namespace std;
class person
{
	friend person operator+(person& A, person& B);
public:
	person();
	person(int a,int b);
	~person();
	void show();
	//person operator+(person& p);
private:
	int m_a;
	int m_b;

};
person::person()
{
}

person::~person()
{
}
person::person(int a, int b) {
	m_a = a;
	m_b = b;
}
void person::show()
{
	cout << "m_a: " << m_a << " m_b: " << m_b << endl;
}
//person person::operator+(person& p)
//{
//	person pp;
//	pp.m_a = this->m_a + p.m_a;
//	pp.m_b = this->m_b + p.m_b;
//	return pp;
//}

person operator+(person& A, person& B) {
	person p;
	p.m_a = A.m_a + B.m_a;
	p.m_b = A.m_b + B.m_b;

	return p;
}
int main() {
	person A(10, 10);
	person B(20, 20);
	person P;
	//P = A+B;
	P = A + B;
	P.show();
	A.show();
	return 0;
}
```

### 2.重载<<

```cpp
ostream& operator<<(ostream &cout, person& p) {

	cout << "m_a: " << p.m_a << " m_b: " << p.m_b;
	return cout;
}
cout << P << endl;
```

### 3.重载++

```cpp
MyInteger operator++(int); //int 表示占位參數，可用於區分前置和後置遞增
```

```cpp
	MyInteger& operator++() {   //++mi
		m_num++;
		return *this;
	}
	//重载后置++
	MyInteger operator++(int) {  //mi++
		MyInteger temp = *this;
		m_num++;
		return temp;

	}
```

### 4.重载=

```cpp
#include<iostream>

using namespace std;

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);
public:
	Person();
	Person(int age);
	~Person();
	void operator=(Person &p);

private:
	int* m_age;
};

Person::Person()
{
	cout << "默认构造函数" << endl;

}
Person::Person(int age)
{
	cout << "参数构造函数" << endl;
	m_age = new int(age);
}

Person::~Person()
{
	if (m_age != NULL)
	{
		delete m_age;
		m_age = NULL;
	}
	cout << "析构函数" << endl;
}
void Person::operator=(Person& p)
{
	/*if (m_age != NULL)
	{
		delete m_age;
		m_age = NULL;
	}*/
	m_age = new int(*p.m_age);
}
ostream& operator<<(ostream& cout,Person& p) {
	cout << "age:" << *(p.m_age);
	return cout;
}

int main() {

	Person p1(10);
	Person p2(20);
	cout << p1 << endl;
	cout << p2 << endl;
	p1 = p2;
	cout << p1 << endl;
	cout << p2 << endl;

	return 0;
}
```

### 5.重載== ！=

```cpp
bool operator==(Person& p1, Person& p2) {
	if (*p1.m_age == *p2.m_age)
	{
		//cout << "true" << endl;
		return true;
	}
	else
	{
		/*cout << "false" << endl;*/
		return false;
	}
}
bool operator!=(Person& p1, Person& p2) {
	if (*p1.m_age != *p2.m_age)
	{
		//cout << "true" << endl;
		return true;
	}
	else
	{
		/*cout << "false" << endl;*/
		return false;
	}
}
```

### 6.重載（）和匿名函数对象

```cpp
class Myprint {
public:
	void operator()(string name) {
		cout << name << endl;
	}

};

int main() {

	Myprint myprint;
	myprint("hello");
    Myprint()("hello");
	return 0; //匿名函数对象
}
```

### 继承

![https://cdn.nlark.com/yuque/0/2020/png/1399983/1595237563938-762177b9-dc74-42e5-a570-cecd074a3fde.png](https://cdn.nlark.com/yuque/0/2020/png/1399983/1595237563938-762177b9-dc74-42e5-a570-cecd074a3fde.png)

### java中：

[Untitled](https://www.notion.so/84940bf6c2cd4931858a7b34fa2b76e7)

### C+++中

[Untitled](https://www.notion.so/48fb8daeba4c4c08b016555fad932614)