#include <string>

using namespace std;

#define ASPECT_RATIO 1.653

const double AspectRatio = 1.63;

const char* const authorName = "Scott Meyers";

const string authorName("Scott Meyers");

class GamePlayer {
   private:
    static const int NumTurns = 5;
    int scores[NumTurns];
};

const int GamePlayer::NumTurns;

class ConstEstimate {
   private:
    static const double FudgeFactor;
};

const double ConstEstimate::FudgeFactor = 1.35;

class GamePlayer {
   private:
    enum { NumTurns = 5 };

    int scores[NumTurns];
};

#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

int a = 5, b = 0;
CALL_WITH_MAX(++a, b);
CALL_WITH_MAX(++a, b + 10);

template <typename T>
inline void callWithMax(const T& a, const T& b) {
    f(a > b ? a : b);
}