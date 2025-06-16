-- 创建 users 表
CREATE TABLE IF NOT EXISTS users (
    user_id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT NOT NULL UNIQUE,
    password TEXT NOT NULL,
    email TEXT UNIQUE,
    phone TEXT UNIQUE,
    role TEXT CHECK(role IN ('admin', 'user')) NOT NULL DEFAULT 'user',
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- 创建 devices 表
CREATE TABLE IF NOT EXISTS devices (
    device_id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    type TEXT,
    location TEXT,
    manufacturer TEXT,
    model TEXT,
    status TEXT DEFAULT 'NORMAL',
    installation_date DATE
);

-- 创建 data 表
CREATE TABLE IF NOT EXISTS data (
    data_id INTEGER PRIMARY KEY AUTOINCREMENT,
    device_id INTEGER NOT NULL,
    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    temperature REAL,
    humidity REAL,
    light REAL,
    co2 REAL,
    pressure REAL,
    FOREIGN KEY (device_id) REFERENCES devices(device_id)
);

-- 创建 alarm_rules 表
CREATE TABLE IF NOT EXISTS alarm_rules (
    rule_id INTEGER PRIMARY KEY AUTOINCREMENT,
    device_id INTEGER NOT NULL,
    description TEXT,
    condition TEXT NOT NULL,
    action TEXT NOT NULL,
    FOREIGN KEY (device_id) REFERENCES devices(device_id)
);

-- 创建 alarm_records 表
CREATE TABLE IF NOT EXISTS alarm_records (
    alarm_id INTEGER PRIMARY KEY AUTOINCREMENT,
    device_id INTEGER NOT NULL,
    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    content TEXT NOT NULL,
    status TEXT CHECK(status IN ('UNHANDLED', 'HANDLED')) DEFAULT 'UNHANDLED',
    note TEXT,
    FOREIGN KEY (device_id) REFERENCES devices(device_id)
);

-- 创建 system_logs 表
CREATE TABLE IF NOT EXISTS system_logs (
    log_id INTEGER PRIMARY KEY AUTOINCREMENT,
    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    log_type TEXT NOT NULL,
    log_level TEXT CHECK(log_level IN ('INFO','WARNING','ERROR','CRITICAL')) NOT NULL,
    content TEXT NOT NULL,
    user_id INTEGER,
    device_id INTEGER,
    FOREIGN KEY (user_id) REFERENCES users(user_id),
    FOREIGN KEY (device_id) REFERENCES devices(device_id)
);

-- 创建索引优化查询性能
CREATE INDEX IF NOT EXISTS idx_data_device ON data(device_id);
CREATE INDEX IF NOT EXISTS idx_alarm_device ON alarm_records(device_id);
CREATE INDEX IF NOT EXISTS idx_logs_time ON system_logs(timestamp);

-- 初始化管理员用户
INSERT OR IGNORE INTO users (username, password, email, role)
VALUES ('admin', '123456', 'admin@system.com', 'admin');

-- 创建触发器：用户信息更新时间
CREATE TRIGGER IF NOT EXISTS update_user_timestamp
AFTER UPDATE ON users
FOR EACH ROW
BEGIN
    UPDATE users SET updated_at = CURRENT_TIMESTAMP WHERE user_id = OLD.user_id;
END;