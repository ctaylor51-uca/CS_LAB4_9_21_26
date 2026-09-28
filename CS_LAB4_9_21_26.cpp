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
	double stateTax;
	double countyTax;
	double cityTax;
	double totalTax;
	double tipAmount = 0.0;
	double finalTotal;
	char tipChoice;

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
	stateTax = totalPrice * 0.065;
	countyTax = totalPrice * 0.005;
	cityTax = totalPrice * 0.02125;

	totalTax = stateTax + countyTax + cityTax;
	std::cout << std::fixed << std::setprecision(2);

	std::cout << "\nTaxes\n";
	std::cout << std::left
		<< std::setw(25) << "Tax Name"
		<< std::setw(15) << "Percentage"
		<< "Amount\n";

	std::cout << std::setw(25) << "Arkansas State Tax"
		<< std::setw(15) << "6.5%"
		<< "$" << stateTax << "\n";

	std::cout << std::setw(25) << "Faulkner County Tax"
		<< std::setw(15) << "0.5%"
		<< "$" << countyTax << "\n";

	std::cout << std::setw(25) << "Conway Municipal Tax"
		<< std::setw(15) << "2.125%"
		<< "$" << cityTax << "\n";

	std::cout << "Tip Selection";
	std::cout << std::setw(15) << "Amount\n";

	std::cout << std::left << std::setw(20) << "A. 15%"
		<< "$" << totalPrice * 0.15 << "\n";
	
	std::cout << std::left << std::setw(20) << "B. 20%"
		<< "$" << totalPrice * 0.20 << "\n";

	std::cout << std::left << std::setw(20) << "A. 25%"
		<< "$" << totalPrice * 0.25 << "\n";

	std::cout << "D. Other Amount\n";

	std::cout << "What tip do you choose?";
	std::cin >> tipChoice; 

	if (tipChoice == 'A' || tipChoice == 'a')
	{
		tipAmount = totalPrice * 0.15;
	}
	else if (tipChoice == 'B' || tipChoice == 'b')
	{
		tipAmount = totalPrice * 0.20;
	}

	else if (tipChoice == 'C' || tipChoice == 'c')
	{
		tipAmount = totalPrice * 0.25;
	}

	else if (tipChoice == 'D' || tipChoice == 'd')
	{
		std::cout << "How much would you like to tip?";
		std::cin >> tipAmount;
	}
	else
	{
		std::cout << "Invalid";
		tipAmount = 0.0;
	}

	finalTotal = totalPrice + totalTax + tipAmount;
	std::cout << "Subtotal: $" << totalPrice << "\n";
	std::cout << "Total Tax: $" << totalTax << "\n";
	std::cout << "Tip: $" << tipAmount << "\n";
	std::cout << "Total Amount: $" << finalTotal << "\n";

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

