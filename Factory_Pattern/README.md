#工厂模式属于创建型模式，大致可以分为三类，简单工厂模式、工厂方法模式、抽象工厂模式。
1.简单工厂模式:
示例：有一家生产处理器核的厂家，它只有一个工厂，能够生产两种型号的处理器核。客户需要什么样的处理器核，一定要显示地告诉生产工厂。
A.需要的产品 enum {CORE_A,CORE_B}
B.工厂类SignalCore具备的功能，假设为show()
C.分别实现CORE_A/CORE_B 客制化的功能show()
D.定义芯片工厂类CoreFactory，可以生产两种型号的处理器核，在内部判断 
代码：Simple_Factory.cpp