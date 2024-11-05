#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

void addContact(const std::string& filename) {
    Contact contact;
    std::cout << "Enter Name: ";
    std::cin.ignore();
    std::getline(std::cin, contact.name);
    std::cout << "Enter Phone: ";
    std::getline(std::cin, contact.phone);
    std::cout << "Enter Email: ";
    std::getline(std::cin, contact.email);

    std::ofstream outfile(filename, std::ios::app);
    if (outfile.is_open()) {
        outfile << contact.name << "\n" << contact.phone << "\n" << contact.email << "\n";
        outfile.close();
        std::cout << "Contact added successfully!\n";
    } else {
        std::cerr << "Error opening file.\n";
    }
}

void displayContacts(const std::string& filename) {
    std::ifstream infile(filename);
    if (infile.is_open()) {
        Contact contact;
        std::cout << std::setw(20) << "Name" << std::setw(15) << "Phone" << std::setw(30) << "Email\n";
        std::cout << std::string(65, '-') << "\n";
        while (std::getline(infile, contact.name)) {
            std::getline(infile, contact.phone);
            std::getline(infile, contact.email);
            std::cout << std::setw(20) << contact.name << std::setw(15) << contact.phone << std::setw(30) << contact.email << "\n";
        }
        infile.close();
    } else {
        std::cerr << "Error opening file.\n";
    }
}

void searchContact(const std::string& filename) {
    std::string searchName;
    std::cout << "Enter the name to search: ";
    std::cin.ignore();
    std::getline(std::cin, searchName);

    std::ifstream infile(filename);
    if (infile.is_open()) {
        Contact contact;
        bool found = false;
        while (std::getline(infile, contact.name)) {
            std::getline(infile, contact.phone);
            std::getline(infile, contact.email);
            if (contact.name == searchName) {
                std::cout << "\nContact Found:\n";
                std::cout << "Name: " << contact.name << "\n";
                std::cout << "Phone: " << contact.phone << "\n";
                std::cout << "Email: " << contact.email << "\n";
                found = true;
                break;
            }
        }
        infile.close();
        if (!found) {
            std::cout << "Contact not found.\n";
        }
    } else {
        std::cerr << "Error opening file.\n";
    }
}

int main() {
    std::string filename = "contacts.txt";
    int choice;

    do {
        std::cout << "\nContact Management System\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Display All Contacts\n";
        std::cout << "3. Search Contact\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addContact(filename);
                break;
            case 2:
                displayContacts(filename);
                break;
            case 3:
                searchContact(filename);
                break;
            case 4:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
