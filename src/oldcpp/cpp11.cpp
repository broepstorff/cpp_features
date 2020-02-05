#include "cpp11.h"

#include <iostream>
#include <cassert>

//static_assert
static_assert(true, "Static assert");

void TestCpp11Features()
{
    using namespace std;
    cout << "======= cpp11 features ==========\n";
    
    //todo
    auto f = 1.323f;
    auto* pF = &f;
    cout << "Auto: " << f << " " << *pF << endl;
    //todo verify type: something like: cout << "Auto typeof: " << typeof(float) << endl;
    
    {
        constexpr int a = 3;
        constexpr int b = 5;
        constexpr const int aPlusB = a + b;
        static_assert(aPlusB == 8, "");
        //todo constexpr if ?
    }
    
    cout << endl;
}
