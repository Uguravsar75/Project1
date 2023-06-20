#include <iostream> // Input/output stream handling
#include <string> // String manipulation
#include <algorithm> // Algorithms and transformations
#include <vector> // Dynamic array container
#include <fstream> // File stream handling

using namespace std;
// Use the std namespace for convenience and readability in the code


class Clothes {
public:
    // Control if the type of clothes is valid
    bool controlTypeOfClothes(string typeOfClothes);
    // Control if the clothes name is valid
    bool controlClothesName(string clothesName);
    // Control if the size is valid
    bool controlSize(string size);
    // Control if the intended recipient is valid
    bool controlForWhom(string forWhom);
    // Control if the clean/use status of clothes is valid
    bool controlCleanOrUseOfClothes(string cleanOrUseOfClothes);
    // Method to get clothes information
    void get_clothes();
    // Set the type of clothes
    void TypeOfClothes(string typeOfClothes);
    // Set the clothes name
    void ClothesName(string clothesName);
    // Set the clothes size
    void ClothesSize(string size);
    // Set the intended recipient of clothes
    void ClothesForWhom(string forWhom);
    // Set the clean status of clothes
    void ClothesClean(string clean);
    // Set the use of clothes
    void UseOfClothes(string useOfClothes);
    // Set the number of clothes
    void NumberOfClothes(int number = 0);
    // Save clothes profile to file
    void saveToFile(const string& fileName);
    // Load clothes profile from file
    void loadFromFile(const string& fileName);
    // Read clothes profile from file
    void readFromFile(const string& fileName);
private:
    // Private member variables
    string typeOfClothes_;   // Stores the type of clothes
    string clothesName_;     // Stores the name of the clothes
    string size_;            // Stores the size of the clothes
    string colour_;          // Stores the color of the clothes
    string forWhom_;         // Stores the intended recipient of the clothes
    string clean_;           // Stores the clean status of the clothes
    string useOfClothes_;    // Stores the use of the clothes
    int number_{};           // Stores the number of clothes
};




