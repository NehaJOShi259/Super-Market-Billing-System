# Super Market Billing System (C++ Console App)

A simple and interactive console-based billing system built in C++ to simulate a basic supermarket counter.
It allows users to manage inventory and generate bills with real-time stock updates.

---

## Features

* **Inventory Management:** Add, view, and clear items in stock
* **Real-time Billing System:** Automatically updates stock after billing
* **Quantity Validation and Stock Check**
* **Formatted and Readable Bill Output**
* **Implemented using Object-Oriented Programming (OOP)**

---

## Technologies Used

* **C++ (Standard Library)**
* **Object-Oriented Programming (Classes and Constructors)**
* **Array-based Item Storage**
* **Console Input/Output**
* **`iomanip` for formatted display**

---

## Sample Input & Output

**Adding Items:**

```
Enter Item Name: Soap
Enter Item Rate: 30
Enter Item Quantity: 10
Item added successfully!

Enter Item Name: Milk
Enter Item Rate: 25
Enter Item Quantity: 5
Item added successfully!
```

**Display Inventory:**

```
Current Inventory:
Item           Rate      Quantity
--------------------------------------
Soap           30        10
Milk           25        5
```

**Start Billing:**

```
Start Billing (Type 'done' to finish):
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
Total Bill: ₹140
Thank you for shopping!
```

---

## How to Run

1. **Compile the program:**

   ```bash
   g++ supermarket_billing.cpp -o billing
   ```

2. **Run the executable:**

   ```bash
   ./billing
   ```

---

## Project Structure

```
supermarket_billing.cpp   # Main source file
README.md                 # Project documentation
```

---

## Notes

* Designed for console-based demonstration of OOP concepts.
* Can be expanded using file handling or STL containers for larger inventory systems.
