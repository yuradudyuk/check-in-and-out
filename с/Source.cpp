#include <iostream>
#include <conio.h>
#include "TimeTrackingClass.h"
//conio is for keyboard.not using anymore

using namespace std;


int main() {
    int input = 0;
    cout << "Welcome to time tracker!" << endl;
    do{
        cout << "Press 1 to checkin, 2 to checkout, 3 to see time driving" << endl;
        cin >> input; // for interface
        TimeTracking* proc=new TimeTracking();
 
        switch (input) {
        case 1:
            proc->checkIn_writingIntxt();
            break;
        case 2:
            proc->checkIn_readingfromtxt();

            break;
        case 3:
            proc->printing_time();
            break;
        default:
            cout << "You entered wrong number" << endl;
        }
        delete proc;

        
    } while (true);
    
    return 0;
}