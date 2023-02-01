#include <iostream>
#include <stdbool.h>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include <string>
#include <conio.h>
#include <bits/stdc++.h>
#include "Bank.h"

using namespace std;
template<class typeaccount>
class Account
{
public:
    typeaccount acc;
    Account *Next;
};

class Bank_Managment : protected Bank_account,protected Employees_account,protected Administrative_account
{
private:
    Account<Administrative_account> *A = new Account<Administrative_account>() ;//= (Account<Administrative_account>*) malloc(sizeof(Account<Administrative_account>));
    Account<Employees_account> *E = new   Account<Employees_account>();
    Account<Bank_account> *C = new Account<Bank_account>();
public:

    void Del_In_List_Acc(Account<Administrative_account>*);
    void Del_In_List_Acc(Account<Employees_account>*);
    void Del_In_List_Acc(Account<Bank_account>*);
    void User_Options(Account<Administrative_account>*);
    void User_Options(Account<Employees_account>*);
    void User_Options(Account<Bank_account>*);
    void Login();
    void SignUp();
    void Delete();
    friend void Run_bank_App();
};

void Bank_Managment::Del_In_List_Acc(Account<Administrative_account> *D)
{
    Account<Administrative_account> *tmp = A;
    while(tmp->Next != D) tmp = tmp->Next;
    if(tmp != nullptr)
    {
        tmp->Next = D->Next;
        free(D);
    }
}

void Bank_Managment::Del_In_List_Acc(Account<Bank_account> *D)
{
    Account<Bank_account> *tmp = C;
    while(tmp->Next != D) tmp = tmp->Next;
    if(tmp != nullptr)
    {
        tmp->Next = D->Next;
        free(D);
    }
}

void Bank_Managment::Del_In_List_Acc(Account<Employees_account> *D)
{
    Account<Employees_account> *tmp = E;
    while(tmp->Next != D) tmp = tmp->Next;
    if(tmp != nullptr)
    {
        tmp->Next = D->Next;
        free(D);
    }
}

void Bank_Managment::User_Options(Account<Administrative_account>*AU)
{
    int Num;
First:
    do
    {
        system("CLS");
        cout<<"\t\t\t[ 01 ] Update account \n\n";
        cout<<"\t\t\t[ 02 ] Details account \n\n";
        cout<<"\t\t\t[ 03 ] Delete acount \n\n";
        cout<<"\t\t\t[ 04 ] Log out \n\n";
        cout<<"\tYour choice : ";
        cin>>Num;
    }
    while( Num > 4 || Num <= 0 );

    switch(Num)
    {
    case 1:
        AU->acc.Update_account();
        break;
    case 2:
        AU->acc.Details_account();
        break;
    case 3:
        AU->acc.Delete_account();
        if(AU == A)
        {
            A = A->Next;
            free(AU);
        }
        else  Del_In_List_Acc(AU);
        break;
    }
    char c;
    do
    {
        cout<<"\n\nDo you want continue managment ( Y => YES / N => NO ) : ";
        c = getche();
        if(c == 'Y' || c == 'y' || c == 'N' || c == 'n' ) break;
        cout<<"\n\nRe-enter : \n\n";
    }
    while(1);

    switch(c)
    {
    case 'Y':
        goto First;
        break;
    case 'y':
        goto First;
        break;
    default:
        break;
    }
}

