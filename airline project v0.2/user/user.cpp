#include "user.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

user::user(string _username, string _password, int _access, int _admin_access, int _co_cert_, int _visa_cert_, int _balance_)
{
    username = _username;
    password = _password;
    access = _access;
    admin_access = _admin_access;
    co_cert = _co_cert_;
    visa_cert = _visa_cert_;
    balance = _balance_;
    if(!(user::search_username(username))){
    save_user_direct();
    cout << "created successfully " << endl;}
}
user::~user()
{
}
string user::give_access_username()
{
    return username;
}

string user::give_access_password()
{
    return password;
}

int user::give_access_access()
{
    return access;
}

int user::give_access_admin_access()
{
    return admin_access;
}

int user::give_access_co_cert()
{
    return co_cert;
}

int user::give_access_visa_cert()
{
    return visa_cert;
}

int user::give_access_balance()
{
    return balance;
}

void user::edit_access_username(string _user)
{
    username = _user;
}

void user::edit_access_password(string _password)
{
    password = _password;
}

void user::edit_access_access(int _access)
{
    access = _access;
}

void user::edit_access_admin_access(int _admin_access)
{
    admin_access = _admin_access;
}

void user::edit_access_co_cert(int _co_cert__)
{
    co_cert = _co_cert__;
}

void user::edit_access_visa_cert(int _visa_cert_)
{
    visa_cert = _visa_cert_;
}

int user::edit_access_balance(int _balance_)
{
    if(_balance_)
    {
        balance =_balance_;
        return 1;
    }
    return 0;
}

void user::save_user_direct()
{
    ofstream finput("user.txt", ios::app);
    finput << give_access_username() << " " << give_access_password() << " ";
    finput << give_access_access() << " " << give_access_admin_access() << " ";
    finput << give_access_co_cert() << " " << give_access_visa_cert() << " ";
    finput << give_access_balance() << endl;
    finput.close();
}
void user::update_user_direct(string new_str) {
    ifstream fin("user.txt");
    ofstream fout("user_new.txt",ios::app);
    string current_str;
    int arr[5];
    string str[2];
    while (fin >> str[0] >> str[1] >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4]){
        if (current_str == new_str) {
            fout << give_access_username() << " " << give_access_password() << " ";
            fout << give_access_access() << " " << give_access_admin_access() << " ";
            fout << give_access_co_cert() << " " << give_access_visa_cert() << " ";
            fout << give_access_balance() << endl;
        } else {
            fout << str[0] << " " << str[1] << " ";
            fout << arr[0] << " " << arr[1] << " ";
            fout << arr[2] << " " << arr[3] << " ";
            fout << arr[4] << endl;
        }
    }
    fin.close();
    fout.close();
    remove("user.txt") ;
    rename("user_new.txt", "user.txt");
}


user user::extract_info_username(string username_)
{
    ifstream foutput("user.txt");
    string str[2];
    int arr[5];
    while (foutput >> str[0] >> str[1] >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4])
    {
        if (str[0] == username_)
        {
            user u1("","",0,0,0,0,0);
            u1.edit_access_username(str[0]);
            u1.edit_access_password(str[1]);
            u1.edit_access_access(arr[0]);
            u1.edit_access_admin_access(arr[1]);
            u1.edit_access_co_cert(arr[2]);
            u1.edit_access_visa_cert(arr[3]);
            u1.edit_access_balance(arr[4]);
            foutput.close();
            return u1;
        }
    }
    foutput.close();
}

int user::print_info_username(string username_)
{
    ifstream f2("user.txt");
    string str[2];
    int arr[5];
    while (f2 >> str[0] >> str[1] >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4])
    {
        if (str[0] == username_)
        {
            cout << str[0]  << str[1] << arr[0]  << arr[1] << arr[2] << arr[3] << arr[4]  << endl;
            return 1;
        }
    }
    f2.close();
    return 0;
}

int user::search_username(string username_)
{
    ifstream f3("user.txt");
    string str[2];
    int arr[5];
    while (f3 >> str[0] >> str[1] >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4])
    {
        if (str[0] == username_)
        {
            f3.close();
            return 1;
        }
    }
    f3.close();
    return 0;
}

int user::print_user_operation(string username_)
{
    ifstream f4("user.txt");
    string str[2];
    int arr[5];
    while (f4 >> str[0] >> str[1] >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4])
    {
        if (str[0] == username_)
        {
            cout << "User Information : " << endl;
            cout << "The User Name : " << str[0] << endl;
            cout << "The User Password : " << str[1] << endl;
            cout << "The User Access : " << arr[0] << endl;
            cout << "The User Admin Access : " << arr[1] << endl;
            cout << "The User Covid-19 Certificate : " << arr[2] << endl;
            cout << "The User Visa-Country Certificate  : " << arr[3] << endl;
            cout << "The User Balance : " << arr[4] << endl;
            f4.close();
            return 1;
        }
    }
    f4.close();
    return 0;
}

void user::save_user_operation(string username_, int id_, int value)
{
    try
    {
        ofstream finput("operation_user.txt", ios::app);
        if (!(finput.is_open()))
        {
            throw error_file_not_founded();
        }
        finput << username_ << " " << id_ << " " << value << endl;
        finput.close();
    }
    catch (error_file_not_founded)
    {
        cerr << "File Not Founded, Check your Information !" << endl;
    }
}

int user::return_user_operation(string username_, int id_, int value)
{
    try
    {
        int arr[2];
        string str;
        ifstream f5("operation_user.txt");
        ofstream f6("operation_user_new.txt");
        if (!(f5.is_open()))
        {
            throw error_file_not_founded();
        }
        while (f5 >> str >> arr[0] >> arr[1])
        {
            if (id_ != arr[0])
            {
                f6 << username_ << " " << id_ << " " << value << endl;
            }
        }
        f6.close();
        f5.close();
        remove("operation_user.txt") ;
        rename("operation_user_new.txt", "operation_user.txt");
    }
    catch (error_file_not_founded)
    {
        cerr << "File Not Founded, Check your Information !" << endl;
    }
    return 0;
}

int user::delete_username(string username_)
{
    int arr[5];
    string str[2];
    ifstream f7("user.txt");
    ofstream f8("user_new.txt");
    while (f7 >> str[0] >> str[1] >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4])
    {
        if (username_ != str[0])
        {
            f8 << str[0] << " " << str[1] << " ";
            f8 << arr[0] << " " << arr[1] << " ";
            f8 << arr[2] << " " << arr[3] << " ";
            f8 << arr[4] << endl;
        }
    }
    f8.close();
    f7.close();
    remove("user.txt") ;
    rename("user_new.txt", "user.txt");
    return 1;
}
