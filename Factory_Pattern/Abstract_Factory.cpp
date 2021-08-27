#include<iostream>
using namespace std;


// //A.define mode
// typedef enum _Core_Type
// {
//     CORE_DEFAULT = 0,
//     CORE_A,
//     CORE_B
// }Core_e;

//b.SignalCore
class SignalCore
{
public:
    virtual void show() = 0;
};

class MultiCore
{
public:
    virtual void show() = 0;
};

//c.SignalCoreA/SignalCoreB
class SignalCoreA :public SignalCore
{
public:
    void show(){ cout<<"Signal A factory!!!"<<endl; }
};

class SignalCoreB :public SignalCore
{
public:
    void show(){ cout<<"Signal B factory!!!"<<endl; }
};

//multiCoreA/multiCoreB
class MultiCoreA :public MultiCore
{
public:
    void show(){ cout<<"Multi A factory!!!"<<endl; }
};

class MultiCoreB :public MultiCore
{
public:
    void show(){ cout<<"Multi B factory!!!"<<endl; }
};




//d.virtual CoreFactory
class CoreFactory
{
public:
    virtual SignalCore* createSignalCore() = 0;
    virtual MultiCore* createMultiCore() = 0;
};

//f.factory a/b
class CoreFactoryA :public CoreFactory
{
public:
    SignalCore* createSignalCore()
    {
        return new SignalCoreA();
    }

    MultiCore* createMultiCore()
    {
        return new MultiCoreA();
    }

};

class CoreFactoryB :public CoreFactory
{
public:
    SignalCore* createSignalCore()
    {
        return new SignalCoreB();
    }

    MultiCore* createMultiCore()
    {
        return new MultiCoreB();
    }
};


 int main(int argc, char const *argv[])
 {
     /* code */
     CoreFactoryA cfa;
     CoreFactoryB cfb;
    {
        SignalCore* sfa = cfa.createSignalCore();
        MultiCore* mfa = cfa.createMultiCore();
        sfa->show();
        mfa->show();
        delete sfa;
        sfa = NULL;
        delete mfa;
        mfa = NULL;
    }

    {
        SignalCore* sfb = cfb.createSignalCore();
        MultiCore* mfb = cfb.createMultiCore();
        sfb->show();
        mfb->show();
        delete sfb;
        sfb = NULL;
        delete mfb;
        mfb = NULL;
    }

     return 0;
 }
 
