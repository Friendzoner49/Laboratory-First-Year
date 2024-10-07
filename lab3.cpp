#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;


string res_s, tmp_s = "";
int res = 0, tmp = 0;


int main()
{
	string s;
	string path;
	ifstream yourFile;


	cout << "Enter path of file: ";
	cin >> path;
	string name = path;

	if (0 <= path.rfind('\\') && path.rfind('\\') < path.length())
	{
		name = name.substr(name.rfind('\\') + 1, name.length() - name.rfind('\\') - 1);
	}
	if (0 <= path.rfind('/') && path.rfind('/') < path.length())
	{
		name = name.substr(name.rfind('/') + 1, name.length() - name.rfind('/') - 1);
	}


	if (0 <= name.rfind('.') && name.rfind('.') < name.length())
	{
		name = name.substr(0, name.rfind('.'));
		while (name.length() >= 0 && 0 <= name.rfind('.') && name.rfind('.') < name.length())
		{
			name = name.substr(0, name.rfind('.'));
		}

	}
	for (int i = 0; i < name.length(); i++)
	{
		name[i] = tolower(name[i]);
	}

	if (name == "aux" || name == "clock$" || name == "com1" || name == "com2" || name == "com3" || name == "com4" || name == "lpt1" || name == "lpt2" || name == "lpt3" || name == "con" || name == "nul" || name == "prn")
	{
		cout << "No acess to this file";
	}
	else {

		yourFile.open(path.c_str());


		if (yourFile.is_open()) {
			while (getline(yourFile, s, '|')) {

				for (int i = 0; i < s.size(); i++)
				{
					if (s[i] >= 48 && s[i] <= 57)
					{
						tmp++;
						tmp_s = tmp_s + s[i];
					}
					else
					{
						if (res < tmp)
						{
							res = tmp;
							res_s = tmp_s;
						}
						tmp_s = "";
						tmp = 0;
					}
				}
			}
		}
		else {
			std::cout << "Couldn't open file\n";
		}
		if (res < tmp)
		{
			res = tmp;
			res_s = tmp_s;
		}
		if (res == 0) {
			cout << "No number";
		}
		else {

			cout << res_s;
		}
		yourFile.close();
		return 0;
	}
}
