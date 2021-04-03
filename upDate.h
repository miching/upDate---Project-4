#ifndef UPDATE_H
#define UPDATE_H

#include <iostream>
#include <string>
using namespace std;

class upDate 
{

  private:
    int *ptr;

  public:
    upDate();
    upDate(int, int, int);
    upDate(int);
    ~upDate();
    void setDate(int, int, int);
    int getMonth();
    int getDay();
    int getYear();
    string getMonthName();

/*
    void display();
    void increaseDate(int);
    void decreaseDate(int);
    int daysBetween(upDate);
    int dayOfYear();
    string dayName();
    string toString();
    void randBirthday(upDate, upDate);
    int JDdate();
  */
    
};
#endif