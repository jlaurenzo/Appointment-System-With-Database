#include "database.h"
#include <sqlite3.h>
#include <iostream>

static sqlite3* db = nullptr;

bool initDatabase(const std::string& dbName) {
    if (sqlite3_open(dbName.c_str(), &db)) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << "\n";
        return false;
    }

    const char* sql = "CREATE TABLE IF NOT EXISTS appointments ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "Name TEXT, "
                      "Service TEXT, "
                      "Stylist TEXT, "
                      "Schedule TEXT, "
                      "Payment TEXT, "
                      "AmountPaid INTEGER);";   // includes amountPaid

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
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
    std::string sql = "INSERT INTO appointments (name, service, stylist, schedule, payment, amountPaid) "
                      "VALUES (?, ?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Prepare failed: " << sqlite3_errmsg(db) << "\n";
        return false;
    }

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, service.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, stylist.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, schedule.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, paymentMethod.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 6, amountPaid);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << "\n";
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}
