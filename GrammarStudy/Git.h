//
//  Git.h
//  GrammarStudy
//
//  Created by 陈舒澳 on 16/5/19.
//  Copyright © 2016年 speeda. All rights reserved.
//

#ifndef Git_h
#define Git_h

/*-------------------------------------------------------Git-------------------------------------------------------*/
/*
    git常用指令直接查看 git常用指令.jpg
 
 
 
 
 */
/*--------------------------------------------------   本地操作   --------------------------------------------------*/
/*
 $ svn help
 查看svn所有命令的帮助
 $ svn help 子命令
 
 # 要退出帮助信息，按"q"
 # 翻看下页，按"空格"
 # 翻看上页，按"CTRL+B"
 # 要搜索相关文字，按"/"然后输入"相关文字"
 
 03. 创建代码库 & 配置个人信息
 ================================================================================
 1>  创建代码仓库
 $ git init
 
 2>  配置用户名和邮箱
 $ git config user.name fuzongjian
 $ git config user.email fuzongjan@gmail.com
 
 * 以上两个命令会将用户信息保存在当前代码仓库中
 
 # 只有配置了用户和邮箱之后，git才能识别出操作的人员信息，通过钩子(hooks)程序可以设置一些动作
 # 例如单元测试发现问题后，自动给相关人员发送电子邮件
 * 注意 暂时不建议投入一毛钱精力
 
 3>  如果要一次性配置完成可以使用一下命令
 $ git config --global user.name fuzongjian
 $ git config --global user.email fuzongjian@gmail.com
 
 * 以上两个命令会将用户信息保存在用户目录下的 .gitconfig 文件中
 
 4>  查看当前所有配置
 $ git config -l
 
 04. 实际开发
 ================================================================================
 1>  创建代码，开始开发
 $ touch main.c
 $ open main.c
 
 2>  将代码添加到代码库
 # 查看当前代码库状态
 $ git status
 # 将文件添加到代码库
 $ git add main.c
 # 将修改提交到代码库
 $ git commit -m "添加了main.c"
 
 提示：
 *   在此一定要使用 -m 参数指定修改的备注信息
 *   否则会进入 vim 编辑器，如果对vim不熟悉，会是很糟糕的事情
 
 # 将当前文件夹下的所有新建或修改的文件一次性添加到代码库
 $ git add .
 
 3>  添加多个文件
 $ touch Person.h Person.m
 $ git add .
 $ git commit -m "添加了Person类"
 $ open Person.h
 $ git add .
 $ git commit -m "增加Person类属性"
 
 * 注意 使用git时，每一次修改都需要添加再提交，这一点是与svn不一样的
 
 git 的重要概念及工作原理
 --------------------------------------------------------------------------------
 工作区
 暂存区(staged)
 分支(HEAD)
 
 05. 别名 & 日志
 ================================================================================
 $ git config alias.st status
 $ git config alias.ci "commit -m"
 
 个人建议：除非特殊原因，最好不要设置别名，否则换一台机器就不会用了
 
 # 查看所有版本库日志
 $ git log
 # 查看指定文件的版本库日志
 $ git log 文件名
 
 # 配置带颜色的log别名
 $ git config --global alias.lg "log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit"
 
 提示：在git中，版本号是一个由SHA1生成的哈希值
 
 06. 版本号，让我们在任意版本之间穿梭
 ================================================================================
 # 回到当前版本，放弃所有没有提交的修改
 $ git reset --hard HEAD
 # 回到上一个版本
 $ git reset --hard HEAD^
 # 回到之前第3个修订版本
 $ git reset --hard HEAD~(3)
 # 回到指定版本号的版本
 $ git reset e695b67
 
 # 查看分支引用记录
 $ git reflog
 
 07. 单个文件的修改管理
 ================================================================================
 # 查看文件变化
 $ git diff
 # 撤销对文件做的修改
 $ git checkout Person.h
 # 从代码库（暂存区中删除文件）
 */



