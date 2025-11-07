
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const string extras = "Extras.txt";
const string it = "It.txt";
const string rpt = "Report.txt";

int main()
{
	// these are the variables to hold user input
	string name;
	string extraItem;
	string activity;
	char ch;
	int campers;
	int nightsStaying;
	int fireStarter;
	double lbsMarshmallow;
	int firesPlanned;
	int menu;
	bool itinerary = false;
	ofstream outData;
	ifstream inData;

	cout << "Welcome! This is Shane's Camping Supply List Generator!" << endl
		<< "Allow me to take some information to help with planning your trip-\n"
		<< "- to begin, what is your name?  ";
	
	getline(cin, name);
	
	cout << endl << endl << "Okay, " << name << ", and how many campers will be going, "
		<< "including yourself? " << endl;
	
	if (!(cin >> campers)) {//initialize campers variable; handle non-numerical entries
		campers = 1; //invalid entries will set variable equal to 1
		cout << "The value needs to be an integer! I've set the value to 1" << endl;
	}
	
	cout << campers << " Campers\n" << "Great! Now, how many nights " << endl
		<< "will you be staying ? " << endl; 
		

	cin.clear();          //clear and reset istream in fail state
	cin.ignore(50, '\n');
	
	if (!(cin >> nightsStaying)) {//initialize nightsStaying variable; handle exceptions
		nightsStaying = 1; //invalid entries will set variable equal to 1
		cout << "The value needs to be an integer! I've set the value to 1" << endl;
	}

	cout << nightsStaying << " Nights\n" << "Okay- and how many fires do you" << endl
		<< "plan to have each day ? " << endl;


	cin.clear();          //clear and reset istream in fail state
	cin.ignore(50, '\n');
	
	if (!(cin >> firesPlanned)) {//initialize firesPlanned variable; handle exceptions
		firesPlanned = 2; //invalid entries will set variable equal to 2
		cout << "The value needs to be an integer! I've set the value to 2" << endl;
	}
	
	cout << firesPlanned << " Campfires/day... Alright, now..." << endl
		<< "are there any other items you would like to add to " << endl
		<< "your camping list? Enter Y for yes" << endl;

	cin.clear();          //clear and reset istream in fail state
	cin.ignore(50, '\n');
	
	cin >> ch;		  //get user response for adding an extra item
	
	if (ch == 'y' || ch == 'Y') {  //COVER THE FIRST IF ELSE BLOCK

		cin.ignore(1, '/n');
		cout << endl << "Please enter each item you would like to add one at a time - "
			<< "enter \"done\" when finished" << endl << endl;
		outData.open(extras);

		if (!outData)
		{
			cout << "Unable to open output file";
			return 1;
		}

		while (extraItem != "done" && extraItem != "DONE") //while loop, extraItem is initialized as ""
														//requirement for assignment 4
		{
			getline(cin, extraItem);//extraItem initialized to user input
			if (extraItem != "done" && extraItem != "DONE")
			{
				cout << extraItem << " - got it!" << endl;
				outData << right << setfill('.') << setw(35) << extraItem << endl;
			}
		}


		outData.close();
	}
	else
		cout << "No extra items to add - got it!" << endl << endl;


	//initialize fireStarter variable; set # of fire starters to bring = fires
	//planned per day times the # of nights the user plans to be camping
	fireStarter = firesPlanned * nightsStaying;

	//initialize lbsMarshmallow variable; set weight of marshmallow to bring = total # 
	//of campfires planned during the user's stay times the number of campers; then 
	//divide by 4, this assumes each person will consume .25 lbs of marshmallow per fire
	lbsMarshmallow = (fireStarter * campers) / 4.0; 
		//lbsMarshmallow should be appropriate for the "derived value" requirement
		

	//do...while loop requirement for assignment 4
	do {
		cout << "How would you like to proceed?" << endl << endl
			<< "1 = Make/Replace Itinerary" << endl
			<< "2 = Save and display on screen" << endl
			<< "3 = Save to file only" << endl << endl;

		cin >> menu;//get user menu selection
		
		switch (menu) {
		case 1:
			itinerary = true; //set itinerary boolean to true if user wants to create itinerary
			outData.open(it);
			cout << endl << "Let's build an itinerary for your trip!" << endl << endl;
			cin.clear();
			cin.ignore(1, '\n');
			for (int n = 1; n <= nightsStaying; n++) //for loop to get activities for each day
												//for loop requirement for assignment 4
			{
				cout << "What activity do you have planned for day " << n << "?" << endl
					<< "You can say things like \"Kayaking\", \"Hiking\", or \"Fishing\"" << endl;
				getline(cin, activity);
				cout << "<(" << activity << ") added to itinerary>" << endl << endl;
				outData << left << setfill(' ') << "*Day " << right << setw(2) << n 
					<< ": " << right << setw(25) << activity << "*" << endl;
			}
			outData.close();
			cout << "Perfect! I've created your personalized itinerary." << endl;
			break;

		case 2:
			cout << "Printing list to screen" << endl;
			if (itinerary) //if itinerary was created, read from 'it' file
			{
				inData.open(it);

				if (!inData) // open input file; handle exceptions
				{
					cout << "Cannot open input file - exiting program" << endl << endl;
					return 1;
				}

				cout << "#*********************************#" << endl
					<< setw(19) << setfill('.') << name    //
					<< left << setw(17) << "'s Itinerary" << endl
					<< right << "#*********************************#" << endl;


				while (inData) // read and print itinerary to screen
				{
					getline(inData, activity);
					cout << activity << endl;
				}
				inData.close();

			}
			cout << "#*********************************#" << endl;
			cout << setw(19) << setfill('.') << name    //name the camping list
				<< left << "'s Camp Supplies" << endl
				<< showpoint << fixed << setprecision(2) //will only apply to lbsMarshmallow variable
				<< setw(28) << "Size of camping party:"
				<< right << setw(7) << campers << endl  //set party size = campers variable
				<< left << setw(28) << "Duration of stay:"
				<< right << setw(7) << nightsStaying << endl  //duration of stay = nightsStaying
				<< setfill('-') << "#" << setw(34) << "#" << endl
				<< "#" << setw(34) << "#" << endl
				<< setfill('.') << "#" << setw(16) << "Things "
				<< left << setw(17) << "to pack" << "#" << endl
				<< "Need: " << static_cast<int>((campers / 2.0) + .5)      //want to round up for both 2 man and
				<< "x 2-man OR " << static_cast<int>((campers / 5.0) + .8) //5 man tents thus adding .5 & .8 to
				<< "x 5-man tent(s)" << endl							   //static_cast<int>
				<< setw(28) << "- - - Sleeping bags"
				<< right << setw(7) << campers << endl   //set # of sleeping bags = campers variable
				<< left << setw(28) << "- - - Fire starters"
				<< right << setw(7) << fireStarter << endl //print # of fire starters to bring
				<< left << setw(28) << "- - - Lbs of Marshmallow"
				<< right << setw(7) << lbsMarshmallow << endl; //print weight of marshmallows to bring
			if (ch == 'y' || ch == 'Y')
			{
				inData.open(extras);
				
				if (!inData)//open input file; handle exceptions
				{
					cout << "Unable to open file - exiting program..." << endl;
				}

				cout << right << setw(35) << setfill('.') 
					<< "Extra items to pack" << endl;

				while (inData) // read and print extra items to screen
				{
					getline(inData, extraItem);
					cout << extraItem << endl;
				}
				inData.close();
			}
			cout << "#" << setfill('-') << setw(34) << "#" << endl
				<< setfill('.') << setw(26) << "And lots of camping "
				<< left << "spirit!!!" << endl
				<< "#*********************************#"
				<< endl << endl << endl;

		case 3:			
			outData.open(rpt);
			cout << "Saving your report now..." << endl;
			if (itinerary) //if itinerary was created, read from 'it' file
			{
				
				inData.open(it);

				outData << "#*********************************#" << endl
					<< setw(19) << setfill('.') << name    //name the itinerary for the output file
					<< left << setw(17) << "'s Itinerary" << endl
					<< right << "#*********************************#" << endl;


				if (!inData) //open input file; handle exceptions
				{
					cout << "Cannot open input file - exiting program" << endl << endl;
					return 1;
				}

				while (inData) // read from itinerary file and write to report file
				{
					getline(inData, activity);
					outData << activity << endl;
				}
				inData.close();

			}
			outData << "#*********************************#" << endl;
			outData << setw(19) << setfill('.') << name    //name the camping list
				<< left << "'s Camp Supplies" << endl
				<< showpoint << fixed << setprecision(2) //will only apply to lbsMarshmallow variable
				<< setw(28) << "Size of camping party:"
				<< right << setw(7) << campers << endl  //set party size = campers variable
				<< left << setw(28) << "Duration of stay:"
				<< right << setw(7) << nightsStaying << endl  //duration of stay = nightsStaying
				<< setfill('-') << "#" << setw(34) << "#" << endl
				<< "#" << setw(34) << "#" << endl
				<< setfill('.') << "#" << setw(16) << "Things "
				<< left << setw(17) << "to pack" << "#" << endl
				<< "Need: " << static_cast<int>((campers / 2.0) + .5)      //want to round up for both 2 man and
				<< "x 2-man OR " << static_cast<int>((campers / 5.0) + .8) //5 man tents thus adding .5 & .8 to
				<< "x 5-man tent(s)" << endl							   //static_cast<int>
				<< setw(28) << "- - - Sleeping bags"
				<< right << setw(7) << campers << endl   //set # of sleeping bags = campers variable
				<< left << setw(28) << "- - - Fire starters"
				<< right << setw(7) << fireStarter << endl //print # of fire starters to bring
				<< left << setw(28) << "- - - Lbs of Marshmallow"
				<< right << setw(7) << lbsMarshmallow << endl; //print weight of marshmallows to bring
			if (ch == 'y' || ch == 'Y')
			{
				inData.open(extras);
				outData << right << setw(35) << setfill('.')
					<< "Extra items to pack" << endl;
				while (inData) {
					getline(inData, extraItem);
					outData << extraItem << endl;
				}
				inData.close();
			}
			outData << "#" << setfill('-') << setw(34) << "#" << endl
				<< setfill('.') << setw(26) << "And lots of camping "
				<< left << "spirit!!!" << endl
				<< "#*********************************#"
				<< endl << endl << endl;
			
			cout << "Save complete!" << endl;
			break;

		default:
			cout << "Invalid menu selection - no output will be generated" << endl
				<< "Please restart the program to try again." << endl;
			return 1; //exit program with error code if invalid menu selection
		}
	} while (menu == 1);

	cout << "Thanks for allowing me to assist you with planning!" << endl
		<< "I hope you found this tool to be helpful - enjoy your trip!!"
		<< endl << endl;
	

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

