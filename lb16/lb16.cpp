#include <iostream>
#include <ctime>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int monthLength(int year, int month) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeap(year)) {
        return 29;
    }
    return daysInMonth[month];
}

Date today(void) {
    time_t t = time(NULL);
    tm tl = *localtime(&t);
    Date d;
    d.year = tl.tm_year + 1900;
    d.month = tl.tm_mon + 1;
    d.day = tl.tm_mday;
    return d;
}

long dateToDays(Date d) {
    long days = (d.year - 1) * 365 + ((d.year - 1) / 4 - (d.year - 1) / 100 + (d.year - 1) / 400);
    for (int i = 1; i < d.month; i++) {
        days += monthLength(d.year, i);
    }
    days += d.day;
    return days;
}

int main(void) {
    Date bday;
    
    cout << "Enter your birth year: ";
    cin >> bday.year;
    cout << "Enter your birth month: ";
    cin >> bday.month;
    cout << "Enter your birth day: ";
    cin >> bday.day;

    Date current = today();
    long daysPassed = dateToDays(current) - dateToDays(bday);

    cout << "\nCurrent date: " << current.year << "-" << current.month << "-" << current.day << "\n";
    cout << "Days passed since birth: " << daysPassed << "\n";

    return 0;
}