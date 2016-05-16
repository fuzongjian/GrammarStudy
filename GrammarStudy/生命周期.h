//
//  声明周期.h
//  GrammarStudy
//
//  Created by 陈舒澳 on 16/5/16.
//  Copyright © 2016年 speeda. All rights reserved.
//

#ifndef _____h
#define _____h
/*
 
 一、视图的生命周期（摘抄与网络）
 1、 alloc 创建对象，分配空间
 2、 init (initWithNibName) 初始化对象，初始化数据
 3、 loadView 从nib载入视图 ，除非你没有使用xib文件创建视图
 4、 viewDidLoad 载入完成，可以进行自定义数据以及动态创建其他控件
 5、 viewWillAppear视图将出现在屏幕之前，马上这个视图就会被展现在屏幕上了
 6、 viewDidAppear 视图已在屏幕上渲染完成
 
 1、viewWillDisappear 视图将被从屏幕上移除之前执行
 2、viewDidDisappear 视图已经被从屏幕上移除，用户看不到这个视图了
 3、dealloc 视图被销毁，此处需要对你在init和viewDidLoad中创建的对象进行释放.
 
 viewVillUnload－ 当内存过低，即将释放时调用；
 viewDidUnload－当内存过低，释放一些不需要的视图时调用。
 
 二、应用程序的声明周期
 1，启动但还没进入状态保存 ：
 - (BOOL)application:(UIApplication *)application willFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 
 2，基本完成程序准备开始运行：
 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 
 3，当应用程序将要入非活动状态执行，应用程序不接收消息或事件，比如来电话了：
 - (void)applicationWillResignActive:(UIApplication *)application
 
 4，当应用程序入活动状态执行，这个刚好跟上面那个方法相反：
 - (void)applicationDidBecomeActive:(UIApplication *)application
 
 5，当程序被推送到后台的时候调用。所以要设置后台继续运行，则在这个函数里面设置即可：
 - (void)applicationDidEnterBackground:(UIApplication *)application
 
 6，当程序从后台将要重新回到前台时候调用，这个刚好跟上面的那个方法相反：
 - (void)applicationWillEnterForeground:(UIApplication *)application
 
 7，当程序将要退出是被调用，通常是用来保存数据和一些退出前的清理工作：
 - (void)applicationWillTerminate:(UIApplication *)application
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 */

#endif /* _____h */
