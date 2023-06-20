#include "clothes.h" // Include the clothes header file
#include "goods.h"   // Include the goods header file
#include "person.h"  // Include the person header file
#include <fstream>   // Include the fstream library for file operations
 
using namespace std;


int main()
{
    cout << "Hello, please enter the required information for donation;" << endl; // Prompt the user for donation information
    Person person = get_person_info(); // Get the person's information
    cout << endl;

    // File names for storing person, clothes, and goods profiles
    string personFilename = "person.txt";
    string clothesProfileFilename = "clothes.txt";
    string goodsProfileFilename = "goods.txt";
    string continueStr = "yes"; // Variable to determine if the donation process should continue

    while (continueStr == "yes" || continueStr == "y") { 
        // Execute the following code as long as the user wants to continue donating (when continueStr is "yes" or "y")
        cout << "Please write the type you want to donate. ('clothes' for Clothes, 'goods' for Goods): ";
        string choiceStr;
        getline(cin, choiceStr);
        cout << endl; // Blank line for better readability

        if (choiceStr == "goods") {
            Goods goods;
            goods.get_goods_donation();
            // Create a Goods object and prompt the user to enter donation information

            goods.saveProfileToFile(goodsProfileFilename);
            // Save the donation profile to a file

            goods.loadProfileFromFile(goodsProfileFilename);
            // Load the donation profile from the file

            cout << "------------------------------------------------------------------------------------------------" << endl;
            cout << "Do you want to view the donation information from the file? (yes/no): ";
            // Prompt the user to choose whether they want to view the donation information from the file
            string viewFromFile;
            getline(cin, viewFromFile);
            // Read the user's response and store it in the viewFromFile variable
            cout << endl; // Print a blank line for better readability

            if (viewFromFile == "yes") {
                // If the user wants to view the donation information from the file
                cout << "Displaying donation information from the file;" << endl;
                // Display a message indicating that the donation information will be shown
                person.savePersonToFile(personFilename);
                // Save the person's information to a file
                cout << endl;
                // Print a blank line for better readability
                person.loadAndDisplayPersonFromFile(personFilename);
                // Load and display the person's information from the file
                goods.readProfileFromFile(goodsProfileFilename);
                // Read the donation profile from the file
            }
        }
        else if (choiceStr == "clothes") {
            Clothes clothes;
            clothes.get_clothes();
            // Create a Clothes object and prompt the user to enter clothes donation information

            clothes.saveToFile(clothesProfileFilename);
            // Save the clothes donation profile to a file

            clothes.loadFromFile(clothesProfileFilename);
            // Load the clothes donation profile from the file

            cout << "------------------------------------------------------------------------------------------------" << endl;
            cout << "Do you want to view the donation information from the file? (yes/no): ";
            // Prompt the user to choose whether they want to view the donation information from the file or not
            string viewFromFile;
            getline(cin, viewFromFile);
            // Read the user's response and store it in the viewFromFile variable
            cout << endl;// Print a blank line for better readability

            if (viewFromFile == "yes") {
                // If the user wants to view the donation information from the file
                cout << "Displaying donation information from the file:" << endl;
                // Print a message indicating that the donation information will be displayed
                person.savePersonToFile(personFilename);
                // Save the person's information to a file
                cout << endl;
                // Print a blank line for better readability
                person.loadAndDisplayPersonFromFile(personFilename);
                // Load and display the person's information from the file
                clothes.readFromFile(clothesProfileFilename);
                // Read the clothes donation profile from the file
            }
        }

        else {
            cout << "Invalid choice!" << endl;
            continue;
            // If the user enters an invalid choice, display an error message and continue to the next iteration of the loop
        }

        cout << "------------------------------------------------------------------------------------------------\n";
        // Print a line of dashes as a visual separator
        cout << "Do you want to continue donating? (yes/no): ";
        // Prompt the user to enter whether they want to continue donating or not
        getline(cin, continueStr);
        // Read the user's response and store it in the continueStr variable
        cout << endl;
        // Print a blank line for better readability
    }
    // End of the while loop
    cout << "Thank you for donation , have a nice day." << endl;
    return 0;
    // Exit the program with a successful status code (0)
}



