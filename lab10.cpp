#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <stdio.h> 
#include <conio.h>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <windows.h> 
using namespace std;


string Tentep(string path) {
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
    return name;
}

int main()
{

    string path;
    ifstream yourFile;

    fstream saveFile;
    saveFile.open("out.txt", fstream::in | fstream::out);
    cout << "Enter path of file: ";
    cin >> path;
    cin.ignore();

    string name = Tentep(path);

    string s, res = "";
    if (name == "aux" || name == "clock$" || name == "com1" || name == "com2" || name == "com3" || name == "com4" || name == "lpt1" || name == "lpt2" || name == "lpt3" || name == "con" || name == "nul" || name == "prn")
    {
        cout << "No acess to this file";
    }
    else {

        yourFile.open(path.c_str());
        if (yourFile.is_open()) {
            cout << endl << "File contains text: \n";
            while (getline(yourFile, s)) {
                res += s + "\n";
            }
            yourFile.close();
            cout << res;
            cout << endl;
            int choice_count = 1;
            while (choice_count > 0) {

                cout << "Enter your selection: \n" << "1. Adding to the end.\n" << "2. Replace all lowercase letters with uppercase ones.\n" << "3. Inserting text from a file. \n" << "4. File extension name. \n" << "5. Close program. \n";
                cout << "Your choice: " << endl;
                int choice;
                cin >> choice;
                cin.ignore();
                if (choice == 1) {
                    string s_add = "", s_tempadd;
                    cout << "Enter the string you want to add at the end: ";
                    getline(cin, s_add);
                    res = res + s_add;
                    cout << "Text after editing: " << res << endl;
                }
                else if (choice == 2) {
                    for (int i = 0; i < res.size(); i++) {
                        if (res[i] >= 97 && res[i] <= 122) {
                            res[i] -= 32;
                        }
                    }
                    cout << "Text after editing: " << res << endl;

                }
                else if (choice == 3) {
                    string path_new;
                    ifstream newFile;

                    cout << "Enter path of new file: ";
                    cin >> path_new;
                    cin.ignore();

                    string new_name = Tentep(path_new);

                    string temp_new, s_new = "";

                    if (name == "aux" || name == "clock$" || name == "com1" || name == "com2" || name == "com3" || name == "com4" || name == "lpt1" || name == "lpt2" || name == "lpt3" || name == "con" || name == "nul" || name == "prn")
                    {
                        cout << "No acess to this file";
                    }
                    else {
                        newFile.open(path_new.c_str());
                        while (getline(newFile, temp_new)) {
                            s_new += temp_new;
                        }
                    }
                    newFile.close();
                    res = res + s_new;
                    cout << "Text after editing: " << res << endl;
                }
                else if (choice == 5) {
                    saveFile << res;
                    choice_count--;
                    saveFile.close();
                }
                else if (choice == 4) {
                    cout << "The file extension name is: ";
                    for (auto it = path.end(); it != path.begin(); --it) {
                        if (*it == 46) {
                            break;
                        }
                        else {
                            cout << *it;
                        }
                    }
                    cout << endl;
                }
                else {
                    cout << "Your selection is invalid, please select again: \n";
                }
            }
        }
        else {
            cout << "No acess to this file";
        }
    }
    return 0;
}