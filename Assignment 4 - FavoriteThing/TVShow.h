#pragma once
#include <string>
#include <iostream>

class TVShow
{
private:
	int showID;
	static int showIDGenerator;
	std::string name;
	double rating;
	std::string genre;
	int numSeasons;

public:
	TVShow();
	TVShow(int id, std::string n, double r, std::string g, int ns);
	int addShow();
	void displayHeading();
	void displayShow();
	void deleteShow();

	friend std::ofstream& operator<<(std::ofstream& out, TVShow *show);
	friend bool TVShow::operator== (const TVShow& s1, const TVShow& s2);
};

