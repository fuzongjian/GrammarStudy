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
@property (nonatomic,strong) UIView * smallView;
@end

@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    
    
//    UIView * small = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 200, 200)];
//    small.center = self.view.center;
//    small.backgroundColor = [UIColor colorWithRed:0.078 green:0.039 blue:1.000 alpha:1.000];
//    _smallView = small;
//    [self.view addSubview:small];
    
    
    UIButton * button = [UIButton buttonWithType:UIButtonTypeSystem];
    button.frame = CGRectMake(0, 0, 100, 100);
    button.center = self.view.center;
    [button setTitle:@"点我" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(buttonClicked:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    
    
//    [self boundsandframe];
//    [self autorealease];
    [self OC_DIAN];
    
}
- (void)returnSomething:(NSString *)str{
     NSLog(@"协议---%@",str);
}
- (void)buttonClicked:(UIButton *)sender{
    protocolController * protocol = [[protocolController alloc] init];
    [self.navigationController pushViewController:protocol animated:YES];
}
#pragma mark --- autorelease的对象何时被释放
// 内存爆涨的原因是产生的对象一直放在自动释放池中管理，内存得不到释放
- (void)autorealease{
//  看运行内存  memory 25  CPU 45
    for (int i = 0; i < 100000; i ++) {
        NSString * str = @"Fuzongjian";
        str = [str lowercaseString];
        str = [str stringByAppendingString:@"asd"];
         NSLog(@"%@",str);
    }
//    看运行内存   memory  11.8    CPU  39%
    for (int i = 0; i < 100000; i ++) {
        @autoreleasepool {
            NSString * str = @"Fuzongjian";
            str = [str lowercaseString];
            str = [str stringByAppendingString:@"asd"];
            NSLog(@"%@",str);// 看内存  CPU 39  memory 11.8
        }
        
    }
    
    
}
// TODO: 我们接下来准备做什么
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
    
    NSArray * array = [NSArray arrayWithObjects:@"fu",@"zong",@"jian" ,nil];
    
    Person * person = [[Person alloc] init];
    
    [person personMethod];
    
    // 调用setter方法，涉及到值得变化  [person setName:@"fuzongjian"];
    person.name = @"fuzongjian";
    // 调用getter方法，只是获取值，并没有改变值  [person name];
    NSLog(@"---%@----年龄%d---%@",person.name,person.age,array);

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
#pragma mark --- 一般性的问题
#pragma mark --- bounds和frame的区别
- (void)boundsandframe{
    //  视图上放一块view
    UIView * bg = [[UIView alloc] initWithFrame:CGRectMake(10, 10, 200, 200)];
   
    bg.backgroundColor = [UIColor greenColor];
    [self.view addSubview:bg];
    
    // 在放两块小View
    
    // bounds 默认的起点坐标(0,0);
    UIView * first = [[UIView alloc] initWithFrame:bg.bounds];
    first.backgroundColor = [UIColor redColor];
    [self.view addSubview:first];
    
    
    UIView * second = [[UIView alloc] initWithFrame:bg.frame];
    second.backgroundColor = [UIColor blueColor];
    [bg addSubview:second];
    
    
     NSLog(@"%@---%@",NSStringFromCGRect(first.frame),NSStringFromCGRect(second.frame));
}

@end
