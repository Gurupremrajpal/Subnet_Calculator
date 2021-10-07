/*
Name- Guruprem Rajpal
Class- CST 412
Date- 8 October 2021
*/

#include <iostream>
#include <math.h>
#include <iterator>
#include <vector>
#include <sstream>

using namespace std;


struct change : ctype<char> 
{
     const mask* arr() 
    {
        static vector<mask> m(classic_table(), classic_table() + table_size);
        m['.'] |= space;
        m['/'] |= space;
        return &m[0];
    }
    change(size_t s = 0) : ctype(arr(), false, s) {}
}; //size_t can store maximum size of a theoretically possible object of any type

int n(int number)
{
    int num;

    if(number == 1)
        num = 128;
    if(number == 2)
        num = 192;
    if(number == 3)
        num = 224;
    if(number == 4)
        num = 240;
    if(number == 5)
        num = 248;
    if(number == 6)
        num = 252;
    if(number == 7)
        num = 254;

    return num;
}

int main()
{
    string str;
    cout << "Enter an IP address: ";
    cin >> str;

    istringstream ins(str); 

    ins.imbue(locale(ins.getloc(), new change()));
    istream_iterator<long> a(ins), end;
    vector<long> vect(a, end);
    char ch;

    if(vect[0] <= 127)
    {
        ch = 'A';
    }
    else if(vect[0] >= 128 && vect[0] <= 191)
    {
        ch = 'B';
    }
    else if(vect[0] >= 192 && vect[0] <= 223)
    {
        ch = 'C';
    }
    else{
      cout<< "error" << '\n';
    }

    cout<< "Number of usable Hosts: ";
    int nouh;
    nouh = 32 - vect[4];
    nouh = pow(2, nouh);
    cout<< nouh - 2 << '\n';

    int snet;
    int snt;

    snet = vect[4] / 8;
    snt = snet;
    snet = vect[4] - (8 * snet);
    snet = n(snet);
    
    cout<< "Class Type: " << ch << '\n';
    cout<< "Subnet Address: ";

    if(snt == 0){
        cout<< snet << ".0.0.0" << '\n';
    }
    else if(snt == 1){
        cout<< "255." << snet << ".0.0" << '\n';
    }
    else if(snt == 2){
        cout<< "255.255." << snet << ".0" << '\n';
    }
    else if(snt == 3){
        cout<< "255.255.255." << snet << '\n';
    }
    else{
        cout<< "ERROR!" << '\n';
    }

    int bc;
    int sub=0;
    int sn = vect[4] / 8;
    sn = vect[4] - (8 * sn);
    sn = n(sn);
    bc = 256-sn;
    bc = bc + sub -1;

    cout<< "Broadcast Address: ";
    if(vect[4] < 8){
        cout<< bc << ".255.255.255" << '\n';
    }

    if(vect[4] >= 8 && vect[4] < 16){
        cout<< vect[0] << "." << bc << ".255.255" << '\n';
    }

    if(vect[4] >= 16 && vect[4] < 24){
        cout<< vect[0] << "." << vect[1] << "." << bc << ".255" << '\n';
    }

    if(vect[4] >= 24 && vect[4] < 32){
        cout<< vect[0] << "." << vect[1] << "." << vect[2] << "." << bc << '\n';
    }
    
    return 0;
}