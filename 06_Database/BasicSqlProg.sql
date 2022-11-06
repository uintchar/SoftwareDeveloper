show databases;
use test;
show tables;
create table if not exists tb1 (
  id int not null auto_increment,
  field1 char(50) not null,
  field2 char(50) null,
  primary key (id)
) engine = innodb default charset = utf8;
insert into
  tb1 (id, field1, field2)
values
  (0, 'a', 'b');
select * from tb1;
select now();
select upper('abc');