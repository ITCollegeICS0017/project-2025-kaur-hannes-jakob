#include <stdio.h>

enum Currency { 
	USD, 
	EUR, 
	GBP,
	JPY,
	PLN,
	CNY,
};

struct Transaction {
	int id;
	double amount;
	Currency currency;
};

class Cashier {
public:
	void processTransaction() {
		std::cout << "Processing transaction..." << std::endl;
	}
};

class Manager {
	public:
	void manageFees() {
		std::cout << "Changing the fee..." << std::endl;
	}
};

class Receipt {
public:
	void printReceipt() {
		std::cout << "Receipt printed." << std::endl;
	}
};