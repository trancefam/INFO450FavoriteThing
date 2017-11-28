#include "stdafx.h"
#include "TVShow.h"
#include <iostream>
#include <string>
#include <fstream>

int TVShow::showIDGenerator = 1000;

TVShow::TVShow()
{
	showID = showIDGenerator++;
	name = "";
	rating = 0;
	genre = "";
	numSeasons = 0;
}

TVShow::TVShow(int id, std::string n, double r, std::string g, int ns)
{
	showIDGenerator = id;
	showID = showIDGenerator++;
	name = n;
	rating = r;
	genre = g;
	numSeasons = ns;
}

int TVShow::addShow()
{
	std::cout << "Enter TV Show Name: ";
	std::cin.ignore();
	getline(std::cin, name);
	std::cout << "Enter Rating (0-10): ";
	std::cin >> rating;
	std::cout << "Enter Genre: ";
	std::cin.ignore();
	getline(std::cin, genre);
	std::cout << "Enter Number of Seasons: ";
	std::cin >> numSeasons;

	return 0;
}

void TVShow::displayHeading()
{
	std::cout << "\n\nID#\t" << "# of Seasons\t" << "Rating\t" << "Genre\t\t" << "Name" << std::endl;
	std::cout << "------------------------------------------------------------------" << std::endl;
}

void TVShow::displayShow()
{
	std::cout << showID << "\t" <<numSeasons << "\t\t" << rating << "\t" << genre 
		<< "\t\t" << name << std::endl;
}

void TVShow::deleteShow()
{
	//tbd
}

std::ofstream & operator<<(std::ofstream & out, TVShow *show)
{
	out << show->showID << "|" << show->name << "|" << show->rating 
		<< "|" << show->genre << "|" << show->numSeasons << std::endl;
	return out;
}

bool operator== (const TVShow& s1, const TVShow& s2)
{
	if (s1.name == s2.name)
		return true;

	return false;
}
