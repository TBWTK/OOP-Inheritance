//
//  main.cpp
//  Productclass
//
//  Created by Илья on 17/02/2021.
//  Copyright © 2021 Илья. All rights reserved.
//


#include <iostream>

#define a1 num.find_last_not_of("-0123456789")
#define a2 num.find_last_of("-")

#define b1 numf.find_last_not_of("-0123456789.")
#define b2 numf.find_last_of("-")

using namespace std;

class Product
{
protected:
    int check_input_int();
    float check_input_float();
    float weight_product, price_product;
    string name_product;
public:
    Product() {};
    void product();
    ~Product();
};
int Product::check_input_int()
{
    // INITIALIZE VARIABLE
    string num = "";
    int n = 0;
    // LOOP do/while
    do
    {
        // THE FUNCTION BODY IS BEING EXECUTED
        do
        {
            // THE FUNCTION BODY IS BEING EXECUTED
            cout << " = "; // OUTPUT TO THE SCREEN
            getline(cin, num); // READING INPUT DATA TO THE NUM VARIABLE
        } while ((a1 != -1) or (a2 != -1 and a2 != 0)); //THIS REPEATEDLY THE LOOP S LONG AS THE CONDITION IS TRUE
        n = atoi(num.c_str()); // THE atoi FUNCTION IS APPILIED
    } while (n < 1);
    return n;
}
float Product::check_input_float()
{
    // INITIALIZE VARIABLE
    string numf;
    float n = 0.0;
    // LOOP do/while
    do
    {
        // THE FUNCTION BODY IS BEING EXECUTED
        do
        {
            // THE FUNCTION BODY IS BEING EXECUTED
            cout << " = "; // OUTPUT TO THE SCREEN
            getline(cin, numf); // READING INPUT DATA TO THE NUM VARIABLE
        } while ((b1 != -1) or (b2 != -1 and b2 != 0)); //THIS REPEATEDLY THE LOOP S LONG AS THE CONDITION IS TRUE
        n = stof(numf.c_str()); // THE stof FUNCTION IS APPILIED
    } while (n < 0);
    return n;
}
void Product::product()
{
    cout << "Input name product = ";
    getline(cin, name_product);
    cout << "Input weight product\0";
    weight_product = check_input_float();
    cout << "Input price product for Kg";
    price_product = check_input_float();
}
Product::~Product()
{
    cout << "Delete Product\n";
}


class Party : public Product
{
protected:
    int number_party;
    int qua_product;
    float price_party;
public:
    Party();
    void party();
    void party_show();
    float party_price();
    ~Party();
};
Party::Party(){}
void Party::party()
{
    cout << "Input number party";
    number_party = check_input_int();
    cout << "Input quantity product in party " << number_party;
    qua_product = check_input_int();
}
float Party::party_price()
{
    return price_party = weight_product * qua_product * price_product;
}
void Party::party_show()
{
    cout<< "Number party        " <<number_party << endl
        << "Name product        " <<name_product << endl
        << "Wieght product      " <<weight_product << endl
        << "Price product       " <<price_product << endl
        << "Quantity product    " <<qua_product << endl
        << "Price party         " <<price_party << endl;
}
Party::~Party()
{
    cout << "Delete Party\n";
}


class Supply : public Party
{
protected:
    int number_supply = 0, qua_party = 0;
    string date_supply;
    float price_supply = 0.0;
    Party *arr;
    string input_date();
public:
    Supply();
    ~Supply();
};
Supply::Supply()
{
    cout << "Input number supply";
    number_supply = check_input_int();
    cout << "Input date supply:\n";
    date_supply = input_date();
    cout << "Input quantity party";
    qua_party = check_input_int();
    
    arr = new Party[qua_party];
    for (int i = 0; i < qua_party; i++)
    {
        arr[i].party();
        arr[i].product();
        arr[i].party_price();
        price_supply += arr[i].party_price();
    }
    cout << endl;
    cout << "Number supply       " << number_supply << endl
         << "Date supply         " << date_supply << endl
         << "Quantity party      " << qua_party << endl
         << "Price supply        " << price_supply << endl;
    cout << endl;
    for (int i = 0; i < qua_party; i++)
    {
        arr[i].party_show();
        cout << endl;
    }
}
string Supply::input_date()
{
    int year = 0, month = 0, day = 0;
    cout << "Input year";
    do
    {
        year = check_input_int();
    } while (year > 2100 or year < 2000);
    
    cout << "Input month";
    do
    {
        month = check_input_int();
    } while (month > 12);
    
    cout << "Input day";
    // 31 - январь март май июль август октябрь декабрь 1 3 5 7 8 10 12
    // 30 - апрель июнь сентябрь ноябрь 4 6 9 11
    // 28 - февраль 2
    if (month == 2)
    {
        do
        {
            day = check_input_int();
        } while (day > 29);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        do
        {
            day = check_input_int();
        } while (day > 30);
    }
    if (month == 1  || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        do
        {
            day = check_input_int();
        } while (day > 31);
    }
    string date;
    if(month < 10)
        date = to_string(day) + '.' + to_string(month) + '.' + to_string(year);
    else
        date = to_string(day) + '.' + '0' + to_string(month) + '.' + to_string(year);
    return date;
}
Supply::~Supply()
{
    cout << "SDES\n";
    delete [] arr;
}

int main()
{
    Supply A;
    cout << endl;
    return 0;
}
