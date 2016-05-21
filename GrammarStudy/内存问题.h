//
//  内存问题.h
//  GrammarStudy
//
//  Created by 陈舒澳 on 16/5/6.
//  Copyright © 2016年 speeda. All rights reserved.
//

#ifndef _____h
#define _____h


#endif /* _____h */
/*
 
 一、内存管理的方式
    ARC（自动内存计数）与MRC（手动内存计数）
    内存管理主要避免“过早释放”和“内存泄漏”,对于“过早释放”需要注意的是@property设置属性的时候，用对关键字；对于“内存泄漏”申请了要负责释放
 二、内存管理的几条原则是什么？
 三、MRC与ARC混编设置方式
     在XCode中targets的build phases选项下Compile Sources下选择 不需要arc编译的文件
     双击输入 -fno-objc-arc 即可
     
     MRC工程中也可以使用ARC的类，方法如下：
     在XCode中targets的build phases选项下Compile Sources下选择要使用arc编译的文件
     双击输入 -fobjc-arc 即可
 四、内存管理基本原则
    一、MRC
    OC内存管理遵循“谁创建，谁释放，谁引用，谁管理”的机制，当创建或者引用一个对象的时候，需要向它发送alloc、copy、retain消息，当释放该对象发送release消息，当对象引用计数为0是，系统将释放该对象，这是OC的手动管理机制（MRC）
    二、ARC
    a、iOS5.0之后引用自动管理机制——自动引用计数（ARC），管理机制和手动管理机制类似，只是不再需要调用retain、release、autorelease；
    b、它编译的特性，当你使用ARC时，在适当的位置插入release和autorelese；
    c、strong修饰的指针变量指向对象时，当指针指向新值或者指针不复存在，相关联对象就会被自动释放，而weak修饰的指针变量指向对象，当对象的拥有者指向新值或者不存在时weak修饰的指针会自动置为nil
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 */