/*--------------------------------------------------   Git团队开发操作   --------------------------------------------------*/
/*
 01. 建立代码仓库(专门用于团队开发的代码仓库)
 ================================================================================
 
 # 切换目录
 $ cd /Users/lnj/Desktop/git演练/公司/weibo
 # 建立空白代码库(专门用于团队开发)
 $ git init --bare
 
 02. 项目经理准备项目(前奏)
 ================================================================================
 
 # 切换目录
 $ cd /Users/lnj/Desktop/git演练/经理
 # "克隆"代码库到本地
 $ git clone /Users/lnj/Desktop/git演练/公司/weibo/
 
 # 个人信息配置(因为要演示一台机器上的多人协作，日常开发可以忽略)
 $ git config user.name manager
 $ git config user.email manager@163.com
 
 .gitignore
 --------------------------------------------------------------------------------
 .gitignore可以指定哪些文件不纳入版本库的管理
 
 参考网址：https://github.com/github/gitignore
 
 # 命令行中进入与.git同级的目录
 $ cd /Users/lnj/Desktop/git演练/经理/weibo
 
 将以下命令一次性粘贴到命令行中
 --------------------------------------------------------------------------------
 echo -e "# Xcode
 #
 build/
 *.pbxuser
 *.mode1v3
 *.mode2v3
 *.perspectivev3
 xcuserdata
 *.xccheckout
 *.moved-aside
 DerivedData
 *.hmap
 *.ipa
 *.xcuserstate
 # CocoaPods
 #
 # We recommend against adding the Pods directory to your .gitignore. However
 # you should judge for yourself, the pros and cons are mentioned at:
 # http://guides.cocoapods.org/using/using-cocoapods.html#should-i-ignore-the-pods-directory-in-source-control
 #
 # Pods/" > .gitignore
 --------------------------------------------------------------------------------
 # 将.gitignore添加到代码库
 $ git add .gitignore
 
 03. 创建项目
 ================================================================================
 提交同时"push"到远程代码仓库
 
 04. 新人加入
 ================================================================================
 
 ...
 
 05. 分布式的代码库 - 仅供参考
 ================================================================================
 由于git是分布式的，任何一台计算机上都保留有完整的代码库的内容，因此可以把团队开发的代码库放在任何位置
 
 
 多个远程代码库之间的同步演练"提示，此演练仅供了解，具体的使用，需要一定的团队规模之后，才能够体会"
 
 
 06. 分支管理 - Tag
 ================================================================================
 # 查看当前标签
 $ git tag
 # 在本地代码库给项目打上一个标签
 $ git tag -a v1.0 -m 'Version 1.0'
 # 将标签添推送到远程代码库中
 $ git push origin v1.0
 
 # 使用tag，就能够将项目快速切换到某一个中间状态，例如产品开发线上的某一个稳定版本
 # 签出v1.0标签
 $ git checkout v1.0
 # 从签出状态创建v1.0bugfix分支
 $ git checkout -b bugfix1.0
 
 # 查看远程分支
 $ git branch -r
 # 删除远程分支
 $ git branch -r -d origin/bugfix1.0

 */

/*--------------------------------------------------   Git团队开发操作   --------------------------------------------------*/
/*
 
 01. 分布式的代码库 - 仅供参考
 ================================================================================
 由于git是分布式的，任何一台计算机上都保留有完整的代码库的内容，因此可以把团队开发的代码库放在任何位置
 
 
 多个远程代码库之间的同步演练"提示，此演练仅供了解，具体的使用，需要一定的团队规模之后，才能够体会"
 
 
 02. 分支管理 - Tag
 ================================================================================
 # 查看当前标签
 $ git tag
 # 在本地代码库给项目打上一个标签
 $ git tag -a v1.0 -m 'Version 1.0'
 # 将标签添推送到远程代码库中
 $ git push origin v1.0
 
 # 使用tag，就能够将项目快速切换到某一个中间状态，例如产品开发线上的某一个稳定版本
 # 签出v1.0标签
 $ git checkout v1.0
 # 从签出状态创建v1.0bugfix分支
 $ git checkout -b bugfix1.0
 
 # 查看远程分支
 $ git branch -r
 # 删除远程分支
 $ git branch -r -d origin/bugfix1.0
 
 */
#endif /* Git_h */
