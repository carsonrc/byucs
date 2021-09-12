//
// Created by carso on 11/11/2020.
//

#ifndef PREPLAB7_ITEMTOPURCHASE_H
#define PREPLAB7_ITEMTOPURCHASE_H
#include <string>
using namespace std;


class ItemToPurchase {
private:
    string itemName = "none";
    double itemPrice = 0.0;
    int itemQuantity = 0;
public:
    ItemToPurchase();
    void SetName(string name);
    string GetName();
    void SetPrice(double price);
    double GetPrice();
    void SetQuantity(int quantity);
    int GetQuantity();

};


#endif //PREPLAB7_ITEMTOPURCHASE_H
