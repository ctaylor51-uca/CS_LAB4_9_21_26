#include <iomanip>
#include <string>
#include <iostream>
#include <limits>
#include <fstream>

int main()
{
	std::string food1, food2, food3, food4;

	double food1Sm, food1Med, food1Lg;
	double food2Sm, food2Med, food2Lg;
	double food3Sm, food3Med, food3Lg;
	double food4Sm, food4Med, food4Lg;

	std::ifstream menuFile("menu.txt");

	if (!menuFile)
	{
		std::cout << "Error opening menu file!\n";
		return 1;
	}

	std::getline(menuFile, food1);
	menuFile >> food1Sm >> food1Med >> food1Lg;
	menuFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::getline(menuFile, food2);
	menuFile >> food2Sm >> food2Med >> food2Lg;
	menuFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::getline(menuFile, food3);
	menuFile >> food3Sm >> food3Med >> food3Lg;
	menuFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::getline(menuFile, food4);
	menuFile >> food4Sm >> food4Med >> food4Lg;

	menuFile.close();


	// Global receipt and tracking variables
	double grandTotalSales = 0.0;
	int TotalCustomers = 0;
	char anotherCustomer = 'Y';

	while (anotherCustomer == 'Y' || anotherCustomer == 'y')
	{


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

		std::cout << std::fixed << std::setprecision(2);

		std::cout << std::left << std::setw(18) << ("A) " + food1)
			<< "$" << std::setw(11) << food1Sm
			<< "$" << std::setw(11) << food1Med
			<< "$" << food1Lg << "\n";

		std::cout << std::left << std::setw(18) << ("B) " + food2)
			<< "$" << std::setw(11) << food2Sm
			<< "$" << std::setw(11) << food2Med
			<< "$" << food2Lg << "\n";

		std::cout << std::left << std::setw(18) << ("C) " + food3)
			<< "$" << std::setw(11) << food3Sm
			<< "$" << std::setw(11) << food3Med
			<< "$" << food3Lg << "\n";

		std::cout << std::left << std::setw(18) << ("D) " + food4)
			<< "$" << std::setw(11) << food4Sm
			<< "$" << std::setw(11) << food4Med
			<< "$" << food4Lg << "\n";



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
			foodName = food1;
			if (sizeChoice == 's' || sizeChoice == 'S') unitPrice = food1Sm;
			else if (sizeChoice == 'm' || sizeChoice == 'M') unitPrice = food1Med;
			else if (sizeChoice == 'l' || sizeChoice == 'L') unitPrice = food1Lg;
		}
		else if (itemChoise == 'B' || itemChoise == 'b')
		{
			foodName = food2;
			if (sizeChoice == 's' || sizeChoice == 'S') unitPrice = food2Sm;
			else if (sizeChoice == 'm' || sizeChoice == 'M') unitPrice = food2Med;
			else if (sizeChoice == 'l' || sizeChoice == 'L') unitPrice = food2Lg;
		}
		else if (itemChoise == 'C' || itemChoise == 'c')
		{
			foodName = food3;
			if (sizeChoice == 's' || sizeChoice == 'S') unitPrice = food3Sm;
			else if (sizeChoice == 'm' || sizeChoice == 'M') unitPrice = food3Med;
			else if (sizeChoice == 'l' || sizeChoice == 'L') unitPrice = food3Lg;
		}
		else if (itemChoise == 'D' || itemChoise == 'd')
		{
			foodName = food4;
			if (sizeChoice == 's' || sizeChoice == 'S') unitPrice = food4Sm;
			else if (sizeChoice == 'm' || sizeChoice == 'M') unitPrice = food4Med;
			else if (sizeChoice == 'l' || sizeChoice == 'L') unitPrice = food4Lg;
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
		itemizedReceipt += std::to_string(itemQuantity) + "x " + sizeName + " " + foodName + "$ " + std::to_string(itemSubtotal) + "\n";


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

	int loyaltyPoints = static_cast<int>(finalPriceWithDiscount / 3);
	std::cout << "Loyalty Points: ";

	for (int i = 0; i < loyaltyPoints; i++) {
		std::cout << "*";
	}
	std::cout << "\n";

	if (!cashierNotes.empty()) {
		std::cout << "Notes: " << cashierNotes << "\n";
	}
	std::cout << "===============================\n";
	grandTotalSales += finalPriceWithDiscount;
	TotalCustomers++;

	std::cout << "Is there another customer? (Y/N): ";
	std::cin >> anotherCustomer;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::cout << "\n======== Daily Sales Summary ========\n";
std::cout << "Total Customers: " << TotalCustomers << "\n";
std::cout << std::fixed << std::setprecision(2);
std::cout << "Total Sales: $" << grandTotalSales << "\n";
std::cout << "======================\n";
    return 0;
}
	