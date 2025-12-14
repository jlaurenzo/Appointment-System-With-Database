#ifndef DATABASE_H
#define DATABASE_H
#include <string>
using namespace std;

int createDB(const char* s);
int createTable(const char* s);
bool isSlotTaken(const char* s, const string& day, const string& time, const string& stylist, int date);
int insertData(const char* s,
               string name,
               string service,
               string stylist,
               string day,
               int date,
               string time,
               string paymentMethod,
               int amountPaid);
int displayAllAppointments(const char* s);
int rescheduleAppointment(const char* s, const string& name);

#endif
