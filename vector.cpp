#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int	main(void)
{
	vector <int> vec(10);
	// все элементы в массиве = 0
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] = i + 1;
		cout << vec[i];
	}
	cout << endl;
	vector <int> vec2(vec); // создание копии вектора, достаточно отправить ссылку на переменную
	for (int i = 0; i < vec2.size(); i++)
		cout << vec2[i];
	cout << endl;
	// сравнение значений в векторе осуществялется простым оператором сравнения
	if (vec == vec2)
		cout << "vec == vec2\n";
	// добавление нового элемента в вектор
	vec.insert(vec.end(), 11);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i];
	return (0);
}
