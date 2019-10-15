#include "Inventory.h"

const int NUM_SHOT_TYPES = 5;
const int NUM_SHOT_VARIABLES = 5;
string inventoryFile = "tutorial.txt";
int numCheat = 0;
Shot shotArray[NUM_SHOT_TYPES];

//Default Constructor
Inventory::Inventory()
{
}

//stub to finish
//Reads from the file "InventoryFile" defined above to populate shotArray
// and cheatnum variables. Run first if already have inventory file setup
void Inventory::readFromInventoryFile()
{
	string input;
	std::ifstream file;
	file.open(inventoryFile, fstream::in);
	for (int i = 0; NUM_SHOT_TYPES > i; i++)
	{
		for (int j = 0; NUM_SHOT_VARIABLES > j; j++)
		{
			file >> input;
			if (input == "Name:")
			{
				file >> input;
				shotArray[i].setShotName(input);
			}
			else if (input == "Code:")
			{
				file >> input;
				shotArray[i].setShotCode(input[0]);
			}
			else if (input == "Pattern:")
			{
				file >> input;
				shotArray[i].setPattern(input[0]);
			}
			else if (input == "Ammount:")
			{
				file >> input;
				shotArray[i].setAmmount(stoi(input));
			}
			else if (input == "Range:")
			{
				file >> input;
				shotArray[i].setRange(stoi(input));
			}
		}

	}

	file >> input;
	if (input == "-cheatermode")
	{
		file >> input;
		if (input == "Num:")
			file >> numCheat;
	}
	file.close();
}

//stub to finish
//Writes current inventory to the inventoryFile defined above. Warning
//WARNING:Default constructor for Shot produces nonsense so only write after
//Variables have been manually set or read from already existing file
void Inventory::writeToInventoryFile()
{
	

}

void Inventory::setInventoryFile(string input)
{
	inventoryFile = input;
}
string Inventory::getInventoryFile()
{
	return inventoryFile;
}
void Inventory::setNumCheat(int input)
{
	numCheat = input;
}
int Inventory::getNumCheat()
{
	return numCheat;
}

Shot* Inventory::getShotArray()
{
	return shotArray;
}

void setShotArray(Shot* input)
{
	for (int i = 0; NUM_SHOT_TYPES > i; i++)
	{
		shotArray[i] = input[i];
	}
}

