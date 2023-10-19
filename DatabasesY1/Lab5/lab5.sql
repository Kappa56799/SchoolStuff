-- Drops previous tables if they exist to reset the data
drop table if exists follow, likes, photos, users;

-- Creates the users table with the required attributes
create table users (
    user_id INT PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    created DATE
);

-- Creates the photos table with the required attributes
create table photos (
    photo_id INT PRIMARY KEY,
    url VARCHAR(100),
    user_id INT,
    created DATE,
    FOREIGN KEY (user_id) REFERENCES users(user_id)
);

-- Creates the likes table with the required attributes
create table likes (
    user_id INT,
    photo_id INT,
    likedate DATE,
    PRIMARY KEY (user_id, photo_id),
    FOREIGN KEY (user_id) REFERENCES users(user_id),
    FOREIGN KEY (photo_id) REFERENCES photos(photo_id)
);

-- Creates the follow table with the required attributes
create table follow (
    follower_id INT,
    followed_person_id INT,
    follow_date DATE,
    PRIMARY KEY (follower_id, followed_person_id),
    FOREIGN KEY (follower_id) REFERENCES users(user_id),
    FOREIGN KEY (followed_person_id) REFERENCES users(user_id)
);

-- Inserts values into the users table
insert into users (user_id, username, created) values 
(1,   'jargontt0',    '2023-07-13'),
(2,   'czukierman1',  '2023-03-05'),
(3,   'kbilovsky2',   '2022-10-11'),
(4,   'dorourke3',    '2023-03-15'),
(5,   'aclearley4',    null       ),
(6,   'fmcskin5',     '2022-10-21'),
(7,   'atabbitt6',    '2022-12-20'),
(8,   'mtrussler7',   '2023-09-14'),
(9,   'dtomsu8',      '2023-04-05'),
(10,  'bbyrde9',       null       ),
(11,  'lrandalstona', '2023-03-08'),
(12,  'adellab',      '2023-02-27'),
(13,  'shendricksc',  '2023-03-06'),
(14,  'rtocqued',     '2023-02-24'),
(15,  'drechere',     '2023-04-06'),
(16,  'lorpen0',      '2023-03-28'),
(17,  'grimpna',      '2023-08-29'),
(18,  'khornbuckle2', '2022-11-01'),
(19,  'pgunnell3',    '2023-05-26'),
(20,  'nlerwell4',    '2022-11-03'),
(21,  'mleversha5',   '2023-01-30'),
(22,  'drimes6',      '2023-06-06'),
(23,  'cyarnall7',     null       ),
(24,  'echaters8',    '2023-01-27'),
(25,  'ecesco9',      '2023-01-29');

