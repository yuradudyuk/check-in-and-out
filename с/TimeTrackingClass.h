#pragma once
#include<time.h>
#include <string>
class TimeTracking
{
public:
	void checkIn_writingIntxt();

	void checkIn_readingfromtxt();

	void printing_time();


private:
	time_t byDefault = 0;
	const std::string path1 = "checkin.txt";
	const std::string path2 = "summary.txt";
	void summary_txt(int number);
	int reading_file(std::string path);
	void writing_file(std::string path, int number);
	int sessiomTime(int checkintime, int checkouttime);
	//треба буде додати три аналогічні функції для публічного інтерфейсу
	// і в них прикрутити запис в лайт SQL
};

