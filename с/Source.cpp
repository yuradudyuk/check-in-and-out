#include <iostream>
#include<time.h>
#include <conio.h>
#include <fstream>
#include <string>
//conio is for keyboard

using namespace std;
class TimeTracking {
private:
    time_t byDefault=0;
    const string path1 = "checkin.txt";
    const string path2 = "summary.txt";

public:
    TimeTracking() {}
    void checkIn_writingIntxt() {
        //function checks whether u checked in or not
        // якщо число у файлі -1 то значить можна чек інитися, якщо ні, то вже зачек-інені
        int checker=reading_file(path1);
        if (checker>1) {
            wcout << "You are already checked-in" << endl;
            return;
        }
        byDefault = time(nullptr);
        writing_file(path1, byDefault);
        
    }

    void checkIn_readingfromtxt() {

        int number= reading_file(path1);
        if (number) {
            writing_file(path1, -1);
            summary_txt(number);
        }
        else
        {
            wcout << "You are not checked-in. check-in first" << endl;
        }
        
    }
private:
    void summary_txt(int number) {
        byDefault = time(nullptr);
        int checkOutTime=byDefault;
        int checkIntime = number;
        //витягнути чек ін, від чек аута відняти чек ні, взяти попередню суму у файлі,
        // та додати з різницею та записати у файл суми часу
        int session_time = sessiomTime(checkIntime, checkOutTime);
        int prev_sum_time = reading_file(path2);
        prev_sum_time += session_time;
        writing_file(path2, prev_sum_time);
    }
public:
    void printing_time() {
        double time = reading_file(path2);
        wcout << time / 3600;
    }
private:

    int reading_file(string path) {
        int number = 0;
        ifstream file_in;
        file_in.open(path);

        while (!file_in.eof())
        {
            file_in >> number;
        }

        file_in.close();
        return number;
    }

    void writing_file(string path,int number) {
        ofstream file_out;
        file_out.open(path);
        file_out << number;
        file_out.close();
    }

    int sessiomTime(int checkintime, int checkouttime) {
        int result = checkouttime - checkintime;
        return result;
    }
    //треба буде додати три аналогічні функції для публічного інтерфейсу
    // і в них прикрутити запис в лайт SQL
};



int main() {
    int input = 0;
    wcout << "Welcome to time tracker!" << endl;
    do{
        wcout << "Press 1 to checkin, 2 to checkout, 3 to see time driving" << endl;
        wcin >> input; // for interface
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
            wcout << "You entered wrong number" << endl;
        }
        delete proc;

        
    } while (true);
    
    return 0;
}