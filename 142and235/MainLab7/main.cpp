#include <iostream>
#include <string>


#include "ShoppingCart.h"

std::string GetUserString(const std::string& prompt);

void AddMenuOption(ShoppingCart &customerCart);
void RemoveMenuOption(ShoppingCart &customerCart);
void ChangeMenuOption(ShoppingCart &customerCart);
void DescriptionsMenuOption(ShoppingCart &customerCart);
void CartMenuOption(ShoppingCart &customerCart);
void OptionsMenuOption();
void QuitMenuOption();


int main() {
    std::string customerName = GetUserString("Enter Customer's Name: ");
    std::string todayDate = GetUserString("Enter Today's Date: ");

    //TODO: Create a shopping cart with the above information
    // .
    // This should be just one line of code that calls your ShoppingCart constructor
    ShoppingCart customerCart(customerName, todayDate);

    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;
    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter option: ");

        if (userMenuChoice == "add") {
            AddMenuOption(customerCart);
        }
        else if (userMenuChoice == "remove") {
            RemoveMenuOption(customerCart);
        }
        else if (userMenuChoice == "change") {
            ChangeMenuOption(customerCart);
        }
        else if (userMenuChoice == "descriptions") {
            DescriptionsMenuOption(customerCart);
        }
        else if (userMenuChoice == "cart") {
            CartMenuOption(customerCart);
        }
        else if (userMenuChoice == "options") {
            OptionsMenuOption();
        }
        else if (userMenuChoice == "quit") {
            QuitMenuOption();
            continueMenuLoop = false;
        }
        else {
            OptionsMenuOption();
        }
    }

    return 0;
}


std::string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}
double GetUserDouble(const std::string& prompt) {
    double userAnswer = 0.0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}
int GetUserInt(const std::string& prompt) {
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}


void AddMenuOption(ShoppingCart &customerCart) {
    std::string itemName = GetUserString("Enter the item name: ");
    std::string itemDescription = GetUserString("Enter the item description: ");
    double itemPrice = GetUserDouble("Enter the item price: ");
    int itemQuantity = GetUserInt("Enter the item quantity: ");

    ItemToPurchase item(itemName, itemDescription, itemPrice, itemQuantity);
    customerCart.AddItemToCart(item);

    //TODO: error?
}

void RemoveMenuOption(ShoppingCart &customerCart) {
    std::string nameOfItemToRemove = GetUserString("Enter name of the item to remove: ");
    customerCart.RemoveItemFromCart(nameOfItemToRemove);
    //TODO: error?
}

void ChangeMenuOption(ShoppingCart &customerCart) {
    std::string nameOfItemToChange = GetUserString("Enter the item name: ");
    int newItemQuantity = GetUserInt("Enter the new quantity: ");
    // You might also print error messages here, depending on how you implement the ShoppingCart class
    customerCart.UpdateQuantity(nameOfItemToChange, newItemQuantity);


}

void DescriptionsMenuOption(ShoppingCart &customerCart) {
    customerCart.PrintCartDescriptions();
}

void CartMenuOption(ShoppingCart &customerCart) {
    customerCart.PrintCartItems();
}

void OptionsMenuOption() {
    std::cout << "MENU" << std::endl
              << "add - Add item to cart" << std::endl
              << "remove - Remove item from cart" << std::endl
              << "change - Change item quantity" << std::endl
              << "descriptions - Print the items' descriptions" << std::endl
              << "cart - Print the shopping cart" << std::endl
              << "options - Print the options menu" << std::endl
              << "quit - Quit" << std::endl << std::endl;
}

void QuitMenuOption() {
    std::cout << "Goodbye." << std::endl;
}