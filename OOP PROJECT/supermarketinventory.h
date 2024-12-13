#ifndef SUPERMARKETINVENTORY_H
#define SUPERMARKETINVENTORY_H

#include "InventoryManager.h"
#include <fstream>
#include <iostream>

class SupermarketInventory : public InventoryManager {
public:
    void addProduct(std::shared_ptr<Product> product) override {
        inventory.push_back(product);
    }

    void displayAllProducts() const override {
        for (const auto& product : inventory) {
            product->displayInfo();
            std::cout << "Discount: $" << product->calculateDiscount() << std::endl;
        }
    }

    void saveInventoryToFile() override {
        std::ofstream outFile("inventory.txt");
        for (const auto& product : inventory) {
            outFile << product->getName() << ","
                    << product->getPrice() << ","
                    << product->getStock() << std::endl;
        }
        outFile.close();
    }

    void loadInventoryFromFile() override {
        std::ifstream inFile("inventory.txt");
        if (!inFile) {
            std::cerr << "Error opening file!" << std::endl;
            return;
        }
        std::string name;
        double price;
        int stock;
        while (inFile >> name >> price >> stock) {
            addProduct(std::make_shared<GroceryProduct>(name, price, stock)); // Generic Product, can be improved
        }
        inFile.close();
    }
};

#endif
