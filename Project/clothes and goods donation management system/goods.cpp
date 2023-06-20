#include "goods.h"
// Include the header file for the "goods" module
#include <iostream>
// Include the input/output stream library
#include <algorithm>
// Include the algorithm library for various algorithms
#include <fstream>
// Include the file stream library for file I/O operations

using namespace std;
// Use the std namespace for convenience and readability in the code

void Goods::get_goods_donation() {
    string typeOfGoods, nameOfGoods, colour, status;
    // Declare string variables to store the type, name, colour, and status of goods
    string numberStr;
    // Declare a string variable to store a numerical value as a string

    cout << "1)Please write one of the following for which type of goods you would like to donate;" << endl;
    cout << "(Kitchen,Bath,Home decoration,Art,Furniture,Hobby,Stationery,Sports,Outdoor,Motorcycle,Other): ";
    getline(cin, typeOfGoods);
    // Read a line of input from the user and store it in the typeOfGoods variable
    getValidTypeOfGoods(typeOfGoods);
    // Call a function to validate and process the typeOfGoods input

    cout << endl; // Print a new line for better readability

    cout << "2)Please enter name of goods: ";
    getline(cin, nameOfGoods);
    // Read a line of input from the user and store it in the nameOfGoods variable
    NameOfGoods(nameOfGoods);
    // Call a function to validate and process the nameOfGoods input

    cout << endl;// Print a new line for better readability

    cout << "3)Enter the colour of the goods: ";
    getline(cin, colour);
    // Read a line of input from the user and store it in the colour variable
    get_goods_colour(colour);
    // Call a function to validate and process the colour input

    cout << endl;// Print a new line for better readability

    cout << "4)Enter the status of the goods (New/Second hand): ";
    getline(cin, status);
    // Read a line of input from the user and store it in the status variable
    goods_status(status);
    // Call a function to validate and process the status input

    cout << endl;// Print a new line for better readability

    while (true) {
        cout << "5)How many goods would you like to donate?: ";
        // Prompt the user to enter the number of goods they would like to donate

        getline(cin, numberStr);
        // Read the user's input and store it in the numberStr variable

        try {
            int number = stoi(numberStr);
            // Convert the input from string to integer using stoi() function

            goods_number(number);
            // Call a function to handle the input and perform further actions based on the number of goods

            break;
            // Exit the while loop if the input is valid and processed successfully
        }
        catch (const exception& e) {
            cout << "Invalid number. Please enter a valid number." << endl;
            // Display an error message if the input cannot be converted to an integer or is invalid
        }
    }

    cout << endl;// Print a new line for better readability
}

//The function getValidTypeOfGoods takes a string parameter typeOfGoods, which represents the user's input for the type of goods.
void Goods::getValidTypeOfGoods(string typeOfGoods) {
    while (!controlTypeOfGoods(typeOfGoods)) {
        // Continue looping until a valid type of goods is entered
        cout << "Invalid type, please try again: ";
        // Prompt the user to enter a valid type of goods
        getline(cin, typeOfGoods);
        // Read the user's input and store it in the typeOfGoods variable
    }
    typeOfGoods_ = typeOfGoods;
    // Set the member variable typeOfGoods_ to the validated typeOfGoods
}

//The function controlTypeOfGoods takes a string parameter typeOfGoods, which represents the user's input for the type of goods.
bool Goods::controlTypeOfGoods(string typeOfGoods) {
    string validGoods[] = { "Kitchen", "Bath" , "Home decoration",
        "Art", "Furniture", "Hobby", "Stationery" ,"Sports" , "Outdoor" , "Motorcycle" , "Other" };
    int numValidGoods = sizeof(validGoods) / sizeof(validGoods[0]);

    transform(typeOfGoods.begin(), typeOfGoods.end(), typeOfGoods.begin(), ::tolower);
    // Convert the typeOfGoods input to lowercase for case-insensitive comparison

    for (int i = 0; i < numValidGoods; i++) {
        // Iterate through the validGoods array to check for a match
        string s = validGoods[i];
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // Convert the current validGoods element to lowercase for case-insensitive comparison

        if (typeOfGoods == s) {
            // If a match is found, return true indicating a valid type of goods
            return true;
        }
    }
    // If no match is found, return false indicating an invalid type of goods
    return false;
}


//The function NameOfGoods takes a string parameter nameOfGoods, which represents the user's input for the name of goods.
void Goods::NameOfGoods(string nameOfGoods) {
    while (!controlNameOfGoods(nameOfGoods) || nameOfGoods.empty()) {
        // Continue looping until a valid name of goods is entered and the input is not empty
        cout << "Invalid type, please enter a valid goods name: ";
        // Prompt the user to enter a valid name of goods
        getline(cin, nameOfGoods);
        // Read the user's input and store it in the nameOfGoods variable
    }
    nameOfGoods_ = nameOfGoods;
    // Set the member variable nameOfGoods_ to the validated nameOfGoods
}

