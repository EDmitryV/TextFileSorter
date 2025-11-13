#include "Profile.h"

Profile::Profile(const string& name, const string& familyName, const string& phoneNumber):name(name), familyName(familyName), phoneNumber(phoneNumber){}

string Profile::getName() const
{
	return name;
}

string Profile::getFamilyName() const {
	return familyName;
}

string Profile::getPhoneNumber() const {
	return phoneNumber;
}