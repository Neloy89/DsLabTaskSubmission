#include<iostream>
using namespace std;

struct BankAccount
{
    int acnum;
    string hname;
    float balance;
};

void deposit(BankAccount &bacc, int x)
{
    bacc.balance+=x;
}
void withdraw(BankAccount &bacc,int x)
{
    bacc.balance-=x;
}
void display(BankAccount bacc)
{
    cout<<"Bank account details"<<endl;
    cout<<"Host name:"<<bacc.hname<<endl;
    cout<<"Account number:"<<bacc.acnum<<endl;
    cout<<"Account balance:"<<bacc.balance<<endl;
}

int main()
{
    BankAccount person1;
    person1.acnum=11122;
    person1.hname="neloy";
    person1.balance=100;
    deposit(person1,500);
    withdraw(person1,60);
    display(person1);

    return 0;
}
