#include <sqlite3.h>
#include <string>
#include <iostream>
using namespace std;

int createDB(const char* s);
int createTable(const char* s);
bool isSlotTaken(const char* s, const string& day, const string& time, const string& stylist);
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
    string sql = "CREATE TABLE IF NOT EXISTS Appointments("
                "NO INTEGER PRIMARY KEY AUTOINCREMENT, "
                "NAME TEXT NOT NULL, "
                "SERVICE TEXT NOT NULL, "
                "STYLIST TEXT NOT NULL, "
                "DAY TEXT NOT NULL, "
                "DATE INT NOT NULL, "
                "TIME TEXT NOT NULL, "
                "PAYMENT_METHOD TEXT NOT NULL, "
                "AMOUNT_PAID INT NOT NULL);";

    int exit = sqlite3_open(s, &DB);
    sqlite3_exec(DB, sql.c_str(),nullptr, nullptr, nullptr);
    sqlite3_close(DB);
    return exit;
}

bool isSlotTaken(const char* s, const string& day, const string& time, const string& stylist, int date) {
    sqlite3* DB;
    sqlite3_stmt* stmt;
    if (sqlite3_open(s, &DB) != SQLITE_OK) return true;

    const char* sql = "SELECT COUNT(*) FROM Appointments WHERE DAY = ? AND DATE = ? AND TIME = ? AND STYLIST = ?;";
    sqlite3_prepare_v2(DB, sql, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, day.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, date);
    sqlite3_bind_text(stmt, 3, time.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, stylist.c_str(), -1, SQLITE_TRANSIENT);

    bool taken = false;
    if (sqlite3_step(stmt) == SQLITE_ROW)
        taken = (sqlite3_column_int(stmt, 0) > 0);

    sqlite3_finalize(stmt);
    sqlite3_close(DB);
    return taken;
}


int insertData(const char* s,
               string name,
               string service,
               string stylist,
               string day,
               int date,
               string time,
               string paymentMethod,
               int amountPaid)
{
    sqlite3* DB;
    int exit = sqlite3_open_v2(s, &DB, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, nullptr);

    string sql = "INSERT INTO Appointments (NAME, SERVICE, STYLIST, DAY, DATE, TIME, PAYMENT_METHOD, AMOUNT_PAID) "
                 "VALUES('" + name + "', '" + service + "', '" + stylist + "', '" + day + "', " +
                 to_string(date) + ", '" + time + "', '" + paymentMethod + "', " + to_string(amountPaid) + ");";

    sqlite3_exec(DB, "BEGIN TRANSACTION;", nullptr, nullptr, nullptr);
    sqlite3_exec(DB, sql.c_str(), nullptr, nullptr, nullptr);
    sqlite3_exec(DB, "COMMIT;", nullptr, nullptr, nullptr);

    sqlite3_close(DB);
    return exit;
}


int displayAllAppointments(const char* s) {
    sqlite3* DB;
    sqlite3_stmt* stmt;
    int exit = sqlite3_open(s, &DB);
    if (exit != SQLITE_OK) return exit;

    const char* sql = "SELECT NAME, SERVICE, STYLIST, DAY, DATE, TIME, PAYMENT_METHOD, AMOUNT_PAID FROM Appointments;";

    if (sqlite3_prepare_v2(DB, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        cout << "Failed to prepare statement.\n";
        sqlite3_close(DB);
        return 1;
    }

    cout << "\n* * * * * * * * * * * * * * * * Scheduled Appointments * * * * * * * * * * * * * * * * * * *\n";
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        cout << "*-----------------------------------------------------------------------------------------*\n";
        cout << "*Name: " << sqlite3_column_text(stmt, 0) << "\n";
        cout << "*Service: " << sqlite3_column_text(stmt, 1) << "\n";
        cout << "*Stylist: " << sqlite3_column_text(stmt, 2) << "\n";
        cout << "*Day: " << sqlite3_column_text(stmt, 3) << "\n";
        cout << "*Date: " << sqlite3_column_int(stmt, 4) << "\n";
        cout << "*Time: " << sqlite3_column_text(stmt, 5) << "\n";
        cout << "*Payment Method: " << sqlite3_column_text(stmt, 6) << "\n";
        cout << "*Amount Paid: " << sqlite3_column_int(stmt, 7) << "\n";
    }
    cout << "*----------------------------------------------------------------------------------------*\n";
    cout << "*                                End of Schedule List                                    *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * *\n";

    sqlite3_finalize(stmt);
    sqlite3_close(DB);
    return 0;
}


