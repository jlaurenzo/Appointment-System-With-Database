#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>
#include <string>
#include <limits>
#include "database.h"
using namespace std;

void printWordByWord(const string & text, int delayMs = 300) {
    stringstream ss(text);
    string word;
    while (ss >> word) {
        cout << word << " " << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
    cout << endl;
}

bool readInt(int & out) {
    if (!(cin >> out)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void waitEnter(const string & msg = "Input Enter to go back...") {
    cout << msg << flush;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
int  main() {
    const char* dbFile = "appointments.db";
    createDB(dbFile);
    createTable(dbFile);

    string name;
    int choice = 0, choice2 = -1, choice3 = -1, choice4 = -1, choice5 = -1, choice6 = -1, choice7 = -1, choice8 = -1, choice9 = -1;
    int cash, amount, paid;
    
     while (true) {
        while (true) {
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*                                 ====================                                    *\n";
            cout << "*                                      WELCOME TO                                         *\n";
            cout << "*                                  Salon & Barbershop                                     *\n";
            cout << "*                                 ====================                                    *\n";
            cout << "*                                                                                         *\n";
            cout << "*                                                                                         *\n";
            cout << "*                                                                                         *\n";
            cout << "*          ---------------------                        -----------------------           *\n";
            cout << "*          | VIEW APPOINTMENTS |                        | BOOK AN APPOINTMENT |           *\n";
            cout << "*          ---------------------                        -----------------------           *\n";
            cout << "*                                                                                         *\n";
            cout << "*                                                                                         *\n";
            cout << "*                                                                                         *\n";
            cout << "*                                                                                         *\n";
            cout << "*                                                                                         *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
        cout << "Input (1) to View Scheduled Appointments\n";
        cout << "Input (2) to Book an Appointment\n";
        cout << "Input (3) to Reschedule an Appointment\n";
        cout << "Input (4) to Exit\n";
        cout << "Enter your choice: ";

        int startChoice;
        if (!readInt(startChoice)) {
            cout << "Invalid input.\n";
            waitEnter();
            continue;
        }

        if (startChoice == 1) {
            displayAllAppointments(dbFile);
            waitEnter();
            continue;
        } 
        else if (startChoice == 2) {
            do {
                cout << "Enter Your Full Name: ";
                getline(cin >> ws, name);
            } while (name.empty());
            cout << "Welcome, " << name << "\n";
        } 
        else if (startChoice == 3) {
            string name;
            cout << "Enter your full name to reschedule: ";
            getline(cin >> ws, name);
            rescheduleAppointment(dbFile, name);
            waitEnter();
            continue;
        } 
        else if (startChoice == 4) {
            cout << "Exiting program...\n";
            return 0;
        } 
        else {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }
    
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*                                   Salon & Barbershop                                    *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                   *Services Offered*                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                               ------       ------------                                 *\n";
    cout << "*                              | Hair |     | Treatments |                                *\n";
    cout << "*                               ------       ------------                                 *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    
    this_thread::sleep_for(chrono::milliseconds(300)); 
    printWordByWord("Select a service you want to appoint:", 30);
    printWordByWord("Input (1) if you want to select Hair service", 30);
    printWordByWord("Input (2) if you want to select Treatment service", 30);
    printWordByWord("Input (3) if you want to exit", 30);
    cout << "Enter Your Choice: ";
        if (!readInt(choice)) {
            cout << "Invalid input. Type a number (1-5).\n";
            waitEnter();
            continue;
        }

        if (choice == 3) {
            printWordByWord("Leaving the site..", 30);
            break;
        }
        if (choice < 1 || choice > 3) {
            cout << "Choice must be 1..5.\n";
            waitEnter();
            continue;
        }
        
        switch (choice) {
            case 1: {
            choice2 = -1;
            while (choice2 != 0) {
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                               ------       ------------                                 *\n";
    cout << "*                              | Hair |     | Treatments |                                *\n";
    cout << "*                               ------       ------------                                 *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    printWordByWord("Input (1) if you want to proceed in selection of service", 40);
    printWordByWord("Input (0) if you want to go back and select other type of service", 40);
    cout << "Enter Your Choice: ";
        if (!readInt(choice2)) {
                    cout << "Invalid input.\n";
                    waitEnter();
                    continue;
                }

                if (choice2 == 0) {
                    break;
            } else if (choice2 == 1) {    
            choice3 = -1;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*  -------------------------------------------------------------------------------------  *\n";
    cout << "*  |                                     Haircuts                                       | *\n";
    cout << "*  |                                    P250 Men                                        | *\n";
    cout << "*  |                                    P250 Women                                      | *\n";
    cout << "*  |                                    P150 Kids                                       | *\n";
    cout << "*  |                                                                                    | *\n";
    cout << "*  |                                   Hair Styling                                     | *\n";
    cout << "*  |                                P500 Hair & Makeup                                  | *\n";
    cout << "*  |                                P180 Shampoo & Blowdry                              | *\n";
    cout << "*  |                                                                                    | *\n";
    cout << "*  |                                                                                    | *\n";
    cout << "*  -------------------------------------------------------------------------------------  *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "Input (1) for Men Haircut\n";
    cout << "Input (2) for Women Haircut\n";
    cout << "Input (3) for Kids Haircut\n";
    cout << "Input (4) for Hair & Makeup\n";
    cout << "Input (5) for Shampoo & Blowdry\n";
    cout << "Input (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    
    if (!readInt(choice3)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice3 == 0) {
                            continue;
                        }
                    if (choice3 >= 1 && choice3 <= 5) {
                         switch (choice3) {
                                case 1: cout << "You selected Men haircut\n"; break;
                                case 2: cout << "You selected Women haircut\n"; break;
                                case 3: cout << "You selected Kids haircut\n"; break;
                                case 4: cout << "You selected Hair & Makeup\n"; break;
                                case 5: cout << "You selected Shampoo & Blowdry\n"; break;
                            }
        choice4 = -1;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*  -------------------------------------------------------------------------------------- *\n";
    cout << "*  |                                  *Hairstylists*                                    | *\n";
    cout << "*  |                                 Lourd Ryan Ramos                                   | *\n";
    cout << "*  |                                    Jing Monis                                      | *\n";
    cout << "*  |                                  Alex Carbonell                                    | *\n";
    cout << "*  |                                   Henri Calayag                                    | *\n";
    cout << "*  |                                    Nelson Cruz                                     | *\n";
    cout << "*  |                                                                                    | *\n";
    cout << "*  |                                                                                    | *\n";
    cout << "*  |                                                                                    | *\n";
    cout << "*  |                                                                                    | *\n";
    cout << "*  -------------------------------------------------------------------------------------- *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "Input (1) for Lourd Ryan Ramos\n";
    cout << "Input (2) for Jing Monis\n";
    cout << "Input (3) for Alex Carbonell\n";
    cout << "Input (4) for Henri Calayag\n";
    cout << "Input (5) for Nelson Cruz\n";
    cout << "Input (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    if (!readInt(choice4)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice4 == 0) continue;
                            if (choice4 < 1 || choice4 > 5) {
                                cout << "Invalid hairstylist option\n";
                                waitEnter();
                                continue;
                            }
                    switch (choice4) {
                                case 1: cout << "You selected Lourd Ryan Ramos as your Hairstylist\n"; break;
                                case 2: cout << "You selected Jing Monis as your Hairstylist\n"; break;
                                case 3: cout << "You selected Alex Carbonell as your Hairstylist\n"; break;
                                case 4: cout << "You selected Henri Calayag as your Hairstylist\n"; break;
                                case 5: cout << "You selected Nelson Cruz as your Hairstylist\n"; break;
                            }
    printWordByWord("Proceeding to the selection of schedules...", 30);
    choice5 = -1;
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*                                       *Schedule*                                        *\n";
    cout << "*        ----------------------------------------------------------------------           *\n";
    cout << "*       | Sunday | Monday | Tuesday | Wednesday | Thursday | Friday | Saturday |          *\n";
    cout << "*        ----------------------------------------------------------------------           *\n";
    cout << "*       |   1    |   2    |    3    |     4     |    5     |   6    |    7     |          *\n";
    cout << "*        ----------------------------------------------------------------------           *\n";
    cout << "*       |   8    |   9    |    10   |     11    |    12    |  13    |    14    |          *\n";
    cout << "*        ----------------------------------------------------------------------           *\n";
    cout << "*       |   15   |   16   |    17   |     18    |    19    |  20    |    21    |          *\n";
    cout << "*        ----------------------------------------------------------------------           *\n";
    cout << "*       |   22   |   23   |    24   |     25    |    26    |  27    |    28    |          *\n";
    cout << "*        ----------------------------------------------------------------------           *\n";
    cout << "*       |   29   |   30   |    31   |           |          |        |          |          *\n";
    cout << "*        ----------------------------------------------------------------------           *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    cout << "Input (0) to return to Hair menu\n";
    cout << "Enter the day you prefer: ";
    if (!readInt(choice5)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice5 == 0) continue;
                            if (choice5 < 1 || choice5 > 31) {
                                cout << "Invalid schedule option\n";
                                waitEnter();
                                continue;
                            }
                    cout << "You selected schedule option " << choice5 << "\n";
    
    
    printWordByWord("Proceeding to the selection of schedules...", 30);
    choice6 = -1;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*                                       *Schedule*                                        *\n";
    cout << "*                                   ------------------                                    *\n";
    cout << "*                                  |  9:00am-9:45am   |                                   *\n";
    cout << "*                                  |  11:00am-11:45am |                                   *\n";
    cout << "*                                  |  1:00pm-1:45pm   |                                   *\n";
    cout << "*                                  |  3:00pm-3:45pm   |                                   *\n";
    cout << "*                                  |  5:00pm-5:45pm   |                                   *\n";
    cout << "*                                  |  7:00pm-7:45pm   |                                   *\n";
    cout << "*                                  |  9:00pm-9:45pm   |                                   *\n";
    cout << "*                                   ------------------                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "Input (1) for 9:00am-9:45am\n";
    cout << "Input (2) for 11:00am-11:45am\n";
    cout << "Input (3) for 1:00pm-1:45pm\n";
    cout << "Input (4) for 3:00pm-3:45pm\n";
    cout << "Input (5) for 5:00pm-5:45pm\n";
    cout << "Input (6) for 7:00pm-7:45pm\n";
    cout << "Input (7) for 9:00pm-9:45pm\n";
    cout << "Input (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    if (!readInt(choice6)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice5 == 0) continue;
                            if (choice6 < 1 || choice6 > 7) {
                                cout << "Invalid schedule option\n";
                                waitEnter();
                                continue;
                            }
                    cout << "You selected schedule option " << choice6 << "\n";
                        string day, time, stylist;
                        int date = choice5;
                         int dayofweek = choice5 % 7;
                        if (dayofweek == 1) day = "Sunday";
                        else if (dayofweek == 2) day = "Monday";
                        else if (dayofweek == 3) day = "Tuesday";
                        else if (dayofweek == 4) day = "Wednesday";
                        else if (dayofweek == 5) day = "Thursday";
                        else if (dayofweek == 6) day = "Friday";
                        else if (dayofweek == 0) day = "Saturday";

                        if (choice6 == 1) time = "9:00am-9:45am";
                        else if (choice6 == 2) time = "11:00am-11:45am";
                        else if (choice6 == 3) time = "1:00pm-1:45pm";
                        else if (choice6 == 4) time = "3:00pm-3:45pm";
                        else if (choice6 == 5) time = "5:00pm-5:45pm";
                        else if (choice6 == 6) time = "7:00pm-7:45pm";
                        else if (choice6 == 7) time = "9:00pm-9:45pm";

                        if (choice4 == 1) stylist = "Lourd Ryan Ramos";
                        else if (choice4 == 2) stylist = "Jing Monis";
                        else if (choice4 == 3) stylist = "Alex Carbonell";
                        else if (choice4 == 4) stylist = "Henri Calayag";
                        else if (choice4 == 5) stylist = "Nelson Cruz";
                        if (isSlotTaken(dbFile, day, time, stylist, date)) {
                            cout << "Sorry, " << stylist << " is already booked on " << date <<" "<< day << " at " << time << ".\n";
                            cout << "Please select another time or another stylist.\n";
                            this_thread::sleep_for(chrono::milliseconds(1000));
                            continue;
    }

                    cout << "Schedule is available!\n";
    printWordByWord("Proceeding to the selection of payment...", 30);
         choice7 = -1;
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*                                   *Payment Selection*                                   *\n";
    cout << "*                                   ------------------                                    *\n";
    cout << "*                                  |  Gcash           |                                   *\n";
    cout << "*                                  |  QR PH           |                                   *\n";
    cout << "*                                  |  MasterCard      |                                   *\n";
    cout << "*                                  |  Gotyme          |                                   *\n";
    cout << "*                                  |  BDO             |                                   *\n";
    cout << "*                                  |  BPI             |                                   *\n";
    cout << "*                                  |  PayMaya         |                                   *\n";
    cout << "*                                  |  Walk-in Payment |                                   *\n";
    cout << "*                                   ------------------                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    cout << "Input (1) for Gcash\n";
    cout << "Input (2) for QR PH\n";
    cout << "Input (3) for MasterCard\n";
    cout << "Input (4) for Gotyme\n";
    cout << "Input (5) for BDO\n";
    cout << "Input (6) for BPI\n";
    cout << "Input (7) for PayMaya\n";
    cout << "Input (8) for Walk-in Payment\n";
    cout << "Input (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    if (!readInt(choice7)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                     if (choice7 == 0) continue;
                            if (choice7 < 1 || choice7 > 8) {
                                cout << "Invalid payment option\n";
                                waitEnter();
                                continue;
                            }
                   cout << "You selected payment option " << choice7 << "\n";

    printWordByWord("Proceeding to the confirmation of the options you have selected...", 30);
    choice8 = -1;
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                Options you've selected:                                 *\n";
    if (choice3 == 1) {
    cout << "*                                    P250 Men                                             *\n";
    } else if (choice3 == 2) {
    cout << "*                                    P250 Women                                           *\n";
    } else if (choice3 == 3) {
    cout << "*                                    P150 Kids                                            *\n";
    } else if (choice3 == 4) {
    cout << "*                                    P500 Hair & Makeup                                   *\n";
    } else if (choice3 == 5) {
    cout << "*                                    P180 Shampoo & Blowdry                               *\n"; }
    if (choice4 == 1) {                     
    cout << "*                                    Lourd Ryan Ramos                                     *\n";
    } else if (choice4 == 2) {
    cout << "*                                    Jing Monis                                           *\n";
    } else if (choice4 == 3) {
    cout << "*                                    Alex Carbonell                                       *\n";
    } else if (choice4 == 4) {
    cout << "*                                    Henri Calayag                                        *\n";
    } else if (choice4 == 5) {
    cout << "*                                    Nelson Cruz                                          *\n";}
    if (choice5 == 2 || choice5 == 9 || choice5 == 16 || choice5 == 23 || choice5 == 30) {
        if (choice5 == 2)
    cout << "*                                    Monday 2nd                                           *\n";
        else if (choice5 == 9)
    cout << "*                                    Monday 9th                                           *\n";
        else if (choice5 == 16)
    cout << "*                                    Monday 16th                                          *\n";
        else if (choice5 == 23)
    cout << "*                                    Monday 23rd                                          *\n";
        else if (choice5 == 30)
    cout << "*                                    Monday 30th                                          *\n"; 
    } else if (choice5 == 3 || choice5 == 10 || choice5 == 17 || choice5 == 24 || choice5 == 31) {
    if (choice5 == 3)
    cout << "*                                    Tuesday 3rd                                          *\n";
        else if (choice5 == 10)
    cout << "*                                    Tuesday 10th                                         *\n";
        else if (choice5 == 17)
    cout << "*                                    Tuesday 17th                                         *\n";
        else if (choice5 == 24)
    cout << "*                                    Tuesday 24th                                         *\n";
        else if (choice5 == 31)
    cout << "*                                    Tuesday 31st                                         *\n";
    } else if (choice5 == 4 || choice5 == 11 || choice5 == 18 || choice5 == 25) {
    if (choice5 == 4)
    cout << "*                                    Wednesday 4th                                        *\n";
        else if (choice5 == 11)
    cout << "*                                    Wednesday 11th                                       *\n";
        else if (choice5 == 18)
    cout << "*                                    Wednesday 18th                                       *\n";
        else if (choice5 == 25)
    cout << "*                                    Wednesday 25th                                       *\n";
    } else if (choice5 == 5 || choice5 == 12 || choice5 == 19 || choice5 == 26) {
    if (choice5 == 5)
    cout << "*                                    Thursday 5th                                         *\n";
        else if (choice5 == 12)
    cout << "*                                    Thursday 12th                                        *\n";
        else if (choice5 == 19)
    cout << "*                                    Thursday 19th                                        *\n";
        else if (choice5 == 26)
    cout << "*                                    Thursday 26th                                        *\n";
    } else if (choice5 == 6 || choice5 == 13 || choice5 == 20 || choice5 == 27) {
    if (choice5 == 6)
    cout << "*                                    Friday 6th                                           *\n";
        else if (choice5 == 13)
    cout << "*                                    Friday 13th                                          *\n";
        else if (choice5 == 20)
    cout << "*                                    Friday 20th                                          *\n";
        else if (choice5 == 27)
    cout << "*                                    Friday 27th                                          *\n";
    } else if (choice5 == 7 || choice5 == 14 || choice5 == 21 || choice5 == 28) {
    if (choice5 == 7)
    cout << "*                                    Saturday 7th                                         *\n";
        else if (choice5 == 14)
    cout << "*                                    Saturday 14th                                        *\n";
        else if (choice5 == 21)
    cout << "*                                    Saturday 21st                                        *\n";
        else if (choice5 == 28)
    cout << "*                                    Saturday 28th                                        *\n";
    } else if (choice5 == 1 || choice5 == 8 || choice5 == 15 || choice5 == 22 || choice5 == 29) {
    if (choice5 == 1)
    cout << "*                                    Sunday 1st                                           *\n";
        else if (choice5 == 8)
    cout << "*                                    Sunday 8th                                           *\n";
        else if (choice5 == 15)
    cout << "*                                    Sunday 15th                                          *\n";
        else if (choice5 == 22)
    cout << "*                                    Sunday 22nd                                          *\n";
        else if (choice5 == 29)
    cout << "*                                    Sunday 29th                                          *\n"; }
    if (choice6 == 1) {
    cout << "*                                    9:00am-9:45am                                        *\n";
    } else if (choice6 == 2) {
    cout << "*                                    11:00am-11:45am                                      *\n";
    } else if (choice6 == 3) {
    cout << "*                                    1:00pm-1:45pm                                        *\n";
    } else if (choice6 == 4) {
    cout << "*                                    3:00pm-3:45pm                                        *\n";
    } else if (choice6 == 5) {
    cout << "*                                    5:00pm-5:45pm                                        *\n";
    } else if (choice6 == 6) {
    cout << "*                                    7:00pm-7:45pm                                        *\n";
    } else if (choice6 == 7) {
    cout << "*                                    9:00pm-9:45pm                                        *\n"; }
    if (choice7 == 1) {
    cout << "*                                    Gcash                                                *\n";
    } else if (choice7 == 2) {
    cout << "*                                    QR PH                                                *\n";
    } else if (choice7 == 3) {
    cout << "*                                    MasterCard                                           *\n";
    } else if (choice7 == 4) {
    cout << "*                                    ApplyPay                                             *\n";
    } else if (choice7 == 5) {
    cout << "*                                   BDO                                                  *\n";
    } else if (choice7 == 6) {
    cout << "*                                   BPI                                                  *\n";
    } else if (choice7 == 7) {
    cout << "*                                   PayMaya                                              *\n";
    } else if (choice7 == 8) {
    cout << "*                                   Walk-in Payment                                      *\n";   
    }
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    printWordByWord("Input (1) if there is no changes needed to be done", 40);
    printWordByWord("Input (0) if you want to go back and repeat the choices", 40);
    cout << "Enter Your Choice: ";
        if (!readInt(choice8)) {
                    cout << "Invalid input.\n";
                    waitEnter();
                    continue;
                }

                if (choice8 == 0) {
                    break;
                } else if (choice7 == 8 && choice8 == 1) { 
                cout << "Successfully booked, thank you!\n"; 
                break; }
                    else if (choice8 == 1) {
    printWordByWord("Proceeding to the payment transaction...", 30);
    do {                    
        choice9 = -1;
       
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*                                  *Payment Transaction*                                  *\n";
    cout << "*                                  --------------------                                   *\n";
    cout << "*                                 | Send to:           |                                  *\n";
    cout << "*                                 | 09285739896        |                                  *\n";
    cout << "*                                 |                    |                                  *\n";
    cout << "*                                 | Please send the    |                                  *\n";
    cout << "*                                 | exact price of     |                                  *\n";
    cout << "*                                 | the chosen service:|                                  *\n";
   if (choice3 == 1 || choice3 == 2) {
    cout << "*                                 |  P250 Men/Women    |                                  *\n";
    } else if (choice3 == 3) {
    cout << "*                                 |  P150 Kids         |                                  *\n";
    } else if (choice3 == 4) {
    cout << "*                                 |  P500 Hair & Makeup|                                  *\n";
    } else if (choice3 == 5) {
    cout << "*                                 |  P180 Shampoo &    |                                  *\n";
    cout << "*                                 | Blowdry            |                                  *\n";}
    cout << "*                                  --------------------                                   *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "Please send the exact price of the chosen service: ";
    if (!readInt(choice9)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        break;
                    }
                    bool ok = false;
                                if ((choice3 == 1 || choice3 == 2) && choice9 == 250) ok = true;
                                if (choice3 == 3 && choice9 == 150) ok = true;
                                if (choice3 == 4 && choice9 == 500) ok = true;
                                if (choice3 == 5 && choice9 == 180) ok = true;

                                if (ok) {
                                    cout << "Successfully paid, Thank you!\n";
                                    string service, stylist, day, time, payment;

                                    if (choice == 1) {
                                        if (choice3 == 1) service = "Men Haircut";
                                        else if (choice3 == 2) service = "Women Haircut";
                                        else if (choice3 == 3) service = "Kids Haircut";
                                        else if (choice3 == 4) service = "Hair & Makeup";
                                        else if (choice3 == 5) service = "Shampoo & Blowdry";
                                    } else if (choice == 2) {
                                        if (choice3 == 1) service = "Hot Oil/Hair Spa";
                                        else if (choice3 == 2) service = "Cynos with Creme";
                                        else if (choice3 == 3) service = "Scalp Treatment";
                                        else if (choice3 == 4) service = "Rebonding";
                                        else if (choice3 == 5) service = "Japanese Rebonding";
                                        else if (choice3 == 6) service = "Hair Color Change";
                                        else if (choice3 == 7) service = "Keratin Treatment";
                                    }

                                    if (choice4 == 1) stylist = "Lourd Ryan Ramos";
                                    else if (choice4 == 2) stylist = "Jing Monis";
                                    else if (choice4 == 3) stylist = "Alex Carbonell";
                                    else if (choice4 == 4) stylist = "Henri Calayag";
                                    else if (choice4 == 5) stylist = "Nelson Cruz";

                                    int date = choice5;
                                    int dayofweek = choice5 % 7;
                                    if (dayofweek == 1) day = "Sunday";
                                    else if (dayofweek == 2) day = "Monday";
                                    else if (dayofweek == 3) day = "Tuesday";
                                    else if (dayofweek == 4) day = "Wednesday";
                                    else if (dayofweek == 5) day = "Thursday";
                                    else if (dayofweek == 6) day = "Friday";
                                    else if (dayofweek == 0) day = "Saturday";
                                    
                                    if (choice6 == 1) time = "9:00am-9:45am";
                                    else if (choice6 == 2) time = "11:00am-11:45am";
                                    else if (choice6 == 3) time = "1:00pm-1:45pm";
                                    else if (choice6 == 4) time = "3:00pm-3:45pm";
                                    else if (choice6 == 5) time = "5:00pm-5:45pm";
                                    else if (choice6 == 6) time = "7:00pm-7:45pm";
                                    else if (choice6 == 7) time = "9:00pm-9:45pm";
                                    
                                    if (choice7 == 1) payment = "Gcash";
                                    else if (choice7 == 2) payment = "QR PH";
                                    else if (choice7 == 3) payment = "MasterCard";
                                    else if (choice7 == 4) payment = "Gotyme";
                                    else if (choice7 == 5) payment = "BDO";
                                    else if (choice7 == 6) payment = "BPI";
                                    else if (choice7 == 7) payment = "PayMaya";
                                    else if (choice7 == 8) payment = "Walk-in Payment";
                                    string schedule = date + " " + day + " " + time;

                                    insertData(dbFile, name, service, stylist, day, date, time, payment, choice9);

                                    break;
                                } else {
                                    cout << "Invalid payment, please send the exact price for that service.\n";
                                }
                            } while (true);
                    waitEnter();
                        } else {
                            cout << "Invalid haircut option\n";
                            waitEnter();
                        }
                    } else {
                        cout << "Enter 0 or 1\n";
                        waitEnter();
                    }
            
                }
            }
                continue;
            }
    
    case 2: {
        choice2 = -1;
         while (choice2 != 0) {
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*                                   ===================                                   *\n";
    cout << "*  < Back                           Treatments Services                                   *\n";
    cout << "*                                   ===================                                   *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                ------       -----------                                 *\n";
    cout << "*                               | Hair |     | Tretments |                                *\n";
    cout << "*                                ------       -----------                                 *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    printWordByWord("Input (1) if you want to proceed in selection of service", 50);
    printWordByWord("Input (0) if you want to go back and select other type of service", 50);
    cout << "Enter Your Choice: ";
        if (!readInt(choice2)) {
                    cout << "Invalid input.\n";
                    waitEnter();
                    continue;
                }

                if (choice2 == 0) {
                    break;
                }
                else if (choice2 == 1) {
                choice3 = -1;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*                                   ===================                                   *\n";
    cout << "*  < Back                           Treatments Services                                   *\n";
    cout << "*                                   ===================                                   *\n";
    cout << "*  -------------------------------------------------------------------------------------  *\n";
    cout << "*  |                               P500 Hot Oil/Hair Spa                                | *\n";
    cout << "*  |                               P800 Cynos with Creme                                | *\n";
    cout << "*  |                               P700 Scalp Treatment                                 | *\n";
    cout << "*  |                               P1100 Rebonding                                      | *\n";
    cout << "*  |                               P1500 Japanese Rebonding                             | *\n";
    cout << "*  |                               P1800 Hair Color Change                              | *\n";
    cout << "*  |                               P5500 Keratin Treatment                              | *\n";
    cout << "*  |                                                                                    | *\n";
    cout << "*  |                                                                                    | *\n";
    cout << "*  |                                                                                    | *\n";
    cout << "*  -------------------------------------------------------------------------------------  *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "Input (1) for Hot Oil/Hair Spa\n";
    cout << "Input (2) for Cynos with Creme\n";
    cout << "Input (3) for Scalp Treatment\n";
    cout << "Input (4) for Rebonding\n";
    cout << "Input (5) for Japanese Rebonding\n";
    cout << "Input (6) for Hair Color Change\n";
    cout << "Input (7) for Keratin Treatment\n";
    cout << "Input (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    
    if (!readInt(choice3)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice3 == 0) {
                            continue;
                        }
                    if (choice3 >= 1 && choice3 <= 7) {
                         switch (choice3) {
                                case 1: cout << "You selected Hot Oil/Hair Spa\n"; break;
                                case 2: cout << "You selected Cynos with Creme\n"; break;
                                case 3: cout << "You selected Scalp Treatment\n"; break;
                                case 4: cout << "You selected Rebonding\n"; break;
                                case 5: cout << "You selected Japanese Rebonding\n"; break;
                                case 6: cout << "You selected Hair Color Change\n"; break;
                                case 7: cout << "You selected Keratin Treatment\n"; break;
                            }
        choice4 = -1;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*                                   ===================                                   *\n";
    cout << "*  < Back                           Treatments Services                                   *\n";
    cout << "*                                   ===================                                   *\n";
    cout << "*  -------------------------------------------------------------------------------------  *\n";
    cout << "*  |                                  *Hairstylists*                                    | *\n";
    cout << "*  |                                 Lourd Ryan Ramos                                   | *\n";
    cout << "*  |                                    Jing Monis                                      | *\n";
    cout << "*  |                                  Alex Carbonell                                    | *\n";
    cout << "*  |                                   Henri Calayag                                    | *\n";
    cout << "*  |                                    Nelson Cruz                                     | *\n";
    cout << "*  |                                                                                    | *\n";
    cout << "*  |                                                                                    | *\n";
    cout << "*  |                                                                                    | *\n";
    cout << "*  |                                                                                    | *\n";
    cout << "*  -------------------------------------------------------------------------------------  *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "Input (1) for Lourd Ryan Ramos\n";
    cout << "Input (2) for Jing Monis\n";
    cout << "Input (3) for Alex Carbonell\n";
    cout << "Input (4) for Henri Calayag\n";
    cout << "Input (5) for Nelson Cruz\n";
    cout << "Input (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    if (!readInt(choice4)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice4 == 0) continue;
                            if (choice4 < 1 || choice4 > 5) {
                                cout << "Invalid hairstylist option\n";
                                waitEnter();
                                continue;
                            }
                    switch (choice4) {
                                case 1: cout << "You selected Lourd Ryan Ramos as your Hairstylist\n"; break;
                                case 2: cout << "You selected Jing Monis as your Hairstylist\n"; break;
                                case 3: cout << "You selected Alex Carbonell as your Hairstylist\n"; break;
                                case 4: cout << "You selected Henri Calayag as your Hairstylist\n"; break;
                                case 5: cout << "You selected Nelson Cruz as your Hairstylist\n"; break;
                            }
    printWordByWord("Proceeding to the selection of schedules...", 30);
    choice5 = -1;
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*                                       *Schedule*                                        *\n";
    cout << "*        ----------------------------------------------------------------------           *\n";
    cout << "*       | Sunday | Monday | Tuesday | Wednesday | Thursday | Friday | Saturday |          *\n";
    cout << "*        ----------------------------------------------------------------------           *\n";
    cout << "*       |   1    |   2    |    3    |     4     |    5     |   6    |    7     |          *\n";
    cout << "*        ----------------------------------------------------------------------           *\n";
    cout << "*       |   8    |   9    |    10   |     11    |    12    |  13    |    14    |          *\n";
    cout << "*        ----------------------------------------------------------------------           *\n";
    cout << "*       |   15   |   16   |    17   |     18    |    19    |  20    |    21    |          *\n";
    cout << "*        ----------------------------------------------------------------------           *\n";
    cout << "*       |   22   |   23   |    24   |     25    |    26    |  27    |    28    |          *\n";
    cout << "*        ----------------------------------------------------------------------           *\n";
    cout << "*       |   29   |   30   |    31   |           |          |        |          |          *\n";
    cout << "*        ----------------------------------------------------------------------           *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    cout << "Input (0) to return to Hair menu\n";
    cout << "Enter the day you prefer: ";
    if (!readInt(choice5)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice5 == 0) continue;
                            if (choice5 < 1 || choice5 > 31) {
                                cout << "Invalid schedule option\n";
                                waitEnter();
                                continue;
                            }
                    cout << "You selected schedule option " << choice5 << "\n";
    
                
    printWordByWord("Proceeding to the selection of schedule...", 30);
    choice6 = -1;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*                                   ===================                                   *\n";
    cout << "*  < Back                           Treatments Services                                   *\n";
    cout << "*                                   ===================                                   *\n";
    cout << "*                                       *Schedule*                                        *\n";
    cout << "*                                   ------------------                                    *\n";
    cout << "*                                  |  9:00am-9:45am   |                                   *\n";
    cout << "*                                  |  11:00am-11:45am |                                   *\n";
    cout << "*                                  |  1:00pm-1:45pm   |                                   *\n";
    cout << "*                                  |  3:00pm-3:45pm   |                                   *\n";
    cout << "*                                  |  5:00pm-5:45pm   |                                   *\n";
    cout << "*                                  |  7:00pm-7:45pm   |                                   *\n";
    cout << "*                                  |  9:00pm-9:45pm   |                                   *\n";
    cout << "*                                   ------------------                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "Input (1) for 9:00am-9:45am\n";
    cout << "Input (2) for 11:00am-11:45am\n";
    cout << "Input (3) for 1:00pm-1:45pm\n";
    cout << "Input (4) for 3:00pm-3:45pm\n";
    cout << "Input (5) for 5:00pm-5:45pm\n";
    cout << "Input (6) for 7:00pm-7:45pm\n";
    cout << "Input (7) for 9:00pm-9:45pm\n";
    cout << "Input (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    if (!readInt(choice6)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice6 == 0) continue;
                            if (choice6 < 1 || choice6 > 7) {
                                cout << "Invalid schedule option\n";
                                waitEnter();
                                continue;
                            }
                    cout << "You selected schedule option " << choice6 << "\n";
                    string day, time, stylist;
                    int date = choice5;
                    int dayofweek = choice5 % 7;

                    if (dayofweek == 1) day = "Sunday";
                    else if (dayofweek == 2) day = "Monday";
                    else if (dayofweek == 3) day = "Tuesday";
                    else if (dayofweek == 4) day = "Wednesday";
                    else if (dayofweek == 5) day = "Thursday";
                    else if (dayofweek == 6) day = "Friday";
                    else if (dayofweek == 0) day = "Saturday";

                    if (choice6 == 1) time = "9:00am-9:45am";
                    else if (choice6 == 2) time = "11:00am-11:45am";
                    else if (choice6 == 3) time = "1:00pm-1:45pm";
                    else if (choice6 == 4) time = "3:00pm-3:45pm";
                    else if (choice6 == 5) time = "5:00pm-5:45pm";
                    else if (choice6 == 6) time = "7:00pm-7:45pm";
                    else if (choice6 == 7) time = "9:00pm-9:45pm";

                    if (choice4 == 1) stylist = "Lourd Ryan Ramos";
                    else if (choice4 == 2) stylist = "Jing Monis";
                    else if (choice4 == 3) stylist = "Alex Carbonell";
                    else if (choice4 == 4) stylist = "Henri Calayag";
                    else if (choice4 == 5) stylist = "Nelson Cruz";
                    if (isSlotTaken(dbFile, day, time, stylist, date)) {
                        cout << "Sorry, " << stylist << " is already booked on " << date <<" "<< day << " at " << time << ".\n";
                        cout << "Please select another time or another stylist.\n";
                        this_thread::sleep_for(chrono::milliseconds(1000));
                        continue;
}

                    cout << "Schedule is available!\n";          

    printWordByWord("Proceeding to the selection of payment...", 30);
        
        choice7 = -1;
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ===================                                   *\n";
    cout << "*  < Back                           Treatments Services                                   *\n";
    cout << "*                                   ===================                                   *\n";
    cout << "*                                   *Payment Selection*                                   *\n";
    cout << "*                                   ------------------                                    *\n";
    cout << "*                                  |  Gcash           |                                   *\n";
    cout << "*                                  |  QR PH           |                                   *\n";
    cout << "*                                  |  MasterCard      |                                   *\n";
    cout << "*                                  |  Gotyme          |                                   *\n";
    cout << "*                                  |  BDO             |                                   *\n";
    cout << "*                                  |  BPI             |                                   *\n";
    cout << "*                                  |  PayMaya         |                                   *\n";
    cout << "*                                  |  Walk-in Payment |                                   *\n";
    cout << "*                                   ------------------                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    cout << "Input (1) for Gcash\n";
    cout << "Input (2) for QR PH\n";
    cout << "Input (3) for MasterCard\n";
    cout << "Input (4) for Gotyme\n";
    cout << "Input (5) for BDO\n";
    cout << "Input (6) for BPI\n";
    cout << "Input (7) for PayMaya\n";
    cout << "Input (8) for Walk-in Payment\n";
    cout << "Input (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    if (!readInt(choice7)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                     if (choice7 == 0) continue;
                            if (choice7 < 1 || choice7 > 8) {
                                cout << "Invalid payment option\n";
                                waitEnter();
                                continue;
                            }
                   cout << "You selected payment option " << choice7 << "\n";

    printWordByWord("Proceeding to the confirmation of the options you have selected...", 30);
choice8 = -1;
     cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ==================                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                Options you've selected:                                 *\n";
    if (choice3 == 1) {
    cout << "*                                    P250 Men                                             *\n";
    } else if (choice3 == 2) {
    cout << "*                                    P250 Women                                           *\n";
    } else if (choice3 == 3) {
    cout << "*                                    P150 Kids                                            *\n";
    } else if (choice3 == 4) {
    cout << "*                                    P500 Hair & Makeup                                   *\n";
    } else if (choice3 == 5) {
    cout << "*                                    P180 Shampoo & Blowdry                               *\n"; }
    if (choice4 == 1) {                     
    cout << "*                                    Lourd Ryan Ramos                                     *\n";
    } else if (choice4 == 2) {
    cout << "*                                    Jing Monis                                           *\n";
    } else if (choice4 == 3) {
    cout << "*                                    Alex Carbonell                                       *\n";
    } else if (choice4 == 4) {
    cout << "*                                    Henri Calayag                                        *\n";
    } else if (choice4 == 5) {
    cout << "*                                    Nelson Cruz                                          *\n";}
    if (choice5 == 2 || choice5 == 9 || choice5 == 16 || choice5 == 23 || choice5 == 30) {
        if (choice5 == 2)
    cout << "*                                    Monday 2nd                                           *\n";
        else if (choice5 == 9)
    cout << "*                                    Monday 9th                                           *\n";
        else if (choice5 == 16)
    cout << "*                                    Monday 16th                                          *\n";
        else if (choice5 == 23)
    cout << "*                                    Monday 23rd                                          *\n";
        else if (choice5 == 30)
    cout << "*                                    Monday 30th                                          *\n"; 
    } else if (choice5 == 3 || choice5 == 10 || choice5 == 17 || choice5 == 24 || choice5 == 31) {
    if (choice5 == 3)
    cout << "*                                    Tuesday 3rd                                          *\n";
        else if (choice5 == 10)
    cout << "*                                    Tuesday 10th                                         *\n";
        else if (choice5 == 17)
    cout << "*                                    Tuesday 17th                                         *\n";
        else if (choice5 == 24)
    cout << "*                                    Tuesday 24th                                         *\n";
        else if (choice5 == 31)
    cout << "*                                    Tuesday 31st                                         *\n";
    } else if (choice5 == 4 || choice5 == 11 || choice5 == 18 || choice5 == 25) {
    if (choice5 == 4)
    cout << "*                                    Wednesday 4th                                        *\n";
        else if (choice5 == 11)
    cout << "*                                    Wednesday 11th                                       *\n";
        else if (choice5 == 18)
    cout << "*                                    Wednesday 18th                                       *\n";
        else if (choice5 == 25)
    cout << "*                                    Wednesday 25th                                       *\n";
    } else if (choice5 == 5 || choice5 == 12 || choice5 == 19 || choice5 == 26) {
    if (choice5 == 5)
    cout << "*                                    Thursday 5th                                         *\n";
        else if (choice5 == 12)
    cout << "*                                    Thursday 12th                                        *\n";
        else if (choice5 == 19)
    cout << "*                                    Thursday 19th                                        *\n";
        else if (choice5 == 26)
    cout << "*                                    Thursday 26th                                        *\n";
    } else if (choice5 == 6 || choice5 == 13 || choice5 == 20 || choice5 == 27) {
    if (choice5 == 6)
    cout << "*                                    Friday 6th                                           *\n";
        else if (choice5 == 13)
    cout << "*                                    Friday 13th                                          *\n";
        else if (choice5 == 20)
    cout << "*                                    Friday 20th                                          *\n";
        else if (choice5 == 27)
    cout << "*                                    Friday 27th                                          *\n";
    } else if (choice5 == 7 || choice5 == 14 || choice5 == 21 || choice5 == 28) {
    if (choice5 == 7)
    cout << "*                                    Saturday 7th                                         *\n";
        else if (choice5 == 14)
    cout << "*                                    Saturday 14th                                        *\n";
        else if (choice5 == 21)
    cout << "*                                    Saturday 21st                                        *\n";
        else if (choice5 == 28)
    cout << "*                                    Saturday 28th                                        *\n";
    } else if (choice5 == 1 || choice5 == 8 || choice5 == 15 || choice5 == 22 || choice5 == 29) {
    if (choice5 == 1)
    cout << "*                                    Sunday 1st                                           *\n";
        else if (choice5 == 8)
    cout << "*                                    Sunday 8th                                           *\n";
        else if (choice5 == 15)
    cout << "*                                    Sunday 15th                                          *\n";
        else if (choice5 == 22)
    cout << "*                                    Sunday 22nd                                          *\n";
        else if (choice5 == 29)
    cout << "*                                    Sunday 29th                                          *\n"; }
    if (choice6 == 1) {
    cout << "*                                    9:00am-9:45am                                        *\n";
    } else if (choice6 == 2) {
    cout << "*                                    11:00am-11:45am                                      *\n";
    } else if (choice6 == 3) {
    cout << "*                                    1:00pm-1:45pm                                        *\n";
    } else if (choice6 == 4) {
    cout << "*                                    3:00pm-3:45pm                                        *\n";
    } else if (choice6 == 5) {
    cout << "*                                    5:00pm-5:45pm                                        *\n";
    } else if (choice6 == 6) {
    cout << "*                                    7:00pm-7:45pm                                        *\n";
    } else if (choice6 == 7) {
    cout << "*                                    9:00pm-9:45pm                                        *\n"; }
    if (choice7 == 1) {
    cout << "*                                    Gcash                                                *\n";
    } else if (choice7 == 2) {
    cout << "*                                    QR PH                                                 *\n";
    } else if (choice7 == 3) {
    cout << "*                                    MasterCard                                           *\n";
    } else if (choice7 == 4) {
    cout << "*                                    ApplyPay                                             *\n";
    } else if (choice7 == 5) {
    cout << "*                                    BDO                                     *\n";
    } else if (choice7 == 6) {
    cout << "*                                    BPI                                               *\n";
    } else if (choice7 == 7) {
    cout << "*                                    PayMaya                                              *\n";
    }else if (choice7 == 8) {
    cout << "*                                    Walk-in Payment                                      *\n";   
    }
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    printWordByWord("Input (1) if there is no changes needed to be done", 40);
    printWordByWord("Input (0) if you want to go back and repeat the choices", 40);
    cout << "Enter Your Choice: ";
        if (!readInt(choice8)) {
                    cout << "Invalid input.\n";
                    waitEnter();
                    continue;
                }

                if (choice8 == 0) {
                    break;
                } else if (choice7 == 8 && choice8 == 1) { 
                cout << "Successfully booked, thank you!\n"; 
                break; }
                else if (choice8 == 1) {
    printWordByWord("Proceeding to the payment transaction...", 30);
                            
    do {                    
        choice9 = -1;
       
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*                                      ===================                                  *\n";
    cout << "*  < Back                              Treatments Services                                  *\n";
    cout << "*                                      ===================                                  *\n";
    cout << "*                                     *Payment Transaction*                                 *\n";
    cout << "*                                  --------------------------                               *\n";
    cout << "*                                 | Send to:                 |                              *\n";
    cout << "*                                 | 09285739896              |                              *\n";
    cout << "*                                 |                          |                              *\n";
    cout << "*                                 | Please send the          |                              *\n";
    cout << "*                                 | exact price of           |                              *\n";
    cout << "*                                 | the chosen service:      |                              *\n";
   if (choice3 == 1 ) {
    cout << "*                                 |  P500 Hot Oil/Hair Spa   |                              *\n";
    } else if (choice3 == 2) {
    cout << "*                                 |  P800 Cynos with Creme   |                              *\n";
    } else if (choice3 == 3) {
    cout << "*                                 |  P700 Scalp Treatment    |                              *\n";
    } else if (choice3 == 4) {
    cout << "*                                 |  P1100 Rebonding         |                              *\n";
    } else if (choice3 == 5) {
    cout << "*                                 |  P1500 Japenese Rebonding|                              *\n";
    } else if (choice3 == 6) {
    cout << "*                                 |  P1800 Hair Color Change |                              *\n";
    } else if (choice3 == 7) {                                                          
    cout << "*                                 |  P5500 Keratin Treatment |                              *\n";}
    cout << "*                                  --------------------------                               *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "Please send the exact price of the chosen service: ";
    if (!readInt(choice9)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        break;
                    }
                    bool ok = false;
                                if (choice3 == 1 && choice9 == 500) ok = true;
                                if (choice3 == 2 && choice9 == 800) ok = true;
                                if (choice3 == 3 && choice9 == 700) ok = true;
                                if (choice3 == 4 && choice9 == 1100) ok = true;
                                if (choice3 == 5 && choice9 == 1500) ok = true;
                                if (choice3 == 6 && choice9 == 1800) ok = true;
                                if (choice3 == 7 && choice9 == 5500) ok = true;
                                

                                if (ok) {
                                    cout << "Successfully paid, Thank you!\n";
                                    string service, stylist, day, time, payment;
                                    if (choice == 1) {
                                        if (choice3 == 1) service = "Men Haircut";
                                        else if (choice3 == 2) service = "Women Haircut";
                                        else if (choice3 == 3) service = "Kids Haircut";
                                        else if (choice3 == 4) service = "Hair & Makeup";
                                        else if (choice3 == 5) service = "Shampoo & Blowdry";
                                    } else if (choice == 2) {
                                        if (choice3 == 1) service = "Hot Oil/Hair Spa";
                                        else if (choice3 == 2) service = "Cynos with Creme";
                                        else if (choice3 == 3) service = "Scalp Treatment";
                                        else if (choice3 == 4) service = "Rebonding";
                                        else if (choice3 == 5) service = "Japanese Rebonding";
                                        else if (choice3 == 6) service = "Hair Color Change";
                                        else if (choice3 == 7) service = "Keratin Treatment";
                                    }
                                    
                                    if (choice4 == 1) stylist = "Lourd Ryan Ramos";
                                    else if (choice4 == 2) stylist = "Jing Monis";
                                    else if (choice4 == 3) stylist = "Alex Carbonell";
                                    else if (choice4 == 4) stylist = "Henri Calayag";
                                    else if (choice4 == 5) stylist = "Nelson Cruz";
                                    
                                    int date = choice5;
                                    int dayofweek = choice5 % 7;
                                    if (dayofweek == 1) day = "Sunday";
                                    else if (dayofweek == 2) day = "Monday";
                                    else if (dayofweek == 3) day = "Tuesday";
                                    else if (dayofweek == 4) day = "Wednesday";
                                    else if (dayofweek == 5) day = "Thursday";
                                    else if (dayofweek == 6) day = "Friday";
                                    else if (dayofweek == 0) day = "Saturday";
                                    
                                    if (choice6 == 1) time = "9:00am-9:45am";
                                    else if (choice6 == 2) time = "11:00am-11:45am";
                                    else if (choice6 == 3) time = "1:00pm-1:45pm";
                                    else if (choice6 == 4) time = "3:00pm-3:45pm";
                                    else if (choice6 == 5) time = "5:00pm-5:45pm";
                                    else if (choice6 == 6) time = "7:00pm-7:45pm";
                                    else if (choice6 == 7) time = "9:00pm-9:45pm";
                                    
                                    if (choice7 == 1) payment = "Gcash";
                                    else if (choice7 == 2) payment = "QR PH";
                                    else if (choice7 == 3) payment = "MasterCard";
                                    else if (choice7 == 4) payment = "Gotyme";
                                    else if (choice7 == 5) payment = "BDO";
                                    else if (choice7 == 6) payment = "BPI";
                                    else if (choice7 == 7) payment = "PayMaya";
                                    else if (choice7 == 8) payment = "Walk-in Payment";
                                    string schedule = date + " " + day + " " + time;

                                    insertData(dbFile, name, service, stylist, day, date, time, payment, choice9);

                                    break;
                                } else {
                                    cout << "Invalid payment, please send the exact price for that service.\n";
                                }
                            } while (true);
                    waitEnter();
                        } else {
                            cout << "Invalid haircut option\n";
                            waitEnter();
                        }
                    } else {
                        cout << "Enter 0 or 1\n";
                        waitEnter();
                    }
                }
         }
                continue;
            }
            } 
    break;
    
        }  while (true);
     }
}
