#include <iostream>
using namespace std; //make separate classes for receipt, transactions and currency reserve

int choice;
class manager {
public:  //change from public to only what manager needs to access
	void manager_profile() {
		while (choice != 0) {
			cout << "press 1 to view reports\n" << "press 2 to manage employees\n" << "press 3 if you want to end the day\n" << "Press 0 to return to main menu" << endl;
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "REPORTS:\n";  //special function or class for reports later on
				break;
			case 2:
				cout << "EMPLOYEE BONUS\n";
				break;
			case 3:
				cout << "are you sure you want to end the day?\n"; //this needs a function
				break;
			case 0:
				break;
			default:
				cout << "Invalid option, try again!\n";
				continue;
			}
		}
	}
};
class cashier {
public: // change from public to only what cashier needs to access
	void cashier_profile() {
		while (choice != 0) {
			cout << "press 1 if you want to make a transaction\n" << "press 2 if you want to create a daily summary\n" << "press 3 if you want to print a receipt\n" << "Press 0 to return to main menu" << endl;
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "TRANSACTIONS\n";  // separate class for this
				break;
			case 2:
				cout << "DAILY SUMMARY\n"; // separate function for this
				break;
			case 3:
				cout << "RECEIPTS\n"; //separate class for this
				break;
			case 0:
				break;
			default:
				cout << "Invalid option, try again!\n";
				continue;

			}
		}
	}
};

class transaction_calc {
public:  //correct permissions, who can access etc
	void convertToEur() {
		cout << "Choose the currency you want to exchange from\m" << "press 1 for EUR\n" << "Press 2 for USD\n" << "Press 3 for Pounds" << endl;
		cin >> choice;
		double rateToEur = 0;
		while (true) {  // vaata ule kas see while(true) loop sobib siia ikka???
			switch (choice) {
			case 1:
				rateToEur = 1.0;
				break;
			case 2:
				rateToEur = 0.85;
				break;
			case 3:
				rateToEur = 1.15;
				break;
			default:
				cout << "Invalid option, try again!" << endl;
				continue;
			}
		}
	}
};

void main_menu() {
	cout << "Select your profile:\n" << "Press 1 for Cashier Profile\n" << "Press 2 for Manager profile\n" << "Press 0 to exit" << endl;
	cin >> choice;
}
int main() {
	while (true) {
		main_menu();
		switch (choice) {
		case 1:
			cout << "Cashier profile selected" << endl;
			cashier c;
			c.cashier_profile();
			break;
		case 2:
			cout << "Manager profile selected" << endl;
			manager m;
			m.manager_profile();
			break;
		case 0:
			return 0;
		default:
			cout << "Invalid option, please try again" << endl;
			continue;
		}
	}
}