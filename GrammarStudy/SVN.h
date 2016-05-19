//
//  代码管理基础.h
//  GrammarStudy
//
//  Created by 陈舒澳 on 16/5/19.
//  Copyright © 2016年 speeda. All rights reserved.
//

#ifndef _______h
#define _______h
/*-------------------------------------------------------SVN-------------------------------------------------------*/
/*
 01.	将服务器文件下载到本地
 ================================================================================
 
 # 切换工作目录
 $ cd 经理的工作目录
 # checkout服务器上的代码仓库
 $ svn co http://10.0.1.15/svn/weibo --username manager --password jingli
 
 提示：checkout(co)之后，本地代码库中会记录用户名和密码，后续操作不用再另行指定
 
 02.	经理添加文件
 ================================================================================
 
 * svn 常用命令
 --------------------------------------------------------------------------------
 # 查看本地代码库状态
 $ svn st
 错误提示："is not a working copy"，必须在svn的工作目录下才能正确使用svn的命令
 # 查看svn日志
 $ svn log
 # 查看某一个文件的日志
 $ svn log filename
 # 查看某一个文件某个版本的日志
 $ svn log filename@1
 
 * 创建文件
 --------------------------------------------------------------------------------
 # 切换到工作目录
 $ cd weibo
 # 创建文件
 $ touch main.c
 # 打开并编写文件内容
 $ open main.c
 
 * 将文件提交到服务器
 --------------------------------------------------------------------------------
 # 查看工作目录状态
 $ svn st
 # 将文件添加到本地版本库中
 $ svn add main.c
 # 将文件提交到服务器的版本库中
 $ svn ci -m "添加了main.c文件"
 
 "小结" - 添加文件的两个步骤
 --------------------------------------------------------------------------------
 1>  将新建的文件添加到本地代码库
 $ svn add main.c
 2>  将刚刚添加的文件提交到服务器
 $ svn ci -m "备注信息"
 
 注意：一定要养成写注释的良好习惯
 
 03.	团队成员加入
 ================================================================================
 
 1>  张三
 $ svn co http://10.0.1.15/svn/weibo --username=zhangsan --password=zhang
 2>  李四
 $ svn co http://10.0.1.15/svn/weibo --username=lisi --password=li
 
 "小结" 至此，一个项目的搭建工作就告一段落了
 1> 项目准备工作，通常由项目经理完成
 2> 程序员只需要把项目 co 到本地即可
 
 提示：新入职一家公司后，别忘记让经理分配 svn 的账号和密码
 
 04.	张三添加文件
 ================================================================================
 
 # 添加文件 Person.h Person.m
 $ touch Person.h Person.m
 # 修改 Person.h Person.m
 $ open Person.h
 $ open Person.m
 # 将 Person.h Person.m 添加到本地代码库
 $ svn add Person.*
 # 将内容提交到服务器
 $ svn ci -m "添加了Person类"
 
 05. 删除文件
 ================================================================================
 
 # 删除文件
 $ svn rm Person.h
 # 提交删除
 $ svn ci -m "删除了文件"
 
 注意：不要使用文件管理器直接删除文件
 
 06. 撤销修改
 ================================================================================
 $ svn revert Person.m
 
 07. 恢复到之前的某个版本
 ================================================================================
 $ svn up
 
 08. 冲突解决
 (p) postpone            对比
 (mc) mine-conflict      使用我的
 (tc) theirs-conflict    使用对方的
 
 
 如果遇到有些文件夹添加不了  尝试 svn add * —- force
 查看最新版本  svn info
 
 
SVN创建分支
 首先在服务器上必须要有主线：trunk  分支：branches  以及版本库：tags
 指令：svn cp /trunk http://www.svnchina.com/svn/manager_test/branches/新的分支名字 -m”日志”(同时将主线的工程clone到分支上了)
 在分支上操作完之后，上传到svn，合并的事情只能在主线上操作，一般都是经理做的
 分支合并到主线上
 cd 到主线  即  cd trunk
 svn merge —reintegrate http://www.svnchina.com/svn/manager_test/branches/刚刚操作的分支名   即完成合并
 合并并完成测试之后，需要建立tags备份版本信息
 指令：svn copy http://www.svnchina.com/svn/manager_test/trunk http://www.svnchina.com/svn/manager_test/tags/release-1.0 -m”日志”
 删除branches分支以及版本备份tags
 svn rm http://www.svnchina.com/svn/manager_test/branches/分支名字 -m”日志”
 svn rm http://www.svnchina.com/svn/manager_test/tags/release-1.0
 */
/*---------------------------------   svn st 显示的文件状态   ---------------------------------------*/
/*
 ' ' 没有修改
 'A' 被添加到本地代码仓库
 'C' 冲突
 'D' 被删除
 'I' 被忽略
 'M' 被修改
 'R' 被替换
 'X' 外部定义创建的版本目录
 '?' 文件没有被添加到本地版本库内
 '!' 文件丢失或者不完整（不是通过svn命令删除的文件）
 '~' 受控文件被其他文件阻隔
 
 
 */
#endif /* _______h */
