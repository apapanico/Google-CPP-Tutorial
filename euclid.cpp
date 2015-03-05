#include <iostream>
using namespace std;

int main () {
  int a,b,r1,r2,t;
  int n = 10000;

  do {
    cout << "Enter a: ";
    if (!(cin >> a)) {
      cout << "You entered a non-numeric. Try again..." << endl;
      cin.clear();
      cin.ignore(n,'\n');
    } else if (a < 1) {
      cout << "You entered a non-postive number.  Try again..." << endl;
    }
  } while (a < 1);

  do {
    cout << "Enter b: ";
    if (!(cin >> b)) {
      cout << "You entered a non-numeric. Try again..." << endl;
      cin.clear();
      cin.ignore(n,'\n');
    } else if (b < 1) {
      cout << "You entered a non-postive number.  Try again..." << endl;
    }
  } while (b < 1);

  r1 = a;
  r2 = b;
  while (r2){
  	t = r2;
  	r2 = r1 % r2;
  	r1 = t;
  }
  cout << "GCD(" << a << "," << b << "): " << r1 << endl;


}
