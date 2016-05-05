//
//  代码规范.h
//  GrammarStudy
//
//  Created by 陈舒澳 on 16/5/5.
//  Copyright © 2016年 speeda. All rights reserved.
//

#ifndef _____h
#define _____h

/*
 /---------------------------------------------------- 项目结构 ------------------------------------------------------------/
 
  Controllers               控制器
  View                      自定义视图
  Category                  分类
  Common                    公用得文件
  Extensions                拓展类
  Libs                      引用的三方（一般cocoapods管理，特殊除外）
  Model                     模型
  Services                  网络请求、数据库操作、缓存等操作类
  Sources                   资源文件
 
/---------------------------------------------------- 代码结构 ------------------------------------------------------------/
 
#pragma mark --- Lifecycle(生命周期)

#pragma mark --- Loaddata_Method(数据加载)

#pragma mark --- Private_Method(私有方法)

#pragma mark --- Public_Method(公有方法)

#pragma mark --- Gesture_Method(手势方法)

#pragma mark --- Action_Method(按钮点击)

#pragma mark --- Delegate_Method(代理方法)

#pragma mark --- Notification(通知注册销毁)
 
 
/---------------------------------------------------- 命名规范 ------------------------------------------------------------/
 
 所有命名均遵循驼峰命名规则这是根本
 
 一、控件命名必须加上控件后缀
 
    UIButton * settingButton
 
 二、常见变量命名（所有的命名都应该达到简单易懂的程度）
 
    （1）数据、字典等命名都要带上类型
        @property (strong, nonatomic) NSMutableArray *orderDictionary;
        @property (strong, nonatomic) NSMutableArray *orderArray;
    （2）Bool类型用is前缀
        @property (assign, nonatomic) BOOL isLogin;
     (3)Model类命名
        控制器
    (4) 类名首字母要大写。
 
 三、常量命名
 
    （1）UserDefault Key常量 使用前缀kUDKey标明
        static NSString * const kUDKeyLoginState = @"kUDKeyLoginState";
 
    （2）Notification Key常量 使用小写k开头Notification结尾
        static NSString * const kAddDiarySucceedNotificaiton = @"kAddDiarySucceedNotificaiton";
        
    （3）枚举 使用NS_ENUM进行枚举，加上前缀
         typedef NS_ENUM(NSInteger, KBUserSex) {
         KBUserSexMan = 1,          //男
         KBUserSexWoman = 2,        //女
         };
 
 四、方法定义
 
    方法类型（-/+符号）之后应该有一个空格
    在参数之前应该包含一个具有描述性的关键字来描述参数
 
- (void)setExampleText:(NSString *)text image:(UIImage *)image;
- (void)sendAction:(SEL)aSelector to:(id)anObject forAllCells:(BOOL)flag;
- (id)viewWithTag:(NSInteger)tag;
- (instancetype)initWithWidth:(CGFloat)width height:(CGFloat)height;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 */
#endif /* _____h */
