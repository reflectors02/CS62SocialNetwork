#include "network.h"
#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;

void addUserOption(Network & network)
{
	string first_name, last_name, year, zip;
	cout << "Enter user information: ";
	cin >> first_name;
	cin >> last_name;
	cin >> year;
	cin >> zip;
	cout << "\n";

	network.addUser(new User(network.numUsers(), first_name + " " + last_name, stoi(year), stoi(zip), set<int> {}));
}


int addFriendConnectionOption(Network & network)
{
	string name1_first, name1_last, name2_first, name2_last;
	cout << "Please enter two names in the format: Hankang Gao Joachim Peiper: ";
	cin >> name1_first;
	cin >> name1_last;
	cin >> name2_first;
	cin >> name2_last;

	string name1 = name1_first + " " + name1_last;
	string name2 = name2_first + " " + name2_last;

	if(network.getId(name1) == -1 || network.getId(name2) == -1) {return -1;}

	network.addConnection(name1, name2);
	return 0;
}


int deleteFriendConnectionOption(Network & network)
{
	string name1_first, name1_last, name2_first, name2_last;
	cout << "Please enter two names in the format: Hankang Gao Joachim Peiper: ";
	cin >> name1_first;
	cin >> name1_last;
	cin >> name2_first;
	cin >> name2_last;

	string name1 = name1_first + " " + name1_last;
	string name2 = name2_first + " " + name2_last;

	if(network.getId(name1) == -1 || network.getId(name2) == -1) {return -1;}

	network.deleteConnection(name1, name2);
	return 0;
}


void writeToFileOption(Network & network)
{
	string user_input;
	cout << "Enter the output filename: ";
	cin >> user_input;

	network.writeUsers(user_input.c_str());
	cout << "\n";
}

void showMostRecent(Network & network)
{
	cout << "Please enter the name of the user of interest: ";
	string first, last;
	cin >> first;
	cin >> last;
	string name = first + " " + last;
	cout << "\n";

	cout << "How many posts is needed? ";
	int howMany = 0;
	cin >> howMany;
	cout << "\n";

	int profileId = network.getId(name);

	cout << network.getPostsString(profileId, howMany) << "\n";

}

int main(int argc, char* argv[3])
{
	Network KMT;
	KMT.readUsers(argv[1]);
	KMT.readPosts(argv[2]);
	set<int> valid_inputs {1,2,3,4,5};

	int input = -1;
	do
	{
		cout << "Please select an option: " << endl;
		cout << "Option 1: Add User format e.g., 'Joachim Peiper, 1918, 95014'" << endl;
		cout << "Option 2: Add friend connection (Give two usernames)" << endl;
		cout << "Option 3: Delete friend connection" << endl;
		cout << "Option 4: Write to file e.g., example.txt" << endl;
		cout << "Option 5: Show the most recent post of User e.g., Joachim Peiper 5 will show 5 most recent post by Peiper" << endl;
		cout << "Selected option: ";
		cin >> input;
		cout << "\n";

		switch(input)
		{
			case 1:
				addUserOption(KMT);
				break;

			case 2:
				addFriendConnectionOption(KMT);
				break;

			case 3:
				deleteFriendConnectionOption(KMT);
				break;

			case 4:
				writeToFileOption(KMT);
				break;

			case 5:
				showMostRecent(KMT);
				break;

			default:
				break;
		}

	} 
	while(valid_inputs.find(input) != valid_inputs.end());
}