int x = 0;
const char* text = "A C-style string";

double d;
std::cin >> d;

class PhoneNumber {...}
class ABEntry {
public:
	ABEntry(const std::string& name, const std::string& address,
			const std::list<PhoneNumber>& phones);
private:
	std::string theName;
	std::string theAddress;
	std::list<PhoneNumber> thePhones;
	int numTimesConsulted;
};
ABEntry::ABEntry(const std::string& name, const std::string& address,
				 const std::list<PhoneNumber>& phones) {
	theName = name;				// 赋值
	thePhones = phones;
	theAddress = address;
	numTimesConsulted = 0;		// 初始化
}

// member initialization list
ABEntry::ABEntry(const std::string& name, const std::string& address,
				 const std::list<PhoneNumber>& phones)
	:theName(name),				// 现在这些都是初始化
	 thePhones(phones),
	 theAddress(address),
	 numTimesConsulted(0) 
{}

ABEntry::ABEntry()
	:theName(),				// 调用theName的default构造函数
	 thePhones(),
	 theAddress(),
	 numTimesConsulted(0)	// 记得将numTimesConsulted显示初始化为0
{}

/*
所谓static对象，其寿命从构造出来直到程序结束为止，因此stack和heap除外。
local static对象： 函数内的static对象
non-local static对象：global对象，定义于namespace作用域的对象，
					 在class内，在file作用域内的对象

所谓编译单元是指产出单一目标文件的那些源码。基本上它是单一源码文件加上其所含入的头文件。
*/

class FileSystem {						// 来自你的程序库
public:
	...
	std::size_t numDisks() const;
	...
};
extern FileSystem tfs;					// 预备给客户使用的对象；
										// tfs代表"the file system"

class Directory {
public:
	Directory( params );
	...
};

Directory::Directory( params ) {
	...
	std::size_t disks = tfs.numDisks();		// 使用tfs对象
}


class FileSystem {...}
FileSystem& tfs() {
	static FileSystem fs;
	return fs;
}
class Directory {...};
Directory::Directory( params ) {
	...
	std::size_t disks = tfs().numDisks();
	...
}
Directory& tempDir() {
	static Directory td;
	return td;
}





