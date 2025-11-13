#pragma once
#include <string>
using namespace std;
class Profile
{
private:
	string name;
	string familyName;
	string phoneNumber;
public:
	Profile(const string& name, const string& familyName, const string& phoneNumber);

	string getName() const;
	string getFamilyName() const;
	string getPhoneNumber() const;
};

