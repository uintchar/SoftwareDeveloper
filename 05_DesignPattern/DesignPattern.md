- [1. 设计模式简介](#1-设计模式简介)
  - [1.1. 设计模式的用途](#11-设计模式的用途)
  - [1.2. 设计模式的原则](#12-设计模式的原则)
  - [1.3. 设计模式的分类](#13-设计模式的分类)
- [2. UML类图](#2-uml类图)
  - [2.1. UML模型结构](#21-uml模型结构)
  - [2.2. UML类的表示](#22-uml类的表示)
  - [2.3. UML类图常用关系](#23-uml类图常用关系)
    - [2.3.1. 泛化 (Generalization)](#231-泛化-generalization)
    - [2.3.2. 实现 (Realization)](#232-实现-realization)
    - [2.3.3. 关联 (Association)](#233-关联-association)
    - [2.3.4. 聚合 (Aggregation)](#234-聚合-aggregation)
    - [2.3.5. 组合 (Composition)](#235-组合-composition)
    - [2.3.6. 依赖(Dependency)](#236-依赖dependency)
- [3. 创建型模式](#3-创建型模式)
  - [3.1. 简单工厂模式](#31-简单工厂模式)
    - [3.1.1. 概念](#311-概念)
    - [3.1.2. 应用场景](#312-应用场景)
    - [3.1.3. 具体实现](#313-具体实现)
    - [3.1.4. 优缺点](#314-优缺点)
    - [3.1.5. C++代码](#315-c代码)
  - [3.2. 工厂模式](#32-工厂模式)
    - [3.2.1. 概念](#321-概念)
    - [3.2.2. 应用场景](#322-应用场景)
    - [3.2.3. 具体实现](#323-具体实现)
    - [3.2.4. 优缺点](#324-优缺点)
    - [3.2.5. C++代码](#325-c代码)
  - [3.3. 抽象工厂模式](#33-抽象工厂模式)
    - [3.3.1. 概念](#331-概念)
    - [3.3.2. 应用场景](#332-应用场景)
    - [3.3.3. 具体实现](#333-具体实现)
    - [3.3.4. 优缺点](#334-优缺点)
    - [3.3.5. C++代码](#335-c代码)
  - [3.4. 单例模式](#34-单例模式)
    - [3.4.1. 概念](#341-概念)
    - [3.4.2. 应用场景](#342-应用场景)
    - [3.4.3. 具体实现](#343-具体实现)
    - [3.4.4. 优缺点](#344-优缺点)
    - [3.4.5. C++代码](#345-c代码)
  - [3.5. 建造者模式](#35-建造者模式)
    - [3.5.1. 概念](#351-概念)
    - [3.5.2. 应用场景](#352-应用场景)
    - [3.5.3. 具体实现](#353-具体实现)
    - [3.5.4. 优缺点](#354-优缺点)
    - [3.5.5. C++代码](#355-c代码)
  - [3.6. 原型模式](#36-原型模式)
    - [3.6.1. 概念](#361-概念)
    - [3.6.2. 应用场景](#362-应用场景)
    - [3.6.3. 具体实现](#363-具体实现)
    - [3.6.4. 优缺点](#364-优缺点)
    - [3.6.5. C++代码](#365-c代码)
- [4. 结构型模式](#4-结构型模式)
- [5. 行为型模式](#5-行为型模式)

参考资料：
<https://blog.csdn.net/sinat_21107433/article/details/103021839>
<https://www.runoob.com/design-pattern/design-pattern-intro.html>
<http://c.biancheng.net/view/1317.html>

# 1. 设计模式简介

## 1.1. 设计模式的用途

## 1.2. 设计模式的原则

- **单一职责原则**
  - 概念：一个对象应该只包含单一的职责，并且该职责被完整地封装在一个类中。就一个类而言，应该仅有一个引起它变化的原因；
  - 目的：软件设计过程中，如果一个类承担的职责越多，那么它被复用的可能性越小。另一方面，如果一个类承担的职责越多，各个职责耦合在一起，修改其中一个职责可能“牵一发而动全身”；高内聚，低耦合。
  - 方法：将职责进行分离，不同的职责封装在不同的类中。

- **开放封闭闭原则（Open Close Principle）**
  - 概念：对扩展开放，对修改关闭。在程序需要进行拓展的时，不能去修改原有的代码，实现一个热插拔的效果；
  - 目的：为了使程序的扩展性好，易于维护和升级；
  - 方法：使用接口和抽象类。

- **里氏代换原则（Liskov Substitution Principle）**
  - 概念：任何基类可以出现的地方，子类一定可以出现；
  - 目的：LSP 是继承复用的基石，只有当派生类可以替换掉基类，且软件单位的功能不受到影响时，基类才能真正被复用，而派生类也能够在基类的基础上增加新的行为。里氏代换原则是对开闭原则的补充；
  - 方法：实现开闭原则的关键步骤就是抽象化，而基类与子类的继承关系就是抽象化的具体实现，所以里氏代换原则是对实现抽象化的具体步骤的规范。

- **依赖倒转原则（Dependence Inversion Principle）**
  - 概念：针对接口编程，不要针对实现编程。高层模块不应该依赖低层模块，它们都应该依赖抽象。抽象不应该依赖于细节，细节应该依赖于抽象

- **接口隔离原则（Interface Segregation Principle）**
  - 概念：使用多个隔离的接口，比使用单个接口要好。客户端不应该依赖那些它不需要的接口；
  - 目的：降低类之间的耦合度。

- **迪米特法则，又称最少知道原则（Demeter Principle）**
  - 概念：一个实体应当尽量少地与其他实体之间发生相互作用，使得系统功能模块相对独立。

- **合成复用原则（Composite Reuse Principle）**
  - 概念：尽量使用关联、聚合、组合的方式，而不是使用继承来达到复用的目的。
  - 目的：对象组合可以使系统更加灵活（黑箱复用），降低类与类之间的耦合度，一个类的变化尽可能不影响其他类。如果要使用继承，则需考虑里氏代换原则和依赖倒转原则。继承关系会破坏系统的封装性，会将基类的实现细节暴露给子类（白箱复用），如果基类发生改变，那么子类的实现也不得不改变。

## 1.3. 设计模式的分类

- **创建型模式：**
  - 简单工厂模式（Simple Factory Pattern）
  - 工厂模式（Factory Pattern）
  - 抽象工厂模式（Abstract Factory Pattern）
  - 单例模式（Singleton Pattern）
  - 建造者模式（Builder Pattern）
  - 原型模式（Prototype Pattern）

- **结构型模式：**
  - 适配器模式（Adapter Pattern）
  - 桥接模式（Bridge Pattern）
  - 过滤器模式（Filter、Criteria Pattern）
  - 组合模式（Composite Pattern）
  - 装饰器模式（Decorator Pattern）
  - 外观模式（Facade Pattern）
  - 享元模式（Flyweight Pattern）
  - 代理模式（Proxy Pattern）

- **行为型模式：**
  - 责任链模式（Chain of Responsibility Pattern）
  - 命令模式（Command Pattern）
  - 解释器模式（Interpreter Pattern）
  - 迭代器模式（Iterator Pattern）
  - 中介者模式（Mediator Pattern）
  - 备忘录模式（Memento Pattern）
  - 观察者模式（Observer Pattern）
  - 状态模式（State Pattern）
  - 空对象模式（Null Object Pattern）
  - 策略模式（Strategy Pattern）
  - 模板模式（Template Pattern）
  - 访问者模式（Visitor Pattern）

# 2. UML类图

## 2.1. UML模型结构

## 2.2. UML类的表示

## 2.3. UML类图常用关系

![类之间的关系实例](./Figure/DesignPattern/Simples.png)

### 2.3.1. 泛化 (Generalization)

- 含义：类的继承关系。
- 表示：用空心三角和实线，空心三角指向父类。
- 举例：狗和猫都是一种动物。

### 2.3.2. 实现 (Realization)

- 含义：类与接口的关系，表示类是接口所有特征和行为的实现。
- 表示：用空心三角和虚线，空心三角指向接口。
- 举例：狗和猫实现了动物的`eat()`和`run()`的接口。

### 2.3.3. 关联 (Association)

关联是一种拥有关系（has），一个类可以调用另一个类的公有的属性和方法。在类中以成员变量的方式表示。比如老师有自己的学生，知道学生的姓名学号成绩；学生有自己的老师，也知道老师的姓名和所教的科目。关联分为单向关联、双向关联和自关联。

1. **单向关联**

2. **双向关联**

3. **自关联**

4. **多重性关联**

### 2.3.4. 聚合 (Aggregation)

- 含义：整体与部分的关系，部分离开整体后可以单独存在。常用于类的成员变量。
- 表示：带空心菱形和箭头的直线（或没有箭头），菱形挨着整体，箭头指向部分。
- 举例：汽车和轮胎，轮胎是汽车的一部分，但轮胎也可以单独存在。

### 2.3.5. 组合 (Composition)

- 含义：整体与部分的关系，部分离开整体后不可以单独存在，代表整体的对象负责代表部分的对象的生命周期。常用于类的成员变量。
- 表示：带实心菱形和箭头的直线（或没有箭头），菱形挨着整体，箭头指向部分。
- 举例：公司和部门，部门是公司的一部分，但部门不可以单独存在。

### 2.3.6. 依赖(Dependency)

- 含义：是一种使用的关系，即一个类的实现需要另一个类的协助，常用于类方法的局部变量、方法参数等。
- 表示：带箭头的虚线，箭头指向协助的类。
- 举例：Animal的`eat()`方法的参数是`Food`。

# 3. 创建型模式

提供了一种在创建对象的同时隐藏创建逻辑的方式，而不是使用 `new` 运算符直接实例化对象。这使得程序在判断针对某个给定实例需要创建哪些对象时更加灵活。

创建型模式关注对象的创建过程，在软件开发中应用非常广泛。创建型模式描述如何将对象的创建和使用分离，让用户在使用对象过程中无须关心对象的创建细节，从而降低系统耦合度，并且让系统易于修改和扩展。

## 3.1. 简单工厂模式

### 3.1.1. 概念

- 定义一个简单工厂类，它可以根据输入参数的不同创建不同类的实例，被创建的实例通常都具有共同的父类。

### 3.1.2. 应用场景

- 凡是需要生成复杂对象的地方，都可以尝试考虑使用工厂模式来代替。复杂对象指的是类的构造函数参数过多等对类的构造有影响的情况，因为类的构造过于复杂，如果直接在其他业务类内使用，则两者的耦合过重，后续业务更改，就需要在任何引用该类的源代码内进行更改。
- 对于产品种类相对较少的情况，考虑使用简单工厂模式。使用简单工厂模式时不需要关心如何创建对象的逻辑，只需要向简单工厂类提供的创建产品的方法中传入相应参数，就可以很方便地创建所需产品。
- 例子：一个体育用品生产厂（Factory），该工厂可以根据客户需求生产篮球、足球和排球。篮球、足球和排球被称为产品（Product），产品的名称可以被称为参数。

### 3.1.3. 具体实现

- **简单工厂类：** 提供一个生产各种产品的方法（通常为静态`static`方法），负责实现创建所有实例的内部逻辑。该方法根据传入参数（产品名称）创建不同的具体产品类对象，可以被外界直接调用；
- **抽象产品类：** 是简单工厂创建的所有对象的父类，负责描述所有实例共有的公共接口；
- **具体产品类：** 从抽象产品类中派生出多个具体产品类，具体产品类中实现抽象产品类的接口；
- **客户访问类：** 客户只需要知道简单工厂类和抽象产品类，以及具体产品的名称；
![简单工厂模式](./out/Figure/UML/DesignPattern/SimpleFactoryPattern.png)

### 3.1.4. 优缺点

- **优点：**
  - 工厂类提供创建具体产品的方法，并包含一定判断逻辑，客户不必参与产品的创建过程；
  - 客户只需要知道对应产品的参数即可，参数一般简单好记，如数字、字符或者字符串等。
- **缺点：**
  - 违背了开闭原则：假设有一天工厂需要生产一种新的产品，则需要从抽象产品类派生出一个新产品类，并在工厂类的`createProduct`方法中增加的条件分支，即在扩展功能时修改了既有的代码；
  - 简单工厂模式所有的判断逻辑都在工厂类中实现，一旦工厂类设计故障，则整个系统都受之影响。

### 3.1.5. C++代码

- **C++和`static`相关的知识：**
- `static`数据成员：
  - 属于类的全体对象共有；
  - 生命周期不依赖于任何对象，为程序的生命周期；
  - 可以通过类名直接访问公有静态成员变量；
  - 可以通过对象名访问公有静态成员变量；
  - 静态成员变量需要在类外单独进行初始化，`Type className::VarName = value`；
  - 静态成员变量在程序内部位于全局数据区；
- `static`函数成员：
  - 属于类的全体对象共有，没有`this`指针；
  - 只能直接访问静态成员变量和静态成员函数，不能访问非静态成员；
  - 可以通过类名直接访问类的公有静态成员函数；
  - 可以通过对象名访问类的公有静态成员函数；
  - 不能是虚函数，虚函数依靠`vptr`和`vtable`来处理。`vptr`是一个指针，在类的构造函数中创建生成，并且只能用`this`指针来访问它，因为它是类的一个成员，并且`vptr`指向保存虚函数地址的`vtable`。
- 普通成员函数：
  - 属于类的全体对象共有，含有`this`指针；
  - 既可以访问静态成员变量和静态成员函数，又可以访问非静态成员；
  - 不可以通过类名直接访问类的公有静态成员函数；
  - 可以通过对象名访问类的公有静态成员函数；

- **C++和析构函数相关的知识：**
  
- 析构顺序？
  - 派生类 `->` 成员类 `->` 父类；
- 为什么需要把基类的析构函数设置为虚函数？
  - 因为多态。C++中可以使用基类指针或引用指向派生类对象，当使用`delete`删除此基类指针时，若不将析构函数设为虚函数，则会调用基类的析构函数，从而无法正确析构子类对象。
- 虚析构函数的本质？
  - 虚析构其实就是虚函数加上析构函数，本质是会维护一个虚表和指向虚表的指针；
- 纯虚构析构函数？
  - 把成员函数设置为纯虚函数是不想这个类实例化，存在纯虚函数的类称为抽象类，并且这个纯虚函数一般不提供实现。但是如果析构函数是纯虚函数则需要在类定义体之外对其进行实现，因为在其派生类中需要调用父类的析构函数析构父类对象；
- 那么如果父类有纯虚析构函数，子类继承后，怎么定义子类实例呢？
  - 子类需要为自己的析构函数提供定义实现；
- 总结:
  - 如果类会被继承，当作基类，那么一定要把基类析构函数设置为虚函数；
  - 如果类不会被继承，那么不需要把析构函数设置为析构函数，因为会浪费空间，多一个虚表指针。

```cpp {class=line-numbers}
class AbstractProduct
{
public:
  virtual void method()=0;
  virtual ~AbstractProduct()=0;
};

AbstractProduct::~AbstractProduct() { cout << "AbstractProduct的析构函数" << endl; }

class ConcreteProductA : public AbstractProduct
{
public:
  virtual void method() { std::cout << "I am ProductA" << std::endl; }
  virtual ~ConcreteProductA() { cout << "ConcreteProductA的析构函数" << endl; }
};

class ConcreteProductB : public AbstractProduct
{
public:
  virtual void method() { std::cout << "I am ProductB" << std::endl; }
  virtual ~ConcreteProductB() { cout << "ConcreteProductB的析构函数" << endl; }
};

class SimpleFactory
{
public:
  static AbstractProduct *createProduct(const string &productName)
  {
    AbstractProduct *pro = nullptr;
    if (productName == "ProductA")
      pro = new ConcreteProductA();
    else if (productName == "ProductB")
      pro = new ConcreteProductB();
    return pro;
  }
};

int main()
{
  AbstractProduct *pro1 = SimpleFactory::createProduct("ProductA");
  AbstractProduct *pro2 = SimpleFactory::createProduct("ProductB");
  if (!pro1) pro1->method();
  if (!pro2) pro2->method();
  delete pro1;
  delete pro2;
  return 0;
}
```

## 3.2. 工厂模式

### 3.2.1. 概念

- 定义一个用于创建对象的接口，但是让其子类决定将哪一个类实例化。工厂方法模式让一个类的实例化延迟到其子类。

### 3.2.2. 应用场景

- 客户不关心创建产品的细节，只关心创建产品的工厂名，而不知道具体的产品名，创建具体产品的任务由多个具体子工厂中的某一个完成，而抽象工厂只提供创建产品的接口；
- 当需要生成的产品不多且不会增加，一个具体工厂类就可以完成任务时，可删除抽象工厂类。这时工厂方法模式将退化到简单工厂模式；
- 日志记录器：记录可能记录到本地硬盘、系统事件、远程服务器等，用户可以选择记录日志到什么地方；
- 数据库访问，当用户不知道最后系统采用哪一类数据库，以及数据库可能有变化时；
- 设计一个连接服务器的框架，需要三个协议，`POP3`、`IMAP`、`HTTP`，可以把它们作为产品类，共同实现一个接口。

### 3.2.3. 具体实现

- **抽象工厂类：** 提供创建产品的公共接口，调用者通过该接口来创建产品；
- **具体工厂类：** 用于实现抽象工厂中的抽象方法，完成具体传品的创建；
- **抽象产品类：** 定义了产品的规范，描述了产品的属性和功能；
- **具体产品类：** 用于实现抽象产品类中定义的公共接口，由具体工厂类创建具体产品实例，与具体工厂类一一对应；
- **客户访问类：** 只需要知道抽象工厂和抽象产品，以及生产具体产品的具体工厂的名字；
![工厂模式](./out/Figure/UML/DesignPattern/FactoryPattern.png)

### 3.2.4. 优缺点

- **优点：**
  - 用户只需要知道具体工厂的名称就可得到所要的产品，无须知道产品的具体创建过程；
  - 灵活性增强，对于新产品的创建，只需多写一对相应的具体工厂类和具体产品类，无须修改原有类，满足开闭原则；
  - 典型的解耦框架。高层模块只需要知道产品的抽象类，无须关心其他实现类，满足迪米特法则、依赖倒置原则和里氏替换原则。
- **缺点：**
  - 类的个数容易过多，增加复杂度；
  - 增加了系统的抽象性和理解难度；
  - 抽象产品只能生产一种产品，此弊端可使用抽象工厂模式解决。

### 3.2.5. C++代码

```cpp {class=line-numbers}
class AbstractProduct
{
public:
  virtual void method()=0;
  virtual ~AbstractProduct()=0;
};

AbstractProduct::~AbstractProduct() { cout << "AbstractProduct的析构函数" << endl; }

class ConcreteProductA : public AbstractProduct
{
public:
  virtual void method() { std::cout << "I am ProductA" << std::endl; }
  virtual ~ConcreteProductA() { cout << "ConcreteProductA的析构函数" << endl; }
};

class ConcreteProductB : public AbstractProduct
{
public:
  virtual void method() { std::cout << "I am ProductB" << std::endl; }
  virtual ~ConcreteProductB() { cout << "ConcreteProductB的析构函数" << endl; }
};

class AbstractFactory
{
public:
  virtual AbstractProduct *createProduct(void)=0;
  virtual ~AbstractFactory()=0;
};

AbstractFactory::~AbstractFactory() { cout << "AbstractFactory的析构函数" << endl; }

class ConcreteFactoryA : public AbstractFactory
{
public:
  virtual AbstractProduct *createProduct(void)
  {
    return new ConcreteProductA;
  }
  virtual ~ConcreteFactoryA() { cout << "ConcreteFactoryA的析构函数" << endl; }
};

class ConcreteFactoryB : public AbstractFactory
{
public:
  virtual AbstractProduct *createProduct(void)
  {
    return new ConcreteProductB;
  }
  virtual ~ConcreteFactoryB() { cout << "ConcreteFactoryB的析构函数" << endl; }
};

int main()
{
  AbstractFactory *fac = nullptr;
  AbstractProduct *pro = nullptr;
  fac = new ConcreteFactoryA;
  if (fac)
  {
    pro = fac->createProduct();
    pro->method();
  }
  delete pro;
  delete fac;
  return 0;
}
```

## 3.3. 抽象工厂模式

### 3.3.1. 概念

- 一种为访问类提供一个创建一组相关或相互依赖对象的接口，且访问类无须指定所要产品的具体类就能得到同族的不同等级的产品的模式结构

### 3.3.2. 应用场景

- 工厂方法模式考虑的是一类产品的生产，如：畜牧场只养动物、球类工厂只生产球类。但是在现实生活中许多工厂是综合型的工厂，能生产多种类的产品，如体育用品厂既生产球类也生产球衣球鞋等；
- 一系列/一族产品需要被同时使用时，适合使用抽象工厂模式；
- 产品结构稳定，设计完成之后不会向系统中新增或剔除某个产品；

### 3.3.3. 具体实现

- **抽象工厂类：** 提供了创建产品的接口，它包含多个创建产品的方法`createProduct()`，可以创建多个不同种类的产品；
- **具体工厂类：** 主要是实现抽象工厂类中的多个抽象方法，完成多个不同种类具体产品的创建；
- **抽象产品类：** 定义了产品的规范，描述了产品的主要属性和功能，抽象工厂模式有多个抽象产品类；
- **具体产品类：** 实现了抽象产品类所定义的接口，由具体工厂来创建，它同具体工厂之间是多对一的关系。
- **客户访问类：**
![抽象工厂模式](./out/Figure/UML/DesignPattern/AbstractFactoryPattern.png)

### 3.3.4. 优缺点

- **优点：**
  - 在类的内部对产品族中相关联的多个产品共同管理，而不必专门引入多个新的类来进行管理；
  - 当增加一个新的产品族（多种不同种类产品的组合）时只需增加一个新的具体工厂，不需要修改原代码，满足开闭原则；
- **缺点：**
  - 当产品族中需要增加一个新种类的产品时，则所有的工厂类都需要进行修改，不满足开闭原则；
  - 当系统中只存在一种种类产品时，抽象工厂模式将退化到工厂方法模式；

### 3.3.5. C++代码

```cpp {class=line-numbers}

```

## 3.4. 单例模式

### 3.4.1. 概念

- 指一个类只能创建一个实例，该实例只能由该类自行创建，且该类应提供一个全局访问点来访问这个唯一实例。例如：
  - Windows 中只能打开一个任务管理器，这样可以避免因打开多个任务管理器窗口而造成内存资源的浪费，或出现各个窗口显示内容的不一致等错误。
  - 在计算机系统中，还有 Windows 的回收站、操作系统中的文件系统、多线程中的线程池、显卡的驱动程序对象、打印机的后台处理服务、应用程序的日志对象、数据库的连接池、网站的计数器、Web 应用的配置对象、应用程序中的对话框、系统中的缓存等常常被设计成单例。

- 单例模式的三大特点：
  - 单例类只能创建一个实例对象；
  - 该单例对象必须由单例类自行创建；
  - 单例类对外提供一个访问该单例的全局访问点。

### 3.4.2. 应用场景

- 需要频繁创建的一些类，使用单例可以降低系统的内存压力，减少 GC。
- 某类只要求生成一个对象的时候，如一个班中的班长、每个人的身份证号等。
- 某些类创建实例时占用资源较多，或实例化耗时较长，且经常使用。
- 某类需要频繁实例化，而创建的对象又频繁被销毁的时候，如多线程的线程池、网络连接池等。
- 频繁访问数据库或文件的对象。
- 对于一些控制硬件级别的操作，或者从系统上来讲应当是单一控制逻辑的操作，如果有多个实例，则系统会完全乱套。
- 当对象需要被共享的场合。由于单例模式只允许创建一个对象，共享该对象可以节省内存，并加快对象访问速度。如 Web 中的配置对象、数据库的连接池等。

### 3.4.3. 具体实现

![单例模式](./out/Figure/UML/DesignPattern/Singleton.png)

### 3.4.4. 优缺点

- **优点：**
  - 单例模式可以保证内存里只有一个实例，减少了内存的开销；
  - 可以避免对资源的多重占用；
  - 单例模式设置全局访问点，可以优化和共享资源的访问；
- **缺点：**
  - 单例模式一般没有接口，扩展困难。如果要扩展，则除了修改原来的代码，没有第二种途径，违背开闭原则；
  - 单例模式的功能代码通常写在一个类中，如果功能设计不合理，则很容易违背单一职责原则；
  - 在并发测试中，单例模式不利于代码调试。在调试过程中，如果单例中的代码没有执行完，也不能模拟生成一个新的对象；
  - 多线程下需要考虑线程安全机制；

### 3.4.5. C++代码

- 懒汉式实现：
  - 概念：类加载时没有生成单例，只有当第一次尝试调用`getInstance`获得实例时才创建实例。可能会出现线程不安全问题；
  - 特点：以时间换空间，需要花费时间进行多线程间同步，适用于访问量比较小，线程比较少的场景；
- 饿汉式实现：
  - 概念：类一旦加载就创建一个实例，保证在调用`getInstance`之前单例就已经存在；
  - 特点：以空间换时间，适用于访问量比较大，线程比较多的场景；

```cpp {class=line-numbers}
// 双重检测加锁机制实现线程安全
pthread_mutex_t mutex; //锁变量
class LazySingleton
{
private:
  static LazySingleton *instance;
  LazySingleton() {  }
  LazySingleton(const LazySingleton &other) {  }
public:
  static LazySingleton* getInstance()
  {
    if (!instance) // 只有在实例未创建时才进行加锁
    {
      // 对象的创建过程并非是原子性的，在创建的过程中，由于指令重排的影响，会导致出现线程安全的问题。
      // 线程在创建单例对象时，可能未调用构造函数进行初始化的工作，就将instance置为非空，
      // 此时另一个线程将返回一个未经正确初始化的单例对象
      pthread_mutex_lock(&mutex);
      if (!instance) instance = new LazySingleton(); //可能会出现指令重排问题
      pthread_mutex_unlock(&mutex);
    }
    return instance;
  } 
};
// C++标准规定，非整型和枚举型静态常量类成员需要在类外进行初始化
LazySingleton* LazySingleton::instance = nullptr;
```

```cpp {class=line-numbers}
// C++11标准static支持的线程安全实现
class LazySingleton
{
private:
  LazySingleton() {  }
  LazySingleton(const LazySingleton &other) {  }
public:
  static LazySingleton& getInstance()
  {
    static LazySingleton instance;
    return instance;
  } 
};
```

```cpp {class=line-numbers}
// 饿汉式的代码实现
class HungrySingleton
{
private:
  static HungrySingleton *instance; // 静态数据成员
  HungrySingleton() { }
  LazySingleton(const LazySingleton &other) {  }
public:
  static HungrySingleton* getInstance() // 静态成员函数
  {
    return instance;
  }
};
HungrySingleton* HungrySingleton::instance = new HungrySingleton();
```

## 3.5. 建造者模式

### 3.5.1. 概念

### 3.5.2. 应用场景

### 3.5.3. 具体实现

### 3.5.4. 优缺点

### 3.5.5. C++代码

```cpp {class=line-numbers}

```

## 3.6. 原型模式

### 3.6.1. 概念

### 3.6.2. 应用场景

### 3.6.3. 具体实现

### 3.6.4. 优缺点

### 3.6.5. C++代码

```cpp {class=line-numbers}

```

# 4. 结构型模式

关注类和对象的组合。继承的概念被用来组合接口和定义组合对象获得新功能的方式。

# 5. 行为型模式

关注对象之间的通信。
