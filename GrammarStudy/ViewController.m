//
//  ViewController.m
//  GrammarStudy
//
//  Created by 陈舒澳 on 16/4/21.
//  Copyright © 2016年 speeda. All rights reserved.
//

#import "ViewController.h"
#import "Person.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self OC_DIAN_SECOND];
    
}
#pragma mark --- 属性声明的关键词
/**@property可以自动生成某个成员变量的set和get方法的声明
 * @synthsize可以自动生成某个成员变量的set和get方法的实现
 * 例如：@sythsize age=_age；
 * @synthsize自动生成age的set跟get方法的实现，并且访问_age这个成员变量；
 * @property可以实现三步：
 * a	   定义变量
 * b	 实现方法
 * c	  实现声明
 */
#pragma mark --- OC点语法
/** 定义
 *  1、点语法的本质还是方法的调用。
 *  2、点语法具有编译器特性，会自动展开为对应的set和get方法
 */

- (void)OC_DIAN{
    
    Person * person = [[Person alloc] init];
    
    [person personMethod];
    
    // 调用setter方法，涉及到值得变化  [person setName:@"fuzongjian"];
    person.name = @"fuzongjian";
    // 调用getter方法，只是获取值，并没有改变值  [person name];
    NSLog(@"%@",person.name);

}
/**
 *  调用内部方法，测试点语法和下划线语法
 */
- (void)OC_DIAN_SECOND{
    [[[Person alloc] init] personMethod];
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end