-- Inserts values into the photos table
insert into photos (photo_id, url, user_id, created) values 
(1,  'http://dummyimage.com/10x35.png/dddddd/000000',   1,  '2022-10-27'),
(2,  'http://dummyimage.com/10x41.png/5fa2dd/ffffff',   2,  '2023-05-22'),
(3,  'http://dummyimage.com/10x48.png/5fa2dd/ffffff',   3,   null       ),
(4,  'http://dummyimage.com/10x42.png/5fa2dd/ffffff',   4,  '2023-02-24'),
(5,  'http://dummyimage.com/10x66.png/5fa2dd/ffffff',   5,  '2022-11-12'),
(6,  'http://dummyimage.com/10x73.png/cc0000/ffffff',   6,  '2023-04-21'),
(7,  'http://dummyimage.com/10x20.png/5fa2dd/ffffff',   7,  '2023-09-05'),
(8,  'http://dummyimage.com/10x31.png/5fa2dd/ffffff',   8,  '2022-12-29'),
(9,  'http://dummyimage.com/10x24.png/cc0000/ffffff',   9,  '2023-09-02'),
(10, 'http://dummyimage.com/10x29.png/cc0000/ffffff',   10, '2023-05-16'),
(11, 'http://dummyimage.com/10x64.png/dddddd/000000',   11, '2023-05-21'),
(12, 'http://dummyimage.com/10x43.png/dddddd/000000',   12, '2023-07-29'),
(13, 'http://dummyimage.com/10x67.png/ff4444/ffffff',   13, '2023-02-12'),
(14, 'http://dummyimage.com/10x38.png/dddddd/000000',   14, '2023-01-08'),
(15, 'http://dummyimage.com/10x28.png/ff4444/ffffff',   15,  null       ),
(16, 'http://dummyimage.com/197x100.png/dddddd/000000', 16,  null       ),
(17, 'http://dummyimage.com/144x100.png/ff4444/ffffff', 17, '2023-05-22'),
(18, 'http://dummyimage.com/196x100.png/ff4444/ffffff', 18, '2023-06-09'),
(19, 'http://dummyimage.com/235x100.png/dddddd/000000', 19, '2023-04-15'),
(20, 'http://dummyimage.com/228x100.png/dddddd/000000', 20, '2022-11-19'),
(21, 'http://dummyimage.com/143x100.png/5fa2dd/ffffff', 21, '2022-11-09'),
(22, 'http://dummyimage.com/221x100.png/cc0000/ffffff', 22, '2022-11-02'),
(23, 'http://dummyimage.com/156x100.png/dddddd/000000', 23,  null       ),
(24, 'http://dummyimage.com/106x100.png/5fa2dd/ffffff', 24, '2022-11-25'),
(25, 'http://dummyimage.com/216x100.png/cc0000/ffffff', 25, '2022-10-23');

-- Inserts values into the likes table
insert into likes (user_id, photo_id, likedate) values   
(1,  1,  '2023-01-15'),
(2,  2,  '2023-04-10'),
(3,  3,  '2022-11-25'),
(4,  4,   null       ),
(5,  5,  '2022-11-23'),
(6,  6,   null       ),
(7,  7,  '2023-06-27'),
(8,  8,  '2023-08-06'),
(9,  9,  '2023-07-01'),
(10, 10, '2023-05-09'),
(11, 11, '2023-08-08'),
(12, 12, '2022-11-12'),
(13, 13, '2023-08-23'),
(14, 14, '2022-12-01'),
(15, 15, '2023-06-08'),
(16, 16, '2023-02-21'),
(17, 17, '2023-06-26'),
(18, 18, '2023-04-02'),
(19, 19, '2023-03-04'),
(20, 20,  null       ),
(21, 21, '2022-11-17'),
(22, 22, '2023-01-27'),
(23, 23, '2023-04-11'),
(24, 24, '2023-07-19'),
(25, 25,  null       );

-- Inserts values into the follow table
insert into follow (follower_id, followed_person_id, follow_date) values
(1,  1,  '2022-10-12'),
(2,  2,  '2023-03-19'),
(3,  3,   null       ),
(4,  4,  '2023-05-16'),
(5,  5,  '2023-06-16'),
(6,  6,  '2023-01-29'),
(7,  7,  '2023-01-22'),
(8,  8,  '2022-12-06'),
(9,  9,  '2023-06-23'),
(10, 10, '2023-04-30'),
(11, 11, '2023-09-12'),
(12, 12, '2022-10-16'),
(13, 13, '2023-01-30'),
(14, 14,  null       ),
(15, 15,  null       ),
(16, 16, '2023-06-24'),
(17, 17, '2022-12-12'),
(18, 18,  null       ),
(19, 19, '2023-02-06'),
(20, 20, '2022-10-31'),
(21, 21, '2022-12-17'),
(22, 22, '2023-04-15'),
(23, 23, '2023-09-20'),
(24, 24, '2023-01-25'),
(25, 25, '2023-08-05');


--Question 1
SELECT users.username 
FROM users 
WHERE EXISTS (
    SELECT 1
    FROM follow
    WHERE follow.follower_id = users.user_id
);

--Question 2
SELECT photos.image_url 
FROM photos 
INNER JOIN likes  ON photos.photo_id = likes.photo_id
WHERE likes.user_id = 1;






