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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 */

#endif /* _____h */
