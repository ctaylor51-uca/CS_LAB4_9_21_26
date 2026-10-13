#include <iomanip>
#include <string>
#include <iostream>
#include <limits>
#include <fstream> // Required for file output

int main()
{
    char anotherCustomer = 'Y';
    double grandTotalSales = 0.0;
    int TotalCustomers = 0;

    // Inventory setup (12 items: 4 drinks * 3 sizes)
    std::string itemNames[12] = {
        "Small Coke", "Medium Coke", "Large Coke",
        "Small Pepsi", "Medium Pepsi", "Large Pepsi",
        "Small Sprite", "Medium Sprite", "Large Sprite",
        "Small Fanta", "Medium Fanta", "Large Fanta"
    };
    int startInventory[12] = { 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50 };
    int changeInventory[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    // Outer loop to handle multiple customers
    while (anotherCustomer == 'Y' || anotherCustomer == 'y')
    {
        // Global receipt and tracking variables
        std::string customerName;
        double finalOrderTotal = 0.0;
        char memberInput;
        bool isMember = false;
        std::string cashierNotes;

        // String to store the itemized receipt contents
        std::string itemizedReceipt = "";

        // Loop logic variables
        char itemChoise;
        bool keepingShopping = true;

        // Tax and Tip variables
        double stateTax = 0.06;
        double countyTax = 0.01;
        double cityTax = 0.01;
        double totalTax = 0.0;
        double tipAmount = 0.0;
        double finalTotal = 0.0;
        char tipChoice;

        // Ask for customer details upfront
        std::cout << "Enter customer name: ";
        std::getline(std::cin, customerName);
        std::cout << "\n";

        std::cout << "Are you a member? (Y/N): ";
        std::cin >> memberInput;
        isMember = (memberInput == 'Y' || memberInput == 'y');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << " \n";

        // Main ordering loop
        while (keepingShopping)
        {
            std::cout << "---------------------------------------------\n";
            std::cout << std::left << std::setw(18) << "Drink Options"
                << std::setw(12) << "Small (s)"
                << std::setw(12) << "Medium (m)"
                << std::setw(12) << "Large (l)" << "\n";

            std::cout << std::left << std::setw(18) << "A) Coke"
                << std::setw(12) << "$1.00"
                << std::setw(12) << "$1.50"
                << std::setw(12) << "$2.00" << "\n";
            std::cout << std::left << std::setw(18) << "B) Pepsi"
                << std::setw(12) << "$1.00"
                << std::setw(12) << "$1.50"
                << std::setw(12) << "$2.00" << "\n";
            std::cout << std::left << std::setw(18) << "C) Sprite"
                << std::setw(12) << "$1.00"
                << std::setw(12) << "$1.50"
                << std::setw(12) << "$2.00" << "\n";
            std::cout << std::left << std::setw(18) << "D) Fanta"
                << std::setw(12) << "$1.00"
                << std::setw(12) << "$1.50"
                << std::setw(12) << "$2.00" << "\n";
            std::cout << std::left << std::setw(18) << "E) Checkout" << "\n";
            std::cout << "---------------------------------------------\n";

            // 1. Menu Choice Input Validation Loop
            while (true)
            {
                std::cout << "Select an option (A, B, C, D, or E to Checkout): ";
                std::cin >> itemChoise;
                std::cout << "\n";

                if (itemChoise == 'A' || itemChoise == 'a' ||
                    itemChoise == 'B' || itemChoise == 'b' ||
                    itemChoise == 'C' || itemChoise == 'c' ||
                    itemChoise == 'D' || itemChoise == 'd' ||
                    itemChoise == 'E' || itemChoise == 'e')
                {
                    break;
                }
                std::cout << "Invalid menu choice! Please select a letter from A to E.\n\n";
            }

            // If user chose Checkout, break the main loop immediately
            if (itemChoise == 'E' || itemChoise == 'e')
            {
                keepingShopping = false;
                continue;
            }

            // 2. Size Choice Input Validation Loop
            char sizeChoice;
            std::string sizeName;
            while (true)
            {
                std::cout << "Select a size (s, m, l): ";
                std::cin >> sizeChoice;

                if (sizeChoice == 's' || sizeChoice == 'S') { sizeName = "Small"; break; }
                if (sizeChoice == 'm' || sizeChoice == 'M') { sizeName = "Medium"; break; }
                if (sizeChoice == 'l' || sizeChoice == 'L') { sizeName = "Large"; break; }

                std::cout << "Invalid size choice! Please select s, m, or l.\n\n";
            }

            // Assign core metrics based on drink selection
            std::string foodName;
            double unitPrice = 0.0;
            int drinkBase = 0;

            if (itemChoise == 'A' || itemChoise == 'a')
            {
                foodName = "Coke";
                drinkBase = 0;
                if (sizeChoice == 's' || sizeChoice == 'S') unitPrice = 1.00;
                else if (sizeChoice == 'm' || sizeChoice == 'M') unitPrice = 1.50;
                else if (sizeChoice == 'l' || sizeChoice == 'L') unitPrice = 2.00;
            }
            else if (itemChoise == 'B' || itemChoise == 'b')
            {
                foodName = "Pepsi";
                drinkBase = 3;
                if (sizeChoice == 's' || sizeChoice == 'S') unitPrice = 1.00;
                else if (sizeChoice == 'm' || sizeChoice == 'M') unitPrice = 1.50;
                else if (sizeChoice == 'l' || sizeChoice == 'L') unitPrice = 2.00;
            }
            else if (itemChoise == 'C' || itemChoise == 'c')
            {
                foodName = "Sprite";
                drinkBase = 6;
                if (sizeChoice == 's' || sizeChoice == 'S') unitPrice = 1.00;
                else if (sizeChoice == 'm' || sizeChoice == 'M') unitPrice = 1.50;
                else if (sizeChoice == 'l' || sizeChoice == 'L') unitPrice = 2.00;
            }
            else if (itemChoise == 'D' || itemChoise == 'd')
            {
                foodName = "Fanta";
                drinkBase = 9;
                if (sizeChoice == 's' || sizeChoice == 'S') unitPrice = 1.00;
                else if (sizeChoice == 'm' || sizeChoice == 'M') unitPrice = 1.50;
                else if (sizeChoice == 'l' || sizeChoice == 'L') unitPrice = 2.00;
            }

            // 3. Item Quantity Input Validation Loop
            int itemQuantity;
            while (true)
            {
                std::cout << "\n";
                std::cout << "Enter item quantity: ";
                std::cin >> itemQuantity;
                std::cout << "\n";

                if (std::cin.fail() || itemQuantity <= 0)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid quantity! Please enter a whole number greater than 0.\n\n";
                }
                else
                {
                    break;
                }
            }
            std::cout << " \n";

            // Update inventory tracking array
            int sizeOffset = 0;
            if (sizeChoice == 'm' || sizeChoice == 'M') sizeOffset = 1;
            else if (sizeChoice == 'l' || sizeChoice == 'L') sizeOffset = 2;

            int inventoryIndex = drinkBase + sizeOffset;
            changeInventory[inventoryIndex] -= itemQuantity;

            // Process running totals
            double itemSubtotal = itemQuantity * unitPrice;
            finalOrderTotal += itemSubtotal;

            // Append line item to the text log
            itemizedReceipt += std::to_string(itemQuantity) + "x " + sizeName + " " + foodName + " - $" + std::to_string(itemSubtotal) + "\n";

            std::cout << "Added " << itemQuantity << "x " << foodName << " to your order.\n\n";
        }

        // Wrap up data processing before checkout printout
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter cashier notes: ";
        std::getline(std::cin, cashierNotes);
        std::cout << " \n";

        // Compute potential membership discount
        double finalPriceWithDiscount = finalOrderTotal;
        if (isMember)
        {
            finalPriceWithDiscount = finalOrderTotal * 0.90;
        }

        // Calculate total tax based on post-discount price
        totalTax = finalPriceWithDiscount * (stateTax + countyTax + cityTax);

        // Quick console ask for tip
        std::cout << "Would you like to add a tip? (Y/N): ";
        std::cin >> tipChoice;
        if (tipChoice == 'Y' || tipChoice == 'y') {
            std::cout << "Enter tip amount ($): ";
            std::cin >> tipAmount;
        }

        finalTotal = finalPriceWithDiscount + totalTax + tipAmount;

        // Render console receipt and write to receipt.txt simultaneously
        std::ofstream receipt_fout("receipt.txt", std::ios::app);

        // Header
        std::cout << "\n===============================\n";
        std::cout << "Store Receipt\n";
        std::cout << "Customer Name: " << customerName << "\n";
        std::cout << "===============================\n";

        if (receipt_fout.is_open()) {
            receipt_fout << "\n===============================\n";
            receipt_fout << "Store Receipt\n";
            receipt_fout << "Customer Name: " << customerName << "\n";
            receipt_fout << "===============================\n";
        }

        // Items Ordered
        std::cout << "Items Ordered:\n" << itemizedReceipt;
        std::cout << "===============================\n";
        if (receipt_fout.is_open()) {
            receipt_fout << "Items Ordered:\n" << itemizedReceipt;
            receipt_fout << "===============================\n";
        }

        // Financials
        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::left << std::setw(18) << "Order Subtotal:" << "$" << finalOrderTotal << "\n";
        std::cout << std::left << std::setw(18) << "Member Status:"
            << (isMember ? "Yes (10% Discount Applied)" : "No") << "\n";
        std::cout << std::left << std::setw(18) << "Tax Charged:" << "$" << totalTax << "\n";
        std::cout << std::left << std::setw(18) << "Tip Added:" << "$" << tipAmount << "\n";
        std::cout << std::left << std::setw(18) << "Total Due:" << "$" << finalTotal << "\n";

        if (receipt_fout.is_open()) {
            receipt_fout << std::fixed << std::setprecision(2);
            receipt_fout << std::left << std::setw(18) << "Order Subtotal:" << "$" << finalOrderTotal << "\n";
            receipt_fout << std::left << std::setw(18) << "Member Status:"
                << (isMember ? "Yes (10% Discount Applied)" : "No") << "\n";
            receipt_fout << std::left << std::setw(18) << "Tax Charged:" << "$" << totalTax << "\n";
            receipt_fout << std::left << std::setw(18) << "Tip Added:" << "$" << tipAmount << "\n";
            receipt_fout << std::left << std::setw(18) << "Total Due:" << "$" << finalTotal << "\n";
        }

        // Loyalty Points
        int loyaltyPoints = static_cast<int>(finalTotal / 3);
        std::cout << "Loyalty Points: ";
        for (int i = 0; i < loyaltyPoints; i++) {
            std::cout << "*";
        }
        std::cout << "\n";

        if (receipt_fout.is_open()) {
            receipt_fout << "Loyalty Points: ";
            for (int i = 0; i < loyaltyPoints; i++) {
                receipt_fout << "*";
            }
            receipt_fout << "\n";
        }

        // Notes & Footer
        if (!cashierNotes.empty()) {
            std::cout << "Notes: " << cashierNotes << "\n";
            if (receipt_fout.is_open()) {
                receipt_fout << "Notes: " << cashierNotes << "\n";
            }
        }
        std::cout << "===============================\n";
        if (receipt_fout.is_open()) {
            receipt_fout << "===============================\n\n";
            receipt_fout.close();
        }

        grandTotalSales += finalTotal;
        TotalCustomers++;

        std::cout << "Is there another customer? (Y/N): ";
        std::cin >> anotherCustomer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Daily Sales Summary
    std::cout << "\n======== Daily Sales Summary ========\n";
    std::cout << "Total Customers: " << TotalCustomers << "\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total Sales: $" << grandTotalSales << "\n";
    std::cout << "=====================================\n";

    // Daily Inventory Log
    std::cout << "\nDaily Inventory\n";
    std::cout << std::left << std::setw(25) << "Item"
        << std::setw(10) << "Start"
        << std::setw(10) << "Change"
        << std::setw(10) << "End" << "\n";

    for (int i = 0; i < 12; i++) {
        int endInventory = startInventory[i] + changeInventory[i];
        std::cout << std::left << std::setw(25) << itemNames[i]
            << std::setw(10) << startInventory[i]
            << std::setw(10) << changeInventory[i]
            << std::setw(10) << endInventory << "\n";
    }
    std::cout << "=================================================\n";

    return 0;
}
