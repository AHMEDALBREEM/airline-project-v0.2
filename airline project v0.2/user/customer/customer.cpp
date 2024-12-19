#include "customer.h"
#include <fstream>
#include <ctime>
#include <windows.h>
#include <unistd.h>
#define wait_and_clear sleep(3); system("cls");

customer::customer(string _username, string _password, int _access, int _admin_access, int _co_cert_, int _visa_cert_, int _balance_)
    : user(_username, _password, _access, _admin_access, _co_cert_, _visa_cert_, _balance_)
{
}

customer::~customer()
{
}

void customer::gui_1()
{
    wait_and_clear
    cout << "\a\n1-Return to Dashboard\n2-Exit\nEnter the Number : " << endl;
    int x;
    cin >> x;

    if (x == 1)
    {
        customer::customer_dashboard();
    }
    else
    {
        exit(0);
    }
}

void customer::buy_ticket()
{
    int id_;
    cout << "Enter Id: " << endl;
    cin >> id_;
    tickets t1(0,"","","","",000,000,00);
    t1 = t1.extract_info_id(id_);
    if (!(t1.give_access_price()))
    {
        cout << "ID Ticket Not Found !! " << endl;
        customer::customer_dashboard();
    }
    int temp = user::give_access_balance() - t1.give_access_price();
    if ((temp)<0)
    {
        cout << "Check the Balance !!" << endl;
        customer::customer_dashboard();
    }
user::edit_access_balance(temp);
user::save_user_operation(user::give_access_username(), t1.give_access_id(), t1.give_access_price());
user::update_user_direct(user::give_access_username());
t1.print_info_id(id_);
sleep(3);
cout << "Your Available Balance : " << user::give_access_balance() << endl;
cout << "Your Operation is done !!" << endl;
sleep(2);
gui_1();
}

void customer::return_ticket()
{
    int id_;
    cout << "Enter Id: " << endl;
    cin >> id_;
    tickets t1(00,"","","","",00,00,0);
    t1=t1.extract_info_id(id_);
    if (!(t1.give_access_price()))
    {
        cout << "ID Ticket Not Found !! " << endl;
        customer::gui_1();
    }
    sleep(3);
    user::edit_access_balance(user::give_access_balance() + t1.give_access_price());
    user::return_user_operation(user::give_access_username(), t1.give_access_id(), t1.give_access_price());
    user::update_user_direct(user::give_access_username());
    cout << "Your Operation is done !!" << endl;
    gui_1();
}

void customer::customer_dashboard()
{
    cout << "Welcome To User Panel " << endl;
    cout << "1 - Buy Ticket " << endl;
    cout << "2 - Return Ticket " << endl;
    cout << "3 - Exit Program " << endl;

    int x;
    cin >> x;

    switch (x)
    {
    case 1:
        buy_ticket();
        break;
    case 2:
        return_ticket();
        break;
    case 3:
exit(0);        break;
    default:
        cout << "Invalid option. Please choose again." << endl;
        customer::customer_dashboard();
        break;
    }
}

void view_tickets()
{
    ifstream fileoutput("tickets.txt");
    int arr[4];
    string str[4];

    cout << "Ticket Id \t" << "Ticket from " << "Ticket where " << "Ticket date to go" << "Ticket date to return " << "Ticket price" << endl;

    while (fileoutput >> arr[0] >> str[0] >> str[1] >> str[2] >> str[3] >> arr[1])
    {
        cout << arr[0] << "\t" << str[0] << "\t" << str[1] << "\t" << str[2] << "\t" << str[3] << "\t" << arr[1] << endl;
    }
}
