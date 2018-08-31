#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int ac, char **av)
{
	string str;
	ifstream file (av[1], ios::in);
	if (file)
		while (!file.eof())
			str.push_back(file.get());
	else
		return (0);
	cout << str << endl;
	return (0);
}
