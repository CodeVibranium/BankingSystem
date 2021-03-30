/*
Layout how system should work.
select an option
1.Open an account : ,Account Number, FName , Lname ,Id, Key;
2.Balance Enquiry :Id ,Key,Shows balance;
3.Log history: Widthdrawls,Deposits,account number,Id;
4.Deposit:Account number , money;
5.Withdraw: Acc number ,Id, Key,amount required;
6.Close account:Account number, Id, Key;
7.Exit;
/*8. SuperUser:Show all accounts.:Shows all account holder names and numbers.
*/

#include<iostream>
#include<cstring>
using namespace std;

class BankingSystem
{
private:
 string FirstName;
 string LastName;
 int Id;
 int Key;
 float Deposit;
 float Withdrawl;
public:
 int accountNumber=0;
 int id;
 int Balance;

 //Parametrized Constructors
 BankingSystem(string F="none",string L="none",int key=0,float deposit=0.0,float withdrawl=0.0 )
 {
    setName(F, L);
    setId();
    setKey(key);
    setDeposit(deposit);
    setWithdrawl(withdrawl);
 }
 //Mutators
 void setAccountNumber()
 {
     accountNumber=accountNumber+1;
     cout<<"Account number : "<<accountNumber<<endl;
 }
 void setName(string F,string L)
 {
    FirstName=F;
    LastName=L;
 }

 void setId()
 {  id = rand() % 80 + 19855149; 
    Id=id;
 }
 void setKey(int key)
 {
     Key=key;
 }
 void setDeposit(float deposit)
 {
     Deposit=deposit;
 }
 void setWithdrawl(float withdrawl)
 {
     if(withdrawl>Deposit)
         cout<<"You dont enough funds!!";
    else
     Withdrawl=withdrawl;
 }
 float showBalance()
 {
     return -Withdrawl+Deposit;
 }

//  Accessors
 int getId() 
 {
     return Id;
 }
};

int main()
{
    int key;
    string F,L;
    float deposit,withdrawl;

    BankingSystem a;

    a.setAccountNumber();
    cout<<"Enter Your First Name : ";
    getline(cin,F);
    cout<<"Enter your Last Name : ";
    getline(cin,L);
    a.setName(F,L);
    a.setId();
    cout<<"This is your account id : "<<a.getId()<<endl;
    cout<<"Enter your password : ";
    cin>>key;
    a.setKey(key);
    cout<<"Enter the amount you want to deposit : ";
    cin>>deposit;
    a.setDeposit(deposit);
    cout<<"Enter the amount you want to withdraw : ";
    cin>>withdrawl;
    a.setWithdrawl(withdrawl);
    cout<<"Your balance : "<<a.showBalance();

    return 0;
}