// Trevor Hickey
// Dan Bennett
// Program 5 (Keeping the Books)
// Program Due: 11-11-10
/*
 Purpose:
 This program will will take bank information from one file, make transaactions with another file, and put the
 new calculated data back into the bank file.
 
 Features: 
 Transaction Types:
 -can deposit money
 -can withdraw money
 -can show statements
        
 Error Checking:
 -program will check for mathcing IDs before making a transaction
 
 Notes:
 -I was going to use 'fstream' on 'Balance.dat' since this program imputs AND outputs the file.
  but I'm having trouble clearing the data already in the file once it's read in.
  so for the time being, I have declared BOTH ifstream and ofstream for 'Balance.dat'
  since ofstream automatically clears the contents for writing.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
  
    //outside files this program will interact with
    const string BALANCE = "Balance.dat";
    const string TRANSACTIONS = "Transactions.dat";
  
    //opening a file to both read from and write to
    ifstream balance_input;
    ofstream balance_output;
    //opening file just to read from
    ifstream transactions;
    
    //variables stored from "Balance.dat"
    int balanceID;
    float accountBalance;
    string balanceName;
    
    //variable stored from "Transactions.dat"
    //will hold either 'D', 'W', or 'S'
    char transactionType;
    int transactionID;
    float transactionAmount;
    string transactionComment;
    
    
    //counters for various output throughout the program
    int transactionCounter = 1,
    
        depositCounter = 0,
        withdrawCounter = 0,
        
        depositTotal = 0,
        withdrawTotal = 0,
        
	withdrawErrorCounter = 0,
	depositErrorCounter = 0,
	statementErrorCounter = 0;
	
   
    
    
    //Open files
    //*files must be in the program's directory
    balance_input.open(BALANCE.c_str());
    transactions.open(TRANSACTIONS.c_str());
    
    //tests to make sure files were opened
    if(!balance_input) {
      cout << endl << "ERROR: Failed to open " << "'"<< BALANCE <<"'." << endl
           << "*please make sure you have the file '" << BALANCE <<"' " << "in the same direcotry as this program." <<endl << endl;
      
      return 1;
    }
    if(!transactions) {
      cout << endl << "ERROR: Failed to open " << "'"<<  TRANSACTIONS <<"'." << endl
           << "*please make sure you have the file " << "'"<< TRANSACTIONS <<"' " << "in the same direcotry as this program." <<endl << endl;
      balance_input.close();
      return 1;
    }
    
    //store values from file "Balance.dat"
    balance_input >> balanceID >> accountBalance;
    getline (balance_input,balanceName);
    
    balance_input.close();
    
    
   
    
    //output the Account Information
    cout << endl << endl
         << "Account Name:"         << balanceName     << endl
         << "Your Account Number: " << balanceID       << endl
         << "Account Balance: "     << "$" << accountBalance  << endl
         << endl << endl
         
    //output the transactions performed
         << "Transactions Performed:" << endl;
    
    //while not at the end of the file..
    while(!transactions.eof()) {
        //takes the first character on the current line('D', 'W', 'S')
	//this value will determine which of three following case statements to enter into
        transactions >> transactionType;
	
	
	  //makes the deposit
	  switch (transactionType)
	  {
	    case 'D':
	      //store the Account ID and the amount to be deposited from the current line
	    transactions >> transactionID >> transactionAmount;
	    
	    //stores a comment from the current line (there may not be one)
	      getline (transactions,transactionComment);
	      
	    //before proceding with the transaction, the ID is tested between the two files
	    if (balanceID == transactionID){
	      
	      //deposit transaction value into the current balance
	      accountBalance += transactionAmount;
	      
	      
	      
	      //displays the transaction
	      cout << setw(4)<< right 
	           << transactionCounter 
	           << setw(1)<< left 
	           << ".) "
	           << setw(1)<< left 
	           << "Deposited  $"
	           << setw(8)<< left 
	           << transactionAmount 
	           << setw(1)<< left
	           << " " 
	           <<  setw(10)<< left
	           << "Your new Balance is $" << accountBalance 
	           << "." <<  setw(5)<< left 
	           << " "
	           << transactionComment 
	           << endl;
		   
		   transactionCounter++;
		   depositCounter++;
		   depositTotal+=transactionAmount;
	      
	      //changes values incase the next line in the file does not contain information for them
	      //*the same calculation will not be done multiple times, and the same comment will not be seen multiple times.
	      transactionAmount = 0;
	      transactionComment = "";
	      //change to something other than 'D', 'W', or 'S'
	      //*prevents the while loop from repeating the last action twice
	      transactionType = 'X';
	    }
	    else{
	      //the Account ID do not match between the two files. It skips the transaction and displays a message
	      cout << "       TRANSACTION SKIPPED! (ID ERROR): $" 
	           << transactionAmount 
	           << " was not deposited because the account ID did not match."
	           << endl;
	      depositErrorCounter++;
	    }

	    break;
	    //makes withdrawal
	    case 'W':
	      //store the Account ID and the amount to be withdrawn from the current line
	    transactions >> transactionID >> transactionAmount;
	    //before proceding with the transaction, the ID is tested between the two files
	    
	    //stores a comment from the current line (there may not be one)
	    getline (transactions,transactionComment);
	    if (balanceID == transactionID){
		
	      //withdraws transaction value into the current balance
	      accountBalance -= transactionAmount;
	      
	      //displays the transaction
	      cout << setw(4)<< right 
	           << transactionCounter 
	           << setw(1)<< left 
	           << ".) "
	           << setw(1)<< left 
	           << "Withdrew   $"
	           << setw(8)<< left 
	           << transactionAmount 
	           << setw(1)<< left
	           << " " 
	           <<  setw(10)<< left
	           << "Your new Balance is $" << accountBalance 
	           << "." <<  setw(5)<< left 
	           << " "
	           << transactionComment 
	           << endl;
		   
		   transactionCounter++;
		   withdrawCounter++;
		   withdrawTotal+=transactionAmount;
	      
	      //changes values incase the next line in the file does not contain information for them
	      //*the same calculation will not be done multiple times, and the same comment will not be seen multiple times.
	      transactionAmount = 0;
	      transactionComment = "";
	      //change to something other than 'D', 'W', or 'S'
	      //*prevents the while loop from repeating the last action twice
	      transactionType = 'X';
	    
	    }
	    else{
	      //the Account ID do not match between the two files. It skips the transaction and displays a message
	      cout << "       TRANSACTION SKIPPED! (ID ERROR): $" 
	           << transactionAmount 
	           << " was not withdrawn because the account ID did not match."
	           << endl;
	      withdrawErrorCounter++;
	    }

	    break;
	    //shows statement
	    case 'S':
	      //store the Account ID
	    transactions >> transactionID;
	    //before proceding with the transaction, the ID is tested between the two files
	    if (balanceID == transactionID){
	      cout << endl << "       STATEMENT: A total of " << transactionCounter-1 << " transactions have been performed." << endl
	           << "       " << depositCounter << " transactions were made to deposit a total of $" << depositTotal << "." << endl
	           << "       " << withdrawCounter << " transactions were made a withdraw a total of $"<< withdrawTotal<< "." << endl
	           << "       Your current balance is $" << accountBalance << "." << endl << endl;
	    
	    }
	    else{
	      //the Account ID did not match between the two files.  It skips showing the statement and displays a message.
	      cout << "       STATEMENT CAN NOT BE SHOWN! (ID ERROR): the statment was not shown because the account ID did not match."
	           << endl;
	      statementErrorCounter++;
	    }

	    break;
	  }
    }
      
	 
	 
	 
	 
    //Open file
    //*file must be in the program's directory
    balance_output.open(BALANCE.c_str());
    
    //tests to make sure file was opened
    if(!balance_output) {
      cout << endl << "ERROR: Failed to open " << "'"<< BALANCE <<"'." << endl
           << "*please make sure you have the file '" << BALANCE <<"' " << "in the same direcotry as this program." <<endl << endl;
      
      return 1;
    }
    
    //write account information back into file
    balance_output << balanceID << " " << accountBalance << balanceName;
	 
	 
	 
    //close files
    balance_output.close();
    transactions.close();
    
    
    //output that the program has finished, and display any skipped transactions
    if ((depositErrorCounter == 0) && (withdrawErrorCounter == 0)){
        cout << endl << "       All transactions have been completed succesfully!" << endl;
    }
    else{
      cout << endl << "      Transactions Completed." << endl;
    if (depositErrorCounter != 0){
	cout << "      " << depositErrorCounter;
	if (depositErrorCounter != 1){
	    cout << " deposits were ";
	}
	else{
	    cout << " deposit was ";
	}
	cout << "not made because of an invalid ID!" << endl;
	
    }
    if (withdrawErrorCounter != 0){
      cout << "      " << withdrawErrorCounter;
	if (withdrawErrorCounter != 1){
	    cout << " withdrawals were ";
	}
	else{
	    cout << " withdraw was ";
	}
	cout << "not made because of an invalid ID!" << endl;
	
    }
    }
    
    cout << endl;
    
    
    
    
    
    
 
    return 0;
}