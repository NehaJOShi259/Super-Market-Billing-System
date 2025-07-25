# supermarket

# 🛒 Super Market Billing System (C++ Console App)

This is a simple and interactive **console-based billing system** built in C++ to simulate a basic supermarket counter.  
It allows you to:

- Add items to inventory
- Display current stock
- Clear/reset the inventory
- Start billing with automatic stock update and total calculation

---

## 🚀 Features

- Inventory Management (Add / View / Clear)
- Billing System (Real-time calculation)
- Quantity check and validation
- Neat output with formatted bill
- Fully written in C++ with OOP and arrays

---

## 📦 Technologies Used

- **C++** (Standard)
- OOP (Classes, Constructors)
- Array-based item storage
- Console input/output
- iomanip formatting

---

## 🧪 Sample Input & Output

Enter Item Name: Soap
Enter Item Rate: 30
Enter Item Quantity: 10
✅ Item added successfully!



Enter your choice: 1
Enter Item Name: Milk
Enter Item Rate: 25
Enter Item Quantity: 5
✅ Item added successfully!




Enter your choice: 2

📦 Current Inventory:
Item           Rate      Quantity
--------------------------------------
Soap           30        10
Milk           25        5



Enter your choice: 4

🧾 Start Billing (Type 'done' to finish):
Item           Rate      Qty       Amount
---------------------------------------------
Enter Item Name: Soap
Enter Quantity: 3
Soap           30        3         90

Enter Item Name: Milk
Enter Quantity: 2
Milk           25        2         50

Enter Item Name: done

==============================
✅ Total Bill: ₹140
Thank you for shopping!





---

## 📄 How to Run

1. Compile:  
```bash
g++ supermarket_billing.cpp -o billing
./billing

