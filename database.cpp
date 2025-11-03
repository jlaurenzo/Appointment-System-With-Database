#include <sqlite3.h>
#include <string>
#include <iostream>
using namespace std;

int createDB(const char* s);
int createTable(const char* s);
bool isSlotTaken(const char* s, const string& day, const string& time);
int insertData(const char* s,
               string name,
               string service,
               string stylist,
               string day,
               string time,
               string paymentMethod,
               int amountPaid);
int displayAllAppointments(const char* s);

int createDB(const char* s) {
    sqlite3* DB;
    int exit = sqlite3_open(s, &DB);
    sqlite3_close(DB);
    return exit;
}

int createTable(const char* s) {
    sqlite3* DB;
    char* messageError = nullptr;
    string sql = "CREATE TABLE IF NOT EXISTS Appointments("
                 "NO INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "NAME TEXT NOT NULL, "
                 "SERVICE TEXT NOT NULL, "
                 "STYLIST TEXT NOT NULL, "
                 "DAY TEXT NOT NULL, "
                 "TIME TEXT NOT NULL, "
                 "PAYMENT_METHOD TEXT NOT NULL, "
                 "AMOUNT_PAID INT NOT NULL);";

    int exit = sqlite3_open(s, &DB);
    sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    sqlite3_close(DB);
    return exit;
}

bool isSlotTaken(const char* s, const string& day, const string& time) {
    sqlite3* DB;
    sqlite3_stmt* stmt;
    int exit = sqlite3_open(s, &DB);
    if (exit != SQLITE_OK) return true; // safety fallback

    const char* sql = "SELECT COUNT(*) FROM Appointments WHERE DAY = ? AND TIME = ?;";
    sqlite3_prepare_v2(DB, sql, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, day.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, time.c_str(), -1, SQLITE_TRANSIENT);

    bool taken = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int count = sqlite3_column_int(stmt, 0);
        taken = (count > 0);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(DB);
    return taken;
}

int insertData(const char* s,
               string name,
               string service,
               string stylist,
               string day,
               string time,
               string paymentMethod,
               int amountPaid)
{
    sqlite3* DB;
    char* messageError = nullptr;
    int exit = sqlite3_open_v2(s, &DB, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

    string sql = "INSERT INTO Appointments (NAME, SERVICE, STYLIST, DAY, TIME, PAYMENT_METHOD, AMOUNT_PAID) VALUES('" +
                 name + "', '" + service + "', '" + stylist + "', '" + day + "', '" + time + "', '" + paymentMethod + "', " +
                 to_string(amountPaid) + ");";

    sqlite3_exec(DB, "BEGIN TRANSACTION;", NULL, 0, NULL);
    sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    sqlite3_exec(DB, "COMMIT;", NULL, 0, NULL);

    sqlite3_close(DB);
    return exit;
}

int displayAllAppointments(const char* s) {
    sqlite3* DB;
    sqlite3_stmt* stmt;
    int exit = sqlite3_open(s, &DB);
    if (exit != SQLITE_OK) return exit;

    const char* sql = "SELECT NAME, SERVICE, STYLIST, DAY, TIME, PAYMENT_METHOD, AMOUNT_PAID FROM Appointments;";

    if (sqlite3_prepare_v2(DB, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_close(DB);
    }
    cout << "================================ Scheduled Appointments ===================================\n";

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        cout << "------------------------------------------------------------------------------------------\n";
        cout << "Name: " << sqlite3_column_text(stmt, 0) << "\n";
        cout << "Service: " << sqlite3_column_text(stmt, 1) << "\n";
        cout << "Stylist: " << sqlite3_column_text(stmt, 2) << "\n";
        cout << "Day: " << sqlite3_column_text(stmt, 3) << "\n";
        cout << "Time: " << sqlite3_column_text(stmt, 4) << "\n";
        cout << "Payment Method: " << sqlite3_column_text(stmt, 5) << "\n";
        cout << "Amount Paid: " << sqlite3_column_int(stmt, 6) << "\n";
    }
    cout << "------------------------------------------------------------------------------------------\n";
    cout << "End of weekly schedule.\n";

    sqlite3_finalize(stmt);
    sqlite3_close(DB);
    return 0;
}


