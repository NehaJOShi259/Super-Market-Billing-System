#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

class Item {
public:
    string name;
    int rate;
    int quantity;

    Item() {
        name = "";
        rate = 0;
        quantity = 0;
    }

    Item(string name, int rate, int quantity) {
        this->name = name;
        this->rate = rate;
        this->quantity = quantity;
    }
};

class BillSystem {
private:
    Item inventory[MAX_ITEMS];
    int itemCount;

public:
    BillSystem() {
        itemCount = 0;
    }

    void addItem() {
        if (itemCount >= MAX_ITEMS) {
            cout << "❌ Inventory Full! Cannot add more items.\n";
            return;
        }

        string name;
        int rate, quantity;
        cout << "\nEnter Item Name: ";
        cin >> name;
        cout << "Enter Item Rate: ";
        cin >> rate;
        cout << "Enter Item Quantity: ";
        cin >> quantity;

        inventory[itemCount++] = Item(name, rate, quantity);
        cout << "✅ Item added successfully!\n";
    }

    void displayInventory() {
        if (itemCount == 0) {
            cout << "\n⚠️ Inventory is empty.\n";
            return;
        }

        cout << "\n📦 Current Inventory:\n";
        cout << left << setw(15) << "Item"
             << setw(10) << "Rate"
             << setw(10) << "Quantity" << "\n";
        cout << "--------------------------------------\n";

        for (int i = 0; i < itemCount; i++) {
            cout << left << setw(15) << inventory[i].name
                 << setw(10) << inventory[i].rate
                 << setw(10) << inventory[i].quantity << "\n";
        }
    }

    void clearInventory() {
        itemCount = 0;
        cout << "✅ Inventory cleared!\n";
    }

    void startBilling() {
        int totalBill = 0;
        string itemName;
        int qty;

        cout << "\n🧾 Start Billing (Type 'done' to finish):\n";
        cout << left << setw(15) << "Item"
             << setw(10) << "Rate"
             << setw(10) << "Qty"
             << setw(10) << "Amount" << "\n";
        cout << "---------------------------------------------\n";

        while (true) {
            cout << "\nEnter Item Name: ";
            cin >> itemName;
            if (itemName == "done") break;

            cout << "Enter Quantity: ";
            cin >> qty;

            bool found = false;

            for (int i = 0; i < itemCount; i++) {
                if (inventory[i].name == itemName) {
                    found = true;

                    if (qty <= inventory[i].quantity) {
                        int amount = qty * inventory[i].rate;
                        totalBill += amount;
                        inventory[i].quantity -= qty;

                        cout << left << setw(15) << inventory[i].name
                             << setw(10) << inventory[i].rate
                             << setw(10) << qty
                             << setw(10) << amount << "\n";
                    } else {
                        cout << "❌ Insufficient quantity available!\n";
                    }
                    break;
                }
            }

            if (!found) {
                cout << "❌ Item not found in inventory!\n";
            }
        }

        cout << "\n==============================\n";
        cout << "✅ Total Bill: ₹" << totalBill << "\n";
        cout << "Thank you for shopping!\n";
    }

    void showMenu() {
        int choice;
        bool running = true;

        while (running) {
            cout << "\n==============================\n";
            cout << "  🛒 Super Market Billing System\n";
            cout << "==============================\n";
            cout << "1. Add Item to Inventory\n";
            cout << "2. View Inventory\n";
            cout << "3. Clear Inventory\n";
            cout << "4. Start Billing\n";
            cout << "5. Exit\n";
            cout << "==============================\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addItem(); break;
                case 2: displayInventory(); break;
                case 3: clearInventory(); break;
                case 4: startBilling(); break;
                case 5: running = false; cout << "👋 Exiting... Thank you!\n"; break;
                default: cout << "❌ Invalid choice. Try again.\n";
            }
        }
    }
};

int main() {
    BillSystem system;
    system.showMenu();
    return 0;
}
