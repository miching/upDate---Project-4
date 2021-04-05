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

int upDate::count = 0;

//Non-member Add operator
upDate operator+(int days, upDate d)
{

  upDate temp = d;
  int JDdate = Greg2Julian(temp.ptr[2], temp.ptr[0], temp.ptr[1]);   // year, month, day
  JDdate += days;
  Julian2Greg(JDdate, temp.ptr[2], temp.ptr[0], temp.ptr[1]);
  return temp;

}

upDate::upDate()
{

  ptr = new int [3];
  ptr[0] = 5;
  ptr[1] = 11;
  ptr[2] = 1959;
  count++;

}

upDate::upDate(int m, int d, int y)
{

  int orginalM = m;
  int orginalD = d;
  int orginalY = y;
  ptr = new int [3];
  count++;

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

  ptr = new int [3];
  ptr[0] = month;
  ptr[1] = day;
  ptr[2] = year;
  count++;

}

//Copy Constructor
upDate::upDate(const upDate &d)
{

  ptr = new int [3];
  ptr[0] = d.ptr[0];
  ptr[1] = d.ptr[1];
  ptr[2] = d.ptr[2];
  count++;

}

upDate::~upDate()
{

  count--;
  delete [] ptr;
  

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

//Assignment operator
upDate upDate::operator=(const upDate &d)
{

  this -> ptr[0] = d.ptr[0];
  this -> ptr[1] = d.ptr[1];
  this -> ptr[2] = d.ptr[2];
  return *this;
  
}

upDate upDate::operator+=(int days)
{

  int JDdate = Greg2Julian(this -> ptr[2], this -> ptr[0], this -> ptr[1]);   // year, month, day
  JDdate += days;
  Julian2Greg(JDdate, this -> ptr[2], this -> ptr[0], this -> ptr[1]);
  return *this;

}

upDate upDate::operator-=(int days)
{

  int JDdate = Greg2Julian(this -> ptr[2], this -> ptr[0], this -> ptr[1]);   // year, month, day
  JDdate -= days;
  Julian2Greg(JDdate, this -> ptr[2], this -> ptr[0], this -> ptr[1]);
  return *this;

}

upDate upDate::operator+(int days)
{

  upDate temp = *this;
  int JDdate = Greg2Julian(temp.ptr[2], temp.ptr[0], temp.ptr[1]);   // year, month, day
  JDdate += days;
  Julian2Greg(JDdate, temp.ptr[2], temp.ptr[0], temp.ptr[1]);
  return temp;

}

upDate upDate::operator-(int days)
{

  upDate temp = *this;
  int JDdate = Greg2Julian(temp.ptr[2], temp.ptr[0], temp.ptr[1]);   // year, month, day
  JDdate -= days;
  Julian2Greg(JDdate, temp.ptr[2], temp.ptr[0], temp.ptr[1]);
  return temp;

}

int upDate::operator-(upDate d)
{

  int thisDate = Greg2Julian(this -> ptr[2], this -> ptr[0], this -> ptr[1]);
  int otherDate = Greg2Julian(d.getYear(), d.getMonth(), d.getDay() );
  thisDate -= otherDate;
  return thisDate;

}

int upDate::GetDateCount()
{

  return count;

}

ostream &operator<<(ostream &out, upDate d)
{

  out << d.getMonth() << "/" << d.getDay() << "/" << d.getYear();
  return out;

}

upDate upDate::operator++(int) //Date++
{

  upDate temp = *this;
  int JDdate = Greg2Julian(this -> ptr[2], this -> ptr[0], this -> ptr[1]);   // year, month, day
  JDdate++;
  Julian2Greg(JDdate, this -> ptr[2], this -> ptr[0], this -> ptr[1]);
  return temp;

}

upDate upDate::operator++() //++Date
{

  int JDdate = Greg2Julian(this -> ptr[2], this -> ptr[0], this -> ptr[1]);   // year, month, day
  JDdate++;
  Julian2Greg(JDdate, this -> ptr[2], this -> ptr[0], this -> ptr[1]);
  return *this;

}

upDate upDate::operator--(int)  //Date--
{

  upDate temp = *this;
  int JDdate = Greg2Julian(this -> ptr[2], this -> ptr[0], this -> ptr[1]);   // year, month, day
  JDdate--;
  Julian2Greg(JDdate, this -> ptr[2], this -> ptr[0], this -> ptr[1]);
  return temp;

}

upDate upDate::operator--() //--Date
{

  int JDdate = Greg2Julian(this -> ptr[2], this -> ptr[0], this -> ptr[1]);   // year, month, day
  JDdate--;
  Julian2Greg(JDdate, this -> ptr[2], this -> ptr[0], this -> ptr[1]);
  return *this;

}

int upDate::julian()
{

  return Greg2Julian(ptr[2], ptr[0], ptr[1]);
 
}

bool upDate::operator==(upDate d)
{

  return  (*this).julian() == d.julian();
 
}

bool upDate::operator<(upDate d)
{

  return (*this).julian() < d.julian();

}

bool upDate::operator>(upDate d)
{

  return (*this).julian() > d.julian();

}
