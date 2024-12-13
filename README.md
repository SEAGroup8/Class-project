Supermarket Inventory System in C++

Introduction
The Supermarket Inventory System is a dynamic C++ project designed to efficiently manage products in a supermarket. It demonstrates key Object-Oriented Programming (OOP) principles such as encapsulation, inheritance, polymorphism, and abstraction. The system also incorporates file management and a user-interactive command-line interface for enhanced usability.

Objective
To create a modular and extensible system that:
Manages product information including name, price, stock, and discounts.
Utilizes core OOP principles for maintainable and scalable code.
Saves and retrieves data using file I/O to ensure data persistence.
Provides a user-friendly interface for managing the inventory.

Project Design Overview
1. Class Structure
The project comprises the following core classes:

a. Product (Abstract Base Class)
Attributes:
productName: Name of the product.
price: Price of the product.
stockQuantity: Quantity available in stock.
Methods:
displayInfo(): Displays product details.
calculateDiscount(): Abstract method to compute category-specific discounts.

b. Grocery and Electronics (Derived Classes)
Extend the Product class.
Implement calculateDiscount() with tailored discount logic:
Grocery: 10% discount.
Electronics: 15% discount.
Override displayInfo() to include discount details.

c. InventoryManager (Abstract Class)
Defines essential inventory operations:
Adding products.
Displaying product details.
Saving/loading inventory data.

d. SupermarketInventory (Concrete Class)
Inherits from InventoryManager.
Implements:
addProduct(): Adds products to inventory.
displayAllProducts(): Displays product details with discounts.
saveInventoryToFile(): Saves inventory to a file.
loadInventoryFromFile(): Loads inventory from a file.

Key OOP Principles Demonstrated
1. Encapsulation
Product attributes (productName, price, stockQuantity) are private and accessed via public methods.
Inventory operations are encapsulated within SupermarketInventory.

2. Inheritance
Grocery and Electronics inherit common properties and methods from the Product class.

3. Polymorphism
The displayInfo() and calculateDiscount() methods exhibit polymorphic behavior, invoking the appropriate implementation based on the object type.

4. Abstraction
Abstract classes (Product, InventoryManager) define a blueprint for derived classes, ensuring a consistent structure across the application.

File I/O Integration
Saving Inventory: Writes product details (name, price, stock) to inventory.txt.
Loading Inventory: Reads product data from the file, ensuring continuity between program executions.
Command-Line Interaction
The program provides an interactive menu with the following options:
Add products dynamically by entering their details.
Display all products with their discounts.
Save inventory data to a file for persistence.
Load inventory data from the file for reuse.
Exit the program.


the IDE code blocks
language C++
