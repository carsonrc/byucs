//
// Created by carso on 11/16/2020.
//

#ifndef MAINLAB7_ITEMTOPURCHASE_H
#define MAINLAB7_ITEMTOPURCHASE_H
#include <string>
#include <iostream>
using namespace std;

class ItemToPurchase {
private:
    string itemName = "none";
    double itemPrice = 0.0;
    int itemQuantity = 0;
    string itemDescription = "none";
public:
    explicit ItemToPurchase(string itemName = "none", string itemDescription = "none",
                   double itemPrice = 0.0, int itemQuantity = 0);
    void SetName(string name);
    string GetName();
    void SetPrice(double price);
    double GetPrice();
    void SetQuantity(int quantity);
    int GetQuantity();
    void SetItemDescription(string newItemDescription = "none");
    string GetItemDescription();
    void PrintCostItem();
    void PrintDescriptionItem();

};


#endif //MAINLAB7_ITEMTOPURCHASE_H
