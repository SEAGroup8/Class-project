#include <iostream>
#include <memory>
#include <string>
#include "Grocery.h"
#include "Electronics.h"
#include "SupermarketInventory.h"

void displayMenu() {
    std::cout << "\nSupermarket Inventory System\n";
    std::cout << "1. Add Product\n";
    std::cout << "2. Display All Products\n";
    std::cout << "3. Save Inventory to File\n";
    std::cout << "4. Load Inventory from File\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    SupermarketInventory inventory;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int type;
                std::string name;
                double price;
                int quantity;

                std::cout << "\nSelect Product Type:\n1. Grocery\n2. Electronics\nEnter your choice: ";
                std::cin >> type;
                std::cin.ignore(); // Clear the newline character from the input buffer

                std::cout << "Enter Product Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Price: ";
                std::cin >> price;
                std::cout << "Enter Stock Quantity: ";
                std::cin >> quantity;

                if (type == 1) {
                    inventory.addProduct(std::make_shared<Grocery>(name, price, quantity));
                } else if (type == 2) {
                    inventory.addProduct(std::make_shared<Electronics>(name, price, quantity));
                } else {
                    std::cout << "Invalid Product Type!\n";
                }
                break;
            }
            case 2:
                inventory.displayAllProducts();
                break;
            case 3:
                inventory.saveInventoryToFile();
                std::cout << "Inventory saved to file.\n";
                break;
            case 4:
                inventory.loadInventoryFromFile();
                std::cout << "Inventory loaded from file.\n";
                break;
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
