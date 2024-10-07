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

string Tentep(string path){
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

unsigned long HASH(const char* key, size_t len)
{
    unsigned long hash, i;
    for (hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

int main()
{
    string path;
    ifstream yourFile;

    cout << "Enter path of file: ";
    cin >> path;
    cin.ignore();
    string name = Tentep(path);

    string s;
    int res = 0, tmp = 0;

    map<unsigned long, vector<pair<int, pair<string, string>>>> mp;
    int index = 0;
 
    if (name == "aux" || name == "clock$" || name == "com1" || name == "com2" || name == "com3" || name == "com4" || name == "lpt1" || name == "lpt2" || name == "lpt3" || name == "con" || name == "nul" || name == "prn")
    {
        cout << "No acess to this file";
    } else {
        yourFile.open(path.c_str());
        while (getline(yourFile, s)){
            string s_char = "", s_num = "", s_sum = "";
            index++;

            for (int i = 0; i < s.size(); i++){
                if ((s[i] >= 48 && s[i] <=57 && s[i-1]) || s[i] == 46)
                {
                    s_num += s[i];
                }
                if((s[i] >= 65 && s[i] <= 90 ) || (s[i] >= 97 && s[i] <= 122)){
                    if(s[i+1] == 32 && s[i+2] != 32){
                        s_char = s_char + s[i] + " ";
                    } else {
                        s_char += s[i];
                    }
                }
            }
            s_sum = s_char + " " + s_num;
            const char* lol = s_sum.c_str();
            if(s_char != "") mp[HASH(lol, s_sum.length())].push_back({index, {s_char, s_num}}); 
            }
        for (auto h : mp){
        cout << h.first << ' ';
        for (auto t : mp[h.first]){
            cout << t.first << ' ' << t.second.first << ' ' << t.second.second << ' ';
            }
        cout << endl;
        }

        
        string name_find, num_find, sum_find = "";
        int collision = 0;

        cout << "Enter the name to search: ";
        getline(cin, name_find);
        
        cout << "Enter the IP address to search: ";
        getline(cin, num_find);

        sum_find = name_find + " " + num_find;
        const char* hash_find = sum_find.c_str();

    if (mp.count(HASH(hash_find, sum_find.length())) > 0){
        int loop_name = 0, loop_num = 0;
        for (auto h : mp){
        for (auto t : mp[h.first]){
            if (t.second.first == name_find)
            {
                loop_name++;
            }
            if (t.second.second == num_find)
            {
                loop_num++;
            }
            }
        }
        if(loop_name != 0 && loop_num != 0){
            cout << "FOUND." << endl;
            cout << "Key: " << HASH(hash_find, sum_find.length()) << " Original: " << sum_find << ";";
            for (auto t : mp[HASH(hash_find, sum_find.length())])
                {
                    if (t.second.first != name_find || t.second.second != num_find)
                    {
                        collision++;
                    }
                }
            cout << endl << "Number of collisions: " << collision << endl;
            cout << "Number of duplicate names: " << loop_name << endl;
            cout << "Number of duplicate IP addresses: " << loop_num << endl;
            cout << "The matched data is exactly on the line: ";
            for (auto t : mp[HASH(hash_find, sum_find.length())])
                {
                    if (t.second.first == name_find && t.second.second == num_find)
                    {
                        cout << t.first << ' ';
                    }
                }
                cout << endl;
        } else{
            cout << "There are no matching data.";
            }
    } else{
        cout << "There are no matching data.";
    }

    yourFile.close();
    }
    return 0;
}

