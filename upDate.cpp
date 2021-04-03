#include "upDate.h"
using namespace std;

int Greg2Julian(int y, int m, int d)
{

  int I = y;
  int J = m;
  int K = d;
  
  int JD = K - 32075 + 1461 * (I + 4800 + (J-14)/12)/4 + 367 * (J - 2 - (J - 14)/12 * 12)/12 - 3 * ((I + 4900 + (J-14)/12)/100)/4;

  return JD;

}

void Julian2Greg(int JD, int & year, int & month, int & day)
{

  int I,J,K;
  int L = JD + 68569;
  int N = 4 * L/146097;
  L = L - (146097 * N + 3)/4;
  I = 4000 * (L + 1) / 1461001;
  L = L - 1461 * I/4 + 31;
  J = 80 * L /2447;
  K = L - 2447 * J/80;
  L = J/11;
  J = J + 2 - 12 * L;
  I = 100 * (N - 49) + I + L;

  year = I;
  month = J; 
  day = K;

}

upDate::upDate()
{

  ptr = new int [3];
  ptr[0] = 5;
  ptr[1] = 11;
  ptr[2] = 1959;

}

upDate::upDate(int m, int d, int y)
{

  int orginalM = m;
  int orginalD = d;
  int orginalY = y;
  ptr = new int [3];

  int JD = Greg2Julian(y, m, d);
  Julian2Greg(JD, y, m, d);

  if( (m == orginalM) && (d == orginalD) && (y == orginalY) )
  {

    ptr[0] = m;
    ptr[1] = d;
    ptr[2] = y;

  }
  else
  {
  
    ptr[0] = 5;
    ptr[1] = 11;
    ptr[2] = 1959;

  }

}

upDate::upDate(int JD)
{

  int month;
  int day;
  int year;
  Julian2Greg(JD, year, month, day);

  ptr[0] = month;
  ptr[1] = day;
  ptr[2] = year;

}

upDate::~upDate()
{

  

}

void upDate::setDate(int month, int day, int year)
{

  ptr[0] = month;
  ptr[1] = day;
  ptr[2] = year;

}

int upDate::getMonth()
{

  return ptr[0];

}

int upDate::getDay()
{

  return ptr[1];

}

int upDate::getYear()
{

  return ptr[2];

}


string upDate::getMonthName()
{
  
  string monthName;

  if(ptr[0] == 1)
  {

    monthName = "January";

  }
  else if(ptr[0] == 2)
  {

    monthName = "February";

  }
  else if(ptr[0] == 3)
  {

    monthName = "March";

  }
  else if(ptr[0] == 4)
  {

    monthName = "April";

  }
  else if(ptr[0] == 5)
  {

    monthName = "May";

  }
  else if(ptr[0] == 6)
  {

    monthName = "June";

  }
  else if(ptr[0] == 7)
  {

    monthName = "July";

  }
  else if(ptr[0] == 8)
  {

    monthName = "August";

  }
  else if(ptr[0] == 9)
  {

    monthName = "September";

  }
  else if(ptr[0] == 10)
  {

    monthName = "October";

  }
  else if(ptr[0] == 11)
  {

    monthName = "November";

  }
  else if(ptr[0] == 12)
  {

    monthName = "December";

  }
 
 return monthName;

}

/*
void upDate::increaseDate(int days)
{

  int JD = Greg2Julian(year, month, day);
  JD += days;
  Julian2Greg(JD, year, month, day);

}

void upDate::decreaseDate(int days)
{

  int JD = Greg2Julian(year, month, day);
  JD -= days;
  Julian2Greg(JD, year, month, day);

}

int upDate::daysBetween(myDate d)
{

  int thisDate = Greg2Julian(year, month, day);
  int otherDate = Greg2Julian(d.getYear(), d.getMonth(), d.getDay());
  otherDate -= thisDate;
  return otherDate;

}



int upDate::dayOfYear()
{

 int JD = Greg2Julian(year, month, day);
 int startOfYear = Greg2Julian(year, 1, 1);
 JD = JD - startOfYear + 1;
 return JD;

}

string myDate::dayName()
{

  int JD = Greg2Julian(year, month, day);
  string dayName;

  if(JD % 7 == 0)
  {

    dayName = "Monday";

  }
  else if(JD % 7 == 1)
  {

    dayName = "Tuesday";

  }
  else if(JD % 7 == 2)
  {

    dayName = "Wednesday";

  }
  else if(JD % 7 == 3)
  {

    dayName = "Thursday";

  }
  else if(JD % 7 == 4)
  {

    dayName = "Friday";

  }
  else if(JD % 7 == 5)
  {

    dayName = "Saturday";

  }
  else if (JD % 7 == 6)
  {

    dayName = "Sunday";
    
  }
  
   return dayName;

}

string myDate::toString()
{

  string date;

  if(month == 1)
  {

    date = "January";

  }
  else if(month == 2)
  {

    date = "February";

  }
  else if(month == 3)
  {

    date = "March";

  }
  else if(month == 4)
  {

    date = "April";

  }
  else if(month == 5)
  {

    date = "May";

  }
  else if(month == 6)
  {

    date = "June";

  }
  else if(month == 7)
  {

    date = "July";

  }
  else if(month == 8)
  {

    date = "August";

  }
  else if(month == 9)
  {

    date = "September";

  }
  else if(month == 10)
  {

    date = "October";

  }
  else if(month == 11)
  {

    date = "November";

  }
  else if(month == 12)
  {

    date = "December";

  }
  
  date = date + " " + to_string(day) + ", " + to_string(year);

  return date;
}

 void myDate::randBirthday(myDate oldestDate, myDate youngestDate)
 {

   int old = Greg2Julian(oldestDate.year, oldestDate.month, oldestDate.day);
   int young = Greg2Julian(youngestDate.year, youngestDate.month, youngestDate.day);
  
   int range = young - old + 1;

   //srand(time(NULL));
   int birthday = rand() % range + old;

   Julian2Greg(birthday, year, month, day);

 }
 
 int myDate::JDdate()
 {

  return Greg2Julian(year,month,day);

 }
 */