#ifndef DATABASE_H
#define DATABASE_H

#include <string>

// Open and initialize the SQLite database
bool initDatabase(const std::string& dbName);

// Save one appointment into the database
bool saveAppointment(
    const std::string& name,
    const std::string& service,
    const std::string& stylist,
    const std::string& schedule,
    const std::string& paymentMethod,
    int amountPaid
);

#endif
