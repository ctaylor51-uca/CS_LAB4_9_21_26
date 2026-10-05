#include <iomanip>
#include <string>
#include <iostream>
#include <limits>

int main()
{
    // Global receipt and tracking variables
    std::string customerName;
    double finalOrderTotal = 0.0;
    char memberInput;
    bool isMember;
    std::string cashierNotes;

    // String to store the itemized receipt contents
    std::string itemizedReceipt = "";

    // Loop logic variables
    char itemChoise; // Matching your original variable spelling
    bool keepingShopping = true;

    // Ask for customer details upfront
    std::cout << "Enter customer name: ";
    std::getline(std::cin, customerName);
    std::cout << "\n";

    std::cout << "Are you a member? (Y/N): ";
    std::cin >> memberInput;
    isMember = (memberInput == 'Y' || memberInput == 'y');
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
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
                break; // Valid option entered, exit validation loop
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

        if (itemChoise == 'A' || itemChoise == 'a')
        {
            foodName = "Coke";
            if (sizeChoice == 's' || sizeChoice == 'S') unitPrice = 1.00;
            else if (sizeChoice == 'm' || sizeChoice == 'M') unitPrice = 1.50;
            else if (sizeChoice == 'l' || sizeChoice == 'L') unitPrice = 2.00;
        }
        else if (itemChoise == 'B' || itemChoise == 'b')
        {
            foodName = "Pepsi";
            if (sizeChoice == 's' || sizeChoice == 'S') unitPrice = 1.00;
            else if (sizeChoice == 'm' || sizeChoice == 'M') unitPrice = 1.50;
            else if (sizeChoice == 'l' || sizeChoice == 'L') unitPrice = 2.00;
        }
        else if (itemChoise == 'C' || itemChoise == 'c')
        {
            foodName = "Sprite";
            if (sizeChoice == 's' || sizeChoice == 'S') unitPrice = 1.00;
            else if (sizeChoice == 'm' || sizeChoice == 'M') unitPrice = 1.50;
            else if (sizeChoice == 'l' || sizeChoice == 'L') unitPrice = 2.00;
        }
        else if (itemChoise == 'D' || itemChoise == 'd')
        {
            foodName = "Fanta";
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
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
                std::cout << "Invalid quantity! Please enter a whole number greater than 0.\n\n";
            }
            else
            {
                break; // Valid quantity
            }
        }
        std::cout << " \n";

        // Process running totals
        double itemSubtotal = itemQuantity * unitPrice;
        finalOrderTotal += itemSubtotal;

        // Append line item to the text log
        itemizedReceipt += std::to_string(itemQuantity) + "x " + sizeName + " " + foodName + "\n";

        std::cout << "Added " << itemQuantity << "x " << foodName << " to your order.\n\n";
    }

    // Wrap up data processing before checkout printout
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear stream
    std::cout << "Enter cashier notes: ";
    std::getline(std::cin, cashierNotes);
    std::cout << " \n";

    // Compute potential membership discount
    double finalPriceWithDiscount = finalOrderTotal;
    if (isMember)
    {
        finalPriceWithDiscount = finalOrderTotal * 0.90;
    }

    // Render multi-item updated receipt
    std::cout << "\n===============================\n";
    std::cout << "Store Receipt\n";
    std::cout << "Customer Name: " << customerName << "\n";
    std::cout << "===============================\n";

    // Print out the accumulated order history
    std::cout << "Items Ordered:\n" << itemizedReceipt;
    std::cout << "===============================\n";

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::left << std::setw(18) << "Order Subtotal:" << "$" << finalOrderTotal << "\n";
    std::cout << std::left << std::setw(18) << "Member Status:"
        << (isMember ? "Yes (10% Discount Applied)" : "No") << "\n";
    std::cout << std::left << std::setw(18) << "Total Due:" << "$" << finalPriceWithDiscount << "\n";
    if (!cashierNotes.empty()) {
        std::cout << "Notes: " << cashierNotes << "\n";
    }
    std::cout << "===============================\n";

    return 0;
}