#include <iostream>
#include <stdio.h>
#include <sqlite3.h>

using namespace std;

static int createDB(const char* s); //Gagawin nya yung database
static int createTable(const char* s); //Gagawin nya yung table


int main() {

    const char* dir = "Appointments.db";
    sqlite3* DB;

    createDB(dir); //Sya mag call ng function sa taas
    createTable(dir); //mag call ng function sa taas

    return 0;
}

static int createDB(const char* s) {
    sqlite3 * DB;
    int exit = 0;

    exit = sqlite3_open(s, &DB); // mag open ng database, pag wala pa, create sya ng database.

    sqlite3_close(DB);

    return 0;
}

static int createTable(const char* s) {
    sqlite3*  DB;

    string sql = "CREATE TABLE IF NOT EXISTS Appointments("
        "NO INTEGER PRIMARY KEY AUTOINCREMENT, "
        "NAME               TEXT NOT NULL, "
        "SERVICE            TEXT NOT NULL, "
        "STYLIST            TEXT NOT NULL, "
        "SCHEDULE           TEXT NOT NULL, "
        "PAYMENT_METHOD     INT NOT NULL,  "
        "AMOUNT_PAID        INT NOT NULL);";
try {
    int exit = 0;
    exit = sqlite3_open(s, &DB);

    char* messageError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK) {
        cerr << "Error Create Table!" << messageError << "\n";
        sqlite3_free(messageError);
    } else {
        cout << "Table created Successfully" << "\n";
        sqlite3_close(DB);
    }
}
catch (const exception & e)
{
    cerr << e.what();
}
return 0;
}