#include <iostream>
#include <iomanip>

class test
{
    public:
        test(int x) : p(x) {}
        test& f() { return *this; }
        test& precision(int x) { p = x; return *this; }
        void o() { std::cout << p << std::endl; }
    private:
        int p;
};

int main()
{
    int **p = new int* [10];

}