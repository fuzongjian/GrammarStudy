//
//  Person.m
//  GrammarStudy
//
//  Created by 陈舒澳 on 16/4/21.
//  Copyright © 2016年 speeda. All rights reserved.
//

#import "Person.h"

@implementation Person

- (void)setName:(NSString *)name{
    NSLog(@"setter");
    if (_name!= name ) {
        _name = name;
    }
    
    //  下面这种情况会陷入死循环
    // self.name = name;
}
- (NSString *)name{
    NSLog(@"getter");
    
    return _name;
    
    //  下面这种情况会陷入死循环
    //  return self.name;
}


#pragma mark --- method
- (void)personMethod{
    
    //setter方法调用
    self.name = @"haohaoxuexi";
    //getter方法调用
    NSLog(@"%@",self.name);
    
    // 下滑下语法(不会去调用setter、getter方法)
    _name = @"mingtianhuigenghao";
    
    
     NSLog(@"%@",self.name);
}


@end
