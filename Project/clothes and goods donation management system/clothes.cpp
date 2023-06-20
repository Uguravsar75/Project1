#include "clothes.h"
// Include the header file for the "clothes" module
#include <iostream>
// Include the input/output stream library
#include <algorithm>
// Include the algorithm library for various algorithms
#include <fstream>
// Include the file stream library for file I/O operations

using namespace std;
// Use the std namespace for convenience and readability in the code

// Gets the clothes information from the user through input prompts.
void Clothes::get_clothes() {
	// Initializes variables to store the user input for clothes information.
	string typeOfClothes, clothesName, size, forWhom, clean, useOfClothes, numberStr;
	int number = 0;

	// Prompts the user to enter the type of clothing they would like to donate and validates the input.
	// The user is prompted to re-enter if the input is invalid.
	cout << "1)Please write one of the following for which type of clothing you would like to donate;" << endl;
	cout << "(Mens clothing , Womens clothing , Baby clothing , Kids clothing , Unisex): ";
	getline(cin, forWhom);
	ClothesForWhom(forWhom);

	//Blank line.
	cout << endl;

	// Prompts the user to enter the body part of the clothes they want to donate and validates the input.
	// The user is prompted to re-enter if the input is invalid.
	cout << "2)Please write one of the following for the body part of the clothes you want to donate;" << endl;
	cout << "(Clothes for the head, Upper body clothes, Lower body clothes, Whole body clothes): ";
	getline(cin, typeOfClothes);
	TypeOfClothes(typeOfClothes);

	//Blank line.
	cout << endl;

	// Prompts the user to enter the name of the clothes they want to donate and validates the input.
	// The user is prompted to re-enter if the input is invalid.
	cout << "3)Please enter the name of the clothes you want to donate: ";
	getline(cin, clothesName);
	ClothesName(clothesName);

	//Blank line.
	cout << endl;

	// Prompts the user to enter the size of the clothes and validates the input.
	// The user is prompted to re-enter if the input is invalid.
	cout << "4)Please enter clothes size: ";
	getline(cin, size);
	ClothesSize(size);

	//Blank line.
	cout << endl;

	// Prompts the user to enter the cleanliness status of the clothes and validates the input.
	// The user is prompted to re-enter if the input is invalid.
	cout << "5)Please enter,is the clothes clean? (Yes/No): ";
	getline(cin, clean);
	ClothesClean(clean);

	//Blank line.
	cout << endl;

	// Prompts the user to enter the previous use status of the clothes and validates the input.
	// The user is prompted to re-enter if the input is invalid.
	cout << "6)Please enter,is the clothes been used before?(Yes/No): ";
	getline(cin, useOfClothes);
	UseOfClothes(useOfClothes);

	//Blank line.
	cout << endl;

	/* Prompts the user to enter the number of clothes they will donate.
	The input is validated to ensure it is a valid integer.
	If an invalid number is entered, the user is prompted to re-enter. */
	while (true) {
		cout << "7)Please enter,how many of this clothes will you donate?: ";
		getline(cin, numberStr);

		try {
			int number = stoi(numberStr);
			NumberOfClothes(number);
			break;
		}
		catch (const exception& e) {
			cout << "Invalid number. Please enter a valid number." << endl;
		}
	}

	cout << endl;
}

// Validates and sets the 'forWhom_' field in the Clothes class, ensuring a valid input is provided.
void Clothes::ClothesForWhom(string forWhom) {
	while (!controlForWhom(forWhom)) {
		cout << "Invalid input , please enter valid type: ";
		getline(cin, forWhom);
	}
	forWhom_ = forWhom;
}

// Validates and sets the 'typeOfClothes_' field in the Clothes class, ensuring a valid clothes type is provided.
void Clothes::TypeOfClothes(string typeOfClothes) {
	while (!controlTypeOfClothes(typeOfClothes)) {
		cout << "Invalid type , please enter valid clothes type: ";
		getline(cin, typeOfClothes);
	}
	typeOfClothes_ = typeOfClothes;
}

// Validates and sets the 'clothesName_' field in the Clothes class, ensuring a non-empty valid clothes name is provided.
void Clothes::ClothesName(string clothesName) {
	while (!controlClothesName(clothesName) || clothesName.empty()) {
		cout << "Invalid type , please enter valid clothes name: ";
		getline(cin, clothesName);
	}
	clothesName_ = clothesName;
}

