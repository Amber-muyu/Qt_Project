-- users
CREATE TABLE IF NOT EXISTS users (
    user_id   INTEGER PRIMARY KEY AUTOINCREMENT,
    username  TEXT UNIQUE NOT NULL,
    password  TEXT NOT NULL,
    email     TEXT UNIQUE,
    phone     TEXT UNIQUE,
    role      TEXT CHECK(role IN ('admin','user')) NOT NULL DEFAULT 'user',
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    updated_at DATETIME DEFAULT CURRENT_TIMESTAMP
);
-- devices
CREATE TABLE IF NOT EXISTS devices (
    device_id INTEGER PRIMARY KEY AUTOINCREMENT,
    name      TEXT,
    type      TEXT,
    location  TEXT,
    manufacturer TEXT,
    model     TEXT,
    status    TEXT CHECK(status IN ('ONLINE', 'OFFLINE', 'FAULT')),
    installation_date DATETIME
);
-- data
CREATE TABLE IF NOT EXISTS data (
    data_id    INTEGER PRIMARY KEY AUTOINCREMENT,
    device_id  INTEGER,
    timestamp  DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    temperature REAL,
    humidity   REAL,
    light      REAL,
    co2        REAL,
    pressure   REAL,
    FOREIGN KEY(device_id) REFERENCES devices(device_id) ON DELETE CASCADE
);
-- alarm_rules
CREATE TABLE IF NOT EXISTS alarm_rules (
    rule_id    INTEGER PRIMARY KEY AUTOINCREMENT,
    device_id  INTEGER,
    description TEXT,
    condition   TEXT,
    action      TEXT,
    FOREIGN KEY(device_id) REFERENCES devices(device_id) ON DELETE CASCADE
);
-- alarm_records
CREATE TABLE IF NOT EXISTS alarm_records (
    alarm_id   INTEGER PRIMARY KEY AUTOINCREMENT,
    device_id  INTEGER,
    timestamp  DATETIME,
    content    TEXT,
    status     TEXT CHECK(status IN ('UNHANDLED', 'HANDLED')) DEFAULT 'UNHANDLED',
    note       TEXT,
    FOREIGN KEY(device_id) REFERENCES devices(device_id) ON DELETE CASCADE
);
-- system_logs
CREATE TABLE IF NOT EXISTS system_logs (
    log_id    INTEGER PRIMARY KEY AUTOINCREMENT,
    timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
    log_type  TEXT,
    log_level TEXT CHECK(log_level IN ('INFO','WARNING','ERROR','CRITICAL')) NOT NULL,
    content   TEXT,
    user_id   INTEGER,
    device_id INTEGER,
    FOREIGN KEY(user_id)  REFERENCES users(user_id)   ON DELETE SET NULL,
    FOREIGN KEY(device_id) REFERENCES devices(device_id) ON DELETE SET NULL
);

-- 创建索引
CREATE INDEX IF NOT EXISTS idx_data_device ON data(device_id);
CREATE INDEX IF NOT EXISTS idx_alarm_device ON alarm_records(device_id);
CREATE INDEX IF NOT EXISTS idx_logs_time ON system_logs(timestamp);

-- 初始化管理员用户
INSERT OR IGNORE INTO users (username, password, email, role)
VALUES ('admin', '8d969eef6ecad3c29a3a629280e686cf0c3f5d5a86aff3ca12020c923adc6c92', 'admin@system.com', 'admin');