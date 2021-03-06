#include <iostream>
#include <cstring>
#include "NameCard.h"

NameCard::NameCard(const char* name, const char componyName[], const char* phoneNumber, int jobGrade)
	:jobGrade(jobGrade)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->componyName = new char[strlen(componyName) + 1];
	strcpy_s(this->componyName, strlen(componyName) + 1, componyName);

	this->phoneNumber = new char[strlen(phoneNumber) + 1];
	strcpy_s(this->phoneNumber, strlen(phoneNumber) + 1, phoneNumber);
}

NameCard::NameCard(const NameCard& copy)
	:jobGrade(copy.jobGrade)
{
	name = new char[strlen(copy.name) + 1];
	strcpy_s(name, strlen(copy.name) + 1, copy.name);

	componyName = new char[strlen(copy.componyName) + 1];
	strcpy_s(componyName, strlen(copy.componyName) + 1, copy.componyName);

	phoneNumber = new char[strlen(copy.phoneNumber) + 1];
	strcpy_s(phoneNumber, strlen(copy.phoneNumber) + 1, copy.phoneNumber);

}

void NameCard::ShowNameCardInfo() const
{
	std::cout << "이름: " << name << std::endl;
	std::cout << "회사: " << componyName << std::endl;
	std::cout << "전화번호: " << phoneNumber << std::endl;
	switch (jobGrade) {
	case COMP_POS::CLERK :
		std::cout << "직급: 사원" << std::endl;
		break;

	case COMP_POS::SENIOR:
		std::cout << "직급: 주임" << std::endl;
		break;

	case COMP_POS::ASSIST:
		std::cout << "직급: 대리" << std::endl;
		break;

	default:
		std::cout << "직급: 과장" << std::endl;
		break;
	}
}

NameCard::~NameCard()
{
	delete[] name;
	delete[] componyName;
	delete[] phoneNumber;
}
