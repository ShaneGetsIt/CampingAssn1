
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
	ofstream outData;

	cout << "Welcome! This is Shane's Camping Supply List Generator!" << endl
		<< "Allow me to take some information to help with planning your trip-\n"
		<< "- to begin, what is your name?" << endl;
	
	getline(cin, name);
	
	cout << "Okay, " << name << ", and how many campers will be going, "
		<< "including yourself? " << endl;
	
	if (!(cin >> campers)) {//initialize campers variable; handle non-numerical entries
		campers = 1; //invalid entries will set variable equal to 1
		cout << "The value needs to be an integer! I've set the value to 1" << endl;
	}
	
	cout << campers << " campers\n" << "Great! Now, how many nights " << endl
		<< "will you be staying ? " << endl; 
		

	cin.clear();          //clear and reset istream in fail state
	cin.ignore(50, '\n');
	
	if (!(cin >> nightsStaying)) {//initialize nightsStaying variable; handle exceptions
		nightsStaying = 1; //invalid entries will set variable equal to 1
		cout << "The value needs to be an integer! I've set the value to 1" << endl;
	}

	cout << nightsStaying << " nights\n" << "Okay- and how many fires do you" << endl
		<< "plan to have each day ? " << endl;


	cin.clear();          //clear and reset istream in fail state
	cin.ignore(50, '\n');
	
	if (!(cin >> firesPlanned)) {//initialize firesPlanned variable; handle exceptions
		firesPlanned = 2; //invalid entries will set variable equal to 2
		cout << "The value needs to be an integer! I've set the value to 2" << endl;
	}
	
	cout << firesPlanned << " campfires/day... Awesome- I've prepared your list!\n"
		<< "...Here it is!!!" << endl << endl << endl;

	//initialize fireStarter variable; set # of fire starters to bring = fires
	//planned per day times the # of nights the user plans to be camping
	fireStarter = firesPlanned * nightsStaying;

	//initialize lbsMarshmallow variable; set weight of marshmallow to bring = total # 
	//of campfires planned during the user's stay times the number of campers; then 
	//divide by 4, this assumes each person will consume .25 lbs of marshmallow per fire
	lbsMarshmallow = (fireStarter * campers) / 4.0; 
		//lbsMarshmallow should be appropriate for the "derived value" requirement
		//listed for assignment 2							

	
		// now we can output the camping supply list to a file "Report.txt"
	outData.open("Report.txt");
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
			<< right << setw(7) << lbsMarshmallow << endl //print weight of marshmallows to bring
			<< "#" << setfill('-') << setw(34) << "#" << endl
			<< setfill('.') << setw(26) << "And lots of camping "
			<< left << "spirit!!!" << endl 
			<< "#*********************************#" 
			<< endl << endl << endl;
	outData.close();

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
		<< right << setw(7) << lbsMarshmallow << endl //print weight of marshmallows to bring
		<< "#" << setfill('-') << setw(34) << "#" << endl
		<< setfill('.') << setw(26) << "And lots of camping "
		<< left << "spirit!!!" << endl
		<< "#*********************************#"
		<< endl << endl << endl;


	//to be clear- from the instructions it seems we are only being asked to output to a file
	//on the off chance you wanted common output to console as well as to a file
	//I have added this functionality as well



	cout << "Thanks for allowing me to assist you with planning!" << endl
		<< "I hope you found this tool to be helpful - enjoy your trip!!"
		<< endl << endl;
	

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

