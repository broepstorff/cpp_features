#include "cpp11.h"

#include <iostream>
#include <cassert>

//static_assert
static_assert(true, "Static assert");

void TestCpp11Features()
{
    using namespace std;
    cout << "======= cpp11 features ==========\n";
    
    //auto
    {
        auto f = 1.323f;
        auto* pF = &f;
        cout << "Auto: " << f << " " << *pF << endl;
        //todo verify type: something like: cout << "Auto typeof: " << typeof(float) << endl;
    }
    
    //constexpr
    {
        constexpr int a = 3;
        constexpr int b = 5;
        constexpr const int aPlusB = a + b;
        static_assert(aPlusB == 8, "");
        //todo constexpr if ?
    }
    
    //char16_t, char32_t
    {
        char16_t c16 = 'a';
        char32_t c32 = 'b';
        static_assert(sizeof(c16) == 2);
        static_assert(sizeof(c32) == 4);
    }
    
    cout << endl;
}
