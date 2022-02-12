#include <string>

using namespace std;

// define 发生在预处理阶段
#define ASPECT_RATIO 1.653

const double AspectRatio = 1.63;

// 常量指针
const char* const authorName = "Scott Meyers";

const string authorName("Scott Meyers");

// class专属常量
class GamePlayer {
private:
    static const int NumTurns = 5;	// 常量声明
    int scores[NumTurns];
};

const int GamePlayer::NumTurns; 	// 常量定义

class ConstEstimate {
private:
    static const double FudgeFactor;
};

const double ConstEstimate::FudgeFactor = 1.35;

// the enum hack
class GamePlayer {
private:
    enum { NumTurns = 5 };

    int scores[NumTurns];
};


#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

int a = 5, b = 0;
CALL_WITH_MAX(++a, b);	// a被加2次
CALL_WITH_MAX(++a, b + 10);		// a被加1次

template <typename T>
inline void callWithMax(const T& a, const T& b) {
    f(a > b ? a : b);
}