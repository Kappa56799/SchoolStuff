-- Drops previous tables used to reset the data 
drop table if exists follow, likes, photos, users;

-- Creates the likes table with the attributes required
create table users (userid serial primary key, username varchar(50) unique not null , created date);
create table photos (photoid serial primary key, url varchar(100), userid serial, created date, foreign key (userid) references users(userid));
create table likes (userid serial, photoid serial, likedate date, foreign key (userid) references users(userid), primary key (userid,photoid), foreign key (photoid) references photos(photoid));
create table follow (follower_id serial, followee_id serial, followdate date, primary key (follower_id,followee_id), foreign key (follower_id) references users(userid), foreign key (followee_id) references users(userid));

-- Cretaes users table and writes in the values
insert into users (username, created) values 
('kappa1', '2023-09-08'),
('Gamer2', '2022-10-11'),
('Happy3', '2004-02-23'),
('Boi4', '2005-06-30'),
('Test5', '2020-03-05');

-- Creates the photos table and inputs values
insert into photos (url, created) values 
('https://image.com', '2023-09-08'),
('https://iamge1.com', '2022-10-11'),
('https://image2.com', '2004-02-23'),
('https://image3.com', '2005-06-30'),
('https://image4.com', '2020-03-05');

-- Creates the likes table and inputs values
insert into likes(likedate) values 
('2004-12-12'),	
('2023-11-27'),
('2032-09-30'),
('2045-08-06'),
('2021-06-23');

-- Creates the likes table and inputs values
insert into follow(followdate) values 
('2004-12-11'),	
('2016-11-10'),
('2032-09-08'),
('2023-08-06'),
('2005-06-23');

-- Shows all the values on each table
select * from likes;
select * from photos;
select * from users;
select * from follow;


