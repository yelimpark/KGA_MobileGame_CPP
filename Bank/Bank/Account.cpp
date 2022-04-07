#include "Account.h"
#include <iostream>

Account::Account(int bankAccountNumber, const char* name, int balance)
	:bankAccountNumber(bankAccountNumber), balance(balance)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

int Account::Deposit(int money)
{
	if (money < 0) {
		std::cout << "입금액이 올바르지 않습니다." << std::endl;
		return -1;
	}

	balance += money;
	return 0;
}

int Account::Withdraw(int money)
{
	if (money < 0) {
		std::cout << "출금액이 올바르지 않습니다." << std::endl;
		return -1;
	}
	if (money > balance) {
		std::cout << "계좌의 잔액이 부족합니다." << std::endl;
		return -1;
	}

	balance -= money;
	return 0;
}

void Account::ShowAccountInfo() const
{
	std::cout << "계좌번호 : " << bankAccountNumber << std::endl;
	std::cout << "이 름 : " << name << std::endl;
	std::cout << "잔 액 : " << balance << std::endl;
}

int Account::GetBankAccountNumber() const
{
	return bankAccountNumber;
}

int Account::GetBalance() const
{
	return balance;
}

Account::~Account()
{
	delete []name;
}
