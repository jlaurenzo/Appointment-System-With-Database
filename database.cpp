#include <iostream>
#include <sqlite3.h>
#include <string>

using namespace std;

// Function declarations
int createDB(const char* s);
int createTable(const char* s);
int insertData(const char* s,
               string name,
               string service,
               string stylist,
               string schedule,
               string paymentMethod,
               int amountPaid);

// Create Database
int createDB(const char* s) {
    sqlite3* DB;
    int exit = sqlite3_open(s, &DB);
    if (exit != SQLITE_OK) {
        cerr << "Error creating DB: " << sqlite3_errmsg(DB) << endl;
        return exit;
    }
    sqlite3_close(DB);
    return 0;
}

// Create Table
int createTable(const char* s) {
    sqlite3* DB;
    char* messageError;
    string sql = "CREATE TABLE IF NOT EXISTS Appointments("
                 "NO INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "NAME TEXT NOT NULL, "
                 "SERVICE TEXT NOT NULL, "
                 "STYLIST TEXT NOT NULL, "
                 "SCHEDULE TEXT NOT NULL, "
                 "PAYMENT_METHOD TEXT NOT NULL, "
                 "AMOUNT_PAID INT NOT NULL);";

    int exit = sqlite3_open(s, &DB);
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK) {
        cerr << "Error Creating Table: " << messageError << endl;
        sqlite3_free(messageError);
    } else {
        cout << "Table created successfully.\n";
    }
    sqlite3_close(DB);
    return 0;
}

// Insert Data (called from main.cpp)
int insertData(const char* s,
               string name,
               string service,
               string stylist,
               string schedule,
               string paymentMethod,
               int amountPaid)
{
    sqlite3* DB;
    char* messageError = nullptr;

    int exit = sqlite3_open_v2(s, &DB, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

    if (exit != SQLITE_OK) {
        cerr << "❌ Cannot open DB: " << sqlite3_errmsg(DB) << endl;
        return exit;
    }

    string sql = "INSERT INTO Appointments (NAME, SERVICE, STYLIST, SCHEDULE, PAYMENT_METHOD, AMOUNT_PAID) VALUES('" +
                 name + "', '" + service + "', '" + stylist + "', '" + schedule + "', '" + paymentMethod + "', " + to_string(amountPaid) + ");";

    sqlite3_exec(DB, "BEGIN TRANSACTION;", NULL, 0, NULL);
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    sqlite3_exec(DB, "COMMIT;", NULL, 0, NULL);

    if (exit != SQLITE_OK) {
        cerr << "❌ Error inserting data: " << messageError << endl;
        sqlite3_free(messageError);
    } else {
        cout << "✅ Appointment saved successfully!\n";
    }

    sqlite3_close(DB);
    return 0;
}