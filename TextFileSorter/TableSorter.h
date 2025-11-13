#pragma once
#include <fstream>
#include "SortColumn.h"
using namespace std;

class TableSorter
{
public:
	void SortTable(ifstream& file, SortColumn sc);
};

