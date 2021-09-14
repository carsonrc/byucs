//
// Created by carso on 11/16/2020.
//

#ifndef MAINLAB7_SHOPPINGCART_H
#define MAINLAB7_SHOPPINGCART_H
#include "ItemToPurchase.h"
#include <vector>
using namespace std;

class ShoppingCart {
private:
    string customerName = "none";
    string cartDate = "January 1, 2016";
    vector<ItemToPurchase> cartItems;
public:
    ShoppingCart(string customerName, string cartDate);
    string GetName();
    string GetDate();
    int GetCartQuantity();
    double GetCartCost();
    void PrintCartDescriptions();   //descriptions
    void PrintCartItems();      // item number and cost
    void AddItemToCart(ItemToPurchase item);
    void RemoveItemFromCart(string nameOfItem);
    void UpdateQuantity(string itemName, int itemQuantity);




};


#endif //MAINLAB7_SHOPPINGCART_H