void Bank_Managment::User_Options(Account<Bank_account> *CU)
{
    int Num;
First:
    do
    {
        system("CLS");
        cout<<"\t\t\t[ 01 ] Update account \n\n";
        cout<<"\t\t\t[ 02 ] Details account \n\n";
        cout<<"\t\t\t[ 03 ] Delete acount \n\n";
        cout<<"\t\t\t[ 04 ] Log out \n\n";
        cout<<"\tYour choice : ";
        cin>>Num;
    }
    while( Num > 4 || Num <= 0 );

    switch(Num)
    {
    case 1:
        CU->acc.Update_account();
        break;
    case 2:
        CU->acc.Details_account();
        break;
    case 3:
        CU->acc.Delete_account();
        if(CU == C)
        {
            C = C->Next;
            free(CU);
        }
        else  Del_In_List_Acc(CU);
        break;
    }
    char c;
    do
    {
        cout<<"\n\nDo you want continue managment ( Y => YES / N => NO ) : ";
        c = getche();
        if(c == 'Y' || c == 'y' || c == 'N' || c == 'n' ) break;
        cout<<"\n\nRe-enter : \n\n";
    }
    while(1);

    switch(c)
    {
    case 'Y':
        goto First;
        break;
    case 'y':
        goto First;
        break;
    default:
        break;
    }
}

void Bank_Managment::User_Options(Account<Employees_account> *EU)
{
    int Num;
First:
    do
    {
        system("CLS");
        cout<<"\t\t\t[ 01 ] Update account \n\n";
        cout<<"\t\t\t[ 02 ] Details account \n\n";
        cout<<"\t\t\t[ 03 ] Delete acount \n\n";
        cout<<"\t\t\t[ 04 ] Log out \n\n";
        cout<<"\tYour choice : ";
        cin>>Num;
    }
    while( Num > 4 || Num <= 0 );

    switch(Num)
    {
    case 1:
        system("CLS");
        EU->acc.Update_account();
        break;
    case 2:
        system("CLS");
        EU->acc.Details_account();
        break;
    case 3:
        system("CLS");
        EU->acc.Delete_account();
        if(EU == E)
        {
            E = E->Next;
            free(EU);
        }
        else  Del_In_List_Acc(EU);
        break;
    }
    char c;
    do
    {
        cout<<"\n\nDo you want continue managment ( Y => YES / N => NO ) : ";
        c = getche();
        if(c == 'Y' || c == 'y' || c == 'N' || c == 'n' ) break;
        cout<<"\n\nRe-enter : \n\n";
    }
    while(1);

    switch(c)
    {
    case 'Y':
        goto First;
        break;
    case 'y':
        goto First;
        break;
    default:
        break;
    }
}

void Bank_Managment::Login()
{
    Account<Administrative_account> *tmpA = A;
    Account<Employees_account> *tmpE = E;
    Account<Bank_account> *tmpC = C;
    string str1,str2,str3;
First:
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new
    cout<<"  \n\n     Your First Name : ";
    getline (cin,str1);
    cout<<"  \n     Your Last Name : ";
    getline (cin,str2);
    cout<<"  \n     Your Password : ";
    getline (cin,str3);

    while( tmpA != nullptr  )
    {
        if(tmpA->acc.Get_First_Name() == str1 )
        {
            if( tmpA->acc.Get_Last_Name() == str2 )
            {
                if( tmpA->acc.Get_Password() == str3 ) break;
                else
                {
                    system("CLS");
                    cout<<"\n\n\tIncorrect Password re-enter : \n\n"<<endl;
                    goto First;
                    break;
                }
            }
            else
            {
                system("CLS");
                cout<<"\n\n\tIncorrect Last Name re-enter : \n\n"<<endl;
                goto First;
                break;
            }
        }
        tmpA = tmpA->Next;
    }

    while( tmpE != nullptr  )
    {
        if(tmpE->acc.Get_First_Name() == str1 )
        {
            if( tmpE->acc.Get_Last_Name() == str2 )
            {
                if( tmpE->acc.Get_Password() == str3 ) break;
                else
                {
                    system("CLS");
                    cout<<"\n\n\tIncorrect Password re-enter : \n\n"<<endl;
                    goto First;
                    break;
                }
            }
            else
            {
                system("CLS");
                cout<<"\n\n\tIncorrect Last Name re-enter : \n\n"<<endl;
                goto First;
                break;
            }
        }
        tmpE = tmpE->Next;
    }

    while( tmpC != nullptr  )
    {
        if(tmpC->acc.Get_First_Name() == str1 )
        {
            if( tmpC->acc.Get_Last_Name() == str2 )
            {
                if( tmpC->acc.Get_Password() == str3 ) break;
                else
                {
                    system("CLS");
                    cout<<"\n\n\tIncorrect Password re-enter : \n\n"<<endl;
                    goto First;
                    break;
                }
            }
            else
            {
                system("CLS");
                cout<<"\n\n\tIncorrect Last Name re-enter : \n\n"<<endl;
                goto First;
                break;
            }
        }
        tmpC = tmpC->Next;
    }

    if(tmpA != nullptr) User_Options(tmpA);
    else if(tmpC != nullptr) User_Options(tmpC);
    else if (tmpE != nullptr) User_Options(tmpE);
    else
    {
        cout<<"\n\nNot Found account\n\n";
        system("CLS");
        do
        {
            cout<<"\n\nDo you want Login again ( Y => YES / N => NO ) : ";
            str1[0] = getche();
            if(str1[0] == 'Y' || str1[0] == 'y' || str1[0] == 'N' || str1[0] == 'n' ) break;
            system("CLS");
            cout<<"\n\nRe-enter : ";
        }
        while(1);
        switch(str1[0])
        {
        case 'Y':
            goto First;
            break;
        case 'y':
            goto First;
            break;
        default:
            break;
        }
    }
}


