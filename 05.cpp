class Empty { };

class Empty {
public:
	Empty() { ... }
	Empty(const Empty& rhs) { ... }
	~Empty() { ... }

	Empty& operator=(const Empty& rhs) { ... }
};


Empty e1;

Empty e2(e1);
e2 = e1;

template<typename T>
class NamedObject {
public:
	NamedObject(const char* name, const T& value);
	NamedObject(const std::string& name, const T& value);
	...

private:
	std::string nameValue;
	T objectValue;
};

NamedObject<int> no1("Smallest Prime Number", 2);
NamedObject<int> no2(no1);

template<class T>
class NameObject {
public:
	NameObject(std::string& name, const T& value);
	...

private:
	std::string& nameValue;
	const T objectValue;
};

std::string newDog("Persephone");
std::string oldDog("Satch");
NamedObject<int> p(newDog, 2);

NamedObject<int> s(oldDog, 36);

p = s;		// 编译器拒绝编译这一行赋值动作