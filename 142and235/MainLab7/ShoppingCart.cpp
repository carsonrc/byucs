//
// Created by carso on 11/16/2020.
//

#include "ShoppingCart.h"
#include <iostream>
#include <iomanip>
using namespace std;



ShoppingCart::ShoppingCart(string customerName, string cartDate) {
    ShoppingCart::customerName = customerName;
    ShoppingCart::cartDate = cartDate;

}

void ShoppingCart::RemoveItemFromCart(string nameOfItem) {
    bool error = true;
    for(int i = 0; i < cartItems.size(); i++){
        string nameHolder = cartItems.at(i).GetName();
        if (nameOfItem == nameHolder) {
            cartItems.erase(cartItems.begin() + i);
            error = false;
        }
    }
    if (error) {
        cout << "Item not found in cart. It will not be removed." << endl;
    }
}

void ShoppingCart::AddItemToCart(ItemToPurchase item) {
    string itemName = item.GetName();
    bool pushBack = true;
    for(int i = 0; i < cartItems.size(); ++i) {
        if (cartItems.at(i).GetName() == itemName) {
            pushBack = false;
        }
    }
    if (pushBack) {
        cartItems.push_back(item);
    }
    else {
        cout << "Item is already found in the cart. It will not be added." << endl;
    }
}

void ShoppingCart::UpdateQuantity(string itemName, int itemQuantity) {
    bool notFound = true;
    for(int i = 0; i < cartItems.size(); i++) {
        string nameHolder = cartItems.at(i).GetName();
        if (itemName == nameHolder) {
            cartItems.at(i).SetQuantity(itemQuantity);
            notFound = false;
        }
    }
    if (notFound) {
        cout << "Item not found in cart. It will not be modified." << endl;
    }
}

double ShoppingCart::GetCartCost() {
    return 0;
}

int ShoppingCart::GetCartQuantity() {
    return 0;
}

string ShoppingCart::GetDate() {
    return string();
}

string ShoppingCart::GetName() {
    return string();
}

void ShoppingCart::PrintCartDescriptions() {
    cout << customerName << "'s Shopping Cart - " << cartDate << endl;
    if (!cartItems.empty()) {
        cout << "Item Descriptions" << endl;
        for (int i = 0; i < cartItems.size(); i++) {
            cartItems.at(i).PrintDescriptionItem();
        }
    }
    else {
        cout << "Shopping cart is empty." << endl;
    }
}

void ShoppingCart::PrintCartItems() {
    cout << customerName << "'s Shopping Cart - " << cartDate << endl;
    int sumItems = 0;
    double sumPrice = 0;
    if(!cartItems.empty()) {
        for (int i = 0; i < cartItems.size(); i++) {
            sumItems = sumItems + cartItems.at(i).GetQuantity();
        }

        cout << "Number of Items: " << sumItems << endl;
        cout << endl;

        for (int i = 0; i < cartItems.size(); i++) {
            cartItems.at(i).PrintCostItem();
            sumPrice = sumPrice + (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity());
        }
        cout << "Total: $" << fixed << setprecision(2) << sumPrice << endl;
    }
    else {
        cout << "Shopping cart is empty." << endl;
    }

}
