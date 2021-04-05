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

  upDate count, count2, count3;
  cout << "Number of upDates: " << upDate::GetDateCount() << endl;
  {
    upDate temp(1,1,2012);
    upDate temp2(1,1,2021);
    temp2--;
    cout << "In Bracket: " << upDate::GetDateCount() << endl;
  }
  cout << "Out Bracket: " << upDate::GetDateCount() << endl;


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

 
  cout << "Non-Member Add Days to date: " << endl;
  upDate nonAddDays (2,5,2012);
  upDate nonAdded;
  nonAdded = 10 + nonAddDays;
  cout << nonAddDays << endl;
  cout << nonAdded << endl;


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


  cout << "Print upDate objects: " << endl;
  upDate print(9,9,2019);
  cout << print.getMonth() << "/" << print.getDay() << "/" << print.getYear() << endl;
  cout << print << endl;


  cout << "Post Increment: Date++" << endl;
  upDate postIncrement(7,20,2015);
  cout << postIncrement << endl;
  cout << postIncrement++ << endl;
  cout << postIncrement << endl;
  cout << postIncrement++ << endl;
  cout << postIncrement << endl;


  cout << "Pre Increment: ++Date" << endl;
  upDate preIncrement(3,5,2018);
  cout << preIncrement << endl;
  cout << ++preIncrement << endl;


  cout << "Post decrement: Date--" << endl;
  upDate postDecrement(12,5,2018);
  cout << postDecrement << endl;
  cout << postDecrement++ << endl;
  cout << postDecrement << endl;
  cout << postDecrement++ << endl;
  cout << postDecrement << endl;


  cout << "Pre Increment: --Date" << endl;
  upDate preDecrement(4,19,2012);
  cout << preDecrement << endl;
  cout << ++preDecrement << endl;


  cout << "Julian Date: " << endl;
  upDate jDate (2,12,2001);
  cout << jDate.julian() << endl;


  cout << "Equal Comparison: " << endl;
  upDate equal(11,11,2011);
  upDate equal2(11,11,2011);
  upDate equal3(2,20,2020);
  cout << ((equal==equal2)?"equal to":"not equal to") << endl;
  cout << ((equal==equal3)?"equal to":"not equal to") << endl;


  cout << "Less Than Comparison: " << endl;
  upDate lessThan(9,25,2019);
  upDate lessThan2(12,20,2008);
  upDate lessThan3(2,20,2015);
  cout << ((lessThan3<lessThan)?"less than":"not less than") << endl;
  cout << ((lessThan3<lessThan2)?"less than":"not less than") << endl;


  cout << "Greater Than Comparison: " << endl;
  upDate greaterThan(9,25,2019);
  upDate greaterThan2(12,20,2008);
  upDate greaterThan3(2,20,2015);
  cout << ((greaterThan3>greaterThan)?"greater than":"not greater than") << endl;
  cout << ((greaterThan3>greaterThan2)?"greater than":"not greater than") << endl;

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