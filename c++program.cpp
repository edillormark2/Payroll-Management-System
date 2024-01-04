#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <cstring> // Instead of unistd.h and conio.h
#include <cstdlib>
using namespace std;


    char name[30];
    char id[5];
    char designation[10];
    int choose;
    void waitForEnter();
    int payrate,daysworked;
	float deduction,total_salary,basic_salary;
    char experience[20];
	
	void waitForEnter(){

    cout << "\n\n Press any key to go back to the main menu... ";
    cin.get();
}
  
  void payroll(){
  
    system("cls");
     int total = 1;
    fstream file;
    
    cout <<"\n\t\t EMPLOYEE RECORD" << endl;
    file.open("Em_in.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t ___________________________";
        cout << "\n\t\t\t|                           |";
        cout << "\n\t\t\t|       No Data Found!      |";
        cout << "\n\t\t\t|___________________________|";
        file.close();
    }
    else
    {
        file >> id >> name >> designation;

        cout<<" _____________________________________________________\n";
        cout <<"|            |                     |                  |";
        cout <<"\n|   No.      |       Name          |    Department    |"<<endl;
        cout <<"|____________|_____________________|__________________|\n";
        cout <<"|            |                     |                  |";
        
        while (!file.eof())
        {
            cout << "\n";
            cout <<"|"<< total++ << ". "<<left <<setw (9) << id <<"|"<<" "<< left << setw(20) <<name <<"|"<<" "<< left << setw(15)<< designation<<"  |";
            file >> id >> name >> designation ;
        }
    }
    
    file.close();
    cout <<"\n|____________|_____________________|__________________|\n";

    char checkId[5];
    
    file.open("Em_in.txt", ios::in);
    cout << "\n\n Enter Employee No.: ";
    cin >> checkId;
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> id >> name >> designation ;
        
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                
                cout << " Employee Name: " << name << "\n";
                cout << " Employee No.: " << id << "\n";
                cout << " Employee Department: " << designation << "\n\n";
                
            
 
    cout<<" Enter Rate of Pay: ";
	cin>>payrate;
	cout<<" Enter Days worked: ";
	cin>>daysworked;
     cout<<"\n For Pay Slip ";
        system("pause");
        system("cls");
        
        time_t now=time(0);
        char* dt =ctime(&now);
        cout<<"\n\t\t\t           "<<dt;
        cout<<"\t\t\t\t         P A Y S L I P   ";
        cout<<"\n\n\n Employee: "<<name;
        cout<<"\t\t\t\t\t\t             Department: "<<designation <<left <<setw (60);
       
     
       
    
        
        basic_salary = payrate*daysworked;
        deduction = 600.00+200.00;
        total_salary = basic_salary-deduction;
        cout<<"\n ___________________________ __________________________________ _____________________________";
        cout<<"\n|                           |                                  |                             |";
        cout<<"\n|       EARNINGS            |           DEDUCTION              |         NET PAY             |";
        cout<<"\n|___________________________|__________________________________|_____________________________|";
        cout<<"\n|  Description  |   Amount  |    Description    |    Amount    |  Description  |    Amount   |";
        cout<<"\n|---------------|-----------|-------------------|--------------|---------------|-------------|";
        cout<<"\n| Basic Salary  |  "<<right <<setw (5)<<basic_salary<<".00 |"<<" SSS Payable       |       600.00 | Total Salary  |    "<<right <<setw (5)<<total_salary<<".00 |"<<endl;
        cout<<"| Over Time     |           |"<<" Pag-ibig Payable  |       200.00 |               |             |";
        cout<<"\n|               |           |"<<" Total Deduction   |       "<<deduction<<".00"<<" |               |             |";
        cout<<"\n|_______________|___________|___________________|______________|_______________|_____________|\n\n";
    
}
            file >> id >> name >> designation ;
        }
    }
   file.close();
   
   
   waitForEnter();
   
}

