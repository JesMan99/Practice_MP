/**
 * @file DateTime.cpp
 * @author DECSAI
 * @note To be implemented by students 
 * 
 */

#include <iostream>
#include <sstream>
#include <string>
#include "DateTime.h"
using namespace std;

/**
 * @brief auxiliary function to check if the date and the time are in correct 
 * format, taking into account, leap year etc.
 * @param year input
 * @param month input
 * @param day input
 * @param hour input
 * @param min input
 * @param sec input
 * @return true if is correct, false if not
 */
bool isCorrect(int year, int month, int day, int hour, int min, int sec){
    
    int days_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    month--;
    
    if(month > 11 || month < 1)
        return false;
    
    else if (hour > 23 ||hour < 0 || min > 59 || min < 0 || sec < 0 || sec > 59)
        return false;
    
    if ((year % 4 == 0 && year % 100 != 0) || year %  400 == 0)
        days_month[1]++;
    
    if (day < 1 || day > days_month[month])
        return false;
    else return true; 
}
/**
 * @brief split the first field in 6 components of the data time.
 * Please consider using string::substr(int, int)[https://en.cppreference.com/w/cpp/string/basic_string/substr] to cut the line
 * into the appropriate substrings and then convert it into integer values with 
 * the function stoi(string) [https://en.cppreference.com/w/cpp/string/basic_string/stol]
 * ~~~~
 *      YYYY-MM-dd hh:mm:ss UTC 
 *      +----+----+----+----+----+ 
 *      |    |    |    |    |    |
 *      0    5    10   15   20   25
 * ~~~~
 *  * @param line input string
 * @param y output int
 * @param m output int
 * @param d output int
 * @param h output int
 * @param mn output int
 * @param s output int
 */
void split( const std::string &line, int &y, int &m, int &d, int &h, int &mn, int &s){
    y = stoi(line.substr(0,4));
    m = stoi(line.substr(5,2));
    d = stoi(line.substr(8,2));
    h = stoi(line.substr(11,2));
    mn = stoi(line.substr(14,2));
    s = stoi(line.substr(17,2));
}

DateTime::DateTime() {
    initDefault();
}

void DateTime::initDefault() {
    _year = 1971;
    _month = 1;
    _day = 1;
    _hour = 0; 
    _min = 0;
    _sec = 0;
}

bool isCorrect(int year, int month, int day, int hour, int min, int sec) {


}

void split( const std::string &line, int &y, int &m, int &d, int &h, int &mn, int &s) {
    
}

void DateTime::set( const std::string &line) {
    _year = stoi(line.substr(0,4));
    _month = stoi(line.substr(5,2));
    _day = stoi(line.substr(8,2));
    _hour = stoi(line.substr(11,2));
    _min = stoi(line.substr(14,2));
    _sec = stoi(line.substr(17,2));
}

DateTime::DateTime( const string  &line) {
    set (&line);
}

int DateTime::year() const { return _year; }

int DateTime::month() const { return _month; }

int DateTime::day() const { return _day; }

int DateTime::hour() const { return _hour; }

int DateTime::min() const { return _min; }

int DateTime::sec() const { return _sec; }

bool DateTime::isBefore( DateTime  &one) const  {
    return to_string() < one.to_string();
}

int DateTime::weekDay() const  {
    int a = (14 - _month) / 12;
    int y = _year - a;
    int m = _month + 12 * a -2;
    int wDay;
    wDay = (_day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return wDay;
}

string DateTime::to_string() const {
    char local[64];
    sprintf(local, "%04i-%02i-%02i %02i:%02i:%02i UTC", _year, _month, _day, _hour, _min, _sec);
    return local;
}

