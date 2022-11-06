- [1. MySql 数据类型](#1-mysql-数据类型)
  - [1.1. 数值类型](#11-数值类型)
  - [1.2. 字符串类型](#12-字符串类型)
  - [1.3. 日期/时间类型](#13-日期时间类型)
  - [1.4. 二进制数据类型](#14-二进制数据类型)
- [2. MySql 创建、删除、选择数据库](#2-mysql-创建删除选择数据库)
- [3. MySql 创建、删除、显示数据表](#3-mysql-创建删除显示数据表)
- [4. MySql 插入数据](#4-mysql-插入数据)
- [5. MySql 删除数据](#5-mysql-删除数据)
- [6. MySql 更新数据](#6-mysql-更新数据)
- [7. MySql 查询数据](#7-mysql-查询数据)
  - [正则表达式](#正则表达式)
- [8. 参考资料](#8-参考资料)

# 1. MySql 数据类型

- **待补充**

## 1.1. 数值类型

|     类型      |    大小     |       用途       |
| :-----------: | :---------: | :--------------: |
|    TINYINT    |   1 byte    |     整数类型     |
|   SMALLINT    |   2 bytes   |     整数类型     |
|   MEDIUMINT   |   3 bytes   |     整数类型     |
| INTEGER(INT)  |   4 bytes   |     整数类型     |
|    BIGINT     |   8 bytes   |     整数类型     |
|     FLOAT     |   4 bytes   | 单精度浮点数类型 |
|    DOUBLE     |   8 bytes   | 双精度浮点数类型 |
| DECIMAL(DEC)  |    不定     |   准确精度小数   |
|      BIT      | 1 ~ 64 bits |      位字段      |
| BOOLEAN(BOOL) |   1 byte    |     布尔类型     |

- 整数类型都分为有符号和无符号（unsigned）；
- `boolean` 是 `tinyint(1)` 的同义词，括号中的 1 表示显示宽度而不是存储长度；
- `float`, `double` 为不精确的实数值，其误差取决于其精度；
- `decimal(M, D)` ：M 为总的十进制位数，D 为小数点后的位数；

## 1.2. 字符串类型

|    类型    |                           说明                            |
| :--------: | :-------------------------------------------------------: |
|    CHAR    |                     定长，0~255 bytes                     |
|  VARCHAR   | 变长，5.0 版本以前 0~255 bytes，5.0版本以后 0~65535 bytes |
|    TEXT    |                     变长，0~64K bytes                     |
|  TINYTEXT  |                     变长，0~255 bytes                     |
| MEDIUMTEXT |                     变长，0~16K bytes                     |
|  LONGTEXT  |                     变长，0~4GB bytes                     |
|    ENUM    |       接受最多 64K 个串组成的一个预定义集合的某个串       |
|    SET     |     接受最多64个串组成的一个预定义集合的零个或多个串      |
|   BINARY   |                                                           |
| VARBINARY  |                                                           |

- `CHAR(n)`, `VARCHAR(n)`
- 变长数据类型比较灵活，定长数据类型注重性能；MySQL 处理定长列远比处理变长列快得多；
- MySQL 不允许对变长列（或一个列的可变部分）进行索引；
- **UTF-8：** 一个英文/数字字符占1个字节，一个中文（含繁体）字符占3个字节；
- **Unicode：** 一个英文/数字字符占2个字节，一个中文（含繁体）字符占2个字节；
- **符号：** 英文标点占1个字节，中文标点占2个字节。举例：英文句号“.”占1个字节的大小，中文句号“。”占2个字节的大小；

## 1.3. 日期/时间类型

|   类型    |  大小   |                        说明                         |
| :-------: | :-----: | :-------------------------------------------------: |
|   DATE    | 3 bytes | 格式：YYYY-MM-DD，表示范围：1000-01-01～9999-12-31  |
|   TIME    | 3 bytes |                   格式：HH:MM:SS                    |
|   YEAR    | 1 bytes | 2位 (70～69, 1970年～2069年)， 4位 (1901年～2155年) |
| DATETIME  | 8 bytes |              格式：YYYY-MM-DD HH:MM:SS              |
| TIMESTAMP | 4 bytes |           格式：同 DATETIME（但范围较小）           |

- 每个时间类型有一个有效值范围和一个零值，当指定不合法的 MySQL 不能表示的值时使用零值；
- TIMESTAMP类型有专有的自动更新特性；

## 1.4. 二进制数据类型

|    类型    |         说明         |
| :--------: | :------------------: |
|    BLOB    |   最大长度为 64KB    |
|  TINYBLOB  | 最大长度为 255 Bytes |
| MEDIUMBLOB |   最大长度为 16MB    |
|  LONGBLOB  |    最大长度为 4GB    |

- 二进制数据类型可存储任何数据（甚至包括二进制信息），如图像、多媒体、字处理文档等；

# 2. MySql 创建、删除、选择数据库

- **创建数据库**

  ```sql {class=line-numbers}
  create database database_name;
  ```

- **删除数据库**

  ```sql {class=line-numbers}
  drop database database_name;
  ```

- **选择数据库**

  ```sql {class=line-numbers}
  use database_name;
  ```

# 3. MySql 创建、删除、显示数据表

- **创建数据表**

  ```sql {class=line-numbers}
  create table [if not exists] table_name 
  (
    id     int      not null  auto_increment,
    field1 char(50) not null,
    field2 char(50) null,
    primary key (id)
  ) engine = innodb default charset = utf8;
  ```

- **删除数据表**

  ```sql {class=line-numbers}
  drop table table_name;
  ```

- **显示数据表**

  ```sql {class=line-numbers}
  desc table_name;
  show columns from table_name;
  ```

# 4. MySql 插入数据

# 5. MySql 删除数据

# 6. MySql 更新数据

# 7. MySql 查询数据

## 正则表达式

# 8. 参考资料

- <https://www.runoob.com/mysql/>
- 《MySql必知必会》