// Validates and sets the 'size_' field in the Clothes class, ensuring a valid size is provided.
void Clothes::ClothesSize(string size) {
	while (!controlSize(size)) {
		cout << "Invalid size , please enter valid size: ";
		getline(cin, size);
	}
	size_ = size;

}

// Validates and sets the 'clean_' field in the Clothes class, ensuring a valid input for clean or use of clothes is provided.
void Clothes::ClothesClean(string clean) {
	while (!controlCleanOrUseOfClothes(clean)) {
		cout << "Invalid input , please enter valid input: ";
		getline(cin, clean);
	}
	clean_ = clean;
}

// Validates and sets the 'useOfClothes_' field in the Clothes class, ensuring a valid input for the use of clothes is provided.
void Clothes::UseOfClothes(string useOfClothes) {
	while (!controlCleanOrUseOfClothes(useOfClothes)) {
		cout << "Invalid input , please enter valid type: ";
		getline(cin, useOfClothes);
	}
	useOfClothes_ = useOfClothes;
}

// Validates and sets the 'number_' field in the Clothes class, ensuring a valid positive number is provided.
void Clothes::NumberOfClothes(int number) {
	while (number < 1) {
		cout << "Invalid number, please enter a valid number: ";
		cin >> number;
	}
	number_ = number;
}


// Validates if the 'forWhom' input matches any of the valid options for the target audience of the clothes.
bool Clothes::controlForWhom(string forWhom) {
	vector<string> validForWhom = { "Mens clothing","Womens clothing","Baby clothing","Kids clothing","Unisex" };

	transform(forWhom.begin(), forWhom.end(), forWhom.begin(), ::tolower);

	/* Iterates through the list of valid options for the target audience of the clothes
	and checks if the lowercase 'forWhom' input matches any of the lowercase valid options.
	Returns true if a match is found, indicating a valid input; otherwise, returns false. */
	for (string& s : validForWhom) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);

		if (forWhom == s) {
			return true;
		}
	}
	return false;
}

// Validates if the 'typeOfClothes' input matches any of the valid options for the type of clothes.
bool Clothes::controlTypeOfClothes(string typeOfClothes) {
	string validClothes[] = { "Clothes for the head" , "Upper body clothes" , "Lower body clothes" , "Whole body clothes" };
	int numValidClothes = sizeof(validClothes) / sizeof(validClothes[0]);

	transform(typeOfClothes.begin(), typeOfClothes.end(), typeOfClothes.begin(), ::tolower);

	/* Iterates through the list of valid options for the type of clothes
	and checks if the lowercase 'typeOfClothes' input matches any of the lowercase valid options.
	Returns true if a match is found, indicating a valid input; otherwise, returns false. */
	for (int i = 0; i < numValidClothes; i++) {
		string s = validClothes[i];
		transform(s.begin(), s.end(), s.begin(), ::tolower);

		if (typeOfClothes == s) {
			return true;
		}
	}
	return false;
}

// Validates if the 'clothesName' input meets the criteria for a valid clothes name.
bool Clothes::controlClothesName(string clothesName) {

	/* Iterates through each character in the 'clothesName' string and checks if it meets the criteria for a valid character.
	Returns false if any character is not a letter (uppercase or lowercase), space, or hyphen;
	otherwise, proceeds to check the length of the 'clothesName' string. */
	for (char c : clothesName) {
		if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) {
			if (c != ' ' && c != '-') {
				return false;
			}
		}
	}

	// Checks if the length of the 'clothesName' string exceeds the maximum allowed length of 25 characters.
	// Returns false if the length exceeds 25; otherwise, proceeds to transform the 'clothesName' to uppercase and then to lowercase.
	if (clothesName.length() > 25) {
		return false;
	}

	transform(clothesName.begin(), clothesName.end(), clothesName.begin(), ::toupper);

	transform(clothesName.begin(), clothesName.end(), clothesName.begin(), ::tolower);

	return true;
}

