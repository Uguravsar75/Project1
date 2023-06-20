#include <iostream> // Input/output stream library
#include <string> // String library
#include <vector> // Vector library
#include <limits> // Numeric limits library
#include <regex> // Regular expression library
#include <fstream> // File stream library

using namespace std;
// Use the std namespace for convenience and readability in the code

class Person {
private:
    string name; // Stores the person's name
    string surname; // Stores the person's surname
    int age; // Stores the person's age
    string email; // Stores the person's email address
    string phone; // Stores the person's phone number
public:
    void savePersonToFile(const string& filename) const;
    // Function to save person information to a file
    void loadAndDisplayPersonFromFile(const string& filename);
    // Function to load and display person information from a file
    
    // Constructor for initializing Person object with provided information
    Person(string name, string surname, int age, string email, string phone) {
        this->name = name;
        this->surname = surname;
        this->age = age;
        this->email = email;
        this->phone = phone;
    }

    // Getter functions for accessing individual member variables
    string get_name() const {
        return name;
    }

    string get_surname() const {
        return surname;
    }

    int get_age() const {
        return age;
    }

    string get_email() const {
        return email;
    }

    string get_phone() const {
        return phone;
    }

};


void Person::savePersonToFile(const string& filename) const {
    ofstream file(filename);
    // Checks if the file can be opened successfully in append mode.
    // If the file cannot be opened, displays an error message and returns.
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }
    // Write person information to the file
    file << "Name: " << name << "\n";
    file << "Surname: " << surname << "\n";
    file << "Age: " << age << "\n";
    file << "Email: " << email << "\n";
    file << "Phone: " << phone << "\n";
    file << endl;
    file.close();

    // Output success message
    cout << "Person information saved to file: " << filename << endl;
    cout << "Person information loaded from file: " << filename << endl;
}

// Reads and prints the contents of a file line by line.
void Person::loadAndDisplayPersonFromFile(const string& filename) {
    // Opens the file with the given 'fileName' for reading.
    ifstream file(filename);

    // Checks if the file can be opened successfully.
    // If the file cannot be opened, displays an error message and returns.
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    // Reads each line from the file and prints it to the console.
    // The 'getline' function is used to read each line from the file.
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();// Closes the file after reading all lines.

    cout << endl; // Print a new line for better readability
}

bool is_valid_email(string email) {
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    // Regular expression pattern to validate email format
    return regex_match(email, pattern);
    // Check if the email matches the pattern
}


Person get_person_info() {
    string name; // Stores the person's name
    string surname; // Stores the person's surname
    int age; // Stores the person's age
    string email; // Stores the person's email address
    string phone; // Stores the person's phone number

    while (true) {
        cout << "Please enter Name: "; // Prompting the user to enter their name
        getline(cin, name); 
        // Getting the user's input and storing it in the variable 'name'

        if (name.empty()) {
            cout << "Invalid name. Please enter a valid name: " << endl; 
            // Display an error message for an empty name
            continue; // Skip the rest of the loop and prompt for a valid name again
        }

        if (name.length() > 25) {
            cout << "Invalid name. The name should not exceed 25 characters. Please enter a valid name: " << endl;
            // Display an error message for a name exceeding the character limit
            continue; // Skip the rest of the loop and prompt for a valid name again
        }

        bool valid_name = true;

        // Check if each character in the name is alphabetic
        for (char c : name) {
            if (!isalpha(c)) {
                valid_name = false;
                break;
            }
        }

        if (valid_name) {
            break; // Valid name entered, exit the loop
        }
        else {
            cout << "Invalid name. Please enter a valid name: " << endl; 
            // Display an error message for an invalid name
        }

    }

    while (true) {
        cout << "Please enter Surname: ";// Prompting the user to enter their surname
        getline(cin, surname);
        // Getting the user's input and storing it in the variable 'surname'

        if (surname.empty()) {
            cout << "Invalid surname. Please enter a valid surname: " << endl;
            // Display an error message for an empty surname
            continue; // Skip the rest of the loop and prompt for a valid surname again
        }

        if (surname.length() > 25) {
            cout << "Invalid surname. The surname should not exceed 25 characters. Please enter a valid surname: " << endl;
            // Display an error message for a surname exceeding the character limit
            continue; // Skip the rest of the loop and prompt for a valid surname again
            
        }

        // Check if each character in the name is alphabetic
        bool valid_surname = true;
        for (char c : surname) {
            if (!isalpha(c)) {
                valid_surname = false;
                break;
            }
        }

        if (valid_surname) {
            break;// Valid surname entered, exit the loop
        }
        else {
            cout << "Invalid surname. Please enter a valid surname: " << endl;
            // Display an error message for an invalid surname           
        }

    }


    while (true) {
        cout << "Please enter Age: ";
        // Check if the input for age is a valid integer within the range of 10 to 120
        if (cin >> age && age >= 10 && age <= 120) {
            break; // Valid age entered, exit the loop
        }

        else {
            cout << "Invalid age. Please enter a valid age between 10 and 120: " << endl; 
            // Display an error message for an invalid age
            cin.clear(); // Clear any error flags on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining characters in the input buffer
        }
    }


    while (true) {
        cout << "Please enter Email: ";
        cin.ignore(); // Ignore any remaining characters in the input buffer
        getline(cin, email); // Get the user's input and store it in the variable 'email'

        if (is_valid_email(email)) {
            break; // Valid email entered, exit the loop
        }
        else {
            cout << "Invalid email. Please enter a valid email address: " << endl; 
            // Display an error message for an invalid email
        }
    }


    while (true) {
        cout << "Please enter Phone Number (11 digits): ";

        // Check if the entered phone number is valid
        if (getline(cin, phone) && phone.length() == 11 && phone.find_first_not_of("0123456789") == string::npos && phone.substr(0, 2) == "05") {
            break; // Valid phone number entered, exit the loop
        }
        else {
            cout << "Invalid phone number. Please enter a valid 11-digit phone number starting with '05': " << endl; // Display an error message for an invalid phone number
        }

    }

    return Person(name, surname, age, email, phone); 
    // Create a Person object with the provided information and return it

}


// Function to print person information
void print_person_info(const Person& person) {
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << "Name: " << person.get_name() << endl;
    cout << "Surname: " << person.get_surname() << endl;
    cout << "Age: " << person.get_age() << endl;
    cout << "Email: " << person.get_email() << endl;
    cout << "Phone:" << person.get_phone() << endl;
}

