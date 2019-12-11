#include <iostream>

using namespace std;

class class1 {
    int x;
    int y;
    virtual int add() { return x + y; };
    void setX(int x) { this->x = x; }
};
struct struct1 {
    int x;
    int y;
    virtual int add() { return x + y; };
    void setX(int x) { this->x = x; }
};
class class2 : class1 {
};
struct struct2 : struct1 {
};
int main(void)
{
    cout << sizeof(class1) << endl;
    cout << sizeof(class2) << endl;
    cout << sizeof(struct1) << endl;
    cout << sizeof(struct2) << endl;
    return 0;
}