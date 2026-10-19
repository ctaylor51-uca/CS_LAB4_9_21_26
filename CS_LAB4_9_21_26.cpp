#include <iomanip>
#include <string>
#include <iostream>
#include <limits>
#include <fstream> 
#include <sstream>

// ==========================================
// FUNCTION DECLARATIONS (PROTOTYPES)
// ==========================================
void displayMenu();
char getChoice();
char getSize();
int getQuantity();
void processDrinkSelection(char itemChoice, char sizeChoice, std::string& foodName, std::string& sizeName, double& unitPrice, int& drinkBase);
void updateInventoryAndReceipt(int drinkBase, char sizeChoice, int itemQuantity, double unitPrice, int changeInventory[], double& finalOrderTotal, std::string& itemizedReceipt, std::string foodName, std::string sizeName);
double handleTipSelection(double subTotal);
std::string calculateReceipt(double subTotal, double tip, std::string name, std::string itemizedReceipt, bool isMember, double& finalTotalWithTax);
void printToFile(std::string fileName, std::string text);

// ==========================================
// MAIN PROGRAM
// ==========================================
int main()
{
    char anotherCustomer = 'Y';
    double grandTotalSales = 0.0;
    int totalCustomers = 0;

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
        std::string customerName;
        double finalOrderTotal = 0.0;
        char memberInput;
        bool isMember = false;
        std::string itemizedReceipt = "";
        bool keepingShopping = true;

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
            displayMenu();
            char itemChoice = getChoice();

            // If user chose Checkout, break the main loop immediately
            if (itemChoice == 'E' || itemChoice == 'e')
            {
                keepingShopping = false;
                continue;
            }

            char sizeChoice = getSize();

            // Variables to be populated by the processing function
            std::string foodName = "";
            std::string sizeName = "";
            double unitPrice = 0.0;
            int drinkBase = 0;

            processDrinkSelection(itemChoice, sizeChoice, foodName, sizeName, unitPrice, drinkBase);

            int itemQuantity = getQuantity();

            // Update inventory tracking and running receipt metrics
            updateInventoryAndReceipt(drinkBase, sizeChoice, itemQuantity, unitPrice, changeInventory, finalOrderTotal, itemizedReceipt, foodName, sizeName);
        }

        // Process financial wrap-up if an order was placed
        if (finalOrderTotal > 0.0)
        {
            double tipAmount = handleTipSelection(finalOrderTotal);
            double finalTotalWithTax = 0.0;

            // Generate full layout text
            std::string fullReceiptText = calculateReceipt(finalOrderTotal, tipAmount, customerName, itemizedReceipt, isMember, finalTotalWithTax);

            // Print layout directly to screen console
            std::cout << fullReceiptText << "\n";

            // Print the layout out directly to "receipt.txt" file
            printToFile("receipt.txt", fullReceiptText);

            grandTotalSales += finalTotalWithTax;
            totalCustomers++;
        }
        else
        {
            std::cout << "No items ordered. Transaction canceled.\n\n";
        }

        // Check if another customer needs service
        std::cout << "Process another customer? (Y/N): ";
        std::cin >> anotherCustomer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n";
    }

    // Print final day-end summary reports
    std::cout << "=========================================\n";
    std::cout << "            DAILY SALES REPORT           \n";
    std::cout << "=========================================\n";
    std::cout << "Total Customers Served: " << totalCustomers << "\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Grand Total Revenue:    $" << grandTotalSales << "\n";
    std::cout << "=========================================\n";

    return 0;
}

// ==========================================
// FUNCTION IMPLEMENTATIONS & DOCUMENTATION
// ==========================================

void displayMenu()
{
    std::cout << "---------------------------------------------\n";
    std::cout << std::left << std::setw(18) << "Drink Options"
        << std::setw(12) << "Small (s)"
        << std::setw(12) << "Medium (m)"
        << std::setw(12) << "Large (l)" << "\n";

    std::cout << std::left << std::setw(18) << "A) Coke" << std::setw(12) << "$1.00" << std::setw(12) << "$1.50" << std::setw(12) << "$2.00" << "\n";
    std::cout << std::left << std::setw(18) << "B) Pepsi" << std::setw(12) << "$1.00" << std::setw(12) << "$1.50" << std::setw(12) << "$2.00" << "\n";
    std::cout << std::left << std::setw(18) << "C) Sprite" << std::setw(12) << "$1.00" << std::setw(12) << "$1.50" << std::setw(12) << "$2.00" << "\n";
    std::cout << std::left << std::setw(18) << "D) Fanta" << std::setw(12) << "$1.00" << std::setw(12) << "$1.50" << std::setw(12) << "$2.00" << "\n";
    std::cout << std::left << std::setw(18) << "E) Checkout" << "\n";
    std::cout << "---------------------------------------------\n";
}

char getChoice()
{
    char choice;
    while (true)
    {
        std::cout << "Select an option (A, B, C, D, or E to Checkout): ";
        std::cin >> choice;
        std::cout << "\n";

        if (choice == 'A' || choice == 'a' || choice == 'B' || choice == 'b' ||
            choice == 'C' || choice == 'c' || choice == 'D' || choice == 'd' ||
            choice == 'E' || choice == 'e')
        {
            return choice;
        }
        std::cout << "Invalid menu choice! Please select a letter from A to E.\n\n";
    }
}

