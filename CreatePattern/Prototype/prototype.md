> Specify the kinds of Objects to create using a prototypical instance, and create new objects by copying this prototype.
用原型实例指定创建对象的种类，并且通过复制这些原型创建新的对象。

**为什么需要原型模式**
为什么不用new直接新建对象，而要用原型模式？
首先，用new新建对象不能获取当前对象运行时的状态，其次就算new了新对象，在将当前对象的值复制给新对象，效率也不如原型模式高。
为什么不直接使用拷贝构造函数，而要使用原型模式？
原型模式与拷贝构造函数是不同的概念，拷贝构造函数涉及的类是已知的，原型模式涉及的类可以是未知的（基类的拷贝构造函数只能复制得到基类的对象）。原型模式生成的新对象可能是一个派生类。拷贝构造函数生成的新对象只能是类本身。原型模式是描述了一个通用方法(或概念)，它不管是如何实现的，而拷贝构造则是描述了一个具体实现方法。

**优缺点**
优点
1.如果创建新的对象比较复杂，可以利用原型模式简化对象的创建过程，同时也能够提高效率。
2.简化对象的创建，无需理会创建过程。
3.可以在程序运行时（对象属性发生了变化）获得一份内容相同的实例，他们之间不会相互干扰。
关于第1点效率高的说明:原型模式是内存二进制流的复制，要比直接new 一个对象性能好,特别是在一个循环体内产生大量的对象时，原型模式可以更好地体现其优点

缺点
1.在实现深拷贝时可能需要比较复杂的代码
2.需要为每一个类配备一个克隆方法，而且该克隆方法需要对类的功能进行通盘考虑，这对全新的类来说不是很难，但对已有的类进行改造时，不一定是件容易的事，必须修改其源代码，违背了“开闭原则”。
原型模式很少单独出现，一般是和工厂方法模式一起出现，通过clone()方法创建一个对象，然后由工厂提供给调用者

                        
Ref：https://blog.csdn.net/leonardohaig/article/details/106456372