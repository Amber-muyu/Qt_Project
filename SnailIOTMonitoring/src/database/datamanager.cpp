#include "datamanager.h"

DataManager::DataManager(QObject *parent) : QObject(parent)
{
    m_db = QSqlDatabase::database();          // 默认连接
    if (!m_db.isValid() || !m_db.isOpen())
        qCritical() << "[DataManager] invalid db connection!";
}

DataManager& DataManager::instance()
{
    static DataManager instance;
    return instance;
}

bool DataManager::addData(const QVariantMap &data)
{
    if (!validateData(data,/*insert=*/true)) {
        qWarning() << "Invalid data format";
        return false;
    }

    QSqlQuery query(m_db);
    query.prepare("INSERT INTO data (device_id, temperature, humidity, light, co2, pressure) "
                  "VALUES (:device_id, :temperature, :humidity, :light, :co2, :pressure)");

    query.bindValue(":device_id", data["device_id"]);
    query.bindValue(":temperature", data["temperature"]);
    query.bindValue(":humidity", data["humidity"]);
    query.bindValue(":light", data["light"]);
    query.bindValue(":co2", data["co2"]);
    query.bindValue(":pressure", data["pressure"]);

    if (!query.exec()) {
        qWarning() << "Failed to add data:" << query.lastError().text();
        return false;
    }
    return true;
}

