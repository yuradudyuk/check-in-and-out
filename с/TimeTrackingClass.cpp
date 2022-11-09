#include "TimeTrackingClass.h"
#include <iostream>
#include <fstream>
void TimeTracking::checkIn_writingIntxt()
{
    //function checks whether u checked in or not
       // якщо число у файлі -1 то значить можна чек інитися, якщо ні, то вже зачек-інені
    int checker = reading_file(path1);
    if (checker > 1) {
        std::cout << "You are already checked-in" << std::endl;
        return;
    }
    byDefault = time(nullptr);
    writing_file(path1, byDefault);
}

void TimeTracking::checkIn_readingfromtxt()
{
    int number = reading_file(path1);
    if (number) {
        writing_file(path1, -1);
        summary_txt(number);
    }
    else
    {
        std::cout << "You are not checked-in. check-in first" << std::endl;
    }
}

void TimeTracking::printing_time()
{
    double time = reading_file(path2);
    std::cout << time / 3600;
}

void TimeTracking::summary_txt(int number)
{
    byDefault = time(nullptr);
    int checkOutTime = byDefault;
    int checkIntime = number;
    //витягнути чек ін, від чек аута відняти чек ні, взяти попередню суму у файлі,
    // та додати з різницею та записати у файл суми часу
    int session_time = sessiomTime(checkIntime, checkOutTime);
    int prev_sum_time = reading_file(path2);
    prev_sum_time += session_time;
    writing_file(path2, prev_sum_time);
}

int TimeTracking::reading_file(std::string path)
{
    int number = 0;
    std::ifstream file_in;
    file_in.open(path);

    while (!file_in.eof())
    {
        file_in >> number;
    }

    file_in.close();
    return number;
}

void TimeTracking::writing_file(std::string path, int number)
{
    std::ofstream file_out;
    file_out.open(path);
    file_out << number;
    file_out.close();
}

int TimeTracking::sessiomTime(int checkintime, int checkouttime)
{
    int result = checkouttime - checkintime;
    return result;
}
