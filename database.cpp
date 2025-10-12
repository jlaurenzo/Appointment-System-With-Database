#include <iostream>
#include <stdio.h>
#include <sqlite3.h>

using namespace std;

static int createDB(const char* s); //Gagawin nya yung database
static int createTable(const char* s); //Gagawin nya yung table
static int insertData(const char* s); //For insert ng data


int main() {

    const char* dir = "Appointments.db";
    sqlite3* DB;

    createDB(dir); //Sya mag call ng function sa taas
    createTable(dir); //mag call ng function sa taas
    insertData(dir); //mag call ng function para mag insert ng data.

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
        "PAYMENT_METHOD     TEXT NOT NULL,  "
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

static int insertData(const char* s)
{
    sqlite3* DB;
    char* messageError;

    int exit = sqlite3_open(s, &DB);
    string sql("INSERT INTO Appointments "
                "(NAME, SERVICE, STYLIST, SCHEDULE, PAYMENT_METHOD, AMOUNT_PAID) " 
                "VALUES('John','HairCut', 'Juan', '8', 'Gcash', '200' );");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error Inserting Data!" << "\n";
        sqlite3_free(messageError);
    } else {
        cout <<"Data Recorded Successfully!" <<"\n";
    }
return 0;
}