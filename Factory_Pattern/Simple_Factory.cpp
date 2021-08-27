#include<iostream>
using namespace std;


//A.define mode
typedef enum _Core_Type
{
    CORE_DEFAULT = 0,
    CORE_A,
    CORE_B
}Core_e;

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

//d.CoreFactory
class CoreFactory
{
public:
    SignalCore* createCore(Core_e core);
};

 SignalCore* CoreFactory::createCore(Core_e core)
 {
     switch (core)
     {
        case CORE_A:
        {
            return new SignalCoreA();
        }
        case CORE_B:
        {
            return new SignalCoreB();
        }
        case CORE_DEFAULT:
        {
            return NULL;
        }
     }
     return NULL;
 }


 int main(int argc, char const *argv[])
 {
     /* code */
     //factory
     CoreFactory cf;// singleton?
     SignalCore* sca = cf.createCore(CORE_A);
     sca->show();
     delete sca;
     sca = NULL;

     SignalCore* scb = cf.createCore(CORE_B);
     scb->show();
     delete scb;
     scb = NULL;

     return 0;
 }
 