// Validates if the 'size' input matches any of the valid size options.
bool Clothes::controlSize(string size) {
	vector<string> validSizes = { "XS", "S", "M", "L", "XL", "XXL", "XXXL" , "XXXXL", "XXXXXL" };

	transform(size.begin(), size.end(), size.begin(), ::toupper);

	// Checks if the uppercase 'size' input can be found in the list of valid sizes.
	// Returns true if a match is found, indicating a valid size input; otherwise, returns false.
	if (find(validSizes.begin(), validSizes.end(), size) != validSizes.end()) {
		return true;
	}
	else {
		return false;
	}
}

// Validates if the 'cleanOrUseOfClothes' input matches any of the valid options for indicating whether the clothes need to be cleaned or are ready for use.
bool Clothes::controlCleanOrUseOfClothes(string cleanOrUseOfClothes) {

	// Checks if the 'cleanOrUseOfClothes' input matches any of the valid options: "Yes", "yes", "No", "no", "Unknown", or "unknown".
	// Returns true if a match is found, indicating a valid input; otherwise, returns false.
	if (cleanOrUseOfClothes == "Yes" || cleanOrUseOfClothes == "yes" ||
		cleanOrUseOfClothes == "No" || cleanOrUseOfClothes == "no" ||
		cleanOrUseOfClothes == "Unknown" || cleanOrUseOfClothes == "unknown") {
		return true;
	}
	else {
		return false;
	}
}
//The saveToFile, loadFromFile, and readFromFile member functions in the Clothes class are used for file handling operations.

/*The saveToFile function is used to save the data of a Clothes object to a file.It takes a fileName parameter representing the name of the file to which the data will be saved.
The function opens the file in append mode(ios::app) and checks if the file was successfully opened.If the file cannot be opened, an error message is displayed, and the function returns.
Otherwise, the function writes the clothing data to the file, including the information about the clothes' recipient, type, name, size, cleanliness, usage status, 
and the number of clothes donated. Each piece of information is written on a separate line. Finally, the file is closed, and a message is displayed indicating that the data has been saved.*/

void Clothes::saveToFile(const string& fileName) {

	ofstream file(fileName, ios::app); 
	
	if (!file) {
		cout << "Error opening file." << endl;
		return;
	}


	file << "Clothes for Whom: " << forWhom_ << endl;
	file << "Clothes type: " << typeOfClothes_ << endl;
	file << "Clothes name: " << clothesName_ << endl;
	file << "Clothes size: " << size_ << endl;
	file << "Is the clothes clean?: " << clean_ << endl;
	file << "Has the clothes been used before?: " << useOfClothes_ << endl;
	file << "Number of clothes donated: " << number_ << endl;
	file << endl;
	file.close(); 

	
	cout << "Data saved to file: " << fileName << endl;
}

/*The loadFromFile function is used to load the data of a Clothes object from a file.It takes a fileName parameter representing the name of the file from which the data will be loaded.
The function opens the fileand checks if it was successfully opened.If the file cannot be opened, an error message is displayed, and the function returns.Otherwise,
the function reads each line from the fileand assigns the corresponding values to the member variables of the Clothes object, including the recipient, type, name, size, cleanliness,
usage status, and the number of clothes donated.After reading the data, the file is closed, and a message is displayed indicating that the data has been loaded.*/

void Clothes::loadFromFile(const string& fileName) {

	ifstream file(fileName);

	if (!file) {
		cout << "Error opening file." << endl;
		return;
	}

	getline(file, forWhom_);
	getline(file, typeOfClothes_);
	getline(file, clothesName_);
	getline(file, size_);
	getline(file, clean_);
	getline(file, useOfClothes_);
	file >> number_;
	
	file.ignore();

	file.close();

	cout << "Data loaded from file: " << fileName << endl;
}


/*The readFromFile function is used to readand display the contents of a file without storing them in the Clothes object.It takes a fileName parameter representing the name of the file
to be read.The function opens the fileand checks if it was successfully opened.If the file cannot be opened, an error message is displayed, and the function returns.
Otherwise, the function reads each line from the fileand prints it to the console.After readingand displaying all the lines, the file is closed.*/

void Clothes::readFromFile(const string& fileName) {

	ifstream file(fileName);
	
	if (!file) {
		cout << "Error opening file." << endl;
		return;
	}

	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}

	
	file.close();
}