void Bank_Managment::SignUp()
{
    int select;
    do
    {
        system("CLS");
        cout<<"\t\t\t[ 01 ] Administration account\n\n";
        cout<<"\t\t\t[ 02 ] Employees account\n\n";
        cout<<"\t\t\t[ 03 ] Customer account\n\n";
        cout<<"\t\t\t[ 04 ] Exit : ^_~\n\n";

        cout<<"\t Your choice : ";
        cin>>select;
    }
    while( select < 0 || select > 4 );
    Account<Administrative_account> *tmp1 = A;
    Account<Bank_account> *tmp3 = C;
    Account<Employees_account> *tmp2 = E;

    Account<Administrative_account> *newacc1 = new Account<Administrative_account>();
    Account<Employees_account> *newacc2 = new Account<Employees_account>();
    Account<Bank_account> *newacc3 = new Account<Bank_account>();

    switch(select)
    {
    case 1:
        while(tmp1->Next != nullptr) tmp1 = tmp1->Next;
        system("CLS");
        newacc1->acc.Create_account();
        break;
    case 2:
        while(tmp2->Next != nullptr) tmp2 = tmp2->Next;
        system("CLS");
        newacc2->acc.Create_account();
        break;
    case 3:
        while(tmp3->Next != nullptr) tmp3 = tmp3->Next;
        system("CLS");
        newacc3->acc.Create_account();
        break;
    }
}

void Run_bank_App()
{
    Bank_Managment B;
    int select;
    char c;
First:
    do
    {
        system("CLS");
        cout<<"\n\n\t\t\t[ 01 ] Log in\n\n";
        cout<<"\t\t\t[ 02 ] Sgin up\n\n";
        cout<<"\t\t\t[ 03 ] Exit : ^_~\n\n";

        cout<<"\t Your choice : ";
        cin>>select;
    }while( select < 0 || select > 3 );

    switch(select)
    {
    case 1:
        B.Login();
        break;
    case 2:
        B.SignUp();
        break;
    case 3:
        break;
    }
    do {
    cout<<"\n\nDo you want re-login or open a new account ( Y => YES / N => NO ) : ";
    c = getche();
    if( c == 'Y' || c == 'y' || c == 'N' || c == 'n' ) break;
    system("CLS");
    cout<<"\n\nRe-enter : ";
    }while(1);

switch(c)
{
case 'Y':
    goto First;
    break;
case 'y':
    goto First;
    break;
default:
    break;
}
}

