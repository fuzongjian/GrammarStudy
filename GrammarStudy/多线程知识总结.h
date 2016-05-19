//
//  多线程知识总结.h
//  GrammarStudy
//
//  Created by 陈舒澳 on 16/5/19.
//  Copyright © 2016年 speeda. All rights reserved.
//

#ifndef ________h
#define ________h
/*-----------------------------------    基本概念   ---------------------------------------*/
/*
 一、进程
    1、定义：进程是指系统正在运行的一个应用。
    2、了解：每个进程之间相互独立，均运行在其专用且受保护的内存空间内
 二、线程
    1、定义：线程是进程的基本执行单元，（每个进程至少要有一个线程）
    2、了解：进程中的任务都在线程中执行
 三、多线程
    1、定义：一个进程中可以开启多条线程，多条线程可以并行执行不同的任务
    2、原理：a、同一时间，CPU只能处理一条线程，只有一条线程在工作
            b、多线程并发执行，其实是CPU快速地在多条线程之间调度
            c、CPU调度线程的时间足够快，就造成了多线程并发执行的假象
    3、思考：多条线程在CPU来回切换，会消耗大量的CPU资源
    4、优点：a、可以适当的提高程序的执行效率
            b、提高资源利用率
      缺点：a、线程的创建的越多，CPU在调度线程上开销越大
           b、大量的线程会降低程序的性能
           c、程序设计更加复杂
 */

/*-----------------------------------    以阻塞线程而达到线程同步的效果   ---------------------------------------*/
/*
    一、信号量 dispatch_semaphore 基于计数器的一种多线程同步机制，在多线程访问共有资源时候，会因为多线程的特性而引发数据出错的问题
 
    二、组队列
    创建组队列，在组队列中添加线程操作，当组队列里的线程操作完成后，再去调用 dispatch_group_notify/dispatch_group_wait 进行结果的汇总

 */



/*-----------------------------------    线程创建的方式   ---------------------------------------*/
/*
    一、performSelector方式
 - (void)performSelectorOnMainThread:(SEL)aSelector withObject:(nullable id)arg waitUntilDone:(BOOL)wait modes:(nullable NSArray<NSString *> *)array;
 - (void)performSelectorOnMainThread:(SEL)aSelector withObject:(nullable id)arg waitUntilDone:(BOOL)wait;
	// equivalent to the first method with kCFRunLoopCommonModes
 
 - (void)performSelector:(SEL)aSelector onThread:(NSThread *)thr withObject:(nullable id)arg waitUntilDone:(BOOL)wait modes:(nullable NSArray<NSString *> *)array NS_AVAILABLE(10_5, 2_0);
 - (void)performSelector:(SEL)aSelector onThread:(NSThread *)thr withObject:(nullable id)arg waitUntilDone:(BOOL)wait NS_AVAILABLE(10_5, 2_0);
	// equivalent to the first method with kCFRunLoopCommonModes
 - (void)performSelectorInBackground:(SEL)aSelector withObject:(nullable id)arg NS_AVAILABLE(10_5, 2_0);
 
    二、 NSThread 类方法
 + (void)detachNewThreadSelector:(SEL)selector toTarget:(id)target withObject:(nullable id)argument;
 
    三、NSThread 实例方法
- (instancetype)initWithTarget:(id)target selector:(SEL)selector object:(nullable id)argument NS_AVAILABLE(10_5, 2_0);
 
    四、NSOperationQueue创建操作池，向操作池中添加线程操作，自动异步执行
    1、可以设置最大的并发队列、设置每一个线程的优先等级、设置依赖、暂停/开始所有任务
    2、子线程可以是 NSBlockOperation、NSInvocationOperation
    2.1 NSBlockOperation
 + (instancetype)blockOperationWithBlock:(void (^)(void))block;
    2.2 NSInvocationOperation
 - (nullable instancetype)initWithTarget:(id)target selector:(SEL)sel object:(nullable id)arg;
    3、NSOperationQueue的实例方法
 - (void)addOperation:(NSOperation *)op;
 - (void)addOperations:(NSArray<NSOperation *> *)ops waitUntilFinished:(BOOL)wait NS_AVAILABLE(10_6, 4_0);
 - (void)addOperationWithBlock:(void (^)(void))block NS_AVAILABLE(10_6, 4_0);
 
    五、GCD 异步线程执行耗时操作，主线程刷新UI
 
    六、几种多线程的使用区别看图片  多线程.png
 
 */


/*-----------------------------------    GCD    ---------------------------------------*/
/*
     dispatch_sync :  同步，不具备开启线程的能力
     dispatch_async :   异步，具备开启线程的能力
     并发队列： 多个任务可以同时执行
     串行队列： 一个任务执行完毕后，再执行下一个任务
 
 
 */
#endif /* ________h */
