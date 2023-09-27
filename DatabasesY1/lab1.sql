drop table if exists insta_users;
create table insta_users (username varchar(30) primary key,
first_name char(20), last_name char(20), signup_date date);
insert into insta_users 
values 
('lucky_cat', 'andrea', 'costa', '2021-09-27'),
('kappa12', 'kappa', 'hi', '2023-08-26'),
('Peol_123', 'Peon', 'Loen', '2022-04-22'),
('Maudi', 'Mercedes', 'Audi', '2020-11-12');
select * from insta_users;