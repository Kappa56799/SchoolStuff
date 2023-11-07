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
insert into users (user_id, username, created) values (1, 'cwink0', '25-10-2022');
insert into users (user_id, username, created) values (2, 'dkenneway1', null);
insert into users (user_id, username, created) values (3, 'jscrivner2', '18-05-2023');
insert into users (user_id, username, created) values (4, 'adallon3', '16-04-2023');
insert into users (user_id, username, created) values (5, 'cberrigan4', '13-05-2023');
insert into users (user_id, username, created) values (6, 'dbrownstein5', '15-11-2022');
insert into users (user_id, username, created) values (7, 'iamiranda6', null);
insert into users (user_id, username, created) values (8, 'mdrews7', '17-02-2023');
insert into users (user_id, username, created) values (9, 'hblockwell8', '02-03-2023');
insert into users (user_id, username, created) values (10, 'mbermingham9', '05-05-2023');
insert into users (user_id, username, created) values (11, 'fparrisha', null);
insert into users (user_id, username, created) values (12, 'vhutchingsb', null);
insert into users (user_id, username, created) values (13, 'equirkec', '25-11-2022');
insert into users (user_id, username, created) values (14, 'rmordecaid', '06-04-2023');
insert into users (user_id, username, created) values (15, 'gdericote', null);
insert into users (user_id, username, created) values (16, 'hcordayf', '10-03-2023');
insert into users (user_id, username, created) values (17, 'iandererg', null);
insert into users (user_id, username, created) values (18, 'cdashh', '22-04-2023');
insert into users (user_id, username, created) values (19, 'eramardi', null);
insert into users (user_id, username, created) values (20, 'bjoscelinj', null);
insert into users (user_id, username, created) values (21, 'etresisek', '18-10-2022');
insert into users (user_id, username, created) values (22, 'rswepstonel', '15-11-2022');
insert into users (user_id, username, created) values (23, 'hoglesbeem', '06-04-2023');
insert into users (user_id, username, created) values (24, 'tschimekn', '29-03-2023');
insert into users (user_id, username, created) values (25, 'vtantio', null);
insert into users (user_id, username, created) values (26, 'adarguep', null);
insert into users (user_id, username, created) values (27, 'mgligorijevicq', null);
insert into users (user_id, username, created) values (28, 'dmagisterr', '09-01-2023');
insert into users (user_id, username, created) values (29, 'cdacress', '14-02-2023');
insert into users (user_id, username, created) values (30, 'lmuatt', '24-10-2022');


