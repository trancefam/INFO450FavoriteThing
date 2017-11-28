// Assignment4FavoriteThing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TVShow.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

const int LISTSIZE = 50; //tbd doulble array when full

int main()
{
	TVShow **myTVShowList;
	int count = 0;
	int i=0;
	std::string response = "Y";
	std::string filePath;

	//create dynamic double pointer array
	myTVShowList = new TVShow*[LISTSIZE];
	
	//get file path
	std::cout << "Enter full path of file to save to and read from: " << std::endl;
	std::getline(std::cin, filePath);
	
	//read any existing data
	std::ifstream infile(filePath); 
	if (infile.good()) //file found
	{
		while (!infile.eof()) 
		{
			std::string ID, name, rating, genre, numSeasons;
			getline(infile, ID, '|');
			if (ID.length()) //ID exists
			{
				getline(infile, name, '|');
				getline(infile, rating, '|');
				getline(infile, genre, '|');
				getline(infile, numSeasons, '\n');

				//dynamically allocate object from line data
				myTVShowList[count] = new TVShow(stoi(ID), name, stod(rating), 
					genre, stoi(numSeasons));
				count++;
			}
		}
	}

	//display number of items stored
	if (count > 0)
	{
		std::cout << "You have " << count << " favorites. Add more? ";
		std::cin >> response;
	}

	//add new shows
	while (response == "Y" || response == "y")
	{
		myTVShowList[count] = new TVShow();
		if (myTVShowList[count]->addShow() == 0);
		{
			//check if duplicate
			for (i = 0; i < count; i++)
			{
				if (*myTVShowList[i] == *myTVShowList[count]) 
				{
					std::cout << "Duplicate entry! Try again." << std::endl;
					delete myTVShowList[count--];
					break;
				}
			}
			count++; 
		}
		std::cout << "Add another? ";
		std::cin >> response;
	}

	//display complete list
	myTVShowList[i]->displayHeading();
	for ( i = 0; i < count; i++)
	{
		myTVShowList[i]->displayShow();
	}

	//when user is done, write list to file
	std::ofstream outfile(filePath);
	if (!outfile.good())
	{
		std::cout << "ERROR - can't open file for output. " << std::endl;
	}
	else
	{	
		for (i = 0; i < count; i++)
		{
			outfile << myTVShowList[i];
		}
	}

	//cleanup
	for (int i = 0; i < count; i++)
	{
		delete myTVShowList[i];
	}

	delete myTVShowList;

    return 0;
}


