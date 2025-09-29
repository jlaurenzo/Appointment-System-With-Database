#include "database.h"
#include <sqlite3.h>
#include <iostream>

static sqlite3* db = nullptr;

bool initDatabase(const std::string& dbName) {
    int rc = sqlite3_open(dbName.c_str(), &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << "\n";
        return false;
    }

    const char* createTableSQL =
        "CREATE TABLE IF NOT EXISTS appointments ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, "
        "service TEXT NOT NULL, "
        "stylist TEXT NOT NULL, "
        "schedule TEXT NOT NULL, "
        "paymentMethod TEXT NOT NULL, "
        "amountPaid INTEGER NOT NULL);";

    char* errMsg = nullptr;
    rc = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << "\n";
        sqlite3_free(errMsg);
        return false;
    }

    return true;
}

bool saveAppointment(
    const std::string& name,
    const std::string& service,
    const std::string& stylist,
    const std::string& schedule,
    const std::string& paymentMethod,
    int amountPaid
) {
    const char* insertSQL =
        "INSERT INTO appointments (name, service, stylist, schedule, paymentMethod, amountPaid) "
        "VALUES (?, ?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << "\n";
        return false;
    }

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, service.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, stylist.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, schedule.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, paymentMethod.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 6, amountPaid);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Insert failed: " << sqlite3_errmsg(db) << "\n";
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}
