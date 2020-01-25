#include <iostream>

void func()
{
    std::cout << "func()\n";
}

int main()
{
    int a = 32;
    func();
	std::cout << "hello world 2\n" << "a: " << a << "\n";
    return 0;
}
