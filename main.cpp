#include <iostream>

using namespace std;

int me=0;

string name[3]={"samu","mlimo","toriso"};
int pin[3]={3454,2319,7989};
int accountNumber[3]={24536,76541,98087};
int balance[3]={2400,3670,1060};

double Balance;
double withdrawAmount;
double depositAmount;
double cashSend;

bool verification()
{
    int enteredPin;
    cout<<"enter pin"<<endl;
    cin>>enteredPin;

    for(int i=0;i<3;i++)
    {
     if(enteredPin==pin[i])
     {
        me=i;
        cout<<"hello "<<name[me]<<endl;
        cout<<"your balance is R"<<balance[me]<<endl;
        cout<<"AccNo "<<accountNumber[me]<<endl;
        return true;
     }
    }
        cout<<"incorrect pin"<<endl;
        return false;
}


void withdraw()
{
    int amount;
    cout<<"enter amount to withdraw:";
    cin>>amount;

    if(amount<=0)
    {
        cout<<"amount must be more than 0"<<endl;
    }
    else if(amount>balance[me])
    {
        cout<<"not enough money"<<endl;
    }
    else
    {
        balance[me]=balance[me]-amount;
        cout<<"withdraw successful"<<endl;
        cout<<"new balance R"<<balance[me]<<endl;
    }
}

void deposit()
{
    int amount;
    cout<<"enter amount to deposit "<<endl;
    cin>>depositAmount;
    balance[me]=balance[me]+depositAmount;
    cout<<"your current balance is R"<<balance[me]<<endl;
}

void sendCash()
{
    int targetAccount;
    int amount;

    cout<<"enter account number to send to:";
    cin>>targetAccount;

    cout<<"enter amount to send:";
    cin>>amount;

    if(amount<=0)
    {
        cout<<"amount must be more than 0"<<endl;
        return;
    }
    if(amount>balance[me])
    {
        cout<<"not enough money"<<endl;
        return;
    }

    for(int i=0;i<3;i++)
    {
     if(accountNumber[i]==targetAccount)
     {
      if(i==me)
      {
          cout<<"you cannot send to yourself"<<endl;
      }

      balance[me]=balance[me]-amount;
      balance[i]=balance[i]+amount;

      cout<<"sent R" <<amount<<" to "<<name[i]<<endl;
      cout<<"your new balance: R"<<balance[me]<<endl;
      return;
     }
    }
    cout<<"account not found"<<endl;
}
void displayMenu()
{
    int option;
    cout<<"enter 1 to sendCash"<<endl;
    cout<<"enter 2 to deposit"<<endl;
    cout<<"enter 3 to withdraw"<<endl;
    cin>>option;
    switch(option)
    {
    case 1:
        sendCash();
        break;
    case 2:
        deposit();
        break;
    case 3:
        withdraw();
        break;
    }
}
int main()
{
    if(verification())
    {
        displayMenu();
    }
    else
    return 0;
}
