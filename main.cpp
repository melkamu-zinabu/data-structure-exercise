// we used the following header file
#include <iostream>// for cout and cin header file
#include <iomanip>// to use setw() function
#include <windows.h>// to use sleep() and to add graphics
#include <conio.h>// to use getch() and clrscr().
#include <stdlib.h>// for exit() function
#include <sstream>//to use streamstring class for converting string to int
#include <limits>//numeric limits
#include "functin.h"
using namespace std;
//macro define password and username constant
#define ADMINUSER "ar"

#define ADMINPASSWORD "112233"

#define USER "st"

// we used the following header file
#include <iostream>// for cout and cin header file
#include <iomanip>// to use setw() function
#include <windows.h>// to use sleep() and to add graphics
#include <conio.h>// to use getch() and clrscr().
#include <stdlib.h>// for exit() function
#include <sstream>//to use streamstring class for converting string to int
#include <limits>//numeric limits
using namespace std;
//macro define password and username constant
#define ADMINUSER "ar"

#define ADMINPASSWORD "112233"

#define USER "st"

#define USERPASSWORD "3443"
// linked list used to store course list


int menu()
{
	char grade;
    string fname,lname,coursetitle, sex,id;

    int age,courseno,crh ,x,n;

    char adminUser[10];

    char adminPassword[10];

    char studentUser[10];// it is for those who choose choose 2 i.e student

    char studentPassword[10];

    string NUM;
    int choice=0;
    
    while(true)
    {   
		cout<<"\n\n\t\t\t\t\tWelcome to Student Management System"<<endl;

        cout<<"\t\t\t\t\t ********************************* \t\t\t"<<endl;
        cout<<"\t\t\t\t\t ****STUDENT MANAGEMENT SYSTEM**** \t\t\t"<<endl;
        cout<<"\t\t \t\t\t********************************* \t\t\t"<<endl;
        cout << "\t\t\tWELCOME! THIS IS THE PROGRAM DESIGNED TO IMPROVE STUDENT MANAGMENT PROCESS \n";
	    cout << "\t\t\tCHOOSE THE PAGE \n";

        cout << "#1. FOR ADMIN PAGE\n";
		cout << "#2. FOR STUDENT PAGE\n";
        cout << "#3. exit\n";

	    cin>>NUM;
	    stringstream obj(NUM);
	    obj>>choice;
	    
	    system("cls");

	    if(choice == 1){

		    cout << "\n\n\n\n\t\t\t\t\tWELCOME TO THE ADMIN PAGE";

            cout << "\n\n Please enter your username: ";

            cin >> adminUser;
	 	   
            cout << "\n Please enter your password:";

            cin >> adminPassword;
          
            if ((strcmp (adminUser, ADMINUSER) == 0) &&
			(strcmp (adminPassword, ADMINPASSWORD) == 0)){

				system ("cls");
				cout<<"\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
                for(int a=1;a<8;a++)
				{
                    Sleep(200);
                    cout << "...";
                }
                cout << "\n\n\n\t\t\t\t\tAccess Granted!! \n\n\n";
                system("CLS");

	            int choice=0;
				 while(choice!=12){
					  cout<<"\t\t*********************************"
	                "\n\t\welcome to STUDENT MANAGEMENT SYSTEM ADMIN PAGE "
                    "\n\t\t*********************************"
                    "\n\t Please choose any option "
                    "\n\t\t1.Register student "
                    "\n\t\t2.Register student to course"
                    "\n\t\t3.Maintain the grade of student"
                    "\n\t\t4.Search a student record by student id"
                    "\n\t\t5.Delete student record by id"
                    "\n\t\t6.Display the details of all student "
                    "\n\t\t7.Sort student record"
                    "\n\t\t8.Count number of student who have been registered"
                    "\n\t\t9.Add course"
                    "\n\t\t10.Search a course by course number"
                    "\n\t\t11.Delete a course by course number"
                    "\n\t\t12.go to main page"
                    "\n\t\t13.Exit"
                    "\n\tenter your choice"<<endl;// write a function  to display  course record and reg
                   	cin>>choice;
	                if (choice == 1){
                        system("cls");
                        cout<<"\t\t\t\t\t ********************************* \t\t\t"<<endl;
                        cout<<"\t\t\t\t\t   REGISTERATION OF STUDENT PAGE"<<endl;
                        cout<<"\t\t\t\t\t ********************************* \t\t\t"<<endl;
                        cout << "Enter frist Name of Student\n";
                        cin >> fname;
                        cout<<"enter last name of student\n";
                        cin>>lname;
                        cout << "Enter id of Student\n";
                        cin >> id;
                        cout<<"enter sex of student\n";
                        cin >> sex;
                        cout << "Enter age of student\n";
                        cin >> age;
                        Insert_Record( fname,lname,id, age,sex );

		            }

		           	else if(choice==2)
					{   do{
                        system("cls");
                        cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t   REGISTERATION OF STUDENT TO COURSES  PAGE"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;
		        	    cout<<"enter id of student who want to register"<<endl;
		        	    cin>>id;
		            	cout<<"\nenter the course title"<<endl;
			            cin>>coursetitle;
			            cout<<"enter course number"<<endl;
			            cin>>courseno;
			            cout<<"enter the crh of the course"<<endl;
                        cin>>crh;

		                recordstudentto( id,coursetitle,courseno,crh);

					    cout<<"enter other than 1 to continue"<<endl;
					    cin>>x;
                        system("CLS");
					} while(x!=1);
					
					}
               	    else if(choice==3){
                        system("cls");
                        cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t   STUDENT GRADE MAINTAINACE PAGE"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;
                        
                        maintains_SRecord();

		        	}

                    else if (choice == 4){
                        system("cls");
                        cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t Searches Student by Id and Displays his/her Details if Found"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;
                        cout << "Enter id Number of Student whose "
                        "record is to be search\n";
                        cin >> id;
                        Search_SRecord(id);
                     }
                     else if (choice == 5)  {
                        system("cls");
                        cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t   Delete Student Record By ID"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;
                        cout << "Enter id Number of Student whose "
                        "record you want to deleted\n";
                        cin >> id;
                        Delete_Record( id);
                      }
                     else if (choice == 6)  {
                        system("cls");
                        cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t  Details of All Students"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;

                        show_SRecord();
                     }

                     else if(choice==7)
					 {
					    system("cls");
					    cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t   Details of All Students Sort by there name"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;
                        asc_name_sorting ();
                        show_SRecord();

		             }

      	             else if(choice==8)
					   {
                        system("cls");
                        cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t  Number of Student Who have been Registered"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;
      	             	count_SRecord();

		               }

      	            else if(choice==9)
					  {
                        system("cls");
                        cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t   Add Course"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;
                        cout << "Enter title of course\n";
                        cin>>coursetitle;
                        cout<<"enter the course number"<<endl;
                        	while(!(cin>>courseno))
                      {
                          cin.clear();
                          cin.ignore(numeric_limits<streamsize>::max(), '\n');
                          cout<<"please enter the valid input "<<endl;
                       }
                        cout<<"enter cridit hour of course"<<endl;
                        cin>>crh;
                        Insert_CRecord( coursetitle,courseno,crh);
                         }

		            else if(choice==10)
					  {
                        system("cls");
                        cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t   Search a Course"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;
		               	cout<<" enter the course number which is  needed to be searched"<<endl;
		              	while(!(cin>>courseno))
                      {
                          cin.clear();
                          cin.ignore(numeric_limits<streamsize>::max(), '\n');
                          cout<<"please enter the valid input "<<endl;
                       }
	                	Search_CRecord(courseno);
	                	
	                   	}

                    else if(choice==11)
					  {
                        system("cls");
                        cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t  Delete a Course"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;
                        cout<<"enter the course number"<<endl;
                      while(!(cin>>courseno))
                      {
                          cin.clear();
                          cin.ignore(numeric_limits<streamsize>::max(), '\n');
                          cout<<"please enter the valid input "<<endl;
                       }
                       
				        Delete_CRecord(courseno);

	                   	}
        	        else if(choice==12) {
						system("CLS");
						
					} 
                    else if (choice == 13)
				      {
				        system("cls");
                        exit(0);
                        }
                    else
					  {
                        cout << "Invalid Choice Try Again\n";
                        }
      
	           }

   	       }
           else 
		   {  
           	
     	   system("cls");
		   cout<<"you entered the wrong password or the wrong admin username"<<endl;
		   cout<<"PLEASE TRY AGAIN";
	       }

		}


  	    else if(choice==2){

		    cout << "\t\t\tWELCOME TO THE STUDENT PAGE" << endl;
            cout << "\n ========== Student Login ==========";
            cout << "\n\n Please enter your user name: ";
            cin >> studentUser;
            cout << "\n Please enter your password:";
            cin >> studentPassword;
            
              if ((strcmp (studentUser, USER) == 0) &&
            (strcmp (studentPassword, USERPASSWORD) == 0)){

			    int choice = 0;
                system("cls");

                while(choice!=8){
                    
					  cout<<"\t\t**************************************************"
	                "\n\t\t         WELCOME TO STUDENT RECORD System STUDENT PAGE "
                    "\n\t\t********************************************************"
                    "\n\tplease choose any option "
                    "\n\t\t1.Register Student "
                    "\n\t\t2.Register Student to Course "
                    "\n\t\t3.see your grade of all course"
                    "\n\t\t4.see the course list you can register for"
                    "\n\t\t5.To Count Number of Student Registered"
                    "\n\t\t6.To Search a Course"
                    "\n\t\t7.To Show all Course list"
                    "\n\t\t8.go to main page"
                    "\n\t\t9.exit"
                    "\n\tenter your choice"<<endl;
                 	cin>>choice;

	                if (choice == 1) {
                          system("cls");
                        cout<<"\t\t\t\t\t ********************************* \t\t\t"<<endl;
                        cout<<"\t\t\t\t\t   REGISTERATION OF STUDENT PAGE"<<endl;
                        cout<<"\t\t\t\t\t ********************************* \t\t\t"<<endl;
     	                cout << "Enter frist Name of Student\n";
                        cin >> fname;
                        cout<<"enter last name of student\n";
                        cin>>lname;
                        cout << "Enter id of Student\n";
                        cin >> id;
                        cout<<"enter sex of student\n";
                        cin >> sex;
                        cout << "Enter age of student\n";
                        cin >> age;
                        Insert_Record( fname,lname,id, age,sex );
        		            }
                    else if(choice==2)
					{
						do{
					    system("cls");
                        cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t   REGISTERATION OF STUDENT TO COURSES  PAGE"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;
                        cout<<"enter id of student who want to register"<<endl;
		            	cin>>id;
		             	cout<<"enter the course title"<<endl;
		            	cin>>coursetitle;
		            	cout<<"enter course number"<<endl;
			            cin>>courseno;
		            	cout<<"enter the crh of the course"<<endl;
		            	cin>>crh;
						recordstudentto( id,coursetitle,courseno,crh);
                        cout<<"enter other than 1 to continue"<<endl;
                        cin>>x;
                        system("CLS");

                      }while(x!=1);
			        }
	            	else if(choice==3)
					{
					    system("cls");
                        cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t      your grade of all course are"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;

		                show_grade();

		            }
                    else if (choice == 4)
					{   system("cls") ;
                        cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t      The course list you can register for are"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;
 
					    show_course();
                    }
                   
	             	else if(choice==5)
					 {
					    system("cls");
                        cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t  Number of Student Who have been Registered"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;
					    count_SRecord();
	               	}
	             	else if(choice==6)
					 {
                        system("cls");
                        cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t   Search a Course"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;
                        cout<<" enter the number of course which needed to be searched"<<endl;
                       	while(!(cin>>courseno))
                      {
                          cin.clear();
                          cin.ignore(numeric_limits<streamsize>::max(), '\n');
                          cout<<"please enter the valid input "<<endl;
                       }
	                   	Search_CRecord(courseno);

	             	}
	             	else if(choice==7)
					 {
                        system("cls");
                        cout<<"\t\t\t\t\t ***********************************************\t\t\t"<<endl;
                        cout<<"\t\t\t\t\t   show all Course list"<<endl;
                        cout<<"\t\t\t\t\t *********************************************** \t\t\t"<<endl;
                        show_course();

	             	}
	             	else if (choice==8){
						system("cls"); 
					 }
                    else if (choice == 9)
					 {  system("CLS");
                        exit(0);
                     }
                    else
					 {

                        cout << "Invalid Choice "
                        << "Try Again\n";
                     }

				}

			}
			else
			{   system("cls");
		        cout<<"you entered the wrong password or the wrong student username"<<endl;
		        cout<<"PLEASE TRY AGAIN";
	       }

       }
    	else if(choice==3)
		{ 
		    exit(0);
		}
		
 		else
		 {
		    cout << "Invalid Choice Try Again\n";
		 }
	}// end of while loop

    return 0;
}// end of menu() function

int main(){
    system("color 27");
	menu();
	return 0;
}