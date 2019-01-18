#include <stdlib.h>
#include <iostream>
using namespace std;
namespace A{
    int x =1;
    void fun(){
        cout << 'x' << endl;
    }
}
namespace B{
    int x = 2;
    void fun(){
        cout << "2A" << endl;
    }
}

int main(void)
{
    std::cout << "hello" << '\n';
    cout << A::x << endl;
    B::fun();
}