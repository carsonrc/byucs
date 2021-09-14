#include <iostream>
#include <iomanip>
#include "ItemToPurchase.h"
using namespace std;

int main() {
    string nameInput;
    double priceInput;
    int quantityInput;
    ItemToPurchase myItem;
    ItemToPurchase myOtherItem;

    cout << "Item " << '1' << endl;

    cout << "Enter the item name:" << endl;
    getline(cin, nameInput);
    myItem.SetName(nameInput);

    cout << "Enter the item price:" << endl;
    cin >> priceInput;
    cin.ignore();
    myItem.SetPrice(priceInput);

    cout << "Enter the item quantity:" << endl;
    cin >> quantityInput;
    cin.ignore();
    myItem.SetQuantity(quantityInput);

    // ===================================================
    // item 2

    cout << "Item " << '2' << endl;

    cout << "Enter the item name:" << endl;
    getline(cin, nameInput);
    myOtherItem.SetName(nameInput);

    cout << "Enter the item price:" << endl;
    cin >> priceInput;
    cin.ignore();
    myOtherItem.SetPrice(priceInput);

    cout << "Enter the item quantity:" << endl;
    cin >> quantityInput;
    cin.ignore();
    myOtherItem.SetQuantity(quantityInput);

    //============================================================
    // print items

    cout << "TOTAL COST" << fixed << setprecision(2) << endl;
    cout <<  myItem.GetName() << " " << myItem.GetQuantity() << " @ $" << myItem.GetPrice()
        << " = $" << (myItem.GetQuantity() * myItem.GetPrice()) << endl;
    cout << myOtherItem.GetName() << " " << myOtherItem.GetQuantity() << " @ $" << myOtherItem.GetPrice()
         << " = $" << (myOtherItem.GetQuantity() * myOtherItem.GetPrice()) << endl;
    cout << endl;
    cout << "Total: $" << (myItem.GetQuantity() * myItem.GetPrice())
        + (myOtherItem.GetQuantity() * myOtherItem.GetPrice()) << endl;

    return 0;
}
