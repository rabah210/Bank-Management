#include <iostream>
#include <stdbool.h>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include <string>
#include <conio.h>
#include <bits/stdc++.h>

using namespace std;

class Person
{
private:
    string First_Name;
    string Last_Name;
    long double ID;
    string As_you = "Not Found";
    string Password;
public:
    void Set_First_Name(string);
    string Get_First_Name();
    void Set_Last_Name(string);
    string Get_Last_Name();
    void Set_ID(long double);
    long double Get_ID();
    bool Set_As_you(char);
    string Get_As_you();
    void Set_Password(string);
    string Get_Password();
};

void Person::Set_First_Name( string str )
{
    First_Name = str;
}

string Person::Get_First_Name()
{
    return First_Name;
}

void Person::Set_Last_Name(string x)
{
    Last_Name = x;
}

string Person::Get_Last_Name()
{
    return Last_Name;
}

void Person::Set_ID(long double x)
{
    ID = x;
}

long double Person::Get_ID()
{
    return ID;
}

bool Person::Set_As_you(char x)
{
    if( x == 'A' || x == 'a' )
    {
        As_you = "Administrative";
    }
    else if ( x == 'E' || x == 'e' )
    {
        As_you = "Employee";
    }
    else if ( x == 'C' || x == 'c' )
    {
        As_you = "Customer";
    }
    else
    {
        cout<<"\t\n\nDenied ,Please re-enter : "<<endl;
        return false;
    }
    return true;
}

string Person::Get_As_you()
{
    return As_you;
}

void Person::Set_Password(string x)
{
    Password = x;
}

string Person::Get_Password()
{
    return Password;
}

class Bank_account: public Person
{
private:
    long double Total_balance;
    string Type_account;
    int Money_transfers;
    bool Bank_card;
public :
    Bank_account()
    {
        //Set_First_Name("Not Found");
        Set_Last_Name("Not Found");
        Set_ID(0);
        Set_Password("**********");
        Total_balance = 0;
        Type_account = "No Type";
        Money_transfers = 0;
        Bank_card = false;
    }
    void Create_account();
    void Update_account();
    void Details_account();
    void Delete_account();

};

void Bank_account::Create_account()
{
    string str;
    cout<<"\nYour First Name please ^-^ : ";
    getline (cin,str);
    Set_First_Name(str);
    system("CLS");

    cout<<"\nYour Last Name please ^-^ : ";
    getline (cin,str);
    Set_Last_Name(str);
    system("CLS");

    long double d;
    do
    {
        cout<<"\nYour ID please  ^|^ : ";
        cin>>d;
        if(d < 0)
        {
            system("CLS");
            cout<<"\n\nDenied Please re-enter : "<<endl;
        }
    }
    while(d < 0);
    Set_ID(trunc(d));
    system("CLS");

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new line
    do
    {
        cout<<"\nAs you are ( ( A or a ) for Administration | ( E or e ) for Employee | ( C or c ) for customer : ^-^ : ";
        str[0] = getche();
        system("CLS");
    }
    while( Set_As_you(str[0]) == false );
    system("CLS");

    bool b;
    do
    {
        b = false;
        cout<<"\nYour Pasword ( At least 8 characters ) please ^-^ : ";
        getline (cin,str);
        if( str.size() < 8 )
        {
            system("CLS");
            cout<<"\n\nPlease re-enter ( must be at least 8 characters ): "<<endl;
            b = true;
        }
    }
    while( b );
    Set_Password(str);
    system("CLS");
    do
    {
        cout<<"\nYour conversion amount please ^-^ : ";
        cin>>d;
        if( d < 0 )
        {
            system("CLS");
            cout<<"\n\nPlease re-enter ( must be great of 0 ): "<<endl;
        }
    }
    while( d < 0 );
    Total_balance += d;
    system("CLS");

    do
    {
        b = true;
        cout<<"\n\t\t\t[ C ] - Current account\n\n";
        cout<<"\t\t\t[ S ] - Saving account\n\n";
        cout<<"\t\t\t[ P ] - Payroll account\n\n";
        cout<<"\t\t\t[ B ] - Business account\n\n";

        cout<<"\n\tYour type account : ";
        str[0] = getche();
        if( str[0] == 'C' || str[0] == 'c' )
        {
            Type_account = "Current account";
            b = false;
        }
        else if( str[0] == 'S' || str[0] == 's' )
        {
            Type_account = "Saving account";
            b = false;
        }
        else if( str[0] == 'P' || str[0] == 'p' )
        {
            Type_account = "Payroll account";
            b = false;
        }
        else if( str[0] == 'B' || str[0] == 'b' )
        {
            Type_account = "Business account";
            b = false;
        }
        else
        {
            system("CLS");
            cout<<"\n\nPlease re-enter : \n";
        }
    }
    while( b );
    system("CLS");

    int Trm;
    do
    {
        cout<<"\nYour Number of transfer money please ^-^ : ";
        cin>>Trm;
        if( Trm < 0)
        {
            system("CLS");
            cout<<"\n\nPlease re-enter : \n";
        }
    }
    while ( Trm < 0 );
    Money_transfers = Trm;
    system("CLS");

    do
    {
        b = false;
        cout<<"Do you want Bank card (Y => YES /N => NO) : ";
        str[0] = getche();
        if(str[0] == 'Y' || str[0] == 'y'  ) Bank_card = true;
        else if(str[0] == 'N' || str[0] == 'n'  ) Bank_card = false;
        else
        {
            system("CLS");
            cout<<"\n\nPlease re-enter : \n";
            b = true;
        }
    }
    while (b);
    system("CLS");
}

