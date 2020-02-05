#include "oldcpp.h"

#define SAFE_DELETE(pointer) \
    delete pointer; \
    pointer = NULL;


int PassByVal(float x)
{
    return (int)x+1;
}

int PassByRef(float &x)
{
    return (int)x+1;
}

int Overload(int i)
{
    return i+2;
}

int Overload(const std::string &s)
{
    return s.size();
}

int DefaultVal(int i)
{
    return i+3;
}

BasicClass::BasicClass(int x)
: pX(NULL)
, y(2)
{
    pX = new int(x);
}

BasicClass::~BasicClass()
{
    delete pX;
}

int BasicClass::GetX()
{
    return *pX;
}

class ForwardDeclared
{
public:
    ForwardDeclared() { data = 6; }
    int data;
};

ForwardDeclared* MakeForwardDeclared()
{
    return new ForwardDeclared();
}
    
void TestOldCppFeatures()
{
    using namespace std;
    cout << "======= old_cpp_features ==========\n";
    
    using namespace std;
    
    //Functions
    {
        float f = 1;
        string s = "str";
        cout << "PassByVal: " << PassByVal(f) << endl;
        cout << "PassByRef: " << PassByRef(f) << endl;
        cout << "Overload(int): " << Overload(1) << endl;
        cout << "Overload(string): " << Overload(s) << endl;
        cout << "DefaultVal: " << DefaultVal() << endl;
        cout << "InlineFunc: " << InlineFunc(1) << endl;
    }
    
    //Classes
    {
        //Inheritance
        BasicClass basicClass(1);
        cout << "BasicClass: " << basicClass.GetX() << " " << basicClass.GetY() << " " << basicClass.GetZ() << endl;
        Derived derivedClass(2);
        cout << "Derived: " << derivedClass.GetZ() << endl;
        MultipleInheritance mi(3);
        cout << "Multiple Inheritance: " << mi.GetZ() << " " << mi.GetOtherData() << endl;
        ForwardDeclared *pFD = MakeForwardDeclared();
        cout << "ForwardDeclared: " << pFD->data << endl;
        SAFE_DELETE(pFD);
        
        //Casting
        BasicClass* cCast = (BasicClass*)&derivedClass;
        cout << "C-Cast: " << cCast->GetX() << " " << cCast->GetY() << " " << cCast->GetZ() << endl;
        BasicClass *pStaticCast = static_cast<BasicClass*>(&derivedClass);
        cout << "Static Cast: " << pStaticCast->GetX() << " " << pStaticCast->GetY() << " " << pStaticCast->GetZ() << endl;
        Derived *pDnyamicDownCast = dynamic_cast<Derived*>(pStaticCast);
        assert(pDnyamicDownCast);
        cout << "Dynamic Downcast: " << pDnyamicDownCast->GetZ() << endl;
        BasicClass *pDynamicUpCast = dynamic_cast<BasicClass*>(&derivedClass);
        assert(pDynamicUpCast);
        cout << "Dymamic Upcast: " << pDynamicUpCast->GetZ() << endl;
        Derived *pInvalidDynamicCast = dynamic_cast<Derived*>(&basicClass);
        assert(!pInvalidDynamicCast);
    }
    
    cout << endl;
}
