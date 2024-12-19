#include "admin.h"
#include <unistd.h>
#include <windows.h>
#include <unistd.h>
#define wait_and_cleen sleep(3); system("cls");

void admin::gui_1()
{
    wait_and_cleen
    cout << "\n1-Return to Dashboard\n2-Exit\nEnter the Number : " << endl;
    int x;
    cin >> x;
    if (x == 1)
    {
        wait_and_cleen
        admin::admin_dashboard();
    }
    else
    {
        exit(0);
    }
}

admin::admin(string _username, string _password, int _access, int _admin_access, int _co_cert_, int _visa_cert_, int _balance_)
    : user(_username, _password, _access, _admin_access, _co_cert_, _visa_cert_, _balance_)
{
}
admin::~admin() {}

void admin::admin_dashboard()
{
    cout << "Welcome to admin panel" << endl;
    cout << "1 - Add Ticket" << endl;
    cout << "2 - Edit Ticket" << endl;
    cout << "3 - Delete Ticket" << endl;
    cout << "4 - Specific Ticket Info" << endl;
    cout << "5 - Block User" << endl;
    cout << "6 - Track Operation Specific User" << endl;
    cout << "7 - Specific User Info" << endl;
    cout << "8 - Logout\n"
         << endl;
    cout << "Enter the number : " << endl;
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        admin::add_ticket();
        break;
    case 2:
        admin::edit_ticket();
        break;
    case 3:
        admin::delete_ticket();
        break;
    case 4:
        admin::view_info_ticket();
        break;
    case 5:
        admin::block_user();
        break;
    case 6:
        admin::track_op_user();
        break;
    case 7:
        admin::view_info_user();
        break;
    case 8:
        exit(0);
        break;
    default:
        cout << "Invalid option. Please choose again." << endl;
        admin::admin_dashboard();
        break;
    }
}

void admin::block_user()
{
    wait_and_cleen
    string username;
    cout << "Enter the username :" << endl;
    cin.ignore(); // Ignore newline character left in the buffer
    getline(cin, username);
    user u1("as","",1,1,1,1,0);
    u1=u1.extract_info_username(username);
    if (u1.give_access_balance())
    {
    u1.edit_access_access(0);
    admin::gui_1();
        }
    else{
        cout << "Username Not Found !!" << endl;
        admin::gui_1();
    }
}

void admin::track_op_user()
{
    wait_and_cleen
    string username;
    cout << "Enter the username :" << endl;
    cin.ignore();
    getline(cin, username);
    if (!(print_user_operation(username)))
    {
        cout << "Username Not Found !!" << endl;
    }
    cout << "Extracted Info done !!" << endl;
    admin::gui_1();
}

void admin::view_info_user()
{
    wait_and_cleen
    string username;
    cout << "Enter the username :" << endl;
    cin.ignore();
    getline(cin, username);
    if (!(print_info_username(username)))
    {
        cout << "Username not found " << endl;
    }
    cout << "Printing info done !!" << endl;
    sleep(5);
    admin::gui_1();
}

void admin::add_ticket()
{
    wait_and_cleen
    string temp_str[4];
    int temp_int[4];
    cout << "Provide all the information here : \n"
         << endl;
    cout << "Enter Id : " << endl;
    cin >> temp_int[0];
    cout << "Enter from : " << endl;
    cin >> temp_str[0];
    cout << "Enter where : " << endl;
    cin >> temp_str[1];
    cout << "Enter date to go : " << endl;
    cin >> temp_str[2];
    cout << "Enter date to return  : " << endl;
    cin >> temp_str[3];
    cout << "Enter price : " << endl;
    cin >> temp_int[1];
    cout << "Enter visa requirement : " << endl;
    cin >> temp_int[2];
    cout << "Enter corona requirement : " << endl;
    cin >> temp_int[3];
    tickets t1(temp_int[0], temp_str[0], temp_str[1], temp_str[2], temp_str[3], temp_int[1], temp_int[2], temp_int[3]);
    sleep(5);
    admin::gui_1();
}

void admin::edit_ticket()
{
    wait_and_cleen
    cout << "Enter Your Id: " << endl;
    int x;
    cin >> x;
    tickets t2(0,"","","","",1,1,1);
    if (!(t2.search_id(x)))
    {
        cout << "Your id not Found !!" << endl;
        admin::gui_1();
    }
    t2 = t2.extract_info_id(x);
    cout << "Which data you want to edit ? " << endl;
    cout << " 1- Id \n 2- Where \n 3- From \n 4-date go \n 5-date return \n 6-price \n 7-visa requirement \n 8-covid requirement \n"
         << endl;
    cout << "Enter Number : \n"
         << endl;
    cin >> x;
    string s;
    int a;
    switch (x)
    {
    case 1:
        cin >> a;
        t2.edit_access_id(a);
        break;
    case 2:
        cin >> s;
        t2.edit_access_where(s);
        break;
    case 3:
        cin >> s;
        t2.edit_access_from(s);
        break;
    case 4:
        cin >> s;
        t2.edit_access_date_go(s);
        break;
    case 5:
        cin >> s;
        t2.edit_access_date_ret(s);
        break;
    case 6:
        cin >> a;
        t2.edit_access_price(a);
        break;
    case 7:
        cin >> a;
        t2.edit_access_t_visa_req(a);
        break;
    case 8:
        cin >> a;
        t2.edit_access_t_cov_req(a);
        break;
    default:
        cout << "Invalid option. Please choose again." << endl;
        admin::admin_dashboard();
        break;
    }
    tickets t3(t2);
    cout << "Ticket Updated !!" << endl;
    wait_and_cleen
    admin::gui_1();
}

void admin::delete_ticket()
{
    wait_and_cleen
    cout << "Enter Your Id: " << endl;
    int x;
    cin >> x;
    tickets t1(0,"","","","",1,1,1);
    if (!(t1.delete_ticket(x)))
    {
        cout << "CHECK THE ID OF THE TICKET !!" << endl;
        wait_and_cleen
        admin::admin_dashboard();
    }
    t1.print_info_id(x);
    t1.~tickets();
    cout << "Deleted Done !! " << endl;
    sleep(5);
    wait_and_cleen
    admin::gui_1();
}

void admin::view_info_ticket()
{
    wait_and_cleen
    int x;
    cout << "Enter the ID :" << endl;
    cin >> x;
    tickets t1(0,"","","","",1,1,1);
    if (!(t1.print_info_id(x)))
    {
        cout << "Check the Id !!" << endl;
    }
    cout << "Ticket Info Extracted !!" << endl;
    sleep(5);
    admin::gui_1();
    t1.~tickets();
}
