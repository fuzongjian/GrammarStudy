//
//  protocolController.m
//  GrammarStudy
//
//  Created by 陈舒澳 on 16/5/7.
//  Copyright © 2016年 speeda. All rights reserved.
//

#import "protocolController.h"
#import "ViewController.h"
@implementation protocolController
- (void)viewDidLoad{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    UIButton * backButton = [UIButton buttonWithType:UIButtonTypeSystem];
    backButton.frame = CGRectMake(0, 0, 40, 40);
    backButton.backgroundColor = [UIColor redColor];
    [backButton setTitle:@"返回" forState:UIControlStateNormal];
    [backButton addTarget:self action:@selector(backButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:backButton];
}
- (void)backButtonClicked:(UIButton *)sender{
    
    [[[ViewController alloc] init] returnSomething:@"fuzongjian"];
    
    [self.navigationController popViewControllerAnimated:YES];
}


@end
