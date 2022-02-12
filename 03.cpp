char greeting[] = "Hello";
char* p = greeting;				// non-const pointer, non-const data
const char* p = greeting; 		// non-const pointer, const data
char* const p = greeting;		// const pointer, non-const data
const char* const p = greeting; // const pointer, const data

// 被指物是常量的两种情况
void f1(const Widget* pw);
void f2(Widget const * pw);

std::vector<int> vec;
...
const std::vector<int>::iterator iter = vec.begin();

*iter = 10;		// 没问题，iter的值是可以改变的
++iter;			// 错误，iter不可以改变

std::vector<int>::const_iterator cIter = vec.begin();

*iter = 10;		// 错误，值不可以改变
++iter;			// 正确，iter可以改变

// 函数返回一个const对象
class Rational { ... }
const Rational operator* (const Rational& lhs, const Rational& rhs);

// 返回的是一个不可改变的值，主要是为了避免下面情况的出现
Rational a, b, c;
(a * b) = c;

if (a * b = c)		// 预防没有意思的赋值动作

// const 成员函数
// 根据是否是常量可以对函数进行重载
class TextBlock {
public:
	...
	const char& operator[] (std::size_t position) const {
		return text[position];
	}
	char& operator[] (std::size_t position) {
		return text[position];
	}
};

TextBlock tb("Hello");
std::cout << tb[0];
tb[0] = 'x';		// reference to char

const TextBlock ctb("World");
std::cout << ctb[0];
ctb[0] = 'x'; 		// 错误

// passed by reference-to-const
void print(const TextBlock& ctb) {
	std::cout << ctb[0];
	...
}
 
class CTextBlock {
public:
	...
	char& operator[] (std::size_t position) const {
		return pText[position];
	}

private:
	char* pText;
	
};

const CTextBlock cctb("Hello");
char* pc = &cctb[0];

*pc = 'J';

class CTextBlock {
public:
	...
	std::size_t length() const;
private:
	char* pText;
	std::size_t textLength;
	bool lengthIsValid;
};

std::size_t CTextBlock::length() const {
	if (!lengthIsValid) {
		textLength = std::strlen(pText);	// 错误
		lengthIsValid = true;
	}
	return textLength;
}

// 使用mutable解除non-static成员变量的bitwise constness约束
class CTextBlock {
public:
	...
	std::size_t length() const;
private:
	char* pText;
	mutable std::size_t textLength;
	mutable bool lengthIsValid;
};

std::size_t CTextBlock::length() const {
	if (!lengthIsValid) {
		textLength = std::strlen(pText);	// 正确
		lengthIsValid = true;
	}
	return textLength;
}


class TextBlock {
public:
	...
	const char& operator[](std::size_t position) const {
		...		// 边界检验
		...		// 标志数据访问
		...		// 检验数据完整性
		return text[position];
	}
	char& operator[](std::size_t position) {
		...		// 边界检验
		...		// 标志数据访问
		...		// 检验数据完整性
		return text[position];
	}
private:
	std::string text;
};

class TextBlock {
public:
	...
	const char& operator[](std::size_t position) const {
		...		// 边界检验
		...		// 标志数据访问
		...		// 检验数据完整性
		return text[position];
	}
	char& operator[](std::size_t position) {		// 现在只调用const op[]
		return const_cast<char&>(					// 将op[]返回值的const转除
			static_cast<const TextBlock&>(*this)	// 将*this强制转成const类型
				[position]
		);
	}
...
};

