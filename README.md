Super Market Billing System (C++ Console App)

A simple and interactive console-based billing system built in C++ to simulate a basic supermarket counter.
It allows you to:

Add items to inventory

Display current stock

Clear or reset inventory

Start billing with automatic stock updates and total calculation

Features

Inventory Management (Add / View / Clear)

Real-time Billing System

Quantity Validation and Stock Check

Formatted and Readable Bill Output

Implemented using C++ with OOP and Arrays

Technologies Used

C++ (Standard Library)

Object-Oriented Programming (Classes and Constructors)

Array-based Item Storage

Console Input/Output

iomanip for formatted display

Sample Input & Output
Enter Item Name: Soap
Enter Item Rate: 30
Enter Item Quantity: 10
Item added successfully!

Enter Item Name: Milk
Enter Item Rate: 25
Enter Item Quantity: 5
Item added successfully!


Display Inventory

Current Inventory:
Item           Rate      Quantity
--------------------------------------
Soap           30        10
Milk           25        5


Start Billing

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

How to Run

Compile the code:

g++ supermarket_billing.cpp -o billing


Run the executable:

./billing
