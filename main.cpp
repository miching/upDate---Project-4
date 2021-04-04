// testupDate.cpp
// Author: Steven H Gold
// Program #4 due date: 4/5/2021
// 
// 
//
//

#include "upDate.h"
#include <iostream>
using namespace std;

int main()
{



  upDate bday(10,10,2020);
  upDate bday2(2450000);
  cout << bday.getMonth() << "/" << bday.getDay() << "/" << bday.getYear() << endl;
  cout << bday2.getMonth() << "/" << bday2.getDay() << "/" << bday2.getYear() << endl;

  cout << "Copy: " << endl;
  upDate copyDate = bday;
  upDate copyDate2(bday);
  cout << bday.getMonth() << "/" << bday.getDay() << "/" << bday.getYear() << endl;
  cout << copyDate.getMonth() << "/" << copyDate.getDay() << "/" << copyDate.getYear() << endl;
  cout << copyDate2.getMonth() << "/" << copyDate2.getDay() << "/" << copyDate2.getYear() << endl;

  bday.setDate(2, 12, 2001);

  cout << "Changed bDay " << endl;
  cout << bday.getMonth() << "/" << bday.getDay() << "/" << bday.getYear() << endl;
  cout << copyDate.getMonth() << "/" << copyDate.getDay() << "/" << copyDate.getYear() << endl;
  cout << copyDate2.getMonth() << "/" << copyDate2.getDay() << "/" << copyDate2.getYear() << endl;
  
  cout << "Assignemnt: " << endl;
  upDate assignDate(12,29,2019);
  cout << assignDate.getMonth() << "/" << assignDate.getDay() << "/" << assignDate.getYear() << endl;
  assignDate = bday;
  cout << assignDate.getMonth() << "/" << assignDate.getDay() << "/" << assignDate.getYear() << endl;

  cout << "Increase Days: " << endl;
  upDate increaseDays(1,1,2010);
  cout << increaseDays.getMonth() << "/" << increaseDays.getDay() << "/" << increaseDays.getYear() << endl;
  increaseDays += 7;
  cout << increaseDays.getMonth() << "/" << increaseDays.getDay() << "/" << increaseDays.getYear() << endl;

  cout << "Decrease Days: " << endl;
  upDate decreaseDays(3,10,2020);
  cout << decreaseDays.getMonth() << "/" << decreaseDays.getDay() << "/" << decreaseDays.getYear() << endl;
  decreaseDays -= 7;
  cout << decreaseDays.getMonth() << "/" << decreaseDays.getDay() << "/" << decreaseDays.getYear() << endl;

  cout << "Add Days to date: " << endl;
  upDate addDays (8,8, 2016);
  upDate added (6,6,2018);
  cout << addDays.getMonth() << "/" << addDays.getDay() << "/" << addDays.getYear() << endl;
  cout << added.getMonth() << "/" << added.getDay() << "/" << added.getYear() << endl;
  addDays = added + 10;
  cout << addDays.getMonth() << "/" << addDays.getDay() << "/" << addDays.getYear() << endl;
  cout << added.getMonth() << "/" << added.getDay() << "/" << added.getYear() << endl;

 //NEEDS TO BE FIXED OR added
 /*
  cout << "Non-Member Add Days to date: " << endl;
  addDays = 10 + added;
 */

  cout << "Sub Days to date: " << endl;
  upDate subDays (5,10, 2017);
  upDate subbed (11,23,2015);
  cout << subDays.getMonth() << "/" << subDays.getDay() << "/" << subDays.getYear() << endl;
  cout << subbed.getMonth() << "/" << subbed.getDay() << "/" << subbed.getYear() << endl;
  subDays = subbed - 10;
  cout << subDays.getMonth() << "/" << subDays.getDay() << "/" << subDays.getYear() << endl;
  cout << subbed.getMonth() << "/" << subbed.getDay() << "/" << subbed.getYear() << endl;

  cout << "Days Between: " << endl;
  upDate dayBetween (2,14,2021);
  upDate dayBetween2 (2,20,2021);
  upDate dayBetween3 (2,7,2021);
  cout << "Between Feb 14 and Feb 20: " << dayBetween-dayBetween2 << endl;
  cout << "Between Feb 14 and Feb 7: " << dayBetween-dayBetween3 << endl;


  /*
	upDate Bday;
	upDate duedate(4,5,2021);
	upDate today(duedate);


	cout << endl;
	cout << "Today is " << today << endl;
	cout << "This program is due on " << duedate;
	cout << endl;

	cout << "(3)Right now there are "<<upDate::GetDateCount() << " upDate objects\n";
	{
		upDate d1, d2, d3;
		cout << "(6)Inside this block there are "<<upDate::GetDateCount() << " upDate objects\n";
	}
	cout << "(3)Outside the block there are "<<upDate::GetDateCount() << " upDate objects\n";

	upDate dtemp(duedate);
	dtemp++;
	cout << "If you turn this assignment in on "<<dtemp<<" then is will be late.\n";
	cout << "It is due on "<<--dtemp<<" so don't be late.\n";
	cout << "One week from due date is "<<duedate+7<<endl;
  cout << "One week from due date is "<<7+duedate<<endl;
	cout << "One week earlier from due date is "<<duedate-7<<endl;

	cout << "Your professor was born on "<<Bday<<" : ";
	cout << "Master Gold is "<< duedate - Bday << " days old today\n";
	
	cout << "Today is Julian date "<<duedate.julian()<<endl;;
	cout << "Tomorrrow is Julian date "<<(++duedate).julian()<<endl;;

	cout << "The very first Julian date was " << upDate(11,5,2018)-upDate(11,5,2018).julian()<<endl;

	cout << "The very first Julian date was " << today - today.julian()<<endl;


	upDate yesterday, tomorrow;
	yesterday = today-1;
	tomorrow = today+1;
	
	cout << "Yesterday was "<<yesterday << endl;
	cout << "Today is "<<today<<endl;
	cout << "Tomorrow is "<<tomorrow<<endl;

	cout << "Today is ";
	cout << ((today>tomorrow)?"greater than":"not greater than");
	cout << " than tomorrow\n";

	cout << "Today is ";
	cout << ((today<tomorrow)?"less than":"not less than");
	cout << " than tomorrow\n";

	cout << "Today is ";
	cout << ((today==tomorrow)?"equal to":"not equal to");
	cout << " tomorrow\n";

	getchar();
	return 0;
  */
}