insert into photos (photo_id, url, user_id, created) values (1, 'http://dummyimage.com/242x100.png/5fa2dd/ffffff', 1, '11-01-2024');
insert into photos (photo_id, url, user_id, created) values (2, 'http://dummyimage.com/215x100.png/dddddd/000000', 2, '12-02-2024');
insert into photos (photo_id, url, user_id, created) values (3, null, 3, null);
insert into photos (photo_id, url, user_id, created) values (4, 'http://dummyimage.com/250x100.png/cc0000/ffffff', 4, '02-12-2023');
insert into photos (photo_id, url, user_id, created) values (5, 'http://dummyimage.com/202x100.png/cc0000/ffffff', 5, '21-05-2024');
insert into photos (photo_id, url, user_id, created) values (6, 'http://dummyimage.com/227x100.png/cc0000/ffffff', 6, '11-03-2023');
insert into photos (photo_id, url, user_id, created) values (7, 'http://dummyimage.com/114x100.png/ff4444/ffffff', 7, '29-01-2024');
insert into photos (photo_id, url, user_id, created) values (8, 'http://dummyimage.com/206x100.png/cc0000/ffffff', 8, '10-01-2023');
insert into photos (photo_id, url, user_id, created) values (9, null, 9, null);
insert into photos (photo_id, url, user_id, created) values (10, 'http://dummyimage.com/162x100.png/ff4444/ffffff', 10, '27-07-2023');
insert into photos (photo_id, url, user_id, created) values (11, 'http://dummyimage.com/193x100.png/ff4444/ffffff', 11, '20-05-2024');
insert into photos (photo_id, url, user_id, created) values (12, 'http://dummyimage.com/141x100.png/cc0000/ffffff', 12, '02-01-2023');
insert into photos (photo_id, url, user_id, created) values (13, 'http://dummyimage.com/129x100.png/dddddd/000000', 13, '12-12-2023');
insert into photos (photo_id, url, user_id, created) values (14, 'http://dummyimage.com/177x100.png/cc0000/ffffff', 14, '20-04-2023');
insert into photos (photo_id, url, user_id, created) values (15, 'http://dummyimage.com/128x100.png/dddddd/000000', 15, '21-04-2023');
insert into photos (photo_id, url, user_id, created) values (16, 'http://dummyimage.com/171x100.png/5fa2dd/ffffff', 16, '12-11-2023');
insert into photos (photo_id, url, user_id, created) values (17, 'http://dummyimage.com/125x100.png/dddddd/000000', 17, '30-09-2023');
insert into photos (photo_id, url, user_id, created) values (18, 'http://dummyimage.com/129x100.png/ff4444/ffffff', 18, '05-02-2023');
insert into photos (photo_id, url, user_id, created) values (19, null, 19, null);
insert into photos (photo_id, url, user_id, created) values (20, null, 20, null);
insert into photos (photo_id, url, user_id, created) values (21, null, 21, null);
insert into photos (photo_id, url, user_id, created) values (22, null, 22, null);
insert into photos (photo_id, url, user_id, created) values (23, null, 23, null);
insert into photos (photo_id, url, user_id, created) values (24, 'http://dummyimage.com/179x100.png/ff4444/ffffff', 24, '11-11-2023');
insert into photos (photo_id, url, user_id, created) values (25, 'http://dummyimage.com/198x100.png/ff4444/ffffff', 25, '23-08-2023');
insert into photos (photo_id, url, user_id, created) values (26, 'http://dummyimage.com/188x100.png/5fa2dd/ffffff', 26, '22-08-2023');
insert into photos (photo_id, url, user_id, created) values (27, 'http://dummyimage.com/137x100.png/5fa2dd/ffffff', 27, '14-12-2023');
insert into photos (photo_id, url, user_id, created) values (28, null, 28, null);
insert into photos (photo_id, url, user_id, created) values (29, 'http://dummyimage.com/237x100.png/cc0000/ffffff', 29, '02-04-2023');
insert into photos (photo_id, url, user_id, created) values (30, 'http://dummyimage.com/131x100.png/cc0000/ffffff', 30, '06-06-2023');

-- Inserts values into the likes table
insert into likes (user_id, photo_id, likedate) values (1, 2, '10/09/2024');
insert into likes (user_id, photo_id, likedate) values (2, 2, '02/10/2024');
insert into likes (user_id, photo_id, likedate) values (3, 4, '27/11/2023');
insert into likes (user_id, photo_id, likedate) values (4, 3, '13/10/2023');
insert into likes (user_id, photo_id, likedate) values (5, 6, '23/05/2024');
insert into likes (user_id, photo_id, likedate) values (6, 5, null);
insert into likes (user_id, photo_id, likedate) values (7, 8, '17/10/2024');
insert into likes (user_id, photo_id, likedate) values (8, 7, '17/03/2023');
insert into likes (user_id, photo_id, likedate) values (9, 13, '18/04/2024');
insert into likes (user_id, photo_id, likedate) values (10, 13, null);
insert into likes (user_id, photo_id, likedate) values (11, 13, null);
insert into likes (user_id, photo_id, likedate) values (12, 11, '10/08/2024');
insert into likes (user_id, photo_id, likedate) values (13, 14, '28/04/2023');
insert into likes (user_id, photo_id, likedate) values (14, 3, '25/01/2024');
insert into likes (user_id, photo_id, likedate) values (15, 15, '30/09/2024');
insert into likes (user_id, photo_id, likedate) values (16, 16, '21/03/2023');
insert into likes (user_id, photo_id, likedate) values (17, 17, '30/01/2023');
insert into likes (user_id, photo_id, likedate) values (18, 18, null);
insert into likes (user_id, photo_id, likedate) values (19, 19, null);
insert into likes (user_id, photo_id, likedate) values (20, 20, '16/05/2024');
insert into likes (user_id, photo_id, likedate) values (21, 21, '08/01/2023');
insert into likes (user_id, photo_id, likedate) values (22, 22, null);
insert into likes (user_id, photo_id, likedate) values (23, 23, '30/04/2023');
insert into likes (user_id, photo_id, likedate) values (24, 24, null);
insert into likes (user_id, photo_id, likedate) values (25, 25, '02/02/2024');
insert into likes (user_id, photo_id, likedate) values (26, 26, '26/05/2023');
insert into likes (user_id, photo_id, likedate) values (27, 27, '02/09/2023');
insert into likes (user_id, photo_id, likedate) values (28, 28, null);
insert into likes (user_id, photo_id, likedate) values (29, 29, null);
insert into likes (user_id, photo_id, likedate) values (30, 30, null);


