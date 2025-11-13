#include "TableSorter.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "Profile.h"
#include "SortColumn.h"
#include <regex>
using namespace std;

void TableSorter::SortTable(ifstream& file, SortColumn sc)
{
	vector<Profile> profiles;
	string line;
	while (getline(file, line)) {
		const regex delimiter_regex("(: )|(\\s)");
		sregex_token_iterator it(line.begin(), line.end(), delimiter_regex, -1);
		sregex_token_iterator end;
		vector<string> parts(it, end);
		profiles.push_back(move(Profile(parts.at(1), parts.at(0), parts.at(2))));
	}
	sort(profiles.begin(), profiles.end(), [sc](const Profile& p1, const Profile& p2) {
		switch (sc) {
		case SortColumn::NAME:
			return p1.getName() < p2.getName();
		case SortColumn::FAMILYNAME:
			return p1.getFamilyName() < p2.getFamilyName();
		default:
			try {
				return stoi(p1.getPhoneNumber()) < stoi(p2.getPhoneNumber());
			}
			catch (const invalid_argument& e) {
				return p1.getPhoneNumber() < p2.getPhoneNumber();
			}
		}
		});
		for (const Profile& p : profiles) {
			switch (sc) {
			case SortColumn::NAME:
				cout << p.getName() << " " << p.getFamilyName() << ": " << p.getPhoneNumber() << "\n";
				break;
			case SortColumn::FAMILYNAME:
				cout << p.getFamilyName() <<" " <<p.getName() <<": " << p.getPhoneNumber() << "\n";
				break;
			case SortColumn::PHONE:
				cout << p.getPhoneNumber() << ": " << p.getFamilyName() << " " << p.getName() << "\n";
				break;
			}
	}
}

