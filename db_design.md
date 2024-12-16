数据库设计：

1.用户表user

|     字段      |            类型             |   描述   |
| :-----------: | :-------------------------: | :------: |
|    user_id    | int、unique、auto_increment |   主键   |
|   birthday    |            date             | 出生日期 |
| register_date |          datetime           | 注册时间 |
|   location    |            enum             |  所在地  |
| phone_number  |           varchar           |  手机号  |

2.账户表account

|     字段     |      类型       |                         描述                          |
| :----------: | :-------------: | :---------------------------------------------------: |
|  account_id  | varchar、unique | 账户ID(QQ号：q字母开头+数字/WECHAT号：w字母开头+数字) |
|   user_id    |       int       |                        用户ID                         |
|     type     |      enum       |              账户类型(QQ、WECHAT、WEIBO)              |
| account_name |     varchar     |                        账户名                         |
|   password   |     varchar     |                       账户密码                        |
|    avatar    |     varchar     |                       头像路径                        |

3.账户绑定表account_binding

|     字段     |   类型   |        描述        |
| :----------: | :------: | :----------------: |
|   user_id    |   int    | 用户ID(指向user表) |
| account_id_1 | varchar  |     账户类型1      |
| account_id_2 | varchar  |     账户类型2      |
| create_time  | datetime |   创建绑定的时间   |

3.好友表friendship

|   字段    | 类型 |            描述             |
| :-------: | :--: | :-------------------------: |
|  user_id  | int  |     用户ID(指向user表)      |
| friend_id | int  |     好友ID(指向user表)      |
|   type    | enum | 好友类型(QQ、WECHAT、WEIBO) |

4.好友申请friend_request

|       字段        |   类型   |            描述            |
| :---------------: | :------: | :------------------------: |
|    account_id     | varchar  |          申请人ID          |
| friend_account_id | varchar  |        申请好友的ID        |
|   request_time    | datetime |          申请时间          |
|      status       |   enum   | 状态("PENDING"/"REJECTED") |

5.群申请group_request

|     字段     |   类型   |            描述             |
| :----------: | :------: | :-------------------------: |
|   user_id    |   int    |          申请人ID           |
|   group_id   |   int    |        申请好友的ID         |
|     type     |   enum   | 账户类型(QQ、WECHAT、WEIBO) |
| request_time | datetime |          申请时间           |
|    status    |   enum   | 状态("PENDING"/"REJECTED")  |

4.群组表group

|    字段     |   类型   |        描述        |
| :---------: | :------: | :----------------: |
|  group_id   |   int    |        群ID        |
|    name     | varchar  |        群名        |
|    type     |   enum   | 群类型(QQ、WECHAT) |
|  owner_id   |   int    |       群主ID       |
| create_time | datetime |      创建时间      |

5.群成员表group_member

|   字段   | 类型 |            描述            |
| :------: | :--: | :------------------------: |
| group_id | int  |  群ID(主键，指向group表)   |
| user_id  | int  |     用户ID(指向user表)     |
|   role   | enum | 角色(OWNER、ADMIN、MEMBER) |

6.服务开通表user_service

|    字段     | 类型 |            描述             |
| :---------: | :--: | :-------------------------: |
|   user_id   | int  |     用户ID(指向user表)      |
|    type     | enum | 账户类型(QQ、WECHAT、WEIBO) |
|   status    | int  |   是否开通(1开通/0未开通)   |
| create_time | date |          开通时间           |

7.登录状态login_status

|    字段    |   类型   |            描述             |
| :--------: | :------: | :-------------------------: |
|  user_id   |   int    |     用户ID(指向user表)      |
|    type    |   enum   | 账户类型(QQ、WECHAT、WEIBO) |
| login_time | datetime |          登录时间           |
| is_active  |   int    |          是否在线           |
|     ip     | varchar  |        登录的ip地址         |
|    port    |   int    |           端口号            |

