#include <iostream>
#include <time.h>
using namespace std;

int main () {
  int random_number, guess;
  bool status;
  int n = 10000;
  // Initialize random seed.
  srand (time(NULL));

  // Generate random number between 1 and 100
  random_number = rand() % 100 + 1;
  cout << "Your random number:" << random_number << endl;

  do {
    cout << "Enter a number between 1 and 100 (-1 = quit): ";
    // The following line accepts input from the keyboard into
    // variable guess.
    // cin returns false if an input operation fails, that is, if
    // something other than an int (the type of guess) is entered.
    status = cin >> guess;
    if (!status) {
      cout << "You entered a non-numeric. Try again..." << endl;
      cin.clear();
      cin.ignore(n,'\n');
    } else if (guess == -1){
    	break;
    } else if (guess > 100 || guess < 1){
      cout << "Please guess between 1 and 100. Try again..." << endl;
      cin.clear();
      cin.ignore(n,'\n');
    } else if (guess != random_number) {
      cout << "You entered " << guess << endl;
      if (guess > random_number){
      	cout << "Lower..." << endl;
      } else if (guess < random_number) {
      	cout << "Higher..." << endl;
      }
    }
  } while (guess != random_number);

  if (guess == -1){
  	cout << "Best luck next time." << endl;
  } else {
  	cout << "Congratulations!" << endl;
  }

  
}
