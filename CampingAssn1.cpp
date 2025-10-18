// CampingAssn1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	// these are the variables to hold user input
	int campers;
	int nightsStaying;
	int firesPlanned;

    cout << "Let's get ready to go camping!\n"
		<< "Pack your bags, grab your gear,\n" //the extra lines were suggested
		<< "Adventure awaits, the camp is near!\n"// by Copilot
		<< "Let's take some information to help with planning your trip\n"
		<< "How many campers will be going? " << endl;
	cin >> campers; //initialize campers variable
	cout << "Great- and how many nights will you be staying? " << endl; // suggested by Copilot
	cin >> nightsStaying;//initialize nightsStaying variable
	cout << "Awesome! Lastly, how many campfires do you plan to have? " << endl; // suggested by Copilot
	cin >> firesPlanned;//initialize firesPlanned variable
	
	// now we can output a summary of the camping trip
	cout << "Thanks for the info! Here's a quick summary of your camping trip:\n" // suggested
		<< "Number of campers: " << campers << "\n"								//
		<< "Nights staying: " << nightsStaying << "\n"							//           by
		<< "Planned campfires: " << firesPlanned << "\n"						//					Copilot

		// now give some packing reminders based on the input received
		<< "Remember to bring your tents, " << campers << " sleeping bags, and enough food for " << endl;
	cout << nightsStaying << " nights. Don't forget the marshmallows for the campfires!\n"
		<< "You will need to bring " << (campers * nightsStaying * 2) << " meals in total - \n" 
		// assuming 2 meals per camper per night
		<< "as well as " << firesPlanned << " fire-starters and\n"         
		<< (firesPlanned / 2) << " bags of marshmallows for roasting.\n" // assuming .5 bags of marshmallows per fire
		<< "Get ready for an unforgettable outdoor adventure!" << endl;						

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

