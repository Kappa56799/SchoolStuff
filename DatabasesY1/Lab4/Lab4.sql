-- Drops previous tables used to reset the data 
drop table if exists follow, likes, photos, users;

-- Creates the likes table with the attributes required
create table users (userid serial primary key, username varchar(50) unique not null , created date);
create table photos (photoid serial primary key, url varchar(100), userid serial, created date, foreign key (userid) references users(userid));
create table likes (userid serial, photoid serial, likedate date, foreign key (userid) references users(userid), primary key (userid,photoid), foreign key (photoid) references photos(photoid));
create table follow (follower_id serial, followee_id serial, followdate date, primary key (follower_id,followee_id), foreign key (follower_id) references users(userid), foreign key (followee_id) references users(userid));

-- Inserts 10 additional rows into the users table
INSERT INTO users (username, created) VALUES 
('NewUser1', '2019-05-15'),
('NewUser2', '2018-11-22'),
('NewUser3', '2017-07-10'),
('NewUser4', '2016-03-18'),
('NewUser5', '2015-09-30'),
('NewUser6', '2014-12-05'),
('NewUser7', '2013-06-17'),
('NewUser8', '2012-02-20'),
('NewUser9', '2011-08-14'),
('NewUser10', '2010-04-08');

-- Inserts 10 additional rows into the photos table
INSERT INTO photos (url, created) VALUES 
('https://image5.com', '2019-05-15'),
('https://image6.com', '2018-11-22'),
('https://image7.com', '2017-07-10'),
('https://image8.com', '2016-03-18'),
('https://image9.com', '2015-09-30'),
('https://image10.com', '2014-12-05'),
('https://image11.com', '2013-06-17'),
('https://image12.com', '2012-02-20'),
('https://image13.com', '2011-08-14'),
('https://image14.com', '2010-04-08');

-- Inserts 10 additional rows into the likes table
INSERT INTO likes (likedate) VALUES 
('2006-06-06'),
('2007-07-07'),
('2008-08-08'),
('2009-09-09'),
('2010-10-10'),
('2011-11-11'),
('2012-12-12'),
('2013-01-13'),
('2014-02-14'),
('2015-03-15');

-- Inserts 10 additional rows into the follow table
INSERT INTO follow (followdate) VALUES 
('2016-04-20'),
('2017-05-15'),
('2018-06-12'),
('2019-07-10'),
('2020-08-08'),
('2021-09-06'),
('2022-10-04'),
('2023-11-02'),
('2024-12-01'),
('2025-01-30');

-- Question 1
SELECT username
FROM users 
JOIN likes ON users.userid = likes.userid
WHERE likes.photoid = 4;

-- Question 2
SELECT username
FROM users
JOIN follow ON users.userid = follow.follower_id
WHERE follow.followee_id = (SELECT userid FROM users WHERE username = 'NewUser1');

--Question 3
SELECT username
FROM users 
JOIN likes ON users.userid = likes.userid
JOIN photos ON likes.photoid = photos.photoid
WHERE likes.likedate < '2013-01-13';



