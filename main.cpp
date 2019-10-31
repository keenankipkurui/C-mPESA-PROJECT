//header files used
#include<iostream>
#include<cstdlib>
using namespace std;

// a function to draw a line
void line(){
	cout << "\n\n\t======================================================" << endl;
}

// the class starts here
class transactions
 {
    private: //incapsulation
    	// member varriables
        int accountnum;
        char name[20];
        int deposit;
        int userinput;

    public:
    	// function declarations
        void newAccount();
        void myAccount ()const;
        void depositCash(int);
        void withdrawCash(int);
 }; // end of the class


// function definitions begins

// **********************this function is used to store the users account number, user name and deposit in the incapsulated member varriables****

 void transactions :: newAccount () { // two colons are called the scope resolution
 									  // the scope resolution tells the compiler that the function we are defining is in the transaction class

    cout <<"\n\n\n\tEnter Account number:";
    cin >> accountnum;

    cout<<"\n\tEnter User name:";
    cin >> name;

    cout <<"\n\tEnter first deposit amount(>1000):";
    cin >> deposit;
    line();
    cout<< "\n\tDETAILS UPDATED SUCCESSFULLY!!" << endl;
    cout<< "\n\tPRESS ENTER TO GO BACK TO MAIN MENU"<< endl;
    line();
 }

 // **************function to display account details****************

 void transactions :: myAccount () const {// use the word const because this function does not make any changes on the varriables.
											//its only job is to display
	line();
    cout << "\n\tHELLO" <<"," << name <<endl;

    cout << "\n\tAccount Number:"<< accountnum << endl;

    cout << "\n\tYour account balance is:" << deposit << endl;

    cout<< "\n\tTHANK YOU FOR USING OUR BANKING SERVICE.."<< endl;

    cout<< "\n\tPRESS ENTER TO GO BACK TO MAIN MENU"<< endl;
    line();
 }

 //********************* function used to make a deposit*******
 void transactions :: depositCash(int x) {

	cout << "\n\n\n\tEnter your account number:";
 	cin >> userinput;

 		if (userinput==accountnum){ // checks if the account number entered by the user matches the account number already existing

				cout << "\n\tHELLO" <<"," << name << " Welcome to our Banking Service" << endl;
    			cout <<"\n\tEnter Amount you would like to Deposit:";
    			cin >> x;

				line();
    			cout << "\n\tTRANSACTION COMPLETED" << endl;
				cout << "\n\tYOU HAVE DEPOSITED" <<" "<< x <<" "<< "Shillings SUCCESSFULY"<< endl;

				deposit+=x;

				cout << "\n\tYOUR NEW BALANCE IS:" ;
				cout << deposit << " Shillings" << endl;
				cout<< "\n\tPRESS ENTER TO GO BACK TO MAIN MENU"<< endl;
				line();
		}else{ // if the account number entered does not match the existing num

			line();
			cout << "\n\tTHE ACCOUNT NUMBER ENTERED DOES NOT EXIST" << endl;
			cout<< "\n\tPRESS ENTER TO GO BACK TO MAIN MENU"<< endl;
			line();
	}
}

//  **************function to make a withdrawal*********

void transactions::withdrawCash(int x)
{
	cout << "\n\n\n\tEnter your account number:";
 	cin >> userinput;

 	if (userinput==accountnum){ // checks if the account number entered by the user matches the account number already existing

		cout << "\n\tHELLO" <<"," << name << " Welcome to our Banking Service" << endl;
   		cout <<"\n\tEnter Amount You Would Like to Withdraw:";
    	cin >> x;

			if (x <= deposit){ // checks if the customer has enough money in their account to make the withdrawal
				line();
					// displayed if user has enough money to make withdrawal
				   	cout << "\n\tTRANSACTION COMPLETED" << endl;
					cout << "\n\tYOU HAVE WITHDRAWN" <<" "<< x <<" "<< "Shillings SUCCESSFULY"<< endl;

					deposit-=x;

					cout << "\n\tYOUR NEW BALANCE IS:" << deposit <<" Shillings" <<endl;
					cout<< "\n\tPRESS ENTER TO GO BACK TO MAIN MENU"<< endl;

				line();
				}else{ // this is displayed if user doesnt have enough money in their account
				line();
					cout << "\n\tTRANSACTION FAILED" << endl;
					cout << "\n\tYOU HAVE INSUFFICIENT BALANCE" << "\n\n\tYOUR ACCOUNT BALANCE IS:"<< deposit <<endl;
					cout<< "\n\tPRESS ENTER TO GO BACK TO MAIN MENU"<< endl;
				line();
				}


	}else{ // if the account number entered does not match the existing num
			line();
			cout << "\n\tTHE ACCOUNT NUMBER ENTERED DOESNT EXIST" << endl;
			cout<< "\n\tPRESS ENTER TO GO BACK TO MAIN MENU"<< endl;
   			line();
	}


}
//end of function definitions

// beginning of the main function
int main()
{
    transactions a; // instanciation
	//declarations
	char c;
	int num;

	do
	{
		system ("cls"); // cls means 'clear screen' and makes the output appear in a new empty screen

		cout<<"\n\n\n\tWELCOME TO MONEY BANKING SYSTEM";
		cout<< "\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. CHECK BALANCE";
		cout<<"\n\n\t05. EXIT";
		cout<<"\n\n\tSelect Your Option (1-5) " ;
		cin>>c;

		system ("cls");

	switch(c)
		{
		case '1':
            a.newAccount (); // we call the newAccount function which is in the transaction class
			break;
		case '2':
			a.depositCash(num);
			break;
		case '3':
			a.withdrawCash(num);
			break;
		case '4':
			a.myAccount();
			break;
		 case '5':
			cout<<"\n\n\tThank you for using our banking service";
			break;
		 default :cout<<"\a"; // rings an alert bell if user inputs a number that is not between 1 and 5
		}
		cin.ignore();
		cin.get(); // gets the input by the user
    }while(c!='5');// the loop continues executing until the user enters num 5
	return 0;
}
