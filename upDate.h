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
    

/*
    void display();
    void increaseDate(int);
    void decreaseDate(int);
    int dayOfYear();
    string dayName();
    string toString();
    void randBirthday(upDate, upDate);
    int JDdate();
  */
    
};
#endif