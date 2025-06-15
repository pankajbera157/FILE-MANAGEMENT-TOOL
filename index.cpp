#include <iostream>
#include <fstream>
#include <string>

void writeToFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    std::string data;
    std::cout << "Enter data to write to the file (type 'exit' to stop):" << std::endl;
    while (true) {
        std::getline(std::cin, data);
        if (data == "exit") break;
        outFile << data << std::endl;
    }

    outFile.close();
    std::cout << "Data written to file successfully." << std::endl;
}

void readFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file for reading." << std::endl;
        return;
    }

    std::string line;
    std::cout << "Contents of the file:" << std::endl;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }

    inFile.close();
}

void appendToFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening file for appending." << std::endl;
        return;
    }

    std::string data;
    std::cout << "Enter data to append to the file (type 'exit' to stop):" << std::endl;
    while (true) {
        std::getline(std::cin, data);
        if (data == "exit") break;
        outFile << data << std::endl;
    }

    outFile.close();
    std::cout << "Data appended to file successfully." << std::endl;
}

int main() {
    std::string filename;
    int choice;

    std::cout << "Enter the filename: ";
    std::getline(std::cin, filename);

    do {
        std::cout << "\nFile Management Menu:\n";
        std::cout << "1. Write to file\n";
        std::cout << "2. Read from file\n";
        std::cout << "3. Append to file\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                readFromFile(filename);
                break;
            case 3:
                appendToFile(filename);
                break;
            case 4:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
