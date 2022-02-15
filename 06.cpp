class HomeForSale {
    ...
}

HomeForSale h1;
HomeForSale h2;
HomeForSale h3(h1);  // 不允许通过编译
h1 = h2;             // 不允许通过编译

class HomeForSale {
   public:
    ...;

   private:
    ...;
    HomeForSale(const HomeForSale&);  // 只有声明，不去实现
    HomeForSale& operator=(const HomeForSale&);
};

class Uncopyable {
   protected:
    Uncopyable() {}  // 允许derive对象构造和析构
    ~Uncopyable() {}

   private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);  // 但阻止copying
};

class HomeForSale : private Uncopyable {
    ...
};
