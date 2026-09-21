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

	double totalPrice = itemQuantity * unitPrice;

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

	return 0;
}

