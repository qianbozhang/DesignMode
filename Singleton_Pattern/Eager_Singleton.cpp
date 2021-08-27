#include<iostream>
using namespace std;



/*
饿汉式：在类创建的同时就已经创建好一个静态的对象供系统使用，以后不再改变，所以天生是线程安全的。
*是否 Lazy 初始化：否
*是否多线程安全：是
*实现难度：易

描述：这种方式比较常用，但容易产生垃圾对象。
优点：没有加锁，执行效率会提高。
缺点：类加载时就初始化，浪费内存。
它基于 classloader 机制避免了多线程的同步问题，不过，instance 在类装载时就实例化，虽然导致类装载的原因有很多种，
在单例模式中大多数都是调用 getInstance 方法， 但是也不能确定有其他的方式（或者其他的静态方法）导致类装载，这时
候初始化 instance 显然没有达到 lazy loading 的效果。
*/

class Eager_Singleton
{
public:
    static Eager_Singleton& getInstance()
    {
        static Eager_Singleton object;
        return  object;
    }

    void printHello()
    {
        cout<<"hello Eager Singleton!"<<endl;
    }
protected:
    class Creator
    {
    public:
        Creator() 
        { 
            cout<<"Creator()"<<endl;
            Eager_Singleton::getInstance().printHello(); 
        }
        ~Creator(){ cout<<"~Creator()"<<endl; }
    };

private:
    Eager_Singleton() { cout<<"Eager_Singleton()"<<endl; }
    ~Eager_Singleton() { cout<<"~Eager_Singleton()"<<endl; }
    //实例化
    static Creator _C;

};

int main(int argc, char const *argv[])
{
    /* code */
    cout<<"start"<<endl;
    for(int i = 5; i >= 0; i--){
        // Eager_Singleton& test = Eager_Singleton::getInstance();
        Eager_Singleton::getInstance().printHello();
    }
    
    return 0;
}

