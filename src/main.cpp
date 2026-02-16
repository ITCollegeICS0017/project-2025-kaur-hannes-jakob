#include <stdio.h>
#include <iostream>

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
		std::cout << "Processing transaction...";
	}
};

class Manager {
	public:
	void manageFees() {
		std::cout << "Changing the fee...";
	}
};

class Receipt {
public:
	void printReceipt() {
		std::cout << "Receipt printed.";
	}
};