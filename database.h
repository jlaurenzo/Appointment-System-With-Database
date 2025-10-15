#ifndef DATABASE_H
#define DATABASE_H

int createDB(const char* s);
int createTable(const char* s);
int insertData(const char* s,
               std::string name,
               std::string service,
               std::string stylist,
               std::string schedule,
               std::string paymentMethod,
               int amountPaid);

#endif
