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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 */