bool DataManager::updateData(int dataId, const QVariantMap &updateData)
{
    if (!validateData(updateData, /*insert=*/false)) {
        qWarning() << "Invalid update data format";
        return false;
    }

    QSqlQuery query(m_db);
    query.prepare("UPDATE data SET "
                  "device_id = :device_id, "
                  "temperature = :temperature, "
                  "humidity = :humidity, "
                  "light = :light, "
                  "co2 = :co2, "
                  "pressure = :pressure "
                  "WHERE data_id = :data_id");

    query.bindValue(":data_id", dataId);
    query.bindValue(":device_id", updateData["device_id"]);
    query.bindValue(":temperature", updateData["temperature"]);
    query.bindValue(":humidity", updateData["humidity"]);
    query.bindValue(":light", updateData["light"]);
    query.bindValue(":co2", updateData["co2"]);
    query.bindValue(":pressure", updateData["pressure"]);

    if (!query.exec()) {
        qWarning() << "Failed to update data:" << query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}

bool DataManager::deleteData(int dataId)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM data WHERE data_id = :data_id");
    query.bindValue(":data_id", dataId);

    if (!query.exec()) {
        qWarning() << "Failed to delete data:" << query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}

bool DataManager::deleteDataByDeviceId(int deviceId)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM data WHERE device_id = :device_id");
    query.bindValue(":device_id", deviceId);

    if (!query.exec()) {
        qWarning() << "Failed to delete data by device ID:" << query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}

QVariantMap DataManager::getDataById(int dataId)
{
    QVariantMap data;
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM data WHERE data_id = :data_id");
    query.bindValue(":data_id", dataId);

    if (query.exec() && query.next()) {
        data["data_id"] = query.value("data_id");
        data["device_id"] = query.value("device_id");
        data["timestamp"] = query.value("timestamp");
        data["temperature"] = query.value("temperature");
        data["humidity"] = query.value("humidity");
        data["light"] = query.value("light");
        data["co2"] = query.value("co2");
        data["pressure"] = query.value("pressure");
    } else {
        qWarning() << "Failed to get data by ID:" << query.lastError().text();
    }

    return data;
}

QList<QVariantMap> DataManager::getAllData()
{
    QList<QVariantMap> dataList;
    QSqlQuery query(m_db);

    if (query.exec("SELECT * FROM data ORDER BY timestamp DESC")) {
        while (query.next()) {
            QVariantMap data;
            data["data_id"] = query.value("data_id");
            data["device_id"] = query.value("device_id");
            data["timestamp"] = query.value("timestamp");
            data["temperature"] = query.value("temperature");
            data["humidity"] = query.value("humidity");
            data["light"] = query.value("light");
            data["co2"] = query.value("co2");
            data["pressure"] = query.value("pressure");
            dataList.append(data);
        }
    } else {
        qWarning() << "Failed to get all data:" << query.lastError().text();
    }

    return dataList;
}

QList<QVariantMap> DataManager::getDataByDeviceId(int deviceId)
{
    QList<QVariantMap> dataList;
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM data WHERE device_id = :device_id ORDER BY timestamp DESC");
    query.bindValue(":device_id", deviceId);

    if (query.exec()) {
        while (query.next()) {
            QVariantMap data;
            data["data_id"] = query.value("data_id");
            data["device_id"] = query.value("device_id");
            data["timestamp"] = query.value("timestamp");
            data["temperature"] = query.value("temperature");
            data["humidity"] = query.value("humidity");
            data["light"] = query.value("light");
            data["co2"] = query.value("co2");
            data["pressure"] = query.value("pressure");
            dataList.append(data);
        }
    } else {
        qWarning() << "Failed to get data by device ID:" << query.lastError().text();
    }

    return dataList;
}

QList<QVariantMap> DataManager::getDataByTimeRange(const QString &start, const QString &end)
{
    QList<QVariantMap> dataList;
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM data WHERE timestamp BETWEEN :start AND :end ORDER BY timestamp DESC");
    query.bindValue(":start", start);
    query.bindValue(":end", end);

    if (query.exec()) {
        while (query.next()) {
            QVariantMap data;
            data["data_id"] = query.value("data_id");
            data["device_id"] = query.value("device_id");
            data["timestamp"] = query.value("timestamp");
            data["temperature"] = query.value("temperature");
            data["humidity"] = query.value("humidity");
            data["light"] = query.value("light");
            data["co2"] = query.value("co2");
            data["pressure"] = query.value("pressure");
            dataList.append(data);
        }
    } else {
        qWarning() << "Failed to get data by time range:" << query.lastError().text();
    }

    return dataList;
}

QList<QVariantMap> DataManager::getDeviceDataByTimeRange(int deviceId, const QDateTime &start, const QDateTime &end)
{
    QList<QVariantMap> dataList;
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM data WHERE device_id = :device_id AND timestamp BETWEEN :start AND :end ORDER BY timestamp DESC");
    query.bindValue(":device_id", deviceId);
    query.bindValue(":start", start);
    query.bindValue(":end", end);

    if (query.exec()) {
        while (query.next()) {
            QVariantMap data;
            data["data_id"] = query.value("data_id");
            data["device_id"] = query.value("device_id");
            data["timestamp"] = query.value("timestamp");
            data["temperature"] = query.value("temperature");
            data["humidity"] = query.value("humidity");
            data["light"] = query.value("light");
            data["co2"] = query.value("co2");
            data["pressure"] = query.value("pressure");
            dataList.append(data);
        }
    } else {
        qWarning() << "Failed to get device data by time range:" << query.lastError().text();
    }

    return dataList;
}

bool DataManager::validateData(const QVariantMap &data, bool isInsert)
{
    // 检查必填字段
    if (isInsert && !data.contains("device_id")) {
        qWarning() << "Device ID is required";
        return false;
    }

    // 检查数据类型
    if (data.contains("temperature") && !data["temperature"].canConvert<double>()) {
        qWarning() << "Invalid temperature value";
        return false;
    }

    if (data.contains("humidity") && !data["humidity"].canConvert<double>()) {
        qWarning() << "Invalid humidity value";
        return false;
    }

    if (data.contains("light") && !data["light"].canConvert<double>()) {
        qWarning() << "Invalid light value";
        return false;
    }

    if (data.contains("co2") && !data["co2"].canConvert<double>()) {
        qWarning() << "Invalid CO2 value";
        return false;
    }

    if (data.contains("pressure") && !data["pressure"].canConvert<double>()) {
        qWarning() << "Invalid pressure value";
        return false;
    }

    return true;
}

QList<QVariantMap> DataManager::searchData(const QString &keyword)
{
    QList<QVariantMap> dataList;

    if (keyword.isEmpty()) {
        return getAllData(); // 如果关键字为空，返回所有数据
    }

    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT * FROM data
        WHERE CAST(device_id AS TEXT) LIKE :kw OR
              CAST(temperature AS TEXT) LIKE :kw OR
              CAST(humidity AS TEXT) LIKE :kw OR
              CAST(light AS TEXT) LIKE :kw OR
              CAST(co2 AS TEXT) LIKE :kw OR
              CAST(pressure AS TEXT) LIKE :kw OR
              strftime('%Y-%m-%d %H:%M:%S', timestamp) LIKE :kw
        ORDER BY timestamp DESC
    )");

    query.bindValue(":kw", "%" + keyword + "%");

    if (!query.exec()) {
        qWarning() << "Data search failed:" << query.lastError().text();
        return dataList;
    }

    while (query.next()) {
        QVariantMap data;
        data["data_id"] = query.value("data_id");
        data["device_id"] = query.value("device_id");
        data["timestamp"] = query.value("timestamp");
        data["temperature"] = query.value("temperature");
        data["humidity"] = query.value("humidity");
        data["light"] = query.value("light");
        data["co2"] = query.value("co2");
        data["pressure"] = query.value("pressure");
        dataList.append(data);
    }

    return dataList;
}

bool DataManager::exportToCsv(const QList<QVariantMap> &data, const QString &filePath)
{
    if (data.isEmpty())
        return false;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qWarning() << "无法打开文件:" << file.errorString();
        return false;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8");                 // Excel 识别 UTF‑8
    out << QChar(0xFEFF);                  // 写入 BOM，防止中文乱码

    /* 1. 写表头 */
    QStringList headers = {
        "device_id",
        "timestamp",
        "temperature",
        "humidity",
        "light",
        "co2",
        "pressure"
    };
    out << headers.join(',') << '\n';

    /* 2. 写每行数据：用双引号包裹，并转义内部双引号 */
    for (const QVariantMap &row : data) {
        QStringList line;
        for (const QString &header : headers) {
            QString value = row.value(header).toString();
            // 特殊处理 timestamp 字段（修复时间格式）
            if (header == "timestamp") {
                QDateTime dt = QDateTime::fromString(value, Qt::ISODate);
                if (dt.isValid())
                    value = dt.toString("yyyy-MM-dd HH:mm:ss");
            }
            value.replace('"', "\"\"");          // CSV 规范：双引号转义
            line << '"' + value + '"';
        }
        out << line.join(',') << '\n';
    }
    file.close();
    return true;
}
