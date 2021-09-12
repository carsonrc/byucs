//
// Created by carso on 11/11/2020.
//

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {

}
void ItemToPurchase::SetName(string name) {
    itemName = name;
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


