// Ruben Armenta
// CPSC 120-06
// 2022-10-19
// raarmenta@csu.fullerton.edu
// @rubenarmenta
//
// Lab 07-01
// Partners: @rtrinh02
//
// Program to calculate the number of days between two Gregorian dates.
//
#include <iostream>
int JulianDay(int month, int day, int year) {
  int number_of_days_since_epoch{0};
  number_of_days_since_epoch =
      day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 +
      367 * (month - 2 - (month - 14) / 12 * 12) / 12 -
      3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
  return number_of_days_since_epoch;
}
int DateDifference(int start_month, int start_day, int start_year,
                   int end_month, int end_day, int end_year) {
  int date_difference = JulianDay(end_month, end_day, end_year) -
                        JulianDay(start_month, start_day, start_year);
  return date_difference;
}
void PrintDate(int month, int day, int year) {
  std::cout << month << "/" << day << "/" << year;
}
int main(int argc, char* argv[]) {
  std::cout << "Let's find the number of days between two dates...\n";
  std::cout << "Enter a start month: ";
  int start_month{0};
  std::cin >> start_month;
  std::cout << "Enter a start day: ";
  int start_day{0};
  std::cin >> start_day;
  std::cout << "Enter a start year: ";
  int start_year{0};
  std::cin >> start_year;
  std::cout << "\n";
  std::cout << "Enter an end month: ";
  int end_month{0};
  std::cin >> end_month;
  std::cout << "Enter an end day: ";
  int end_day{0};
  std::cin >> end_day;
  std::cout << "Enter an end year: ";
  int end_year{0};
  std::cin >> end_year;
  int date_difference = DateDifference(start_month, start_day, start_year,
                                       end_month, end_day, end_year);
  std::cout << "The number of days between ";
  PrintDate(start_month, start_day, start_year);
  std::cout << " and ";
  PrintDate(end_month, end_day, end_year);
  std::cout << " is " << date_difference << " days\n";
  return 0;
}
