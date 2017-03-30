#include "QUEUEuser.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	Queue1 <char> queueSymbol(20); int n1 = 0; char ch[2], ch1;
	ifstream fin; fin.open("C:\\Users\\User\\Desktop\\Symbols.txt");
	while (!fin.eof())
	{
		fin.getline(ch, 2);
			if (((int)ch[0] > 47) && ((int)ch[0] < 58)) cout << ch[0] << " ";
			else
			{
				queueSymbol.push(ch[0]); n1++;
			}
		}
	fin.close();
	while (n1 != 0) {
		ch1 = queueSymbol.pop(); n1--;
		if (((int)ch1 < -64) || ((int)ch1 > -1) && ((int)ch1 != -72) && ((int)ch1 != -88))
		{
			queueSymbol.push(ch1);
		}
		else cout << ch1 << " ";
	}
	queueSymbol.printQueue();
	system("pause");
	return 0;
}