int rescheduleAppointment(const char* s, const string& name)
{
    sqlite3* DB;
    sqlite3_stmt* stmt;

    if (sqlite3_open(s, &DB) != SQLITE_OK) {
        cout << "Error opening database.\n";
        return 1;
    }

    const char* findSql =
        "SELECT DATE, DAY, TIME, STYLIST FROM Appointments "
        "WHERE NAME = ? COLLATE NOCASE "
        "ORDER BY NO DESC LIMIT 1;";

    if (sqlite3_prepare_v2(DB, findSql, -1, &stmt, nullptr) != SQLITE_OK) {
        cout << "Failed to prepare query.\n";
        sqlite3_close(DB);
        return 2;
    }

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);

    int date = 0;
    string day, oldTime, stylist;

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        date = sqlite3_column_int(stmt, 0);
        day = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        oldTime = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        stylist = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
    } else {
        cout << "No appointment found for " << name << ".\n";
        sqlite3_finalize(stmt);
        sqlite3_close(DB);
        return 3;
    }
    sqlite3_finalize(stmt);

    cout << "\nYour current appointment:\n";
    cout << "Date: " << date << "\n";
    cout << "Day: " << day << "\n";
    cout << "Time: " << oldTime << "\n";
    cout << "Stylist: " << stylist << "\n\n";

    string timeSlots[8] = {
        "", "9:00am-9:45am", "11:00am-11:45am", "1:00pm-1:45pm",
        "3:00pm-3:45pm", "5:00pm-5:45pm", "7:00pm-7:45pm", "9:00pm-9:45pm"
    };

    int currentIndex = 0;
    for (int i = 1; i <= 7; ++i) {
        if (oldTime == timeSlots[i]) {
            currentIndex = i;
            break;
        }
    }

    if (currentIndex == 7) {
        cout << "You already have the last schedule of the day. Book again for the next day.\n";
        sqlite3_close(DB);
        return 4;
    }

    cout << "Available new time slots:\n";
    for (int i = currentIndex + 1; i <= 7; ++i)
        cout << "Input (" << i << ") for " << timeSlots[i] << "\n";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice <= currentIndex || choice < 1 || choice > 7) {
        cout << "Invalid selection. You can only choose a later time.\n";
        sqlite3_close(DB);
        return 5;
    }

    string newTime = timeSlots[choice];

    const char* checkSql = "SELECT COUNT(*) FROM Appointments WHERE DAY=? AND DATE=? AND TIME=? AND STYLIST=?;";
    sqlite3_prepare_v2(DB, checkSql, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, day.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, date);
    sqlite3_bind_text(stmt, 3, newTime.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, stylist.c_str(), -1, SQLITE_TRANSIENT);

    bool taken = false;
    if (sqlite3_step(stmt) == SQLITE_ROW)
        taken = (sqlite3_column_int(stmt, 0) > 0);
    sqlite3_finalize(stmt);

    if (taken) {
        cout << "Sorry, " << stylist << " is already booked on " << date << " " << day << " at " << newTime << ".\n";
        sqlite3_close(DB);
        return 6;
    }

    const char* updateSql = "UPDATE Appointments SET TIME = ? WHERE NAME = ? AND DATE = ? AND DAY = ? AND TIME = ?;";
    sqlite3_prepare_v2(DB, updateSql, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, newTime.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, date);
    sqlite3_bind_text(stmt, 4, day.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, oldTime.c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) == SQLITE_DONE)
        cout << "Successfully rescheduled to " << newTime << " on " << day << " " << date << ".\n";
    else
        cout << "Failed to reschedule.\n";

    sqlite3_finalize(stmt);
    sqlite3_close(DB);
    return 0;
}
