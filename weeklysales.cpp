#include <iostream>
using namespace std;

// constants which are used throughout the program
#define kPricePerUnit 225  // average price of a pair of shoes
#define kWeeklyWage 600    // current weekly wage - Method 1
#define kSalary 7.0        // hourly salary - Method 2
#define kHoursPerWeek 40    // number of hours worked - Method 2
#define kCommission2  0.10  // commission - Method 2
#define kCommission3 0.2    // commission - Method 3
#define kBonusPerUnit 20    // bonus  - Method 3


int GetInput() {
	int sales;

	cout << "Enter a weekly sales amount (-1 = quit): ";
	if (!(cin >> sales)) {
	  cout << "You entered a non-numeric." << endl;
	  return 0;
	}
	return sales;
}

void CalcMethod1(int sales) {
  cout << "Method 1: $" << kWeeklyWage << "/week" << endl;
}

void CalcMethod2(int sales) {
  double salary;
  salary = kSalary*kHoursPerWeek + kCommission2*kPricePerUnit*sales;
  cout << "Method 2: $" << salary << "/week" << endl;
}

void CalcMethod3(int sales) {
  double salary;
  salary = (kCommission3*kPricePerUnit + kBonusPerUnit)*sales;
  cout << "Method 3: $" << salary << "/week" << endl;
}


int main() {
  int sales; 

  sales = GetInput();
  if (sales == 0) return 0;
  CalcMethod1(sales);
  CalcMethod2(sales);
  CalcMethod3(sales);
}
