#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

const int kNumShells = 10;  // allowed 10 shells per target
const int kMinDist = 200;  // min distance for a target
const int kMaxDist = 900;  // max distance for a target
const double kVelocity = 200.0;  // initial velocity of 200 ft/sec
const double kGravity = 32.2;  // gravity for distance calculation
const double kPi = 3.1415;
const int kBlastTol = 5;

// double Velocity = 200.0; // initial velocity of 200 ft/sec
// double Gravity = 32.2; // gravity for distance calculation

void StartUp(){
	cout << "Welcome to Artillery.\n";
	cout << "You are in the middle of a war and being charged by thousands of enemies.\n";
	cout << "You have one cannon, which you can shoot at any angle.\n";
	cout << "You only have 10 cannonballs for this target..\n";
	cout << "Let's begin...\n\n";
}


int DistanceCalc(double in_angle_rad){
	double time_in_air;
	// in_angle_rad is the angle the player has entered, converted to radians.
	time_in_air = (2.0 * kVelocity * sin(in_angle_rad)) / kGravity;
	return (int) round((kVelocity * cos(in_angle_rad)) * time_in_air);
}

double GetAngle() {
  double in_angle_deg;

  cout << "What angle? ";
  if (!(cin >> in_angle_deg))
    return -1;

  return (in_angle_deg * kPi) / 180.0;
}

bool CheckHit(int target_dist, int shot_dist){

	if (abs(target_dist - shot_dist) <= kBlastTol)  {
		cout << "You hit him!!!" << endl;
		return true;
	} else {
		cout << "You ";
		if (shot_dist > target_dist){
			cout << "over ";
		} else {
			cout << "under ";
		}
		cout << "shot by " << abs(target_dist - shot_dist) << endl;
		return false;
	}

}

int Initialize(){
	srand (time(NULL));
	return rand() % (kMaxDist-kMinDist) + kMinDist;
}


int Fire(){
	int target_dist, shot_dist, count;
	double in_angle_rad;
	bool hit = false;

	target_dist = Initialize();

	cout << "The enemy is " << target_dist << " feet away!!!" << endl;
	count = 0;
	do {
	  in_angle_rad = GetAngle();
	  if (in_angle_rad > 0){
	  	shot_dist = DistanceCalc(in_angle_rad);
	  	hit = CheckHit(target_dist, shot_dist);
	  } else {
	  	return -1;
	  }
	  count++;
	} while (!hit && count < kNumShells);

	if (hit) {
	  cout << "It took you " << count << " shots." << endl;
	  return 1;
	} else{
	  return 0;
	}
	

}






int main(){
	int killed;
	int result;
	char done;

	StartUp(); // This displays the introductory script.
	killed = 0;
	do {
	  result = Fire();
	  if (result != -1){
	  	killed += result;
	  } else {
	  	return 0;
	  }
	  cout << "I see another one, care to shoot again? (Y/N) ";
	  cin >> done;
	} while (tolower(done) != 'n');
	cout << "You killed " << killed << " of the enemy." << endl;



}
