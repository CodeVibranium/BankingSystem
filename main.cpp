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
using namespace std;

class BankingSystem
{
 public:
 int accountNumber=0;
 //Parametrized Constructors
 BankingSystem()
 {
      
 }
 //Mutators
 void setAccountNumber()
 {
     accountNumber=accountNumber+1;
     cout<<"Account number : "<<accountNumber<<endl;
 }
 
};

int main()
{
    BankingSystem a;
    a.setAccountNumber();
}