void Bank_account::Update_account()
{
First:
    cout<<"\n\t\t\t[ 01 ] - First name : "<<Get_First_Name()<<"\n\n";
    cout<<"\t\t\t[ 02 ] - Last name : "<<Get_Last_Name()<<"\n\n";
    if(Get_ID() == 0)  cout<<"\t\t\tID : Not Found\n\n";
    else  cout<<"\t\t\t[ 03 ] - ID : "<<Get_ID()<<"\n\n";
    cout<<"\t\t\t[ 04 ] - Job position : "<<Get_As_you()<<"\n\n";
    cout<<"\t\t\t[ 05 ] - Password : "<<Get_Password()<<"\n\n";
    cout<<"\t\t\t[ 06 ] - Total balance : "<<Total_balance<<"\n\n";
    cout<<"\t\t\t[ 07 ] - Type of accout : "<<Type_account<<"\n\n";
    cout<<"\t\t\t[ 08 ] - Number Transfer Money : "<<Money_transfers<<"\n\n";
    if(Bank_card) cout<<"\t\t\t[ 09 ] - Validation of bank bard : Valid\n"<<endl;
    else cout<<"\t\t\t[ 09 ] - Validation of bank bard : Invalid\n"<<endl;
    cout<<"\t\t\t[ 10 ] - Exit : ^_~\n\n";

    int select;
    cout<<"Please Select your choice : ";
    cin>>select;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new line
    string str;
    bool b;
    long double d;
    switch(select)
    {
    case 1:
        cout<<"UPDATE First Name ^-^ : ";
        getline (cin,str);
        Set_First_Name(str);
        system("CLS");
        break;
    case 2:
        cout<<"\nUPDATE Last Name ^-^ : ";
        getline(cin,str);
        Set_First_Name(str);
        system("CLS");
        break;
    case 3:
        do
        {
            cout<<"\nUPDATE ID ^|^ : ";
            cin>>d;
            if(d < 0)
            {
                system("CLS");
                cout<<"\n\nDenied Please re-enter : "<<endl;
            }
        }
        while(d < 0);
        Set_ID(trunc(d));
        system("CLS");
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new line
        break;
    case 4:
        do
        {
            cout<<"Update your position : \n";
            cout<<"\nAs you are ( ( A or a ) for Administration | ( E or e ) for Employee | ( C or c ) for customer : ^-^ : ";
            str[0] = getche();
            system("CLS");
        }
        while( Set_As_you(str[0]) == false );
        system("CLS");
        break;
    case 5:
        do
        {
            b = false;
            cout<<"\nUPDATE Pasword ( At least 8 characters ) ^-^ : ";
            getline (cin,str);
            if( str.size() < 8 )
            {
                system("CLS");
                cout<<"\n\nPlease re-enter ( must be at least 8 characters ): "<<endl;
                b = true;
            }
        }
        while( b );
        Set_Password(str);
        system("CLS");
        break;
    case 6:
        do
        {
            cout<<"\nYour new conversion amount please ^-^ : ";
            cin>>d;
            if( d < 0 )
            {
                system("CLS");
                cout<<"\n\nPlease re-enter ( must be great of 0 ): "<<endl;
            }
        }
        while( d < 0 );
        b = true;
        do
        {
            cout<<"\n\nDo you pump money or withdraw money (P => Pump Money ,OR W => withdraw Money) : ";
            str[0] = getche();
            if(str[0] == 'P' || str[0] == 'p' || str[0] == 'W' || str[0] == 'w') b = false;
        }
        while(b);
        if(str[0] == 'P' || str[0] == 'p') Total_balance += d;
        else Total_balance -= d;
        system("CLS");
        break;
    case 7:
        do
        {
            b = true;
            cout<<"\n\t\t\t[ C ] - Current account\n\n";
            cout<<"\t\t\t[ S ] - Saving account\n\n";
            cout<<"\t\t\t[ P ] - Payroll account\n\n";
            cout<<"\t\t\t[ B ] - Business account\n\n";

            cout<<"\n\tYour new type account : ";
            str[0] = getche();
            if( str[0] == 'C' || str[0] == 'c' )
            {
                Type_account = "Current account";
                b = false;
            }
            else if( str[0] == 'S' || str[0] == 's' )
            {
                Type_account = "Saving account";
                b = false;
            }
            else if( str[0] == 'P' || str[0] == 'p' )
            {
                Type_account = "Payroll account";
                b = false;
            }
            else if( str[0] == 'B' || str[0] == 'b' )
            {
                Type_account = "Business account";
                b = false;
            }
            else
            {
                system("CLS");
                cout<<"\n\nPlease re-enter : \n";
            }
        }
        while( b );
        system("CLS");
        break;
    case 8:
        int Trm;
        do
        {
            cout<<"\nYour Number of new transfer money please ^-^ : ";
            cin>>Trm;
            if( Trm < 0)
            {
                system("CLS");
                cout<<"\n\nPlease re-enter : \n";
            }
        }
        while ( Trm < 0 );
        Money_transfers += Trm;
        system("CLS");
        break;
    case 9:
        do
        {
            b = false;
            cout<<"Do you want Bank card (Y => YES /N => NO) : ";
            str[0] = getche();
            if(str[0] == 'Y' || str[0] == 'y'  ) Bank_card = true;
            else if(str[0] == 'N' || str[0] == 'n'  ) Bank_card = false;
            else
            {
                system("CLS");
                cout<<"\n\nPlease re-enter : \n";
                b = true;
            }
        }
        while (b);
        system("CLS");
        break;
    case 10 :
        do
        {
            b = true;
            cout<<"Are you sure (Y => Yes/N => NO) : ";
            str[0] = getche();
            if(str[0] == 'Y' || str[0] == 'y' || str[0] == 'N' || str[0] == 'n') b = false;
            else
            {
                system("CLS");
                cout<<"\nRe-enter : \n"<<endl;
            }
        }
        while(b);
        switch(str[0])
        {
        case 'Y':
            goto End;
            break;
        case 'y':
            goto End;
            break;
        default:
            system("CLS");
            goto First;
            break;
        }
        break;
    default :
        system("CLS");
        cout<<"Re-enter : \n"<<endl;
        goto First;
        break;
    }
    do
    {
        b = true;
        cout<<"Do you want Update again (Y => Yes/N => NO) : ";
        str[0] = getche();
        if(str[0] == 'Y' || str[0] == 'y' || str[0] == 'N' || str[0] == 'n') b = false;
        else
        {
            system("CLS");
            cout<<"\nAgain : \n"<<endl;
        }
    }
    while(b);
    switch(str[0])
    {
    case 'N':
        break;
    case 'n':
        break;
    default:
        system("CLS");
        goto First;
        break;
    }
End:
    b = true;
}

