#include <iostream>
#include <stdio.h>
using namespace std; //make separate classes for receipt, transactions and currency reserve

int choice = -1;
enum Currency {USD, EUR, GBP, JPY, PLN, CNY, CURRENCY_COUNT};
enum exchange_fee {
	fee,
};

class currency_reserve {
private:
	double reserve[CURRENCY_COUNT];
public:
	currency_reserve() {
		reserve[USD] = 5000;
		reserve[EUR] = 10000;
		reserve[GBP] = 4000;
		reserve[JPY] = 100000;
		reserve[PLN] = 10000;
		reserve[CNY] = 200000;
	}
	void show_reserve() {
		cout << "USD: " << reserve[USD] << endl;
		cout << "EUR: " << reserve[EUR] << endl;
		cout << "GBP: " << reserve[GBP] << endl;
		cout << "JPY: " << reserve[JPY] << endl;
		cout << "PLN: " << reserve[PLN] << endl;
		cout << "CNY: " << reserve[CNY] << endl;
	}
	bool has_reserve(Currency c, double amount) {
		return reserve[c] >= amount;
	}
};

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
private:
	currency_reserve* reserve;
public: // change from public to only what cashier needs to access
	cashier(currency_reserve* r) : reserve(r) {}
	void cashier_profile() {
		while (choice != 0) {
			cout << "press 1 if you want to make a transaction\n" << "press 2 if you want to create a daily summary\n" << "press 3 if you want to print a receipt\n" <<  "press 4 if you want to see the reserve\n" << "Press 0 to return to main menu" << endl;
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
			case 4:
				reserve->show_reserve();
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

class transaction {
public:  //correct permissions, who can access etc
	void convertToEur() { //see tuleb ringi teha, nii et kasutad enum Currency-t
		cout << "Choose the currency you want to exchange from\n" << "press 1 for EUR\n" << "Press 2 for USD\n" << "Press 3 for Pounds" << endl;
		cin >> choice;
		double rateToEur = 0;
		while (choice != 0) {  // vaata ule kas see while(true) loop sobib siia ikka???
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
	currency_reserve reserve;
	while (true) {
		main_menu();
		switch (choice) {
		case 1: {
			cout << "Cashier profile selected" << endl;
			cashier c(&reserve);
			c.cashier_profile();
			break;
        }
		case 2: {
			cout << "Manager profile selected" << endl;
			manager m;
			m.manager_profile();
			break;
        }
		case 0:
			return 0;
		default:
			cout << "Invalid option, please try again" << endl;
			continue;
		}
	}
}
