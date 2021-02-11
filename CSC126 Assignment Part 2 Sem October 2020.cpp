#include <iostream>
#include <cstring>
using namespace std;



void DisplayBanner()  // function displays the banner below
{
	cout << "\n*********************************************************************\n";
    cout << "           International University eSports Tournament               \n";
    cout << "                    Participants Registration                        \n";
    cout << "*********************************************************************\n";

}

float FeePayment(string cat, char participation)  // function to calculate fee
{
	float fee;

	
		if (cat == "U" || cat == "u")
    {
    	if	    (participation == 'S' || participation == 's')
    	   	     fee = 20.0;
    	   
    	else if (participation == 'T' || participation == 's')
				 fee = 60.0;		 
	}
	
	else if (cat == "P" || cat == "p")
	{
		if	    (participation == 'S' || participation == 's')
    	   	     fee = 40.0;
    	   
    	else if (participation == 'T' || participation == 't')
				 fee = 100.0;		 
	}
	
	return fee;	
}

float CSDiscount(string program, float fee)	 // function to calculate discount
{
	
		if (program == "CS110")
		fee *= 0.5;
		
	return fee;
}
// function for displaying receipt at the end
void displayReceipt(float fee, char participation, string cat, string name) 
{
	
	string pName, catName;
	
	// converts the shortened user input S and T to output Single and Team
	if 		(participation == 'S' || participation == 's' )	
			 pName = "Single";
			 
	else if (participation == 'T' || participation == 't')
			 pName = "Team";
			 
	/* converts the shortened user input U and P
	to output Undergraduate and Postgraduate */
	if 		(cat == "U" || cat == "u")
			 catName = "Undergraduate";
			 
	else if (cat == "P" || cat == "p")
			 catName = "Postgraduate";
	
			 
	cout << "\n------------------------ Registration Receipt ---------------------";
	
	cout << "\nParticipant's Name: " << name;
	cout << "\nParticipant's Category: " << catName;
	cout << "\nType of Participation: " << pName;
	cout << "\nYour total registration fee is RM" << fee;
	cout << "\n\nThank you for your participation!";
	
	cout << "\n--------------------------------------------------------------------";
}

int main()
{
	
	float fee, totalFee ;
	char  participation;
	string cat, id, program, name, decision;
	int sCount = 0, tCount = 0;
	
	do
	{	
		DisplayBanner();
	
		cout << "Enter Student ID: ";
		cin  >> id;
	
		cout << "Enter Student Name: ";
		cin  >> name;
		cin.ignore(100, '\n');  //for enbaling users to enter names with whitespaces
    	
		cout << "Enter Program: ";
		cin  >> program;
	
		cout << "Enter Category (U:Undergraduate|P:Postgraduate): ";
		cin  >> cat;
		
		cout << "Enter Type of Participation (S:Single | T:Team): ";
		cin  >> participation;
		
		// to count how many single and team participation
		if 	    (participation == 'S' || participation == 's')
			     sCount++;	  
				    
		else if (participation == 'T' || participation == 't')
				 tCount++;
				 
		fee = FeePayment(cat, participation);
	
		fee = CSDiscount(program, fee);
	
		displayReceipt(fee, participation, cat, name);
		
		// calculate all of the registration fees
		totalFee += fee;
		
		cout << "\n\nDo you want to continue (y-yes,n-no)? ";
		cin  >> decision;
		
	}
	while (decision == "y" || decision == "Y");
    
	cout << "\n\n\nThe total registration for Single Participation for today : " << sCount;
	cout << "\n\nThe total registration for Team Participation for today : "   	 << tCount;
	cout << "\n\nThe total registration fees for today is RM : "               	 << totalFee;
	
	return 0;
	
}
