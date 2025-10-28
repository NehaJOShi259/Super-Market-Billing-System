#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Item {
private:
    string name;
    int rate;
    int quantity;

public:
    Item(string n, int r, int q) : name(n), rate(r), quantity(q) {}
    Item() : name(""), rate(0), quantity(0) {}

    string getName() const { return name; }
    int getRate() const { return rate; }
    int getQuantity() const { return quantity; }

    void setQuantity(int q) { quantity = q; }
};

class BillSystem {
private:
    vector<Item> inventory;
    const string fileName = "inventory.txt";

    static string toLowerCase(const string& s) {
        string lower = s;
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        return lower;
    }

    void saveInventory() {
        ofstream fout(fileName);
        for (auto& item : inventory) {
            fout << item.getName() << " " << item.getRate() << " " << item.getQuantity() << "\n";
        }
        fout.close();
    }

    void loadInventory() {
        ifstream fin(fileName);
        if (!fin) return;
        string name;
        int rate, quantity;
        while (fin >> name >> rate >> quantity) {
            inventory.push_back(Item(name, rate, quantity));
        }
        fin.close();
    }

public:
    BillSystem() { loadInventory(); }

    void addItem() {
        string name;
        int rate, quantity;

        cout << "\nEnter Item Name: ";
        cin >> name;
        cout << "Enter Item Rate: ";
        if (!(cin >> rate)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid rate!\n"; return; }
        cout << "Enter Item Quantity: ";
        if (!(cin >> quantity)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid quantity!\n"; return; }

        for (auto& item : inventory) {
            if (toLowerCase(item.getName()) == toLowerCase(name)) {
                cout << "Item already exists. Updating quantity.\n";
                item.setQuantity(item.getQuantity() + quantity);
                saveInventory();
                return;
            }
        }

        inventory.push_back(Item(name, rate, quantity));
        saveInventory();
        cout << "Item added successfully!\n";
    }

    void displayInventory() const {
        if (inventory.empty()) {
            cout << "\nInventory is empty.\n";
            return;
        }

        cout << "\nCurrent Inventory:\n";
        cout << left << setw(15) << "Item" 
             << setw(10) << "Rate" 
             << setw(10) << "Quantity" << "\n";
        cout << "--------------------------------------\n";

        for (const auto& item : inventory) {
            cout << left << setw(15) << item.getName()
                 << setw(10) << item.getRate()
                 << setw(10) << item.getQuantity() << "\n";
        }
    }

    void clearInventory() {
        inventory.clear();
        saveInventory();
        cout << "Inventory cleared successfully.\n";
    }

    void startBilling() {
        if (inventory.empty()) {
            cout << "No items available in inventory.\n";
            return;
        }

        int totalBill = 0;
        string itemName;
        int qty;

        cout << "\nStart Billing (Type 'done' to finish):\n";
        cout << left << setw(15) << "Item"
             << setw(10) << "Rate"
             << setw(10) << "Qty"
             << setw(10) << "Amount" << "\n";
        cout << "---------------------------------------------\n";

        while (true) {
            cout << "\nEnter Item Name: ";
            cin >> itemName;
            if (toLowerCase(itemName) == "done") break;

            cout << "Enter Quantity: ";
            if (!(cin >> qty)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid quantity!\n"; continue; }

            bool found = false;

            for (auto& item : inventory) {
                if (toLowerCase(item.getName()) == toLowerCase(itemName)) {
                    found = true;

                    if (qty <= item.getQuantity()) {
                        int amount = qty * item.getRate();
                        totalBill += amount;
                        item.setQuantity(item.getQuantity() - qty);

                        cout << left << setw(15) << item.getName()
                             << setw(10) << item.getRate()
                             << setw(10) << qty
                             << setw(10) << amount << "\n";
                    } else {
                        cout << "Insufficient quantity available!\n";
                    }
                    break;
                }
            }

            if (!found) {
                cout << "Item not found in inventory!\n";
            }
        }

        saveInventory();
        cout << "\n==============================\n";
        cout << "Total Bill: ₹" << totalBill << "\n";
        cout << "Thank you for shopping!\n";
    }

    void showMenu() {
        int choice;
        bool running = true;

        while (running) {
            cout << "\n==============================\n";
            cout << "  Super Market Billing System\n";
            cout << "==============================\n";
            cout << "1. Add Item to Inventory\n";
            cout << "2. View Inventory\n";
            cout << "3. Clear Inventory\n";
            cout << "4. Start Billing\n";
            cout << "5. Exit\n";
            cout << "==============================\n";
            cout << "Enter your choice: ";

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Try again.\n";
                continue;
            }

            switch (choice) {
                case 1: addItem(); break;
                case 2: displayInventory(); break;
                case 3: clearInventory(); break;
                case 4: startBilling(); break;
                case 5: running = false; cout << "Exiting... Thank you!\n"; break;
                default: cout << "Invalid choice. Try again.\n";
            }
        }
    }
};

int main() {
    BillSystem system;
    system.showMenu();
    return 0;
}
