// CampingAssn1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	// these are the variables to hold user input
	string name;
	int campers;
	int nightsStaying;
	int fireStarter;
	double lbsMarshmallow;
	int firesPlanned;
	//int nameLen;

	//cout << "Let's get ready to go camping!\n"
	//	<< "Pack your bags, grab your gear,\n" //the extra lines were suggested
	//	<< "Adventure awaits, the camp is near!\n"// by Copilot
	cout << "Welcome! This is Shane's Camping Supply List Generator!" << endl
		<< "Allow me to take some information to help with planning your trip-\n"
		<< "- to begin, what is your name?" << endl;
	getline(cin, name);
	cout << "Okay, " << name << ", and how many campers will be going, "
		<< "including yourself? " << endl;
	if (!(cin >> campers)) {//initialize campers variable
		campers = 1;
		//cin.clear();
		cout << "The value needs to be an integer! I've set the value to 1" << endl;
	}
	
	cout << campers << " campers\n" << "Great! Now, how many nights " << endl
		<< "will you be staying ? " << endl; // suggested by Copilot
		
	cin.clear();
	cin.ignore(50, '\n');
	if (!(cin >> nightsStaying)) {//initialize nightsStaying variable
		nightsStaying = 1;
		cout << "The value needs to be an integer! I've set the value to 1" << endl;
	}

	cout << nightsStaying << " nights\n" << "Okay- and how many fires do you" << endl
		<< "plan to have each day ? " << endl;
	//cout << "Awesome! Lastly, how many campfires do you plan to have? " << endl; // suggested by Copilot
	cin.clear();
	cin.ignore(50, '\n');
	if (!(cin >> firesPlanned)) {//initialize firesPlanned variable
		firesPlanned = 2;
		cout << "The value needs to be an integer! I've set the value to 2" << endl;
	}
	
	cout << firesPlanned << " campfires/day... Awesome- I've prepared your list!\n"
		<< "...Here it is!!!" << endl << endl << endl;

	fireStarter = firesPlanned * nightsStaying;
	lbsMarshmallow = (fireStarter * campers) / 4.0;
	//nameLen = name.length();

	cout << "#*********************************#" << endl;
	cout << setw(19) << setfill('.') << name
		<< left << "'s Camp Supplies" << endl
		<< showpoint << fixed << setprecision(1)
		<< setw(28) << "Size of camping party:"
		<< right << setw(7) << campers << endl
		<< left << setw(28) << "Duration of stay:"
		<< right << setw(7) << nightsStaying << endl
		<< setfill('-') << "#" << setw(34) << "#" << endl
		<< "#" << setw(34) << "#" << endl
		<< setfill('.') << "#" << setw(16) << "Things "
		<< left << setw(17) << "to pack" << "#" << endl
		<< "Need: " << static_cast<int>((campers / 2.0) + .5)
		<< "x 2-man OR " << static_cast<int>((campers / 5.0) + .8)
		<< "x 5-man tent(s)" << endl
		<< setw(28) << "- - - Sleeping bags"
		<< right << setw(7) << campers << endl
		<< left << setw(28) << "- - - Fire starters"
		<< right << setw(7) << fireStarter << endl
		<< left << setw(28) << "- - - Lbs of Marshmallow"
		<< right << setw(7) << lbsMarshmallow << endl
		<< "#" << setfill('-') << setw(34) << "#" << endl
		<< setfill('.') << setw(26) << "And lots of camping "
		<< left << "spirit!!!" << endl 
		<< "#*********************************#" 
		<< endl << endl << endl;
	cout << "Thanks for allowing me to assist you with planning!" << endl
		<< "I hope you found this tool to be helpful - enjoy your trip!!" 
		<< endl << endl;
	// now we can output a summary of the camping trip
	//cout << "Thanks for the info! Here's a quick summary of your camping trip:\n" // suggested
	//	<< "Number of campers: " << campers << "\n"								//
	//	<< "Nights staying: " << nightsStaying << "\n"							//           by
	//	//<< "Planned campfires: " << firesPlanned << "\n"						//					Copilot

	//	// now give some packing reminders based on the input received
	//	<< "Remember to bring your tents, " << campers << " sleeping bags, and enough food for " << endl;
	//cout << nightsStaying << " nights. Don't forget the marshmallows for the campfires!\n"
	//	<< "You will need to bring " << (campers * nightsStaying * 2) << " meals in total - \n" 
	//	// assuming 2 meals per camper per night
	//	<< "as well as " << nightsStaying*2 << " fire-starters and\n"         
	//	<< (nightsStaying / 2.0)*campers << " bags of marshmallows for roasting.\n" // assuming 5 bags of marshmallows per fire
	//	<< "Get ready for an unforgettable outdoor adventure!" << endl;						

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

