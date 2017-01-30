#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int get_index(int x, int y, int cols)
{
	return (x * cols + y);
}


int min_edit_distance(std::string &s1, std::string &s2)
{
	int rows = s1.size() + 1;
	int cols = s2.size() + 1;

	std::vector<int> table(rows * cols);

	for(int i = 0; i < cols; ++i)
		table[get_index(0, i, cols)] = i;
	
	for(int j = 0; j < rows; ++j)
		table[get_index(j, 0, cols)] = j;

	for(int i = 1; i < rows; ++i)
		for(int j = 1; j < cols; ++j)
			if(s1[i - 1] == s2[j - 1])
				table[get_index(i, j, cols)] = table[get_index(i - 1, j - 1, cols)];
			else
				table[get_index(i, j, cols)] = std::min(table[get_index(i - 1, j - 1, cols)],
														std::min(table[get_index(i, j - 1, cols)], 
																 table[get_index(i - 1, j, cols)]))
											   + 1;
	
	return table[get_index(rows - 1, cols - 1, cols)];
}


int main()
{
	std::string s1, s2;

	std::cout << "String 1: ";
	std::cin >> s1;

	std::cout << "String 2: ";
	std::cin >> s2;

	std::cout << "Min = " << min_edit_distance(s1, s2) << "\n";

	return 0;
}