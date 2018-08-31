#include <iostream>
#include <string>

using namespace std;

int	main(void)
{
	string a  ("Hello");
	cout << a << " size: [" << a.size() << "]" <<  endl;
	string b ("Привет");
	cout << b << endl;
	cout << b.size() << endl;
	for (int i = 0; i < b.size(); i++)
		cout << b[i];
	return (0);
}
