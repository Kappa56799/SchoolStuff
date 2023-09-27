-- Drops previous tables used to reset the data 
drop table if exists users, photos, likes;

-- Creates the likes table with the attributes required
create table likes (userid serial, photoid serial primary key, likedate date);
-- creates the photos table with the attributes required
create table photos (photoid serial primary key, url varchar(100), userid serial, created date);
--Creates the users table with the attributes required
create table users (id serial primary key, username varchar(50), created date);  

-- Creates the likes table and inputs values
insert into likes(likedate) values 
('2004-12-12'),
('2023-11-27'),
('2032-09-30'),
('2045-08-06'),
('2021-06-23');

-- Creates the photos table and inputs values
insert into photos (url, created) values 
('https://image.com', '2023-09-08'),
('https://iamge1.com', '2022-10-11'),
('https://image2.com', '2004-02-23'),
('https://image3.com', '2005-036-30'),
('https://image4.com', '2020-03-05');


-- Cretaes users table and writes in the values
insert into users (username, created) values 
('kappa1', '2023-09-08'),
('Gamer2', '2022-10-11'),
('Happy3', '2004-02-23'),
('Boi4', '2005-06-30'),
('Test5', '2020-03-05');

-- Shows all the values on each table
select * from likes;
select * from photos;
select * from users;