char getSize()
{
    char sizeChoice;
    while (true)
    {
        std::cout << "Select a size (s, m, l): ";
        std::cin >> sizeChoice;

        if (sizeChoice == 's' || sizeChoice == 'S' ||
            sizeChoice == 'm' || sizeChoice == 'M' ||
            sizeChoice == 'l' || sizeChoice == 'L')
        {
            return sizeChoice;
        }

        std::cout << "Invalid size choice! Please select s, m, or l.\n\n";
    }
}

int getQuantity()
{
    int quantity;
    while (true)
    {
        std::cout << "Enter item quantity: ";
        std::cin >> quantity;
        std::cout << "\n";

        if (std::cin.fail() || quantity <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid quantity! Please enter a whole number greater than 0.\n\n";
        }
        else
        {
            return quantity;
        }
    }
}

void processDrinkSelection(char itemChoice, char sizeChoice, std::string& foodName, std::string& sizeName, double& unitPrice, int& drinkBase)
{
    if (sizeChoice == 's' || sizeChoice == 'S') sizeName = "Small";
    else if (sizeChoice == 'm' || sizeChoice == 'M') sizeName = "Medium";
    else if (sizeChoice == 'l' || sizeChoice == 'L') sizeName = "Large";

    if (itemChoice == 'A' || itemChoice == 'a')
    {
        foodName = "Coke";
        drinkBase = 0;
    }
    else if (itemChoice == 'B' || itemChoice == 'b')
    {
        foodName = "Pepsi";
        drinkBase = 3;
    }
    else if (itemChoice == 'C' || itemChoice == 'c')
    {
        foodName = "Sprite";
        drinkBase = 6;
    }
    else if (itemChoice == 'D' || itemChoice == 'd')
    {
        foodName = "Fanta";
        drinkBase = 9;
    }

    if (sizeChoice == 's' || sizeChoice == 'S') {
        unitPrice = 1.00;
    }
    else if (sizeChoice == 'm' || sizeChoice == 'M') {
        unitPrice = 1.50;
    }
    else if (sizeChoice == 'l' || sizeChoice == 'L') {
        unitPrice = 2.00;
    }
}

void updateInventoryAndReceipt(int drinkBase, char sizeChoice, int itemQuantity, double unitPrice, int changeInventory[], double& finalOrderTotal, std::string& itemizedReceipt, std::string foodName, std::string sizeName)
{
    int sizeOffset = 0;
    if (sizeChoice == 'm' || sizeChoice == 'M') sizeOffset = 1;
    else if (sizeChoice == 'l' || sizeChoice == 'L') sizeOffset = 2;

    int itemIndex = drinkBase + sizeOffset;
    changeInventory[itemIndex] += itemQuantity;

    double lineTotal = unitPrice * itemQuantity;
    finalOrderTotal += lineTotal;

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << sizeName << " " << foodName << " x" << itemQuantity << " @ $" << unitPrice << " = $" << lineTotal << "\n";
    itemizedReceipt += oss.str();
}

double handleTipSelection(double subTotal)
{
    double tip = 0.0;
    char choice;
    std::cout << "Would you like to leave a tip? (Y/N): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 'Y' || choice == 'y')
    {
        int tipPercent;
        std::cout << "Enter tip percentage (e.g., 10, 15, 20): ";
        std::cin >> tipPercent;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        tip = subTotal * (tipPercent / 100.0);
    }
    return tip;
}

std::string calculateReceipt(double subTotal, double tip, std::string name, std::string itemizedReceipt, bool isMember, double& finalTotalWithTax)
{
    double discount = isMember ? (subTotal * 0.10) : 0.0;
    double taxableAmount = subTotal - discount;
    double tax = taxableAmount * 0.08;
    finalTotalWithTax = taxableAmount + tax + tip;

    std::ostringstream receipt;
    receipt << std::fixed << std::setprecision(2);
    receipt << "\n=========================================\n";
    receipt << "                 RECEIPT                 \n";
    receipt << "=========================================\n";
    receipt << "Customer: " << name << "\n";
    receipt << (isMember ? "Status: Member (10% Discount Applied)\n" : "Status: Non-Member\n");
    receipt << "-----------------------------------------\n";
    receipt << itemizedReceipt;
    receipt << "-----------------------------------------\n";
    receipt << "Subtotal:        $" << subTotal << "\n";
    if (isMember) {
        receipt << "Discount:       -$" << discount << "\n";
    }
    receipt << "Tax (8%):        $" << tax << "\n";
    receipt << "Tip:             $" << tip << "\n";
    receipt << "=========================================\n";
    receipt << "TOTAL DUE:       $" << finalTotalWithTax << "\n";
    receipt << "=========================================\n";

    return receipt.str();
}

void printToFile(std::string fileName, std::string text)
{
    std::ofstream outFile(fileName, std::ios::app);
    if (outFile.is_open())
    {
        outFile << text << "\n";
        outFile.close();
    }
}