//The function controlNameOfGoods takes a string parameter nameOfGoods, which represents the user's input for the name of goods.
bool Goods::controlNameOfGoods(string nameOfGoods) {
    for (char c : nameOfGoods) {
        // Iterate through each character in the nameOfGoods string

        if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) {
            // Check if the character is not an uppercase or lowercase letter

            if (c != ' ' && c != '-') {
                // Check if the character is not a space or a hyphen
                return false;
            }
        }
    }

    if (nameOfGoods.length() > 25) {
        // Check if the length of the nameOfGoods string is greater than 25
        return false;
    }

    transform(nameOfGoods.begin(), nameOfGoods.end(), nameOfGoods.begin(), ::toupper);
    // Convert the nameOfGoods string to uppercase

    transform(nameOfGoods.begin(), nameOfGoods.end(), nameOfGoods.begin(), ::tolower);
    // Convert the nameOfGoods string to lowercase

    return true;
    // Return true indicating that the nameOfGoods is valid
}

//The function get_goods_colour takes a string parameter colour, which represents the user's input for the colour of the goods.
void Goods::get_goods_colour(string colour) {
    while (!controlColour(colour) || colour.empty()) {
        // Continue looping until a valid colour is entered and the input is not empty
        cout << "Invalid colour, please enter a valid colour: ";
        // Prompt the user to enter a valid colour
        getline(cin, colour);
        // Read the user's input and store it in the colour variable
    }
    colour_ = colour;
    // Set the member variable colour_ to the validated colour
}


//The function controlColour takes a string parameter colour, which represents the user's input for the colour.
bool Goods::controlColour(string colour) {
    for (char c : colour) {
        // Iterate through each character in the colour string

        if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) {
            // Check if the character is not an uppercase or lowercase letter

            if (c != ' ' && c != '-') {
                // Check if the character is not a space or a hyphen
                return false;
            }
        }
    }

    if (colour.length() > 25) {
        // Check if the length of the colour string is greater than 25
        return false;
    }

    transform(colour.begin(), colour.end(), colour.begin(), ::toupper);
    // Convert the colour string to uppercase

    transform(colour.begin(), colour.end(), colour.begin(), ::tolower);
    // Convert the colour string to lowercase

    return true;
    // Return true indicating that the colour is valid
}
//The function goods_status takes a string parameter status, which represents the user's input for the status of the goods.
void Goods::goods_status(string status) {
    while (!controlStatus(status)) {
        // Continue looping until a valid status is entered
        cout << "Invalid input, please enter a valid status: ";
        getline(cin, status);
    }
    status_ = status;
    // Assign the valid status to the member variable
}
//The function controlStatus takes a string parameter status, which represents the user's input for the status.
bool Goods::controlStatus(string status) {
    if (status == "New" || status == "new" ||
        status == "Second hand" || status == "second hand" ||
        status == "Unknown" || status == "unknown") {
        // Check if the status matches one of the valid options: New, Second hand, Unknown
        return true;
    }
    else {
        // If the status does not match any of the valid options, return false
        return false;
    }
}
//The function goods_number takes an integer parameter number, which represents the user's input for the number of goods.
void Goods::goods_number(int number) {
    while (number < 1) {
        // Continue looping until a valid number greater than or equal to 1 is entered
        cout << "Invalid number, please enter a valid number: ";
        cin >> number;
    }
    number_ = number;
    // Assign the valid number to the member variable
}
//The function saveProfileToFile takes a constant reference to a string parameter filename, which represents the name of the file to save the profile to.
void Goods::saveProfileToFile(const string& filename) {
    ofstream file(filename, ios::app);

    if (!file) {
        // Check if there was an error opening the file
        cout << "Error opening file." << endl;
        return;
    }
    file << "Type of donated goods : " << typeOfGoods_ << "\n";
    // Write the type of donated goods to the file
    file << "Name of donated goods : " << nameOfGoods_ << "\n";
    // Write the name of donated goods to the file
    file << "Colour of donated goods : " << colour_ << "\n";
    // Write the colour of donated goods to the file
    file << "What is the status of this goods ? : " << status_ << "\n";
    // Write the status of the goods to the file
    file << "Number of donated goods : " << number_ << "\n";
    // Write the number of the goods to the file
    file << endl;  // Add a new line after writing the content
    file.close();  // Close the file

    cout << "Profile saved to file: " << filename << endl;
    // Displaying a success message indicating the profile has been saved to the file
}

//The function loadProfileFromFile takes a constant reference to a string parameter fileName, which represents the name of the file to load the profile from.
void Goods::loadProfileFromFile(const string& fileName) {
    ifstream file(fileName);

    if (!file) {
        cout << "Error opening file." << endl;
        // Check if there was an error opening the file
        return;
    }

    getline(file, typeOfGoods_);
    // Read a line from the file and assign it to the 'typeOfGoods_' variable
    getline(file, nameOfGoods_);
    // Read a line from the file and assign it to the 'nameOfGoods_' variable
    getline(file, colour_);
    // Read a line from the file and assign it to the 'colour_' variable
    getline(file, status_);
    // Read a line from the file and assign it to the 'status_' variable
    file >> number_;
    // Read a value from the file and assign it to the 'number_' variable
    file.ignore();
    // Ignore any remaining characters in the file stream

    file.close(); // Close the file

    cout << "Data loaded from file: " << fileName << endl;
    // Display a message indicating that the data has been loaded from the file

}


//The function readProfileFromFile takes a constant reference to a string parameter fileName, which represents the name of the file to read.
void Goods::readProfileFromFile(const string& fileName) {
    ifstream file(fileName);

    if (!file) {
        cout << "Error opening file." << endl;
        // Check if there was an error opening the file
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl; // Print each line read from the file
    }

    file.close(); // Close the file

}
