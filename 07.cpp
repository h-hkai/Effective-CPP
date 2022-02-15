class TimeKeeper {
   public:
    TimeKeeper();
    ~TimeKeeper();
    ...;
};

class AtomicClock : public TimeKeeper {
    ...;
};
class WaterClock : public TimeKeeper {
    ...;
};
class WristWatch : public TimeKeeper {
    ...;
};

TimeKeeper*
getTimeKeeper();  // 返回一个指针指向一个TimeKeeper派生类的动态分配对象

TimeKeeper* ptk =
    getTimeKeeper();  // 从TimeKeeper继承体系，获得一个动态分配对象
...;
delete ptk;

class TimeKeeper {
   public:
    TimeKeeper();
    virtual ~TimeKeeper();
    ...;
};
TimeKeeper* ptk = getTimeKeeper();
...;
delete ptk;  // 现在行为正确

class Point {
   public:
    Point(int XCoord, int yCoord);
    ~Point();

   private:
    int x, y;
};

class SpecialString : public std::string {  // 馊主意！ std::string有个
    ...;                                    // non-virtual析构函数
};

SpecialString* pss = new SpecialString("Impending Doom");
std::string* ps;
...;
ps = pss;  // SpecialString* => string*
...;
delete ps;  // 未有定义！现实中*ps的SpecialString资源会泄露，
            // 因为SpecialString析构函数没有被调用

class AWOV {
   public:
    virtual ~AWOV() = 0;  // 声明pure virtual析构函数
};

AWOV::~AWOV() {}