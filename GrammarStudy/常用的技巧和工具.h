//
//  常用的技巧和工具.h
//  GrammarStudy
//
//  Created by 陈舒澳 on 16/5/6.
//  Copyright © 2016年 speeda. All rights reserved.
//

#ifndef _________h
#define _________h
/*
 
 1、内存检测的工具
  a、编译和分析工具        Analyze
  b、内存泄漏检测工具      Leak
  c、内存猛增检测工具      Allocations
 
 
 
 2、Xcode常用技巧
    2.1 常用插件 ---  （Alcatraz插件管理）
 
    a、项目代码的可读性公司相当重视   -------    注释 VVDocument
    b、快速找到项目中的信息          -------    XTodo （ctrl + t）
        ctrl + shift + t   TODO:
        ctrl + shift + x   FIXME:
        ctrl + shift + 1   !!!:
        ctrl + shift + q   ???:
    c、系统代码自动匹配(只需要模糊记得某些就ok)            --------  FuzzyAutocomplete
    d、颜色插件，可以调起颜色面板，根据需要调节颜色               ColorSense
    
 
 
 
    2.2 调试技巧
    a、LLDB是Xcode内置的为我们开发者提供的调试工具。
    调试控制台有八个按钮，前六个按钮的操作说明如下
     第一个按钮点击就会收起这一栏目了，也就看不见了。
     第二个按钮：如果为蓝色，就是断点有效。如果点击它变成灰色，就是所有断点不起作用。
     第三个按钮：是继续的意思，会让程序从断点处恢复继续往下运行，我们点了这个按钮后，应用就会恢复正常运行状态。
     第四个按钮是：单步执行的意思，每点这个按钮一次，程序就会从我们断点开始的地方，向下执行一步。
     第五个按钮是：进入执行的意思，简单来说就是如果我们当前的断点在一个函数调用上，把么断点会继续进入这个函数的内部进行调试。
     第六个按钮是：跳出的意思, 就是如果我们当前在一个函数中，它会跳出当前的函数，回到函数的调用处。
    b、常用的p、po、call命令,打断点输出看区别就知道了
    po 输出的是具体对象的内容。
     NSArray * array = [NSArray arrayWithObjects:@"fu",@"zong",@"jian" ,nil];
     (lldb) po array
     <__NSArrayI 0x7a8387f0>(
     fu,
     zong,
     jian
     )
     (lldb) p array
     (__NSArrayI *) $1 = 0x7a8387f0 @"3 objects"
     (lldb) call array
     (__NSArrayI *) $2 = 0x7a8387f0 @"3 objects"
     (lldb) print array
     (__NSArrayI *) $6 = 0x7a8387f0 @"3 objects"
    
    c、LLDB声明变量,变量的前面都必须要加上$
    我们可以使用e命令定义变量，然后在调试中使用
     lldb) e NSString *$String = @"haohaoxuexi"
     (lldb) po $String
     haohaoxuexi
     
     (lldb) p $String
     (__NSCFString *) $String = 0x7a84b250 @"haohaoxuexi"
     (lldb) print $String
     (__NSCFString *) $String = 0x7a84b250 @"haohaoxuexi"
     (lldb) call $String
     (__NSCFString *) $String = 0x7a84b250 @"haohaoxuexi"

    d、调用变量的API,并尝试强转
     NSArray * array = [NSArray arrayWithObjects:@"fu",@"zong",@"jian" ,nil];
     (lldb) po [array objectAtIndex:2]
     jian
     
     (lldb) po [[array objectAtIndex:2] characterAtIndex:0]
     0x0000006a
     
     (lldb) po (unsigned int)[[array objectAtIndex:2] characterAtIndex:0]
     106
     
     (lldb) po (char)[[array objectAtIndex:2] characterAtIndex:0]
     'j'
     
     (lldb) po (unichar)[[array objectAtIndex:2] characterAtIndex:0]
     U+006a u'j'
     
     (lldb)
    
    e、可以设置断点触发的条件，提示音、提示语等
     右键断点 Edit Breakpoint -> condition
 
    f、常用打印视图层次结构  recursiveDescription
     (lldb) po [self.view recursiveDescription]
     <UIView: 0x7a28b5f0; frame = (0 0; 320 568); autoresize = W+H; layer = <CALayer: 0x7a27efa0>>
     | <_UILayoutGuide: 0x7a0b0610; frame = (0 0; 0 0); hidden = YES; layer = <CALayer: 0x7a0b00b0>>
     | <_UILayoutGuide: 0x7a0b0f50; frame = (0 0; 0 0); hidden = YES; layer = <CALayer: 0x7a0b1020>>
     
     (lldb)
 
    g、修改变量的值
     expr variable = newValue
     (lldb) po person.name
     2016-05-06 16:59:48.701 GrammarStudy[4762:240293] getter
     mingtianhuigenghao
     
     (lldb) expr person.name = @"fuzongjian"
     2016-05-06 17:00:39.664 GrammarStudy[4762:240293] setter
     (__NSCFString *) $1 = 0x7a72c470 @"fuzongjian"
     (lldb) po person.name
     2016-05-06 17:00:49.093 GrammarStudy[4762:240293] getter
     fuzongjian
     
     (lldb)
 
 3、当我们找不到crash的原因和位置的时候，可以采用全局断点定位crash，详细步骤看 - 全局断点定位crash.gif，效果不错
 
 
 
 
 
 
 
 
 
 
 
 
 */

#endif /* _________h */