void Bank_account::Details_account()
{
    bool b = true;
    char ch;
    int select;
First:
    cout<<"\n\tDetails : \n";
    cout<<"\n\t\t\t[ 01 ] - First name\n\n";
    cout<<"\t\t\t[ 02 ] - Last name\n\n";
    cout<<"\t\t\t[ 03 ] - ID\n\n";
    cout<<"\t\t\t[ 04 ] - Job position\n\n";
    cout<<"\t\t\t[ 05 ] - Password\n\n";
    cout<<"\t\t\t[ 06 ] - Total balance\n\n";
    cout<<"\t\t\t[ 07 ] - Type of account\n\n";
    cout<<"\t\t\t[ 08 ] - Number Transfer Money\n\n";
    cout<<"\t\t\t[ 09 ] - Validation of bank bard\n"<<endl;
    cout<<"\t\t\t[ 10 ] - All\n"<<endl;
    cout<<"\t\t\t[ 11 ] - Exit : ^_~\n\n";

    cout<<"Please Select your choice : ";
    cin>>select;
    switch(select)
    {
    case 1:
        cout<<"\n\t\tFirst name : "<<Get_First_Name()<<"\n\n";
        break;
    case 2:
        cout<<"\t\tLast name : "<<Get_Last_Name()<<"\n\n";
        break;
    case 3:
        if(Get_ID() == 0)  cout<<"\t\t\tID : Not Found\n\n";
        else  cout<<"\t\t\tID : "<<Get_ID()<<"\n\n";
        break;
    case 4:
        cout<<"\t\tJob position : "<<Get_As_you()<<"\n\n";
        break;
    case 5:
        cout<<"\t\tPassword : "<<Get_Password()<<"\n\n";
        break;
    case 6:
        cout<<"\t\tTotal balance : "<<Total_balance<<"\n\n";
        break;
    case 7:
        cout<<"\t\tType of account : "<<Type_account<<"\n\n";
        break;
    case 8:
        cout<<"\t\t[ 08 ] - Number Transfer Money : "<<Money_transfers<<"\n\n";
        break;
    case 9:
        if(Bank_card) cout<<"\t\tValidation of bank bard : Valid\n"<<endl;
        else cout<<"\t\tValidation of bank bard : Invalid\n"<<endl;
        break;
    case 10:
        cout<<"\n\t\t\t[ 01 ] - First name : "<<Get_First_Name()<<"\n\n";
        cout<<"\t\t\t[ 02 ] - Last name : "<<Get_Last_Name()<<"\n\n";
        if(Get_ID() == 0)  cout<<"\t\t\tID : Not Found\n\n";
        else  cout<<"\t\t\t[ 03 ] - ID : "<<Get_ID()<<"\n\n";
        cout<<"\t\t\t[ 04 ] - Job position : "<<Get_As_you()<<"\n\n";
        cout<<"\t\t\t[ 05 ] - Password : "<<Get_Password()<<"\n\n";
        cout<<"\t\t\t[ 06 ] - Total balance : "<<Total_balance<<"\n\n";
        cout<<"\t\t\t[ 07 ] - Type of accout : "<<Type_account<<"\n\n";
        cout<<"\t\t\t[ 08 ] - Number Transfer Money : "<<Money_transfers<<"\n\n";
        if(Bank_card) cout<<"\t\t\t[ 09 ] - Validation of bank bard : Valid\n"<<endl;
        else cout<<"\t\t\t[ 09 ] - Validation of bank bard : Invalid\n"<<endl;
        break;
    case 11 :
        do
        {
            cout<<"Are you sure (Y => Yes/N => NO) : ";
            ch = getche();
            if(ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n') b = false;
            else
            {
                system("CLS");
                cout<<"\nRe-enter : \n"<<endl;
            }
        }
        while(b);
        switch(ch)
        {
        case 'Y':
            break;
        case 'y':
            break;
        default:
            system("CLS");
            goto First;
            break;
        }
        break;
    default:
        system("CLS");
        cout<<"\n\tRe-enter : \n"<<endl;
        goto First;
        break;
    }
}

void Bank_account::Delete_account()
{
    Set_First_Name("DELETED");
    Set_Last_Name("DELETED");
    Set_ID(0);
    Set_Password("*********");
    Total_balance = 0;
    Type_account = "DELETED";
    Money_transfers = 0;
    Bank_card = false;
}

class Employees_account : public Person
{
private:
    int Work_Hours;
    string Position;
    float Salary;
public :
    Employees_account()
    {
        Set_First_Name("Not Found");
        Set_Last_Name("Not Found");
        Set_ID(0);
        Set_Password("**********");
        Work_Hours = 0;
        Position = "Not Found";
        Salary = 0;
    }
    void Create_account();
    void Update_account();
    void Details_account();
    void Delete_account();
};

void Employees_account::Create_account()
{
    string str;
    cout<<"\nYour First Name please ^-^ : ";
    getline (cin,str);
    Set_First_Name(str);
    system("CLS");

    cout<<"\nYour Last Name please ^-^ : ";
    getline (cin,str);
    Set_Last_Name(str);
    system("CLS");

    long double d;
    do
    {
        cout<<"\nYour ID please  ^|^ : ";
        cin>>d;
        if(d < 0)
        {
            system("CLS");
            cout<<"\n\nDenied Please re-enter : "<<endl;
        }
    }
    while(d < 0);
    Set_ID(trunc(d));
    system("CLS");

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new line
    do
    {
        cout<<"\nAs you are ( ( A or a ) for Administration | ( E or e ) for Employee | ( C or c ) for customer : ^-^ : ";
        str[0] = getche();
        system("CLS");
    }
    while( Set_As_you(str[0]) == false );
    system("CLS");

    bool b;
    do
    {
        b = false;
        cout<<"\nYour Password ( At least 8 characters ) please ^-^ : ";
        getline (cin,str);
        if( str.size() < 8 )
        {
            system("CLS");
            cout<<"\n\nPlease re-enter ( must be at least 8 characters ): "<<endl;
            b = true;
        }
    }
    while( b );
    Set_Password(str);
    system("CLS");

    cout<<"\n\nYour department please : ";
    getline (cin,Position);
    system("CLS");
    do
    {
        b = false;
        cout<<"\n\n  How much do you work in a day : ";
        cin>>Work_Hours;
        if(Work_Hours < 0 || Work_Hours > 12)
        {
            system("CLS");
            cout<<"\n  Stop lying .\n"<<endl;
            cout<<"  Re-enter : ";
            b = true;
        }
    }
    while(b);
    system("CLS");
    do
    {
        b = false;
        cout<<"\n\n  Your salary Please : ";
        cin>>Salary;
        if(Salary < 0 || Salary > 120000)
        {
            system("CLS");
            cout<<"\n  Stop lying .\n"<<endl;
            cout<<"  Re-enter : ";
            b = true;
        }
    }
    while(b);
    system("CLS");
}

void Employees_account::Update_account()
{
First:
    cout<<"\n\t\t\t[ 01 ] - First name : "<<Get_First_Name()<<"\n\n";
    cout<<"\t\t\t[ 02 ] - Last name : "<<Get_Last_Name()<<"\n\n";
    if(Get_ID() == 0)  cout<<"\t\t\tID : Not Found\n\n";
    else  cout<<"\t\t\t[ 03 ] - ID : "<<Get_ID()<<"\n\n";
    cout<<"\t\t\t[ 04 ] - Job position : "<<Get_As_you()<<"\n\n";
    cout<<"\t\t\t[ 05 ] - Password : "<<Get_Password()<<"\n\n";
    cout<<"\t\t\t[ 06 ] - Department : "<<Position<<"\n\n";
    cout<<"\t\t\t[ 07 ] - Work hours : "<<Work_Hours<<"\n\n";
    cout<<"\t\t\t[ 08 ] - Salary : "<<Salary<<"\n\n";
    cout<<"\t\t\t[ 09 ] - Exit : ^_~\n\n";

    int select;
    cout<<"Please Select your choice : ";
    cin>>select;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new line
    string str;
    bool b;
    long double d;
    switch(select)
    {
    case 1:
        cout<<"\nUPDATE First Name ^-^ : ";
        getline (cin,str);
        Set_First_Name(str);
        system("CLS");
        break;
    case 2:
        cout<<"\nUPDATE Last Name ^-^ : ";
        getline(cin,str);
        Set_First_Name(str);
        system("CLS");
        break;
    case 3:
        do
        {
            cout<<"\nUPDATE ID ^|^ : ";
            cin>>d;
            if(d < 0)
            {
                system("CLS");
                cout<<"\n\nDenied Please re-enter : "<<endl;
            }
        }
        while(d < 0);
        Set_ID(d);
        system("CLS");
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new line
        break;
    case 4:
        do
        {
            cout<<"Update your position : \n";
            cout<<"\nAs you are ( ( A or a ) for Administration | ( E or e ) for Employee | ( C or c ) for customer : ^-^ : ";
            str[0] = getche();
            system("CLS");
        }
        while( Set_As_you(str[0]) == false );
        system("CLS");
        break;
    case 5:
        do
        {
            b = false;
            cout<<"\nUPDATE Pasword ( At least 8 characters ) ^-^ : ";
            getline (cin,str);
            if( str.size() < 8 )
            {
                system("CLS");
                cout<<"\n\nPlease re-enter ( must be at least 8 characters ): "<<endl;
                b = true;
            }
        }
        while( b );
        Set_Password(str);
        system("CLS");
        break;
    case 6:
        cout<<"\n\nUPDATE department : ";
        getline (cin,Position);
        system("CLS");
        break;
    case 7:
        do
        {
            b = false;
            cout<<"\n\n  UPDARE work hours : ";
            cin>>Work_Hours;
            if(Work_Hours < 0 || Work_Hours > 12)
            {
                system("CLS");
                cout<<"\n  Stop lying .\n"<<endl;
                cout<<"  Re-enter : ";
                b = true;
            }
        }
        while(b);
        system("CLS");
        break;
    case 8:
        do
        {
            b = false;
            cout<<"\n\n  UPDATE salary : ";
            cin>>Salary;
            if(Salary < 0 || Salary > 120000)
            {
                system("CLS");
                cout<<"\n  Stop lying .\n"<<endl;
                cout<<"  Re-enter : ";
                b = true;
            }
        }
        while(b);
        system("CLS");
        break;
    case 9:
        do
        {
            b = true;
            cout<<"Are you sure (Y => Yes/N => NO) : ";
            str[0] = getche();
            if(str[0] == 'Y' || str[0] == 'y' || str[0] == 'N' || str[0] == 'n') b = false;
            else
            {
                system("CLS");
                cout<<"\nRe-enter : \n"<<endl;
            }
        }
        while(b);
        switch(str[0])
        {
        case 'Y':
            goto End;
            break;
        case 'y':
            goto End;
            break;
        default:
            system("CLS");
            goto First;
            break;
        }
        break;
    default :
        system("CLS");
        cout<<"Re-enter : \n"<<endl;
        goto First;
        break;

    }

    do
    {
        b = true;
        cout<<"Do you want Update again (Y => Yes/N => NO) : ";
        str[0] = getche();
        if(str[0] == 'Y' || str[0] == 'y' || str[0] == 'N' || str[0] == 'n') b = false;
        else
        {
            system("CLS");
            cout<<"\nAgain : \n"<<endl;
        }
    }
    while(b);
    switch(str[0])
    {
    case 'N':
        break;
    case 'n':
        break;
    default:
        system("CLS");
        goto First;
        break;
    }
End:
    b = true;
}
void Employees_account::Details_account()
{
    bool b = true;
    char ch;
    int select;
First:
    cout<<"\n\tDetails : \n";
    cout<<"\n\t\t\t[ 01 ] - First name\n\n";
    cout<<"\t\t\t[ 02 ] - Last name\n\n";
    cout<<"\t\t\t[ 03 ] - ID\n\n";
    cout<<"\t\t\t[ 04 ] - Job position\n\n";
    cout<<"\t\t\t[ 05 ] - Password\n\n";
    cout<<"\t\t\t[ 06 ] - Department \n\n";
    cout<<"\t\t\t[ 07 ] - Work hours\n\n";
    cout<<"\t\t\t[ 08 ] - Salary\n\n";
    cout<<"\t\t\t[ 09 ] - All\n"<<endl;
    cout<<"\t\t\t[ 10 ] - Exit : ^_~\n\n";

    cout<<"Please Select your choice : ";
    cin>>select;
    switch(select)
    {
    case 1:
        cout<<"\n\t\tFirst name : "<<Get_First_Name()<<"\n\n";
        break;
    case 2:
        cout<<"\t\tLast name : "<<Get_Last_Name()<<"\n\n";
        break;
    case 3:
        if(Get_ID() == 0)  cout<<"\t\t\tID : Not Found\n\n";
        else  cout<<"\t\t\tID : "<<Get_ID()<<"\n\n";
        break;
    case 4:
        cout<<"\t\tJob position : "<<Get_As_you()<<"\n\n";
        break;
    case 5:
        cout<<"\t\tPassword : "<<Get_Password()<<"\n\n";
        break;
    case 6:
        cout<<"\t\tDepartment : "<<Position<<"\n\n";
        break;
    case 7:
        cout<<"\t\tWork hours : "<<Work_Hours<<"\n\n";
        break;
    case 8:
        cout<<"\t\tSalary : "<<Salary<<"\n\n";
        break;
    case 9:
        cout<<"\n\t\t\tFirst name : "<<Get_First_Name()<<"\n\n";
        cout<<"\t\t\tLast name : "<<Get_Last_Name()<<"\n\n";
        if(Get_ID() == 0)  cout<<"\t\t\tID : Not Found\n\n";
        else  cout<<"\t\t\tID : "<<Get_ID()<<"\n\n";
        cout<<"\t\t\tJob position : "<<Get_As_you()<<"\n\n";
        cout<<"\t\t\tPassword : "<<Get_Password()<<"\n\n";
        cout<<"\t\t\tDepartement : "<<Position<<"\n\n";
        cout<<"\t\t\tWork hours : "<<Work_Hours<<"\n\n";
        cout<<"\t\t\tSalary : "<<Salary<<"\n\n";
        break;
    case 10 :
        do
        {
            cout<<"Are you sure (Y => Yes/N => NO) : ";
            ch = getche();
            if(ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n') b = false;
            else
            {
                system("CLS");
                cout<<"\nRe-enter : \n"<<endl;
            }
        }
        while(b);
        switch(ch)
        {
        case 'Y':
            break;
        case 'y':
            break;
        default:
            system("CLS");
            goto First;
            break;
        }
        break;
    default:
        system("CLS");
        cout<<"\n\tRe-enter : \n"<<endl;
        goto First;
        break;
    }
}
void Employees_account::Delete_account()
{
    Set_First_Name("DELETED");
    Set_Last_Name("DELETED");
    Set_ID(0);
    Set_Password("*********");
    Position = "Not Found";
    Work_Hours = 0;
    Salary = 0;
}
class Administrative_account : public Person
{
private:
    float Star;
    double Total_Bank_Safe;
public:
    Administrative_account *Next;
    Administrative_account()
    {
        //cout<<Get_First_Name();
        Set_First_Name("Not Found");
        Set_Last_Name("Not Found");
        Set_ID(0);
        Set_Password("**********");
        Total_Bank_Safe = 0;
        Star = 0;
    }
    void Create_account();
    void Update_account();
    void Details_account();
    void Delete_account();
};

void Administrative_account::Create_account()
{
    string str;
    cout<<"\nYour First Name please ^-^ : ";
    getline (cin,str);
    Set_First_Name(str);
    system("CLS");

    cout<<"\nYour Last Name please ^-^ : ";
    getline (cin,str);
    Set_Last_Name(str);
    system("CLS");

    long double d;
    do
    {
        cout<<"\nYour ID please  ^|^ : ";
        cin>>d;
        if(d < 0)
        {
            system("CLS");
            cout<<"\n\nDenied Please re-enter : "<<endl;
        }
    }
    while(d < 0);
    Set_ID(trunc(d));
    system("CLS");

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new line
    do
    {
        cout<<"\nAs you are ( ( A or a ) for Administration | ( E or e ) for Employee | ( C or c ) for customer : ^-^ : ";
        str[0] = getche();
        system("CLS");
    }
    while( Set_As_you(str[0]) == false );
    system("CLS");

    bool b;
    do
    {
        b = false;
        cout<<"\nYour Password ( At least 8 characters ) please ^-^ : ";
        getline (cin,str);
        if( str.size() < 8 )
        {
            system("CLS");
            cout<<"\n\nPlease re-enter ( must be at least 8 characters ): "<<endl;
            b = true;
        }
    }
    while( b );
    Set_Password(str);
    system("CLS");


    cout<<"\n\n  Total bank safe Please : ";
    cin>>Total_Bank_Safe;
    system("CLS");

    do
    {
        b = false;
        cout<<"\n\n  Your Shares in bank Please (percentage) : ";
        cin>>Star;
        if(Star < 0 || Star > 100)
        {
            system("CLS");
            cout<<"\n  Stop lying .\n"<<endl;
            cout<<"  Re-enter : ";
            b = true;
        }
    }
    while(b);
    Star = (Star * 100) / 5 ;
    system("CLS");
}
void Administrative_account::Update_account()
{
First:
    cout<<"\n\t\t\t[ 01 ] - First name : "<<Get_First_Name()<<"\n\n";
    cout<<"\t\t\t[ 02 ] - Last name : "<<Get_Last_Name()<<"\n\n";
    if(Get_ID() == 0)  cout<<"\t\t\tID : Not Found\n\n";
    else  cout<<"\t\t\t[ 03 ] - ID : "<<Get_ID()<<"\n\n";
    cout<<"\t\t\t[ 04 ] - Job position : "<<Get_As_you()<<"\n\n";
    cout<<"\t\t\t[ 05 ] - Password : "<<Get_Password()<<"\n\n";
    cout<<"\t\t\t[ 06 ] - Total bank safe : "<<Total_Bank_Safe<<"\n\n";
    cout<<"\t\t\t[ 07 ] - Star : "<<Star<<"\n\n";
    cout<<"\t\t\t[ 08 ] - Exit : ^_~\n\n";

    int select;
    cout<<"Please Select your choice : ";
    cin>>select;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new line
    string str;
    bool b;
    long double d;
    switch(select)
    {
    case 1:
        cout<<"\nUPDATE First Name ^-^ : ";
        getline (cin,str);
        Set_First_Name(str);
        system("CLS");
        break;
    case 2:
        cout<<"\nUPDATE Last Name ^-^ : ";
        getline(cin,str);
        Set_First_Name(str);
        system("CLS");
        break;
    case 3:
        do
        {
            cout<<"\nUPDATE ID ^|^ : ";
            cin>>d;
            if(d < 0)
            {
                system("CLS");
                cout<<"\n\nDenied Please re-enter : "<<endl;
            }
        }
        while(d < 0);
        Set_ID(d);
        system("CLS");
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new line
        break;
    case 4:
        do
        {
            cout<<"Update your position : \n";
            cout<<"\nAs you are ( ( A or a ) for Administration | ( E or e ) for Employee | ( C or c ) for customer : ^-^ : ";
            str[0] = getche();
            system("CLS");
        }
        while( Set_As_you(str[0]) == false );
        system("CLS");
        break;
    case 5:
        do
        {
            b = false;
            cout<<"\nUPDATE Pasword ( At least 8 characters ) ^-^ : ";
            getline (cin,str);
            if( str.size() < 8 )
            {
                system("CLS");
                cout<<"\n\nPlease re-enter ( must be at least 8 characters ): "<<endl;
                b = true;
            }
        }
        while( b );
        Set_Password(str);
        system("CLS");
        break;
    case 6:
        cout<<"\n\nUPDATE Total bank safe : ";
        cin>>Total_Bank_Safe;
        system("CLS");
        break;
    case 7:
        do
        {
            b = false;
            cout<<"\n\n  Your Shares in bank Please (percentage) : ";
            cin>>Star;
            if(Star < 0 || Star > 100)
            {
                system("CLS");
                cout<<"\n  Stop lying .\n"<<endl;
                cout<<"  Re-enter : ";
                b = true;
            }
        }
        while(b);
        Star = (Star * 100) / 5 ;
        system("CLS");
        break;
    case 8:
        do
        {
            b = true;
            cout<<"Are you sure (Y => Yes/N => NO) : ";
            str[0] = getche();
            if(str[0] == 'Y' || str[0] == 'y' || str[0] == 'N' || str[0] == 'n') b = false;
            else
            {
                system("CLS");
                cout<<"\nRe-enter : \n"<<endl;
            }
        }
        while(b);
        switch(str[0])
        {
        case 'Y':
            goto End;
            break;
        case 'y':
            goto End;
            break;
        default:
            system("CLS");
            goto First;
            break;
        }
        break;
    default :
        system("CLS");
        cout<<"Re-enter : \n"<<endl;
        goto First;
        break;

    }

    do
    {
        b = true;
        cout<<"Do you want Update again (Y => Yes/N => NO) : ";
        str[0] = getche();
        if(str[0] == 'Y' || str[0] == 'y' || str[0] == 'N' || str[0] == 'n') b = false;
        else
        {
            system("CLS");
            cout<<"\nAgain : \n"<<endl;
        }
    }
    while(b);
    switch(str[0])
    {
    case 'N':
        break;
    case 'n':
        break;
    default:
        system("CLS");
        goto First;
        break;
    }
End:
    b = true;
}
void Administrative_account::Details_account()
{
    bool b = true;
    char ch;
    int select;
First:
    cout<<"\n\tDetails : \n";
    cout<<"\n\t\t\t[ 01 ] - First name\n\n";
    cout<<"\t\t\t[ 02 ] - Last name\n\n";
    cout<<"\t\t\t[ 03 ] - ID\n\n";
    cout<<"\t\t\t[ 04 ] - Job position\n\n";
    cout<<"\t\t\t[ 05 ] - Password\n\n";
    cout<<"\t\t\t[ 06 ] - Total bank safe\n\n";
    cout<<"\t\t\t[ 07 ] - Star\n\n";
    cout<<"\t\t\t[ 08 ] - All\n"<<endl;
    cout<<"\t\t\t[ 09 ] - Exit : ^_~\n\n";

    cout<<"Please Select your choice : ";
    cin>>select;
    switch(select)
    {
    case 1:
        cout<<"\n\t\tFirst name : "<<Get_First_Name()<<"\n\n";
        break;
    case 2:
        cout<<"\t\tLast name : "<<Get_Last_Name()<<"\n\n";
        break;
    case 3:
        if(Get_ID() == 0)  cout<<"\t\t\tID : Not Found\n\n";
        else  cout<<"\t\t\tID : "<<Get_ID()<<"\n\n";
        break;
    case 4:
        cout<<"\t\tJob position : "<<Get_As_you()<<"\n\n";
        break;
    case 5:
        cout<<"\t\tPassword : "<<Get_Password()<<"\n\n";
        break;
    case 6:
        cout<<"\t\tTotal bank safe : "<<Total_Bank_Safe<<"\n\n";
        break;
    case 7:
        cout<<"\t\tStar : "<<Star<<"\n\n";
        break;
    case 8:
        cout<<"\n\t\t\tFirst name : "<<Get_First_Name()<<"\n\n";
        cout<<"\t\t\tLast name : "<<Get_Last_Name()<<"\n\n";
        if(Get_ID() == 0)  cout<<"\t\t\tID : Not Found\n\n";
        else  cout<<"\t\t\tID : "<<Get_ID()<<"\n\n";
        cout<<"\t\t\tJob position : "<<Get_As_you()<<"\n\n";
        cout<<"\t\t\tPassword : "<<Get_Password()<<"\n\n";
        cout<<"\t\t\tTotal bank safe : "<<Total_Bank_Safe<<"\n\n";
        cout<<"\t\t\tStar : "<<Star<<"\n\n";
        break;
    case 9 :
        do
        {
            cout<<"Are you sure (Y => Yes/N => NO) : ";
            ch = getche();
            if(ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n') b = false;
            else
            {
                system("CLS");
                cout<<"\nRe-enter : \n"<<endl;
            }
        }
        while(b);
        switch(ch)
        {
        case 'Y':
            break;
        case 'y':
            break;
        default:
            system("CLS");
            goto First;
            break;
        }
        break;
    default:
        system("CLS");
        cout<<"\n\tRe-enter : \n"<<endl;
        goto First;
        break;
    }

}
void Administrative_account::Delete_account()
{
    Set_First_Name("DELETED");
    Set_Last_Name("DELETED");
    Set_ID(0);
    Set_Password("*********");
    Total_Bank_Safe = 0;
    Star = 0;
}

