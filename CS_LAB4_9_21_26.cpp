#include <iomanip>
#include <string>
#include <iostream>

int main()
{
    std::string foodName;
	int itemQuantity;
    double unitPrice;
    char memberInput;
    bool isMember;
	std::string cashierNotes;
	char itemChoise;
	char sizeChoice;
	std::string sizeName;

	std::cout << "-----------------------------------\n";
	std::cout << std::left << std::setw(18) << "Drink"
		<< std::setw(12) << "Small (s)"
		<< std::setw(12) << "Medium (m)"
		<< std::setw(12) << "Large (l)" << "\n";

	std::cout << std::left << std::setw(18) << "Coke"
		<< std::setw(12) << "$1.00"
		<< std::setw(12) << "$1.50"
		<< std::setw(12) << "$2.00" << "\n";
	std::cout << std::left << std::setw(18) << "Pepsi"
		<< std::setw(12) << "$1.00"
		<< std::setw(12) << "$1.50"
		<< std::setw(12) << "$2.00" << "\n";
	std::cout << std::left << std::setw(18) << "Sprite"
		<< std::setw(12) << "$1.00"
		<< std::setw(12) << "$1.50"
		<< std::setw(12) << "$2.00" << "\n";
	std::cout << std::left << std::setw(18) << "Fanta"
		<< std::setw(12) << "$1.00"
		<< std::setw(12) << "$1.50"
		<< std::setw(12) << "$2.00" << "\n";
	std::cout << "-----------------------------------\n";

	std::cout << "Select an option (Coke, Pepsi, Sprite, Fanta): ";
	std::cin >> itemChoise;

	std::cout << " \n";
	std::cout << "Select a size (s, m, l): ";
	std::cin >> sizeChoice;
	std::cout << " \n";

	if (itemChoise == 'A' || itemChoise == 'a')
	{ 
		foodName = "Coke";
		if (sizeChoice == 's' || sizeChoice == 'S')
		{
			unitPrice = 1.00;
		}
		else if (sizeChoice == 'm' || sizeChoice == 'M')
		{
			unitPrice = 1.50;
		}
		else if (sizeChoice == 'l' || sizeChoice == 'L')
		{
			unitPrice = 2.00;
		}
		else { std::cout << "Invalid size choice. Defaulting to Small.\n";
			unitPrice = 1.00;	

		}
	}
	else if (itemChoise == 'B' || itemChoise == 'b')
	{
		foodName = "Pepsi";
		if (sizeChoice == 's' || sizeChoice == 'S')
		{
			unitPrice = 1.00;
		}
		else if (sizeChoice == 'm' || sizeChoice == 'M')
		{
			unitPrice = 1.50;
		}
		else if (sizeChoice == 'l' || sizeChoice == 'L')
		{
			unitPrice = 2.00;
		}
		else {
			std::cout << "Invalid size choice. Defaulting to Small.\n";
			unitPrice = 1.00;
		}
	}
	else if (itemChoise == 'C' || itemChoise == 'c')
	{
		foodName = "Sprite";
		if (sizeChoice == 's' || sizeChoice == 'S')
		{
			unitPrice = 1.00;
		}
		else if (sizeChoice == 'm' || sizeChoice == 'M')
		{
			unitPrice = 1.50;
		}
		else if (sizeChoice == 'l' || sizeChoice == 'L')
		{
			unitPrice = 2.00;
		}
		else {
			std::cout << "Invalid size choice. Defaulting to Small.\n";
			unitPrice = 1.00;
		}
	}
	else if (itemChoise == 'D' || itemChoise == 'd')
	{
		foodName = "Fanta";
		if (sizeChoice == 's' || sizeChoice == 'S')
		{
			unitPrice = 1.00;
		}
		else if (sizeChoice == 'm' || sizeChoice == 'M')
		{
			unitPrice = 1.50;
		}
		else if (sizeChoice == 'l' || sizeChoice == 'L')
		{
			unitPrice = 2.00;
		}
		else {
			std::cout << "Invalid size choice. Defaulting to Small.\n";
			unitPrice = 1.00;
		}
	}
	else
	{
		std::cout << "Invalid item choice.\n";
		return 1;
	}

	std::cout << "Enter item quantity: ";
	std::cin >> itemQuantity;
	std::cout << " \n";

	std::cout << "Are you a member? (Y/N): ";
	std::cin >> memberInput;
	isMember = (memberInput == 'Y' || memberInput == 'y');
	std::cin.ignore();
	std::cout << " \n";

	std::cout << "Enter cashier notes: ";
	std::getline(std::cin, cashierNotes);
	std::cout << " \n";

	double totalPrice = itemQuantity * unitPrice;
	if (isMember)
	{
		totalPrice = totalPrice * 0.90;
	}


	std::cout << "\n===============================\n";
	std::cout << "Store Receipt\n";
	std::cout << "===============================\n";

	std::cout << std::left << std::setw(15) << "Item Name:" << foodName << "\n";
	std::cout << std::left << std::setw(15) << "Item Quantity:" << itemQuantity << "\n";

	std::cout << std::fixed << std::setprecision(2);
	std::cout << std::left << std::setw(15) << "Unit Price:" << "$" << unitPrice << "\n";
	std::cout << std::left << std::setw(15) << "Total Price:" << "$" << totalPrice << "\n";

	std::cout << std::left << std::setw(15) << "Member Status:"
		<< (isMember ? "Yes (Discount Eligible)" : "No") << "\n";

	std::cout << "===============================\n";

	std::cout << "Inventory Audit\n";

	std::cout << std::left
		<< std::setw(20) << "Item Name"
		<< std::setw(15) << "Quanity"
		<< std::setw(15) << "Unit Price" << "\n";

	std::cout << std::left
		<< std::setw(20) << foodName
		<< std::setw(15) << itemQuantity
		<< std::setw(15) << unitPrice << "\n";

	return 0;
}

