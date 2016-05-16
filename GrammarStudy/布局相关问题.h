//
//  布局相关问题.h
//  GrammarStudy
//
//  Created by 陈舒澳 on 16/5/16.
//  Copyright © 2016年 speeda. All rights reserved.
//

#ifndef _______h
#define _______h
/*
 
 一、iOS7.0后，View的布局是默认全屏的，Navigation Bar默认是半透明的，所以经常可以看到Bar背后的东西
    将edgesForExtendedLayout 设置成UIRectEdgeNone，表明View是不要扩张到整个屏幕的
 
     - (void)viewDidLoad {
     [super viewDidLoad];
        self.edgesForExtendedLayout = UIRectEdgeNone;
     }
 
 二、通常我们希望ScrollView或者UITableView内容显示是在UINavgation Bar下面，两种方法
    1、edgesForExtendedLayout = UIRectEdgeNone
    2、self.navigationController.navigationBar.translucent =NO;
 
 
 
 
 
 */

#endif /* _______h */