void display() {

    system("cls");
    int total = 1;
    fstream file;
    
    cout <<"\n\t\t EMPLOYEE RECORD" << endl;
    file.open("Em_in.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t ___________________________";
        cout << "\n\t\t\t|                           |";
        cout << "\n\t\t\t|       No Data Found!      |";
        cout << "\n\t\t\t|___________________________|";
        file.close();
    }
    else
    {
        file >> id >> name >> designation;

        cout<<" _____________________________________________________\n";
        cout <<"|            |                     |                  |";
        cout <<"\n|   No.      |       Name          |    Department    |"<<endl;
        cout <<"|____________|_____________________|__________________|\n";
        cout <<"|            |                     |                  |";
        
        while (!file.eof())
        {
            cout << "\n";
            cout <<"|"<< total++ << ". "<<left <<setw (9) << id <<"|"<<" "<< left << setw(20) <<name <<"|"<<" "<< left << setw(15)<< designation<<"  |";
            file >> id >> name >> designation ;
        }
    }
    
    file.close();
   cout <<"\n|____________|_____________________|__________________|\n";
       
    waitForEnter();
  
}

  
  void add() {
  	
    system("cls");
    int total = 1;
    fstream file;
    cout <<"\n\t\t    ADD RECORD " << endl;
    file.open("Em_in.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> id >> name >> designation;

        cout<<" _____________________________________________________\n";
        cout <<"|            |                     |                  |";
        cout <<"\n|   No.      |       Name          |    Department    |"<<endl;
        cout <<"|____________|_____________________|__________________|\n";
        cout <<"|            |                     |                  |";
       
        while (!file.eof())
        {
            cout << "\n";
            cout <<"|"<< total++ << ". "<<left <<setw (9) << id <<"|"<<" "<< left << setw(20) <<name <<"|"<<" "<< left << setw(15)<< designation<<"  |";
            file >> id >> name >> designation ;
        }
    }
    file.close();
    cout <<"\n|____________|_____________________|__________________|\n";
    cout << "\n Enter Employee Number: ";
    cin >> id;
	cout << " Enter Employee Name: ";
    cin >> name;
    cout << " Enter Department: ";
    cin >> designation;
    file.open("Em_in.txt", ios::app | ios::out);
    file << " " << id << " " << name << " " << designation << "\n";
    file.close();
   
}  
void deleted(){
	
    system("cls");
     	
    int total = 1;
    fstream file, file1;
   
    cout <<"\n\t\t  DELETE RECORD " << endl;
    file.open("Em_in.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t ___________________________";
        cout << "\n\t\t\t|                           |";
        cout << "\n\t\t\t|       No Data Found!      |";
        cout << "\n\t\t\t|___________________________|";
        file.close();
    }
    else
    {
        file >> id >> name >> designation ;
        cout<<" _____________________________________________________\n";
        cout <<"|            |                     |                  |";
        cout <<"\n|   No.      |       Name          |    Department    |"<<endl;
        cout <<"|____________|_____________________|__________________|\n";
        cout <<"|            |                     |                  |";
       
        while (!file.eof())
        {
            cout << "\n";
            cout <<"|"<< total++ << ". "<<left <<setw (9) << id <<"|"<<" "<< left << setw(20) <<name <<"|"<<" "<< left << setw(15)<< designation<<"  |";
            file >> id >> name >> designation ;
        }
    }
    file.close();
    char checkId[5];
    int found = 0;
    cout <<"\n|____________|_____________________|__________________|\n";
    file.open("Em_in.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Employee No. To Delete Data: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> id >> name >> designation ;
        while (!file.eof())
        {
            if (strcmp(checkId, id) != 0)
            {
                file1 << " " << id << " " << name << " " << designation << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\t ___________________________";
                cout << "\n\t\t\t|                           |";
                cout << "\n\t\t\t| Successfully Deleted Data !|";
                cout << "\n\t\t\t|___________________________|";
               
            }
            file >> id >> name >> designation;
        }
        if (found == 0)
        {
        	cout << "\n\t\t __________________________";
        	cout << "\n\t\t|                          |";
            cout << "\n\t\t| Employee No. Not Found ! |";
            cout << "\n\t\t|__________________________|";
        }
        file1.close();
        file.close();
        remove("Em_in.txt");
        rename("record.txt", "Em_in.txt");
    
    }
}

void exit(){
  	
	
   system ("cls");
  
   cout<<"\n\n\n\t\t\tAll Rights Reserved 2022 (Mark Daniel Edillor)";
   cout<<"\n\t\t\t\t\t   Good Bye!\n";
  
getchar();
cin.get();
exit (0);
   
  
  }
    
    int main (){
  
  

 int choice;
 char x,y; 
   while (true)
    {
        system("cls");
        cout<<"\n\t\t\t\t _____________________________";
        cout<<"\n\t\t\t\t|                             |";
        cout<<"\n\t\t\t\t|  PAYROLL MANAGEMENT SYSTEM  |";
        cout<<"\n\t\t\t\t|_____________________________|";
        cout<<"\n\t\t\t\t|                             |\n";
        cout << "\t\t\t\t| [1] Payroll                 |" << endl;
        cout << "\t\t\t\t| [2] Employee Record         |" << endl;
        cout << "\t\t\t\t| [3] Add Record              |" << endl;
        cout << "\t\t\t\t| [4] Delete Record           |" << endl;
        cout << "\t\t\t\t| [5] Exit                    |" << endl;
        cout << "\t\t\t\t|_____________________________|";

       start:
        cout << "\n\n\t\t\t\t Enter Your Choice: "; 
        cin >> choice;
       
        switch (choice)
        {
        case 1:
            payroll();
            break;
        case 2:
        	display();
          
            break;
        case 3:
           
             do
            {
                add ();
                cout << "\n\n\n Do you want to add another Employee Record Enter [Y] Yes or [N] No : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            if (x == 'n' || x =='N'){
            	 waitForEnter();
			}
            break;
        case 4:
        		do
            {
                deleted();
                cout << "\n\n\n Do you want to delete another Employee Record Enter [Y] Yes or [N] No : ";
                cin >> y;
            } while (y == 'y' || y == 'Y');
            if (y == 'n' || y =='N'){
            	 waitForEnter();
			}
        	
        	break;
        case 5:
        	exit();
        	break;
        
        default:
        	cout << "\n\t\t\t\t __________________________";
        	cout << "\n\t\t\t\t|                          |";
            cout << "\n\t\t\t\t|     INVALID INPUT!       |";
            cout << "\n\t\t\t\t|    PLEASE TRY AGAIN      |";
            cout << "\n\t\t\t\t|__________________________|";
            
        }
        if (choice >= 6){
        	goto start;
		}
   cin.get();

    }
    
return 0;
}
  
