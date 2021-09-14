//
// Created by carso on 11/16/2020.
//

#include "ItemToPurchase.h"
#include <iomanip>
#include <utility>

ItemToPurchase::ItemToPurchase(string itemName, string itemDescription, double itemPrice, int itemQuantity) {
    ItemToPurchase::itemName = itemName;
    ItemToPurchase::itemDescription = itemDescription;
    ItemToPurchase::itemPrice = itemPrice;
    ItemToPurchase::itemQuantity = itemQuantity;
}
void ItemToPurchase::SetName(string name) {
    itemName = std::move(name);
}
string ItemToPurchase::GetName() {
    return itemName;
}

void ItemToPurchase::SetPrice(double price) {
    itemPrice = price;
}

double ItemToPurchase::GetPrice() {
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}

void ItemToPurchase::SetItemDescription(string newItemDescription) {
    itemDescription = newItemDescription;
}

string ItemToPurchase::GetItemDescription() {
    return itemDescription;
}

void ItemToPurchase::PrintCostItem() {
    cout << fixed << setprecision(2) << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $"
        << itemPrice * itemQuantity << endl;
}

void ItemToPurchase::PrintDescriptionItem() {
    cout << itemName << ": " << itemDescription << endl;
}
