//
//  基础知识.h
//  GrammarStudy
//
//  Created by 陈舒澳 on 16/4/21.
//  Copyright © 2016年 speeda. All rights reserved.
//

#ifndef _____h
#define _____h
/**
 1、bounds和frame的区别？
    frame:参照点是父坐标系
    bounds：参照点是本地坐标系，总是以 （0,0 ）为起点
 
 2、UIView和CALayer之间的联系？
    一、UIView是用来显示内容的，可以处理用户事件；CALayer是用来绘制内容的，对内容进行动画处理依赖与UIView进行显示，不能处理用户事件。
    二、UIView和CALayer是相互依赖的关系。UIView依赖与CALayer提供的内容，CALAyer依赖UIView提供容器来显示绘制的内容。即CALayer是这一切的基础，如果没有CALayer，UIView自身也不会存在，UIView是一个特殊的CALayer实现，添加了响应事件的能力。
    三、UIView来自CALayer，高于CALayer，是CALayer高层实现与封装。UIView的所有的特性来源于CALayer支持。
 
    a，每个 UIView 内部都有一个 CALayer 在背后提供内容的绘制和显示，并且 UIView 的尺寸样式都由内部的 Layer 所提供。两者都有树状层级结构，layer 内部有 SubLayers，View 内部有 SubViews.但是 Layer 比 View 多了个AnchorPoint
    b，在 View显示的时候，UIView 做为 Layer 的 CALayerDelegate,View 的显示内容由内部的 CALayer 的 display
    c，CALayer 是默认修改属性支持隐式动画的，在给 UIView 的 Layer 做动画的时候，View 作为 Layer 的代理，Layer 通过 actionForLayer:forKey:向 View请求相应的 action(动画行为)
    d，layer 内部维护着三分 layer tree,分别是 presentLayer Tree(动画树),modeLayer Tree(模型树), Render Tree (渲染树),在做 iOS动画的时候，我们修改动画的属性，在动画的其实是 Layer 的 presentLayer的属性值,而最终展示在界面上的其实是提供 View的modelLayer
    e，两者最明显的区别是 View可以接受并处理事件，而 Layer 不可以
 
 3、什么是Runloop？
 
 4、如何存储用户的敏感信息？比如token？
 
 5、autorelease的对象何时被释放？
    1、autorelease的对象是在每个事件循环结束后，自动释放池才会对所有自动释放的对象的引用计数减一，若引用计数变成了0，则释放对象，回收内存。若想要早一点释放掉auto release对象，那么我们可以在对象外加一个自动释放池。比如，在循环处理数据时，临时变量要快速释放，
    2、因为Run Loop是在每个事件循环结束后才会自动释放池去使对象的引用计数减一，对于引用计数为0的对象才会真正被销毁、回收内存。
 
 6、如何声明一个delegate属性，为什么？
    在ARC下使用weak，在MRC下使用assign。在MRC下，使用assign是因为没有weak关键字，只能使用assign来防止循环引用。在ARC下，使用weak来防止循环引用。
 
 7、UIViewController的viewDidUnload、viewDidLoad和loadView分别什么时候调用？UIView的drawRect和layoutSubviews分别起什么作用？
    1、在控制器被销毁前会调用viewDidUnload（MRC下才会调用）、在控制器没有任何view时，会调用loadView、在view加载完成时，会调用viewDidLoad
    2、在调用setNeedsDisplay后，会调用drawRect方法，我们通过在此方法中可以获取到context（设置上下文），就可以实现绘图、在调用setNeedsLayout后，会调用layoutSubviews方法，我们可以通过在此方法去调整UI。当然能引起layoutSubviews调用的方式有很多种的，比如添加子视图、滚动scrollview、修改视图的frame等。
 
 8、UITableView是如何重用cell的？
    1、UITableView提供了一个属性：visibleCells，它是记录当前在屏幕可见的cell，要想重用cell，我们需要明确指定重用标识（identifier）。
    2、当cell滚动出tableview可视范围之外时，就会被放到可重用数组中。当有一个cell滚动出tableview可视范围之外时，同样也会有新的cell要显示到tableview可视区，因此这个新显示出来的cell就会先从可重用数组中通过所指定的identifier来获取，如果能够获取到，则直接使用之，否则创建一个新的cell。
 
 9、浅拷贝与深拷贝的区别是什么？
    1、浅拷贝就是指针拷贝（指向原有内存空间），而深拷贝是内容拷贝（有新的内存空间）
    2、浅复制并不拷贝对象本身而仅仅是拷贝指向对象的指针；深复制是直接拷贝整个对象内存到另一块内存中
 
 10、属性readwrite、readonly、assign、retain、copy、nonatomic各是什么作用，在哪种情况下用？
 
   作用
     1、readwrite：代表可读可写，会生成getter和setter方法
     2、readonly：代表只读，只生成getter方法，不会生成setter方法
     3、assign：代表普通赋值，通常用于非对象类型
     4、retain：MRC下才能手动使用，与ARC下的strong一样，指定强引用，引用计数加1
     5、copy：代表拷贝，也是强引用，引用计数加1，进行指针拷贝
     6、nonatomic：代表非原子操作，非线程安全，但可提高性能
 
    使用情况
     1、readwrite：默认就是，通过不用显示指定，需要生成setter和getter时使用
     2、readonly：当不希望生成setter时使用
     3、assign：通常是非对象类型使用
     4、retain：MRC下才能使用，表示对象强引用
     5、copy：生成不可变对象、需要拷贝时使用
     6、nonatomic：不要求线程安全时使用，可提高性能，通常都会使用
 
 11、 @property 和@synthsize解释
    @property声明成员变量时，可以自动生成成员变量的setter和gette方法的声明。可以实现三步
    一、定义变量
    二、实现方法
    三、实现声明
    @systhsize可以自动生成成员变量的实现setter和getter的实现
 
 12、分类（category）与类扩展（extension）区别
    一、分类：
      作用  ----  一般是给一个类扩展方法，便于分工合作，不添加变量字段
      命名  ----  NSString + Reversestring
      注意  分类不能添加类的属性和私有变量
    二、类扩展（继承）
       可以定义属性和私有变量
 
 13、堆和栈的区别
    管理方式：
        对于栈来讲，是由编译器自动管理，无需我们手动控制；对于堆来讲，释放工作有程序员控制，容易产生memory leak
    申请大小：
        栈：在Windows下，栈是向低位字扩展的数据结构，是一块连续的内存区域，即栈顶上的地址和栈的最大容量是系统预先规定好的，在Windows下，栈的大小是2M，如果申请的空间超过了栈的剩余空间时候，就会产生overflow，所以，能获得栈的空间比较小。
        堆：堆是向高地址扩展的数据结果，是不连续的内存区域。这是由于系统是链表来存储空闲内存地址，自然是不连续的，而链表的遍历方向是由低地址想高地址。堆的最大空间受限于计算机系统中有效的虚拟内存。由此，堆获得的空间比较灵活，也比较大。
    碎片：对于堆来说，频繁的new/delete必然会造成内存空间的不连续，从而造成大量的碎片，使程序效率降低。对于栈来讲，则不会存在这个问题，因为栈是先进后出的队列，一一对应不可能有一个内存块从栈中弹出。
    分配方式：
        堆都是动态分配的，没有静态分配的堆。栈有两种分配方式：静态分配和动态分配。静态分配是编译器完成的，比如局部变量的分配。动态分配是有alloc函数进行分配的，但是栈的动态分配和对是不同的，他的动态分配由编译器进行释放，无需我们手工实现。
    分配效率：
        栈是由机器系统提供的数据结构，计算机会在底层堆栈提供支持，分配专门的寄存器存放栈的地址，压栈出栈都有专门的指令执行，这就决定了栈的效率比较高。堆则是C/C++函数库提供的，他的机制比较复杂。
 
 14、KVO内部实现原理
    
 15、block内部实现原理

 16、KVO与NSNotification的区别。
    两种是类与类之间的通信、都负责发送通知，剩下的事情就不用管了，没有返回值、一对多
    NSNotification优点：
    a、代码量小
    b、一对多通信
    c、能够传递对象（dictionary），传递消息自定义
    NSNotification缺点：
    a、调试比较难跟踪控制
    b、需要提前知道通知名称、字典key、
    c、注册销毁
    d、编译的时候不能检测通知和观察者是否是正确对应
    
    KVO优点：
    a、能够提供一种简单的方法实现两个对象间的同步
    b、能够及时获得属性的最新值以及以先前值
    c、用key paths来观察属性，即也可以观察嵌套对象
    d、可以一对多
    KVO缺点
    a、观察的属性必须用字符串定义，编译器不会出现警告以及检查
    b、对属性的重构将导致我们的观察代码不可再用
 
 
 17、协议与代理
    为什么要有代理？
    当定义协议者想要传值，此时定义协议的人并不知道谁遵循的协议，这个时候就尴尬了；如果有一个代理属性就ok了，这时就不用担心哪个遵循了协议，直接让代理干活就可以了
    优点：
    a、有利于代码的封装
    b、有利于程序的结构化和层次化
    c、降低程序的耦合度，结构感更强
    缺点：
    a、代码量比较大，定义协议比较麻烦
    b、一对一通信
    c、在一个控制器中有多个delegate对象，并且delegate是遵循同一个协议，比较麻烦。
 
 18、#import与#include的区别？@class呢？#import<>与#import""区别
    #import是OC导入头文件的关键字，#include是C/C++导入头文件的关键字，#import头文件只会自动导入一次，不会重复导入，相当于#include和#prama once；
    @class告诉编译器某个类的声明，当执行的时候才去查看类的实现文件，可以解决头文件相互包含的问题
    #import<>用来包含系统的头文件   #import""用来包含用户头文件
 
 19、OC常见的数据类型有哪些？
    OC常见数据类型：NSString、NSNumber、NSArray、NSMutableArray、NSData等，这些都是类，创建后才是对象。
 
 20、NULL - nil - Nil - NSNULL
    nil是OC的，空对象，地址指向空（0）的对象，对象字面零值
    Nil是Objective-C类的字面零值
    NULL是C的，空地址，地址的数值是0，是个长整数
    NSNUll用于解决想NSArray和NSDictionary等集合中添加空值的问题
 
 21、关于长按手势
    长按手势的方法一般会调用两次，开始和结束都会调用，一般我们在手势开始的时候就做相关处理，手势不知道什么才结束
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 */

#endif /* _____h */
