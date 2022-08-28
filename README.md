# StudentManagementSystem_QT_C-
基于C++的学生管理系统，Qt Designer
QT版本5
### 系统流程
![image](https://user-images.githubusercontent.com/76604021/187072981-a443c8f5-123b-4ec2-8c87-872e9b618132.png)
![image](https://user-images.githubusercontent.com/76604021/187072988-bf28d647-7f83-4cd6-a281-ad056e482d1e.png)



### 功能模块介绍
（1）	登录界面输入账号与密码进行登录，与此同时会对账号和密码进行检测，账号是否已注册，密码是否正确，从而做出相应的操作；
（2）	注册界面通过输入邮箱、密码、再次确定密码以及验证滑动条来进行账号的注册，同时账号若已注册则不能再次注册，两次密码输入能够尽可能地防止手误输入错误密码的问题，验证滑动条能够避免脚本注册等问题。用户信息界面能进行密码的修改；
（3）	增加数据界面通过输入学生学号、姓名，选择学院、专业、性别、年龄、入学时间来进行学生数据的存储，与此同时会判断该学号是否已存在而做出相应的操作；
（4）	删除界面分为单项删除和批量删除，其中单项删除通过学号进行删除，批量删除则通过学院专业进行批量删除；
（5）	修改界面分为单项修改和批量修改，单项修改通过学号进行对应的任意一项数据如学号、姓名等进行单独修改，批量修改则通过学院专业性别进行批量修改，其中能修改的内容有学院专业以及入学时间；
（6）	查询界面分为单项查找和批量查找，单项查找通过学号对其进行查找，批量查找则通过学院专业进行查找，同时批量查找可以进行所以学院数据查找和指定学院所有专业进行查找；
（7）	操作界面阐述了各个操作的可用方法系统实现, 关于软件界面则阐述了开发的一些信息。

### 功能效果
#### 注册
![image](https://user-images.githubusercontent.com/76604021/187072885-a6ee32b3-e8c7-4aca-8432-60eaa11aa3f7.png)
#### 管理界面
![image](https://user-images.githubusercontent.com/76604021/187072896-7c289459-f3f0-4d15-9ab9-a5ea88f72a37.png)
#### 增加数据
![image](https://user-images.githubusercontent.com/76604021/187072900-fced1a9e-1226-457f-b311-a34b2f61e79a.png)
#### 删除数据
![image](https://user-images.githubusercontent.com/76604021/187072902-eb68e3ae-91bf-45cf-ae8a-c6b9a63258a7.png)
#### 修改数据
![image](https://user-images.githubusercontent.com/76604021/187072904-64738edf-901f-442f-8f3c-2cb89d865aa1.png)
#### 查询数据
![image](https://user-images.githubusercontent.com/76604021/187072906-c78825b0-52dd-4783-b6cb-266ace5eae4d.png)

