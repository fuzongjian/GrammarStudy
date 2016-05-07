//
//  protocolController.h
//  GrammarStudy
//
//  Created by 陈舒澳 on 16/5/7.
//  Copyright © 2016年 speeda. All rights reserved.
//

#import <UIKit/UIKit.h>
@protocol protocolReturn <NSObject>

- (void)returnSomething:(NSString *)str;

@end
@interface protocolController : UIViewController

@end
