#ifndef oldcpp_h
#define oldcpp_h

#include <string>

void TestOldCppFeatures();

int PassByVal(float x);
int PassByRef(float &x);

int Overload(int i);
int Overload(const std::string &s);

int DefaultVal(int i = 1);

inline int InlineFunc(int i)
{
    return i+4;
}

class BasicClass
{
public:
    BasicClass(int x);
    virtual ~BasicClass();
    
    int GetX();
    inline int GetY()
    {
        return y;
    }
    
    virtual int GetZ() { return 0; }
protected:
    int* pX;
    
private:
    BasicClass() {}
    
    int y;
};

class Derived : public BasicClass
{
public:
    Derived(int x) : BasicClass(x)
    {
        z = 10;
    }
    virtual ~Derived() {}
    
    virtual int GetZ() { return z; }
        
protected:
    int z;
};

class OtherClass
{
public:
    OtherClass() : otherData(5) {}
protected:
    int otherData;
};

class MultipleInheritance : public Derived, OtherClass
{
public:
    MultipleInheritance(int x)
    : Derived(x)
    {}
    
    int GetOtherData() { return otherData; }
};

class ForwardDeclared* MakeForwardDeclared();

#endif //oldcpp_h
