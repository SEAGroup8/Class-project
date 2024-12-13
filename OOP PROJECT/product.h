#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product {
protected:
    std::string productName;
    double price;
    int stockQuantity;

public:
    Product(std::string name, double p, int qty)
        : productName(name), price(p), stockQuantity(qty) {}

    virtual ~Product() {}

    virtual void displayInfo() const {
        std::cout << "Product: " << productName << ", Price: $" << price << ", Stock: " << stockQuantity << std::endl;
    }

    virtual double calculateDiscount() const = 0;

    std::string getName() const { return productName; }
    double getPrice() const { return price; }
    int getStock() const { return stockQuantity; }
};

class GroceryProduct : public Product {
public:
    GroceryProduct(std::string name, double p, int qty)
        : Product(name, p, qty) {}

    double calculateDiscount() const override {

        return price * 0.1;
    }

    void displayInfo() const override {
        Product::displayInfo();
        std::cout << "Discount: $" << calculateDiscount() << std::endl;
    }
};

#endif
