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

//d.virtual CoreFactory
class CoreFactory
{
public:
    virtual SignalCore* createCore() = 0;
};

//f.factory a/b
class CoreFactoryA :public CoreFactory
{
public:
    SignalCore* createCore()
    {
        return new SignalCoreA();
    }

};

class CoreFactoryB :public CoreFactory
{
public:
    SignalCore* createCore()
    {
        return new SignalCoreB();
    }
};


 int main(int argc, char const *argv[])
 {
     /* code */
     CoreFactoryA cfa;
     CoreFactoryB cfb;

     SignalCore* fa = cfa.createCore();
     fa->show();
     delete fa;
     fa = NULL;

     SignalCore* fb = cfb.createCore();
     fb->show();
     delete fb;
     fb = NULL;

     return 0;
 }
 
