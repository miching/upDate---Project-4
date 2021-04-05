// Michael Ching
// CECS282-01
// Project 4 - Operator Overloading
// Due: 4/5/2021
//
//  I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program.

#ifndef UPDATE_H
#define UPDATE_H

#include <iostream>
#include <string>
using namespace std;

class upDate 
{

  private:
    int *ptr;
    static int count;

  public:
    upDate();
    upDate(int, int, int);
    upDate(int);
    upDate(const upDate&);
    ~upDate();
    friend upDate operator+(int days, upDate d);
    void setDate(int, int, int);
    int getMonth();
    int getDay();
    int getYear();
    string getMonthName();
    upDate operator=(const upDate &);
    upDate operator+=(int);
    upDate operator-=(int);
    upDate operator+(int);
    upDate operator-(int);
    int operator-(upDate);
    static int GetDateCount();
    friend ostream &operator<<(ostream &out, upDate);
    upDate operator++(int);
    upDate operator++();
    upDate operator--(int);
    upDate operator--();
    int julian();
    bool operator==(upDate);
    bool operator<(upDate);
    bool operator>(upDate);
    
};
#endif