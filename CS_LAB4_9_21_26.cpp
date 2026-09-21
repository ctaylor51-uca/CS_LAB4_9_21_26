#include <iomanip>
#include <string>
#include <iostream>

int main()
{
    std::string foodName;
	char itemCode;
	int itemQuantity;
    double unitPrice;
    char memberInput;
    bool isMember;
	std::string cashierNotes;

	std::cout << "Enter food name: ";
	std::getline(std::cin, foodName);

	std::cout << "Enter item code (single character): ";
	std::cin >> itemCode;

	std::cout << "Enter item quantity: ";
	std::cin >> itemQuantity;

	std::cout << "Enter unit price: $";
	std::cin >> unitPrice;

	std::cout << "Are you a member? (Y/N): ";
	std::cin >> memberInput;
	isMember = (memberInput == 'Y' || memberInput == 'y');
	std::cin.ignore();

	std::cout << "Enter cashier notes: ";
	std::getline(std::cin, cashierNotes);

	double totalPrice = itemQuantity * unitPrice;
	if (isMember)
	{
		totalPrice = totalPrice * 0.90;
	}


	std::cout << "\n===============================\n";
	std::cout << "Store Receipt\n";
	std::cout << "===============================\n";

	std::cout << std::left << std::setw(15) << "Item Name:" << foodName << "\n";
	std::cout << std::left << std::setw(15) << "Item Code:" << itemCode << "\n";
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
		<< std::setw(15) << "Item Code"
		<< std::setw(15) << "Quanity"
		<< std::setw(15) << "Unit Price" << "\n";

	std::cout << std::left
		<< std::setw(20) << foodName
		<< std::setw(15) << itemCode
		<< std::setw(15) << itemQuantity
		<< std::setw(15) << unitPrice << "\n";

	return 0;
}