-- Inserts values into the follow table
insert into follow (follower_id, followed_person_id, follow_date) values (1, 1, '07/02/2023');
insert into follow (follower_id, followed_person_id, follow_date) values (2, 2, '17/03/2023');
insert into follow (follower_id, followed_person_id, follow_date) values (3, 3, '13/01/2023');
insert into follow (follower_id, followed_person_id, follow_date) values (4, 4, '28/10/2022');
insert into follow (follower_id, followed_person_id, follow_date) values (5, 5, null);
insert into follow (follower_id, followed_person_id, follow_date) values (6, 6, '13/11/2022');
insert into follow (follower_id, followed_person_id, follow_date) values (7, 7, '01/12/2022');
insert into follow (follower_id, followed_person_id, follow_date) values (8, 8, '25/10/2022');
insert into follow (follower_id, followed_person_id, follow_date) values (9, 9, '17/01/2023');
insert into follow (follower_id, followed_person_id, follow_date) values (10, 10, '08/03/2023');
insert into follow (follower_id, followed_person_id, follow_date) values (11, 11, null);
insert into follow (follower_id, followed_person_id, follow_date) values (12, 12, '27/11/2022');
insert into follow (follower_id, followed_person_id, follow_date) values (13, 13, null);
insert into follow (follower_id, followed_person_id, follow_date) values (14, 14, '26/02/2023');
insert into follow (follower_id, followed_person_id, follow_date) values (15, 15, null);
insert into follow (follower_id, followed_person_id, follow_date) values (16, 16, null);
insert into follow (follower_id, followed_person_id, follow_date) values (17, 17, '13/02/2023');
insert into follow (follower_id, followed_person_id, follow_date) values (18, 18, '05/02/2023');
insert into follow (follower_id, followed_person_id, follow_date) values (19, 19, null);
insert into follow (follower_id, followed_person_id, follow_date) values (20, 20, '08/01/2023');
insert into follow (follower_id, followed_person_id, follow_date) values (21, 21, null);
insert into follow (follower_id, followed_person_id, follow_date) values (22, 22, '21/11/2022');
insert into follow (follower_id, followed_person_id, follow_date) values (23, 23, '09/11/2022');
insert into follow (follower_id, followed_person_id, follow_date) values (24, 24, null);
insert into follow (follower_id, followed_person_id, follow_date) values (25, 25, null);
insert into follow (follower_id, followed_person_id, follow_date) values (26, 26, null);
insert into follow (follower_id, followed_person_id, follow_date) values (27, 27, '14/03/2023');
insert into follow (follower_id, followed_person_id, follow_date) values (28, 28, '09/02/2023');
insert into follow (follower_id, followed_person_id, follow_date) values (29, 29, '28/12/2022');
insert into follow (follower_id, followed_person_id, follow_date) values (30, 30, null);


--Question 1
SELECT username
FROM users 
JOIN follow ON users.user_id = follow.followed_person_id
where follow.follower_id > 0;

--Question 2
SELECT url
FROM photos
JOIN likes ON photos.photo_id = likes.photo_id
WHERE likes.user_id = 2;

--Question 3
SELECT username
FROM users
JOIN photos ON users.user_id = photos.user_id
WHERE photos.created IS NULL;

--Question 4
SELECT username
FROM users 
JOIN likes ON users.user_id = likes.user_id
JOIN photos ON likes.photo_id = photos.photo_id
WHERE users.user_id = photos.user_id;

-- Question 5
SELECT username
FROM users 
JOIN photos ON users.user_id = photos.user_id
LEFT JOIN likes ON photos.photo_id = likes.photo_id
WHERE likes.user_id IS NULL
  AND photos.created IS NOT NULL;


--Question 6
select distinct username
FROM users 
JOIN photos ON users.user_id = photos.user_id
LEFT JOIN likes ON photos.photo_id = likes.photo_id
WHERE likes.photo_id IS not NULL AND photos.created is NOT NULL;

--Question 7
SELECT username
FROM users
WHERE CHAR_LENGTH(username) > 10;

--Quetion 8
SELECT username
FROM users
WHERE username LIKE '%n';

--Question 9
UPDATE users
SET username = REPLACE(username, 'tschimekn', 'kappa12345')
WHERE username LIKE '%tschimekn%';

--Test to see if question 9 worked
--select * from users;














