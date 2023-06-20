// Standard input/output operations
#include <iostream>
// String manipulation operations
#include <string>
// Algorithms for sorting and transforming data
#include <algorithm>
// Dynamic array operations
#include <vector>
// File input/output operations
#include <fstream>

using namespace std;
// Use the std namespace for convenience and readability in the code

class Goods {
public:
	// Validates and sets the type of goods for donation
	void getValidTypeOfGoods(string typeOfGoods);
	// Validates and sets the name of the donated goods
	void NameOfGoods(string nameOfGoods);
	// Validates and sets the colour of the donated goods
	void get_goods_colour(string colour);
	// Validates and sets the status of the donated goods
	void goods_status(string status);
	// Validates and sets the number of goods to be donated
	void goods_number(int number = 0);
	// Performs the process of getting donation information from the user
	void get_goods_donation();
	// Checks if the provided type of goods is valid
	bool controlTypeOfGoods(string typeOfGoods);
	// Checks if the provided name of goods is valid
	bool controlNameOfGoods(string nameOfGoods);
	// Checks if the provided colour is valid
	bool controlColour(string colour);
	// Checks if the provided status is valid
	bool controlStatus(string status);
	// Saves the donation profile to a file
	void saveProfileToFile(const string& filename);
	// Loads the donation profile from a file
	void loadProfileFromFile(const string& fileName);
	// Reads and displays the donation profile from a file
	void readProfileFromFile(const string& fileName);
private:
	// Type of goods for donation
	string typeOfGoods_;
	// Name of the donated goods
	string nameOfGoods_;
	// Colour of the donated goods
	string colour_;
	// Status of the donated goods
	string status_;
	// Number of goods to be donated
	int number_{};
};

