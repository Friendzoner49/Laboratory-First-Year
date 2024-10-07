#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct node 
{
    int data;
    struct node *pLeft;
    struct node *pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

void TaoCay(TREE &t)
{
    t = NULL;
}

void ThemNode(TREE &t, int x)
{
    if(t == NULL)
    {
        NODE *p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    } 
    else {
        if(x <= t->data){
            ThemNode(t->pLeft, x);
        } 
        else if(x > t->data){
            ThemNode(t->pRight, x);
        }
    }
}
int v = 0;
int sodaxep[1000];
void DuyetCay(TREE t){
    
    if(t != NULL)
    {
        sodaxep[v] = t->data;
        v++;
        //cout << t->data << " ";
        DuyetCay(t->pLeft);
        DuyetCay(t->pRight);
    }
}

void so_to_chuoi(int a[1000], int check[1000], string b[1000], string s, int n){
    
    for (int i = 0; i < s.size(); i++){   
        bool loop = false;
        int remove_loop = 0;
        for(int j=0; j<n; j++){ 
            int count=0;
            
            if(a[i] == b[j].size()){
                for(int k=0; k<n; k++){
                    if(b[k]==b[j]) count++;
                }

            if(check[j]==0 && loop == false && count == 1){
                cout << b[j] << "(" << a[i] << ")" << " ";
                check[j] = 1;
                loop = true;
            } else if(check[j]==0 && count != 1 && loop == false && remove_loop == 0){
                cout << b[j] << "(" << a[i] << ")" << " ";
                check[j] = 1;
                remove_loop = 1;
                loop = true;
            } else if(check[j]==0 && count != 1 && remove_loop == 1){
            cout << "[" << count << "] ";
            check[j] = 1;
            remove_loop = 2;
            }
            } 
        }
    }
}
string chuoi_da_xep[1000];
void sap_xep_chuoi(int a[1000], int check[1000], string b[1000], string s, int n){
    
     for (int i = 0; i < s.size(); i++){   
        bool loop = false;
        int remove_loop = 0;
        for(int j=0; j<n; j++){ 
            int count=0;
            
            if(a[i] == b[j].size() && check[j]==0){
                
                //cout << b[j] << "(" << a[i] << ")" << " ";
                check[j] = 1;
                loop = true;
                chuoi_da_xep[i] = b[j];
                break;
            } 
        }
    }
}
int s_count = 0;

bool search(node* root, int val)
{
    if (root == nullptr) 
    {
        return false;
    }
    if (root->data == val)
    {
        s_count++;
        return true;
    }
    if (val < root->data) 
    {
        s_count++;
        return search(root->pLeft, val);
    }
    s_count++;
    return search(root->pRight, val);
}

string res_s, tmp_s = "";
int res = 0, tmp = 0;

int main()
{
int n;
cout << "Input number of characters: ";
cin >> n;
int count = 0;

string s, chuoi[1000];
cin.ignore();  // thêm vào để xoá bộ nhớ đệm, tránh bị trôi lệnh
cout << "Input text:  "<<endl;
getline(std::cin, s);

int a[1000], j=0;
memset(a, 0, 1000);

int check[1000], check2[1000];
memset(check, 0, 1000);
memset(check2, 0, 1000);
bool word_found = false;
cout << "Linear search: " << endl;
for (int i = 0; i < s.size(); i++)
{   
    if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 48 && s[i] <= 57))
    {
        tmp++;
        tmp_s = tmp_s + s[i];
    }
    else if(s[i] == 32 && s[i+1] != 32)
    {
        if (res < tmp)
        {
            res = tmp;
            res_s = tmp_s;
        }
        chuoi[j] = chuoi[j] + tmp_s;
        tmp_s = "";
        tmp = 0;
        count++;
        j++;
    }
    if(i == s.size()-1) chuoi[j] = chuoi[j] + tmp_s;
    if((tmp == n && s[i] != 32 && s[i+1] == 32) ||(tmp == n && i == (s.size()-1))) 
    {
        cout << tmp_s << endl;
        word_found = true;
    }
}
if(word_found == false){
        cout << "No matching words found" << endl;
}

for(int i=0; i < count+1; i++){
    a[i] = chuoi[i].size();
    cout << a[i] << " ";
}
cout << endl;

TREE t;
TaoCay(t);
for(int i=0; i< count+1; i++){
    ThemNode(t, a[i]);
}
DuyetCay(t);

for(int i=0; i < count+1; i++){
    cout << sodaxep[i] << " ";
}
cout << endl;
// for(int i=0; i < count+1; i++){
//  cout << chuoi[i] << " ";
//  if(i==count) cout << "end";
// }
// cout << endl;
// for(int i=0; i < count+1; i++){
//  cout << chuoi_da_xep[i] << " ";
//  if(i==count) cout << "end";
// }

so_to_chuoi(sodaxep, check, chuoi, s, count+1);
cout << endl;
sap_xep_chuoi(sodaxep, check2, chuoi, s, count+1);
cout << "Search by tree: ";
for(int i=0; i < count+1; i++){
    if(sodaxep[i] == n) cout << chuoi_da_xep[i] << " ";
}
cout << endl;

bool p = search(t, n);
if(p==1) cout << "Number of comparisons: " << s_count;
return 0;
}
