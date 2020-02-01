#ifndef oldcpp_h
#define oldcpp_h

#include <iostream>

int BasicFunction(float x)
{
    return (int)x+1;
}

class BasicClass
{
public:
    BasicClass(int x)
        : pIntData(NULL)
    {
        pIntData = new int(x);
    }
    
    ~BasicClass()
    {
        delete pIntData;
    }
    
    int GetData()
    {
        return *pIntData;
    }
    
protected:
    int* pIntData;
};

void TestOldCppFeatures()
{
    using namespace std;
    cout << "======= old_cpp_features ==========\n";
    
    using namespace std;
    cout << "Basic Function: " << BasicFunction(1) << endl;
    
    BasicClass basicClass(1);
    cout << "Basic class: " << basicClass.GetData() << endl;
    
    cout << endl;
}

#endif /* oldcpp_h */
