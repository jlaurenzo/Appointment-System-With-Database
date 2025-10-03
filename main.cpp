#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>
#include <string>
#include <limits>
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
    string name;
    int choice = 0, choice2 = -1, choice3 = -1, choice4 = -1, choice5 = -1, choice6 = -1, choice7 = -1;
    int cash, amount, paid;
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
    cout << "*                                ──────       ───────────                                 *\n";
    cout << "*                               │ Hair │     │ Treatments│                                *\n";
    cout << "*                                ──────       ───────────                                 *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    
    this_thread::sleep_for(chrono::milliseconds(300)); 
    printWordByWord("Select a service you want to appoint:", 30);
    printWordByWord("Press (1) if you want to select Hair service", 30);
    printWordByWord("Press (2) if you want to select Treatment service", 30);
    printWordByWord("Press (3) if you want to exit", 30);
    cout << "Enter Your Choice:\n";
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
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*  < Back                              Hair Services                                      *\n";
    cout << "*                                   ══════════════════                                    *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                                                                         *\n";
    cout << "*                                ──────       ───────────                                 *\n";
    cout << "*                               │ Hair │     │ Treatments│                                *\n";
    cout << "*                                ──────       ───────────                                 *\n";
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
                    if (choice3 == 0) {
                            // back to hair menu
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
                
    printWordByWord("Proceeding to the selection of schedule...", 30);
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
                    if (choice5 == 0) continue;
                            if (choice5 < 1 || choice5 > 7) {
                                cout << "Invalid schedule option\n";
                                waitEnter();
                                continue;
                            }
                    cout << "You selected schedule option " << choice5 << "\n";
                                

    printWordByWord("Proceeding to the selection of payment...", 30);
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
                     if (choice6 == 0) continue;
                            if (choice6 < 1 || choice6 > 7) {
                                cout << "Invalid payment option\n";
                                waitEnter();
                                continue;
                            }
                   cout << "You selected payment option " << choice6 << "\n";

    printWordByWord("Proceeding to the payment transaction...", 30);
                            
    do {                    
        choice7 = -1;
       
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
   if (choice3 == 1 || choice3 == 2) {
    cout << "*                                 │ •₱250 Men/Women    │                                  *\n";
    } else if (choice3 == 3) {
    cout << "*                                 │ •₱150 Kids         │                                  *\n";
    } else if (choice3 == 4) {
    cout << "*                                 │ •₱500 Hair & Makeup│                                  *\n";
    } else if (choice3 == 5) {
    cout << "*                                 │ •₱180 Shampoo &    │                                  *\n";
    cout << "*                                 │ Blowdry            │                                  *\n";}
    cout << "*                                  ────────────────────                                   *\n";
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *\n";
    cout << "Please send the exact price of the chosen service: \n";
    if (!readInt(choice7)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        break;
                    }
                    bool ok = false;
                                if ((choice3 == 1 || choice3 == 2) && choice7 == 250) ok = true;
                                if (choice3 == 3 && choice7 == 150) ok = true;
                                if (choice3 == 4 && choice7 == 500) ok = true;
                                if (choice3 == 5 && choice7 == 180) ok = true;

                                if (ok) {
                                    cout << "Successfully paid, Thank you!\n";
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
                continue;
            } // end of case 1
    
    case 2: {
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
    cout << "*                                ──────       ───────────                                 *\n";
    cout << "*                               │ Hair │     │ Tretments │                                *\n";
    cout << "*                                ──────       ───────────                                 *\n";
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
    cout << "*  │                              •₱500 Hot Oil/Hair Spa                                │ *\n";
    cout << "*  │                              •₱800 Cynos with Creme                                │ *\n";
    cout << "*  │                              •₱700 Scalp Treatment                                 │ *\n";
    cout << "*  │                              •₱1100 Rebonding                                      │ *\n";
    cout << "*  │                              •₱1500 Japenese Rebonding                             │ *\n";
    cout << "*  │                              •₱1800 Hair Color Change                              │ *\n";
    cout << "*  │                              •₱5500 Keratin Treatment                              │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  │                                                                                    │ *\n";
    cout << "*  ─────────────────────────────────────────────────────────────────────────────────────  *\n";
    cout << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * *\n";
    cout << "Press (1) for Hot Oil/Hair Spa\n";
    cout << "Press (2) for Cynos with Creme\n";
    cout << "Press (3) for Scalp Treatment\n";
    cout << "Press (4) for Rebonding\n";
    cout << "Press (5) for Japenese Rebonding\n";
    cout << "Press (6) for Hair Color Change\n";
    cout << "Press (7) for Keratin Treatment\n";
    cout << "Press (0) to return to Hair menu\n";
    cout << "Enter Your Choice: ";
    
    if (!readInt(choice3)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        continue;
                    }
                    if (choice3 == 0) {
                            // back to hair menu
                            continue;
                        }
                    if (choice3 >= 1 && choice3 <= 7) {
                         switch (choice3) {
                                case 1: cout << "You selected Hot Oil/Hair Spa\n"; break;
                                case 2: cout << "You selected Cynos with Creme\n"; break;
                                case 3: cout << "You selected Scalp Treatment\n"; break;
                                case 4: cout << "You selected Rebonding\n"; break;
                                case 5: cout << "You selected Japenese Rebonding\n"; break;
                                case 6: cout << "You selected Hair Color Change\n"; break;
                                case 7: cout << "You selected Keratin Treatment\n"; break;
                            }
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
                
    printWordByWord("Proceeding to the selection of schedule...", 30);
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
                    if (choice5 == 0) continue;
                            if (choice5 < 1 || choice5 > 7) {
                                cout << "Invalid schedule option\n";
                                waitEnter();
                                continue;
                            }
                    cout << "You selected schedule option " << choice5 << "\n";
                                

    printWordByWord("Proceeding to the selection of payment...", 30);
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
                     if (choice6 == 0) continue;
                            if (choice6 < 1 || choice6 > 7) {
                                cout << "Invalid payment option\n";
                                waitEnter();
                                continue;
                            }
                   cout << "You selected payment option " << choice6 << "\n";

    printWordByWord("Proceeding to the payment transaction...", 30);
                            
    do {                    
        choice7 = -1;
       
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * *\n";
    cout << "*                                      ══════════════════                                   *\n";
    cout << "*  < Back                                 Hair Services                                     *\n";
    cout << "*                                      ══════════════════                                   *\n";
    cout << "*                                     *Payment Transaction*                                 *\n";
    cout << "*                                  ──────────────────────────                               *\n";
    cout << "*                                 │ Send to:                 │                              *\n";
    cout << "*                                 │ 09285739896              │                              *\n";
    cout << "*                                 │                          │                              *\n";
    cout << "*                                 │ Please send the          │                              *\n";
    cout << "*                                 │ exact price of           │                              *\n";
    cout << "*                                 │ the chosen service:      │                              *\n";
   if (choice3 == 1 ) {
    cout << "*                                 │ •₱500 Hot Oil/Hair Spa   │                              *\n";
    } else if (choice3 == 2) {
    cout << "*                                 │ •₱800 Cynos with Creme   │                              *\n";
    } else if (choice3 == 3) {
    cout << "*                                 │ •₱700 Scalp Treatment    │                              *\n";
    } else if (choice3 == 4) {
    cout << "*                                 │ •₱1100 Rebonding         │                              *\n";
    } else if (choice3 == 5) {
    cout << "*                                 │ •₱1500 Japenese Rebonding│                              *\n";
    } else if (choice3 == 6) {
    cout << "*                                 │ •₱1800 Hair Color Change │                              *\n";
    } else if (choice3 == 7) {
    cout << "*                                 │ •₱5500 Keratin Treatment │                              *\n";}
    cout << "*                                  ──────────────────────────                               *\n";
    cout << "* * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * *\n";
    cout << "Please send the exact price of the chosen service: \n";
    if (!readInt(choice7)) {
                        cout << "Invalid input. Returning to Hair menu...\n";
                        this_thread::sleep_for(chrono::milliseconds(600));
                        break;
                    }
                    bool ok = false;
                                if (choice3 == 1 && choice7 == 500) ok = true;
                                if (choice3 == 2 && choice7 == 800) ok = true;
                                if (choice3 == 3 && choice7 == 700) ok = true;
                                if (choice3 == 4 && choice7 == 1100) ok = true;
                                if (choice3 == 5 && choice7 == 1500) ok = true;
                                if (choice3 == 6 && choice7 == 1800) ok = true;
                                if (choice3 == 7 && choice7 == 5500) ok = true;
                                

                                if (ok) {
                                    cout << "Successfully paid, Thank you!\n";
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
                continue;
            }
            } // end treatments submenu
    break;
    
        }
}// end main loop



