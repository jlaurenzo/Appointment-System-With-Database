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

void waitEnter(const string & msg = "Press Enter to go back...") {
    cout << msg << flush;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
int  main() {
    const char* dbFile = "Appointments.db";//
    createDB(dbFile);//
    createTable(dbFile);//
    string name, serviceType, stylistName, scheduleSlot, paymentMethod;//
    int choice = 0, choice2 = -1, choice3 = -1, choice4 = -1, choice5 = -1, choice6 = -1, choice7 = -1;
    int cash, amount, paid, amountPaid=0;//

    cout << "Enter Your Full Name:";
    //cin >> name;
    getline(cin, name);
    cout << "Welcome, " << name << "\n";
     while (true) {
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*                                   Salon & Barbershop                                    *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                   *Services Offered*                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*          ──────       ───────────       ────────────        ────────────────            *\n";
    cout << "*         │ Hair │     │ Treatments│     │ Technicals │      │ Other Services │           *\n";
    cout << "*          ──────       ───────────       ────────────        ────────────────            *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    
    this_thread::sleep_for(chrono::milliseconds(300)); 
    printWordByWord("Select a service you want to appoint:", 30);
    printWordByWord("Press (1) if you want to select Hair service", 30);
    printWordByWord("Press (2) if you want to select Treatment service", 30);
    printWordByWord("Press (3) if you want to select Technical service", 30);
    printWordByWord("Press (4) if you want to select Other service", 30);
    printWordByWord("Press (5) if you want to exit", 30);
    cout << "Enter Your Choice:\n";
        if (!readInt(choice)) {
            cout << "Invalid input. Type a number (1-5).\n";
            waitEnter();
            continue;
        }

        if (choice == 5) {
            printWordByWord("Leaving the site..", 30);
            break;
        }
        if (choice < 1 || choice > 5) {
            cout << "Choice must be 1..5.\n";
            waitEnter();
            continue;
        }
        
        if (choice == 1) {
            choice2 = -1;
            while (choice2 != 0) {
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*          ──────       ───────────       ────────────        ────────────────            *\n";
    cout << "*         │ Hair │     │ Treatments│     │ Technicals │      │ Other Services │           *\n";
    cout << "*          ──────       ───────────       ────────────        ────────────────            *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    printWordByWord("Press (1) if you want to proceed in selection of service", 40);
    printWordByWord("Press (0) if you want to go back and select other type of service", 40);
    cout << "Enter Your Choice:\n";
        if (!readInt(choice2)) {
                    cout << "Invalid input.\n";
                    waitEnter();
                    continue;
                }

                if (choice2 == 0) {
                    // back to main menu
                    break;
            } else if (choice2 == 1) {    
            choice3 = -1;
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*  ─────────────────────────────────────────────────────────────────────────────────────  *\n";
    cout << "*  │                                     Haircuts                                       │ *\n";
    cout << "*  │                                   •₱250 Men                                        │ *\n";
    cout << "*  │                                   •₱250 Women                                      │ *\n";
    cout << "*  │                                   •₱150 Kids                                       │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                   Hair Styling                                     │ *\n";
    cout << "*  │                                   •₱500 Hair & Makeup                              │ *\n";
    cout << "*  │                                   •₱180 Shampoo & Blowdry                          │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  ─────────────────────────────────────────────────────────────────────────────────────  *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    cout << "Press (1) for Men Haircut\n";
    cout << "Press (2) for Women Haircut\n";
    cout << "Press (3) for Kids Haircut\n";
    cout << "Press (4) for Hair & Makeup\n";
    cout << "Press (5) for Shampoo & Blowdry\n";
    cout << "Press (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    
    if (!readInt(choice3)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }

                    if (choice3 >= 1 && choice3 <= 5) {
                        switch (choice3) {//
                            case 1: cout << "You selected Men haircut\n"; 
                                            serviceType = "Men Haircut"; break;
                            case 2: cout << "You selected Women haircut\n"; 
                                            serviceType = "Women Haircut"; break;
                            case 3: cout << "You selected Kids haircut\n";
                                            serviceType = "Kids Haircut"; break;
                            case 4: cout << "You selected Hair & Makeup\n"; 
                                            serviceType = "Hair & Makeup"; break;
                            case 5: cout << "You selected Shampoo & Blowdry\n";
                                            serviceType = "Shampoo & Blowdry"; break;
                        }
    if (choice3 == 1) {
        choice4 = -1;
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*  ─────────────────────────────────────────────────────────────────────────────────────  *\n";
    cout << "*  │                                   Hairstylists                                     │ *\n";
    cout << "*  │                                   •Lourd Ryan Ramos                                │ *\n";
    cout << "*  │                                   •Jing Monis                                      │ *\n";
    cout << "*  │                                   •Alex Carbonell                                  │ *\n";
    cout << "*  │                                   •Henri Calayag                                   │ *\n";
    cout << "*  │                                   •Nelson Cruz                                     │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  ─────────────────────────────────────────────────────────────────────────────────────  *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    cout << "Press (1) for Lourd Ryan Ramos\n";
    cout << "Press (2) for Jing Monis\n";
    cout << "Press (3) for Alex Carbonell\n";
    cout << "Press (4) for Henri Calayag\n";
    cout << "Press (5) for Nelson Cruz\n";
    cout << "Press (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    if (!readInt(choice4)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice4 >= 1 && choice4 <= 5) {
                                switch (choice4) {
                                    case 1: cout << "You selected Lourd Ryan Ramos as your Hairstylist\n"; 
                                                    stylistName = "Lourd Ryan Ramos";break;
                                    case 2: cout << "You selected Jing Monis as your Hairstylist\n"; 
                                                    stylistName = "Jing Monis"; break;
                                    case 3: cout << "You selected Alex Carbonell as your Hairstylist\n"; 
                                                    stylistName = "Alex Carbonell"; break;
                                    case 4: cout << "You selected Henri Calayag as your Hairstylist\n"; 
                                                    stylistName = "Henri Calayag"; break;
                                    case 5: cout << "You selected Nelson Cruz as your Hairstylist\n"; 
                                                    stylistName = "Nelson Cruz"; break;
                                }
                
    printWordByWord("Proceeding to the selection of schedule...", 30);
    if (choice4 >= 1 && choice4 <=5 ) {
    choice5 = -1;
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*                                       *Schedule*                                        *\n";
    cout << "*                                   ──────────────────                                    *\n";
    cout << "*                                  │ •9:00am-9:45am   │                                   *\n";
    cout << "*                                  │ •11:00am-11:45am │                                   *\n";
    cout << "*                                  │ •1:00pm-1:45pm   │                                   *\n";
    cout << "*                                  │ •3:00pm-3:45pm   │                                   *\n";
    cout << "*                                  │ •5:00pm-5:45pm   │                                   *\n";
    cout << "*                                  │ •7:00pm-7:45pm   │                                   *\n";
    cout << "*                                  │ •9:00pm-9:45pm   │                                   *\n";
    cout << "*                                   ──────────────────                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    cout << "Press (1) for 9:00am-9:45am\n";
    cout << "Press (2) for 11:00am-11:45am\n";
    cout << "Press (3) for 1:00pm-1:45pm\n";
    cout << "Press (4) for 3:00pm-3:45pm\n";
    cout << "Press (5) for 5:00pm-5:45pm\n";
    cout << "Press (6) for 7:00pm-7:45pm\n";
    cout << "Press (7) for 9:00pm-9:45pm\n";
    cout << "Press (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    if (!readInt(choice5)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice5 >= 1 && choice5 <= 7) {
                                switch (choice5) {
                                    case 1: cout << "You selected 9:00am-9:45am as your Schedule\n"; 
                                                    scheduleSlot = "9:00am-9:45am"; break;
                                    case 2: cout << "You selected 11:00am-11:45am as your Schedule\n"; 
                                                    scheduleSlot = "11:00am-11:45am"; break;
                                    case 3: cout << "You selected 1:00pm-1:45pm as your Schedule\n";
                                                    scheduleSlot = "1:00pm-1:45pm"; break;
                                    case 4: cout << "You selected 3:00pm-3:45pm as your Schedule\n";
                                                    scheduleSlot = "3:00pm-3:45pm"; break;
                                    case 5: cout << "You selected 5:00pm-5:45pm as your Schedule\n";
                                                    scheduleSlot = "5:00pm-5:45pm"; break;
                                    case 6: cout << "You selected 7:00pm-7:45pm as your Schedule\n";
                                                    scheduleSlot = "7:00pm-7:45pm"; break;
                                    case 7: cout << "You selected 9:00pm-9:45pm as your Schedule\n";
                                                    scheduleSlot = "9:00pm-9:45pm"; break;
                                }

    printWordByWord("Proceeding to the selection of payment...", 30);
                            } else if (choice5 == 0) {
                                // back to haircut options
                                continue;
                            } else {
                                cout << "Invalid hairstylist option\n";
                                waitEnter();
                                continue;
                            }
                        }
    if (choice5 >= 1 && choice4 <= 7) {
        choice6 = -1;
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*                                   *Payment Selection*                                   *\n";
    cout << "*                                   ──────────────────                                    *\n";
    cout << "*                                  │ •Gcash           │                                   *\n";
    cout << "*                                  │ •VISA            │                                   *\n";
    cout << "*                                  │ •MasterCard      │                                   *\n";
    cout << "*                                  │ •ApplePay        │                                   *\n";
    cout << "*                                  │ •American Express│                                   *\n";
    cout << "*                                  │ •PayPal          │                                   *\n";
    cout << "*                                  │ •PayMaya         │                                   *\n";
    cout << "*                                   ──────────────────                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    cout << "Press (1) for Gcash\n";
    cout << "Press (2) for VISA\n";
    cout << "Press (3) for MasterCard\n";
    cout << "Press (4) for ApplePay\n";
    cout << "Press (5) for American Express\n";
    cout << "Press (6) for PayPal\n";
    cout << "Press (7) for PayMaya\n";
    cout << "Press (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    if (!readInt(choice6)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice6 >= 1 && choice6 <= 7) {
                                switch (choice6) {
                                    case 1: cout << "You selected Gcash as your Payment Option\n";
                                                    paymentMethod = "Gcash"; break;
                                    case 2: cout << "You selected VISA as your Payment Option\n";
                                                    paymentMethod = "VISA"; break;
                                    case 3: cout << "You selected MasterCard as your Payment Option\n";
                                                    paymentMethod = "MasterCard"; break;
                                    case 4: cout << "You selected Apple Pay as your Payment Option\n";
                                                    paymentMethod = "ApplePay"; break;
                                    case 5: cout << "You selected American Express as your Payment Option\n";
                                                    paymentMethod = "American Express"; break;
                                    case 6: cout << "You selected PayPal as your Payment Option\n";
                                                    paymentMethod = "PayPal"; break;
                                    case 7: cout << "You selected PayMaya as your Payment Option\n";
                                                    paymentMethod = "PayMaya"; break;
                                }

    printWordByWord("Proceeding to the payment transaction...", 30);
                            } else if (choice6 == 0) {
                                // back to haircut options
                                continue;
                            } else {
                                cout << "Invalid hairstylist option\n";
                                waitEnter();
                                continue;
                            }
                        }
    do {                    
    if (choice6 >= 1 && choice6 <= 7) {
        choice7 = -1;
         if (choice3 == 1) {
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*                                  *Payment Transaction*                                  *\n";
    cout << "*                                  ────────────────────                                   *\n";
    cout << "*                                 │ Send to:           │                                  *\n";
    cout << "*                                 │ 09285739896        │                                  *\n";
    cout << "*                                 │                    │                                  *\n";
    cout << "*                                 │ Please send the    │                                  *\n";
    cout << "*                                 │ exact price of     │                                  *\n";
    cout << "*                                 │ the chosen service:│                                  *\n";
    cout << "*                                 │ •₱250 Men          │                                  *\n";
    cout << "*                                   ──────────────────                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    cout << "Please send the exact price of the chosen service: \n";
    if (!readInt(choice7)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice7 == 250) {
                        cout << "Successfully paid, Thank you!\n"; 
                        insertData(dbFile, name, serviceType, stylistName, scheduleSlot, paymentMethod, amountPaid);//
                        cout << "Appointment saved successfully!\n";
                        break;
                    } else {
                        cout << "Invalid payment, it must be ₱250\n";
                    }
                            }
                        }
    } while (true); break;    
                    }
    } 
    
    else if (choice3 == 2) {
        serviceType = "Women Haircut";
        choice4 = -1;
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*  ─────────────────────────────────────────────────────────────────────────────────────  *\n";
    cout << "*  │                                   Hairstylists                                     │ *\n";
    cout << "*  │                                   •Celeste Tuviera                                 │ *\n";
    cout << "*  │                                   •Suyen Salazar                                   │ *\n";
    cout << "*  │                                   •Cherry Reyes                                    │ *\n";
    cout << "*  │                                   •Chiyo Tagami                                    │ *\n";
    cout << "*  │                                   •Carla Quiogue                                   │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  ─────────────────────────────────────────────────────────────────────────────────────  *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    cout << "Press (1) for Celeste Tuviera\n";
    cout << "Press (2) for Suyen Salazar\n";
    cout << "Press (3) for Cherry Reyes\n";
    cout << "Press (4) for Chiyo Tagami\n";
    cout << "Press (5) for Carla Quiogue\n";
    cout << "Press (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    if (!readInt(choice4)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice4 >= 1 && choice4 <= 5) {
                                switch (choice4) {
                                    case 1: cout << "You selected Celeste Tuviera as your Hairstylist\n";
                                    stylistName = "Celeste Tuviera"; break;
                                    case 2: cout << "You selected Suyen Salazar as your Hairstylist\n";
                                    stylistName = "Suyen Salazar"; break;
                                    case 3: cout << "You selected Cherry Reyes as your Hairstylist\n";
                                    stylistName = "Cherry Reyes"; break;
                                    case 4: cout << "You selected Chiyo Tagami as your Hairstylist\n";
                                    stylistName = "Chiyo Tagami"; break;
                                    case 5: cout << "You selected Carla Quiogue as your Hairstylist\n";
                                    stylistName = "Carla Quiogue"; break;
                                }
            printWordByWord("Proceeding to the user information...", 30);
                            } else if (choice4 == 0) {
                                // back to haircut options
                                continue;
                            } else {
                                cout << "Invalid hairstylist option\n";
                                waitEnter();
                                continue;
                            }
                        }
    if (choice4 >= 1 && choice4 <=5 ) {
    choice5 = -1;
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*                                       *Schedule*                                        *\n";
    cout << "*                                   ──────────────────                                    *\n";
    cout << "*                                  │ •9:00am-9:45am   │                                   *\n";
    cout << "*                                  │ •11:00am-11:45am │                                   *\n";
    cout << "*                                  │ •1:00pm-1:45pm   │                                   *\n";
    cout << "*                                  │ •3:00pm-3:45pm   │                                   *\n";
    cout << "*                                  │ •5:00pm-5:45pm   │                                   *\n";
    cout << "*                                  │ •7:00pm-7:45pm   │                                   *\n";
    cout << "*                                  │ •9:00pm-9:45pm   │                                   *\n";
    cout << "*                                   ──────────────────                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    cout << "Press (1) for 9:00am-9:45am\n";
    cout << "Press (2) for 11:00am-11:45am\n";
    cout << "Press (3) for 1:00pm-1:45pm\n";
    cout << "Press (4) for 3:00pm-3:45pm\n";
    cout << "Press (5) for 5:00pm-5:45pm\n";
    cout << "Press (6) for 7:00pm-7:45pm\n";
    cout << "Press (7) for 9:00pm-9:45pm\n";
    cout << "Press (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    if (!readInt(choice5)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice5 >= 1 && choice5 <= 7) {
                                switch (choice5) {
                                    case 1: cout << "You selected 9:00am-9:45am as your Schedule\n";
                                    scheduleSlot = "9:00am-9:45am"; break;
                                    case 2: cout << "You selected 11:00am-11:45am as your Schedule\n";
                                    scheduleSlot = "11:00am-11:45am"; break;
                                    case 3: cout << "You selected 1:00pm-1:45pm as your Schedule\n";
                                    scheduleSlot = "1:00pm-1:45pm"; break;
                                    case 4: cout << "You selected 3:00pm-3:45pm as your Schedule\n";
                                    scheduleSlot = "3:00pm-3:45pm"; break;
                                    case 5: cout << "You selected 5:00pm-5:45pm as your Schedule\n";
                                    scheduleSlot = "5:00pm-5:45pm"; break;
                                    case 6: cout << "You selected 7:00pm-7:45pm as your Schedule\n";
                                    scheduleSlot = "7:00pm-7:45pm"; break;
                                    case 7: cout << "You selected 9:00pm-9:45pm as your Schedule\n";
                                    scheduleSlot = "9:00pm-9:45pm"; break;
                                }

    printWordByWord("Proceeding to the selection of payment...", 30);
                            } else if (choice5 == 0) {
                                // back to haircut options
                                continue;
                            } else {
                                cout << "Invalid hairstylist option\n";
                                waitEnter();
                                continue;
                            }
                        }
    if (choice5 >= 1 && choice4 <= 7) {
        choice6 = -1;
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*                                   *Payment Selection*                                   *\n";
    cout << "*                                   ──────────────────                                    *\n";
    cout << "*                                  │ •Gcash           │                                   *\n";
    cout << "*                                  │ •VISA            │                                   *\n";
    cout << "*                                  │ •MasterCard      │                                   *\n";
    cout << "*                                  │ •ApplePay        │                                   *\n";
    cout << "*                                  │ •American Express│                                   *\n";
    cout << "*                                  │ •PayPal          │                                   *\n";
    cout << "*                                  │ •PayMaya         │                                   *\n";
    cout << "*                                   ──────────────────                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
   cout << "Press (1) for Gcash\n";
    cout << "Press (2) for VISA\n";
    cout << "Press (3) for MasterCard\n";
    cout << "Press (4) for ApplePay\n";
    cout << "Press (5) for American Express\n";
    cout << "Press (6) for PayPal\n";
    cout << "Press (7) for PayMaya\n";
    cout << "Press (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    if (!readInt(choice6)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice6 >= 1 && choice6 <= 7) {
                                switch (choice6) {
                                    case 1: cout << "You selected Gcash as your Payment Option\n";
                                    paymentMethod = "Gcash"; break;
                                    case 2: cout << "You selected VISA as your Payment Option\n";
                                    paymentMethod = "VISA"; break;
                                    case 3: cout << "You selected MasterCard as your Payment Option\n";
                                    paymentMethod = "MasterCard"; break;
                                    case 4: cout << "You selected Apple Pay as your Payment Option\n";
                                    paymentMethod = "ApplePay"; break;
                                    case 5: cout << "You selected American Express as your Payment Option\n";
                                    paymentMethod = "American Express"; break;
                                    case 6: cout << "You selected PayPal as your Payment Option\n";
                                    paymentMethod = "PayPal"; break;
                                    case 7: cout << "You selected PayMaya as your Payment Option\n";
                                    paymentMethod = "PayMaya"; break;
                                }

    printWordByWord("Proceeding to the payment transaction...", 30);
                            } else if (choice6 == 0) {
                                // back to haircut options
                                continue;
                            } else {
                                cout << "Invalid hairstylist option\n";
                                waitEnter();
                                continue;
                            }
                        }                    
   else if (choice3 == 3) {
        choice4 = -1;
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*  ─────────────────────────────────────────────────────────────────────────────────────  *\n";
    cout << "*  │                                   Hairstylists                                     │ *\n";
    cout << "*  │                                   •Celeste Tuviera                                 │ *\n";
    cout << "*  │                                   •Jing Monis                                      │ *\n";
    cout << "*  │                                   •Cherry Reyes                                    │ *\n";
    cout << "*  │                                   •Henri Calayag                                   │ *\n";
    cout << "*  │                                   •Carla Quiogue                                   │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  ─────────────────────────────────────────────────────────────────────────────────────  *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    cout << "Press (1) for Celeste Tuviera\n";
    cout << "Press (2) for Jing Monis\n";
    cout << "Press (3) for Cherry Reyes\n";
    cout << "Press (4) for Henri Calayag\n";
    cout << "Press (5) for Carla Quiogue\n";
    cout << "Press (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    if (!readInt(choice4)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice4 >= 1 && choice4 <= 5) {
                                switch (choice4) {
                                    case 1: cout << "You selected Celeste Tuviera as your Hairstylist\n"; 
                                     stylistName = "Celeste Tuviera"; break;
                                    case 2: cout << "You selected Jing Monis as your Hairstylist\n";
                                    stylistName = "Suyen Salazar"; break;
                                    case 3: cout << "You selected Cherry Reyes as your Hairstylist\n";
                                    stylistName = "Cherry Reyes"; break;
                                    case 4: cout << "You selected Henri Calayag as your Hairstylist\n";
                                     stylistName = "Chiyo Tagami"; break;
                                    case 5: cout << "You selected Carla Quiogue as your Hairstylist\n";
                                    stylistName = "Carla Quiogue"; break;
                                }
            printWordByWord("Proceeding to the user information...", 30);
                            } else if (choice4 == 0) {
                                // back to haircut options
                                continue;
                            } else {
                                cout << "Invalid hairstylist option\n";
                                waitEnter();
                                continue;
                            }
                        }
                        waitEnter();
                    }
                    else if (choice3 == 0) {
                    } else {
                        cout << "Invalid haircut option\n";
                        waitEnter();
                    }
                } else {
                    cout << "Enter 0 or 1.\n";
                    waitEnter();
                }
            }
        }               
            
    else if (choice == 2) {
        choice2 = -1;
         while (choice2 != 0) {
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ═══════════════════                                   *\n";
    cout << "*  < Back                           Treatments Services                                   *\n";
    cout << "*                                   ═══════════════════                                   *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*          ──────       ───────────       ────────────        ────────────────            *\n";
    cout << "*         │ Hair │     │ Tretments │     │ Technicals │      │ Other Services │           *\n";
    cout << "*          ──────       ───────────       ────────────        ────────────────            *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    printWordByWord("Press (1) if you want to proceed in selection of service", 50);
    printWordByWord("Press (0) if you want to go back and select other type of service", 50);
    cout << "Enter Your Choice:\n";
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
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ═══════════════════                                   *\n";
    cout << "*  < Back                           Treatments Services                                   *\n";
    cout << "*                                   ═══════════════════                                   *\n";
    cout << "*  ─────────────────────────────────────────────────────────────────────────────────────  *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  ─────────────────────────────────────────────────────────────────────────────────────  *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    printWordByWord("Press (1) for Facial", 30);
    printWordByWord("Press (2) for Hair Treatment", 30);
    printWordByWord("Press (0) to return to Treatments menu", 30);
    cout << "\nEnter Your Choice: " << flush;
    if (!readInt(choice3)) {
                        cout << "Invalid input.\n";
                        waitEnter();
                        continue;
                    }

                    if (choice3 == 1) {
                        printWordByWord("You selected Facial (placeholder booking)", 30);
                    } else if (choice3 == 2) {
                        printWordByWord("You selected Hair Treatment (placeholder booking)", 30);
                    } else if (choice3 == 0) {
                        // back to treatments submenu
                    } else {
                        cout << "Invalid treatments option.\n";
                    }
                    waitEnter();
                } else {
                    cout << "Enter 0 or 1.\n";
                    waitEnter();
                }
            } // end treatments submenu
     }
    else if (choice == 3) {
        choice2 = -1;
         while (choice2 != 0) {
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ═══════════════════                                   *\n";
    cout << "*  < Back                           Technicals Services                                   *\n";
    cout << "*                                   ═══════════════════                                   *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*          ──────       ───────────       ────────────        ────────────────            *\n";
    cout << "*         │ Hair │     │ Tretments │     │ Technicals │      │ Other Services │           *\n";
    cout << "*          ──────       ───────────       ────────────        ────────────────            *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    printWordByWord("Press (1) if you want to proceed in selection of service", 50);
    printWordByWord("Press (0) if you want to go back and select other type of service", 50);
    cout << "Enter Your Choice:\n";
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
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ═══════════════════                                   *\n";
    cout << "*  < Back                           Technicals Services                                   *\n";
    cout << "*                                   ═══════════════════                                   *\n";
    cout << "*  ─────────────────────────────────────────────────────────────────────────────────────  *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  ─────────────────────────────────────────────────────────────────────────────────────  *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
     printWordByWord("Press (1) for Hair Color", 30);
                    printWordByWord("Press (2) for Perm", 30);
                    printWordByWord("Press (0) to return to Technicals menu", 30);
                    cout << "\nEnter Your Choice: " << flush;

                    if (!readInt(choice3)) {
                        cout << "Invalid input.\n";
                        waitEnter();
                        continue;
                    }

                    if (choice3 == 1) {
                        printWordByWord("You selected Hair Color (placeholder booking)", 30);
                    } else if (choice3 == 2) {
                        printWordByWord("You selected Perm (placeholder booking)", 30);
                    } else if (choice3 == 0) {
                        // back
                    } else {
                        cout << "Invalid technicals option.\n";
                    }
                    waitEnter();
                } else {
                    cout << "Enter 0 or 1.\n";
                    waitEnter();
                }
            } // end technicals submenu
        }
    else if (choice == 4) {
        choice2 = -1;
         while (choice2 != 0) {
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ═══════════════════                                   *\n";
    cout << "*  < Back                              Other Services                                     *\n";
    cout << "*                                   ═══════════════════                                   *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*          ──────       ───────────       ────────────        ────────────────            *\n";
    cout << "*         │ Hair │     │ Tretments │     │ Technicals │      │ Other Services │           *\n";
    cout << "*          ──────       ───────────       ────────────        ────────────────            *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    printWordByWord("Press (1) if you want to proceed in selection of service", 50);
    printWordByWord("Press (0) if you want to go back and select other type of service", 50);
    cout << "Enter Your Choice:\n";
       if (!readInt(choice2)) {
                    cout << "Invalid input.\n";
                    waitEnter();
                    continue;
                }

                if (choice2 == 0) {
                    break; // back
                }
                else if (choice2 == 1) {
                    choice3 = -1;
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ═══════════════════                                   *\n";
    cout << "*  < Back                              Other Services                                     *\n";
    cout << "*                                   ═══════════════════                                   *\n";
    cout << "*  ─────────────────────────────────────────────────────────────────────────────────────  *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  ─────────────────────────────────────────────────────────────────────────────────────  *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";    
   printWordByWord("Press (1) for Shampoo", 30);
                    printWordByWord("Press (2) for Trimming", 30);
                    printWordByWord("Press (0) to return to Other menu", 30);
                    cout << "\nEnter Your Choice: " << flush;

                    if (!readInt(choice3)) {
                        cout << "Invalid input.\n";
                        waitEnter();
                        continue;
                    }

                    if (choice3 == 1) {
                        printWordByWord("You selected Shampoo (placeholder booking)", 30);
                    } else if (choice3 == 2) {
                        printWordByWord("You selected Trimming (placeholder booking)", 30);
                    } else if (choice3 == 0) {
                        // back
                    } else {
                        cout << "Invalid other-services option.\n";
                    }
                    waitEnter();
                } else {
                    cout << "Enter 0 or 1.\n";
                    waitEnter();
                }
            } // end other submenu
        }
}
    } // end main loop
