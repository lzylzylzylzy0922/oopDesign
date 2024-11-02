CREATE TABLE user (
    user_id INT UNIQUE AUTO_INCREMENT PRIMARY KEY,
    birthday DATE,
    register_date DATETIME,
    location ENUM('LOCATION1', 'LOCATION2', 'LOCATION3'), 
    avatar VARCHAR(255),
    phone_number VARCHAR(20)
) AUTO_INCREMENT=10000;

CREATE TABLE account (
    account_id VARCHAR(50) UNIQUE NOT NULL PRIMARY KEY,
    user_id INT,
    type ENUM('QQ', 'WECHAT', 'WEIBO'),
    account_name VARCHAR(100),
    password VARCHAR(255)
);

CREATE TABLE account_binding (
    user_id INT,
    account_id_1 VARCHAR(50),
    account_id_2 VARCHAR(50),
    create_time DATETIME
);

CREATE TABLE friendship (
    user_id INT,
    friend_id INT,
    type ENUM('QQ', 'WECHAT', 'WEIBO')
);

CREATE TABLE friend_request (
    user_id INT,
    friend_id INT,
    type ENUM('QQ', 'WECHAT', 'WEIBO'),
    request_time DATETIME,
    status ENUM('PENDING', 'REJECTED')
);

CREATE TABLE user_group (
    group_id INT PRIMARY KEY,
    name VARCHAR(100),
    type ENUM('QQ', 'WECHAT'),
    owner_id INT,
    create_time DATETIME
);

CREATE TABLE group_member (
    group_id INT,
    user_id INT,
    role ENUM('OWNER', 'ADMIN', 'MEMBER')
);

CREATE TABLE user_service (
    user_id INT,
    type ENUM('QQ', 'WECHAT', 'WEIBO'),
    status INT,
    create_time DATE
);

CREATE TABLE login_status (
    user_id INT,
    type ENUM('QQ', 'WECHAT', 'WEIBO'),
    login_time DATETIME,
    is_active INT,
    ip VARCHAR(45),
    port INT
);