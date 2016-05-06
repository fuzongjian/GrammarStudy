//
//  Person.h
//  GrammarStudy
//
//  Created by 陈舒澳 on 16/4/21.
//  Copyright © 2016年 speeda. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Person : NSObject
{
    //定义成员变量
    NSString * _name;
}
@property (nonatomic,assign) NSInteger  age;
- (void)setName:(NSString *)name;
- (NSString *)name;

- (void)personMethod;
@end
