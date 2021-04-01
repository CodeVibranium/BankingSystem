/*
Layout how system should work.
select an option
1.Open an account : Gives Account Number,Enter FName , Enter Lname ,Gives Id, Create Key;
2.Balance Enquiry :Enter Id ,Enter Key,Shows balance;
3.Log history: Shows Widthdrawls,Shows Deposits,Shows account number,Shows Id;
4.Deposit:Show Account number , Gives money;
5.Withdraw: Show Acc number ,Enter Id, Enter Key,Enter amount required;
6.Close account:Enter Account number, Enter Id,Enter Key;
7.Exit;
/*8. SuperUser:Show all accounts.:Shows all account holder names and numbers.
*/

#include<iostream>
#include<cstring>
#include<fstream>
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
    return  Id;
 }

 string getFname()
 {
    return FirstName;
 }

  string getLname()
 {
    return LastName;
 }

float getDeposit()
{
    return Deposit;
}

float getWithdrawl()
{
    return Withdrawl;
}

float getBalance(){
    return getDeposit()-getWithdrawl();
}

void writeData()
{
 ofstream ofs("AccountHolders.txt",ios::app);
    ofs<<"Account number : "<<accountNumber<<endl;
    ofs<<"Account Id:" <<getId()<<endl;
    ofs<<"Äccount holder's First Name : "<<getFname()<<endl;
    ofs<<"Account holder's Last Name : "<<getLname()<<endl;
    ofs<<"Deposited Money : "<<getDeposit()<<endl;
    ofs<<"Withdrawn Money : "<<getWithdrawl()<<endl;
    ofs<<"Current Balance in your account : "<<getBalance()<<endl;
    ofs<<endl;
    ofs.close();
}
void readData()
{   ifstream ifs("AccountHolders.txt");
    string fileContent;

    // ifs>>"First Name : ">>getFname();
    while(getline(ifs,fileContent))
    {
        cout<<fileContent<<endl;
    }
    ifs.close();
}

 
};
 
 
void Layout()
{
   cout<<"****Welcome to Banking System*****";
   cout<<endl;
   cout<<endl;
   cout<<"1.Open an account"<<endl;
   cout<<"2.Balance Enquiry"<<endl;
   cout<<"3.Log Account details"<<endl;
   cout<<"4.Deposit money into your account"<<endl;
   cout<<"5.Withdraw money from the account"<<endl;
   cout<<"6.Close your account"<<endl;
   cout<<"7.Exit"<<endl;
   cout<<endl;
}

int main()
{
   
    int key;
    string F,L;
    int option;
    float deposit,withdrawl;

    BankingSystem a;

    Layout();
    cout<<"Select an option : ";
    cin>>option;

    while(option!=7)
    {
        switch(option)
        {
            case 1: cout<<"Opening an account"<<endl;
                    a.setAccountNumber();
                    cout<<"Enter Your First Name : ";
                    cin>>F;
                    cout<<"Enter your Last Name : ";
                    cin>>L;
                    a.setName(F,L);
                    a.setId();
                    cout<<"Remember your Id and password to access your account later"<<endl;
                    cout<<"This is your account id : "<<a.getId()<<endl;
                    cout<<"Create your account password : ";
                    cin>>key;
                    a.setKey(key);
                     
                    cout<<"Account created successfully";
                    cout<<endl;
                    cout<<endl;
                    break;
            case 2: cout<<"Getting your account balance..."<<endl;
                    cout<<"Your balance : "<<a.showBalance()<<endl;
                    cout<<"Account balance logged successfully";
                    cout<<endl;
                    cout<<endl;
                    break;
            case 3: cout<<"Logging Account Details "<<endl;
                    a.getId();
                    a.readData();
                    break;
            case 4:
                    cout<<"Enter the amount you want to deposit : ";
                    cin>>deposit;
                    a.setDeposit(deposit);
                    a.writeData();
                    cout<<"Account deposited successfully";
                    cout<<endl;
                    cout<<endl;
                    break;
            case 5: 
                    cout<<"Enter the amount you want to withdraw : ";
                    cin>>withdrawl;
                    a.setWithdrawl(withdrawl);
                    cout<<withdrawl<<" was withdrawn successfully"<<endl;
                    cout<<"Your current balance : "<<a.showBalance()<<endl;
                    cout<<endl;
                    break;
            case 6: cout<<"Account closed successfully";
                    cout<<endl;
                    cout<<endl;
                    break;
            default:cout<<"Something went wrong";

        }
        // Layout();
        cout<<"Select an option : ";
        cin>>option;
    }
    cout<<"Thank you, for banking with us!"<<endl;
    cout<<"Have a nice day";

    return 0;
}
