# 🧾 Appointment System with Database

A simple **Salon & Barbershop Appointment System** built in **C++** with **SQLite3** as its database.  
This console-based program allows users to book, view, and manage salon appointments through an interactive text-based interface.

---

## 📘 About the Project

This project was developed as a **school project** to demonstrate the integration of **C++** programming with a **SQLite3 database**.  
It simulates a booking system where customers can choose services, select stylists, pick available days and times, and confirm payments.

---

## ⚙️ Features

- 📅 **Book Appointments**
  - Choose between Hair or Treatment services  
  - Select stylists and available schedules  
  - Process mock payments through multiple options  

- 🧾 **View Appointments**
  - Displays all stored appointments from the SQLite database  

- 💾 **Database Integration**
  - SQLite3 is used to store and retrieve appointment data  
  - Data is automatically created and saved in `appointments.db`  

- 🖥️ **Console UI**
  - Fully interactive terminal interface using step-by-step prompts  

---

## 🧠 Technologies Used

| Component | Description |
|------------|-------------|
| **Language** | C++ |
| **Database** | SQLite3 |
| **IDE/Compiler** | Code::Blocks / Visual Studio / MinGW |
| **Database File** | `appointments.db` |

---

## 📂 File Structure

```
📦 Appointment-System-With-Database
 ┣ 📜 main.cpp              # Main application logic
 ┣ 📜 database.cpp          # Handles SQLite operations
 ┣ 📜 database.h            # Function declarations
 ┣ 📜 appointments.db       # Generated SQLite database file
 ┗ 📜 README.md             # Project documentation
```

---

## 🧩 How to Run

1. **Install SQLite3 library**  
   Make sure `sqlite3.h` and `sqlite3.lib` (or `libsqlite3.a`) are installed and linked to your compiler.

2. **Compile the project**

   ```bash
   g++ main.cpp database.cpp -o main -lsqlite3
   ```

3. **Run the program**

   ```bash
   ./main
   ```

4. **Follow on-screen instructions**  
   - View existing appointments  
   - Book a new one  
   - Confirm payment  

---

## 🪶 License

This project is for **educational purposes only**.  
You are free to use or modify it for learning or academic demonstrations.
