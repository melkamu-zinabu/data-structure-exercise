/ we used the following header file
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
struct course{	  
    string coursetitle;
    int courseno;
    int crh;
    char grade;
    struct course *next;
};
struct course*start=NULL;/
// linked list used to store student
struct student{
    string fname;
 	string lname;
 	string id;
    int age;
    string sex;
    struct student *next;
 };
 struct student*head=NULL;
 // linked list used to store registerd student to course
 struct node{
	 string id;
	 string coursetitle;
     int courseno;
     int crh;
     char grade;
     struct node*next;
 };
 struct node *begin=NULL;
// Function to check that if  student Record Already Exist or Not
bool check1(string x)
{
	if (head == NULL)
		return false;

	student* t = new student;
	t = head;

    while (t != NULL)
	{
        if (t->id == x)
            return true;
        t = t->next;
    }

    return false;
}
// Function to check that if  course Record Already Exist or Not
bool check2(int x)
{
	if(start==NULL)
		return false;
	
	course*t=new course;
	t=start;
	
	 while (t != NULL)
	{
        if (t->courseno == x)
            return true;
        t = t->next;
    }

    return false;
}
// Function to check that if  course Record Already Exist or Not
bool check3(int x,string y)
{
	if(begin==NULL)
		return false;
	
	node*t=new node;
	t=begin;
	
	 while (t != NULL)
	{
        if (t->courseno == x&&t->id==y)
            return true;
        t = t->next;
    }

    return false;
}

// Function to insert the  student recordrecord
void Insert_Record(string fname,string lname,string id, int age, string sex){
	// if Record Already Exist
	if (check1(id)) {
		cout << "Student with this "
			<< "record Already Exists\n";
		return;
	}

	// Create new Node to Insert Record
	student* t = new student();
    t->id = id;
    t->fname = fname;
    t->lname = lname;
    t->age = age;
    t->sex = sex;
    t->next = NULL;

	// Insert at Begin
	if (head == NULL) {
		t->next = head;
		head = t;
	}

	// Insert at End
	else {
		student* c = head;
		while (c->next != NULL) {
			c = c->next;
		}
		t->next = c->next;
		c->next = t;
	}
	cout << "Record Inserted "
		<< "Successfully\n";
    system("PAUSE");
    system("CLS");
}
// to register student to acourse
void  recordstudentto(string id,string title,int courseno,int crh)
{
	//  to check if course  Record  and student record already Exist
    if (check1( id)){
        if(check2(courseno)){
		    if (check3(courseno,id)){
    	        cout << "Student with this "
		         << "record Already Exists\n";
                 return;
            }
            // Create new Node to Insert Record
	        node* p = new node;
         	p->id = id;
            p->courseno = courseno;
            p->coursetitle = title;
            p->crh = crh;
            p->next = NULL;
	        // Insert at Begin
	        if (begin == NULL||(head->id >= p->id))
			{
	        	p->next = begin;
		        begin = p;
		    }
	     	// Insert at End
         	else
			 {
		 	    node* c = begin;
		        while (c->next != NULL||(head->id >= p->id))
				 {
		         	c = c->next;
		         }
		         
	           	p->next = c->next;
	        	c->next = p;
		
	         } 
             cout << "Student registerd to course succssfully\n";	
    	}//inner if
	    else{
		cout<<"no course  with this course number"<<endl;
    	}		
   } //outer if clause
   else{
	cout<<"no registerd student with this id"<<endl;
   }

}

// to search student record
void Search_SRecord(string id)
{
    // if head is NULL
    if (!head) {
        cout << "No such Record "
             << "Available\n";
        return;
    }

    // Otherwise
    else {
        student* p = head;
        int flag=0;

        while (p) {
            if (p->id == id) {
                cout << "id Number:"
                     << p->id << endl;
                cout << "fristName:"
                     << p->fname << endl;
                cout << "lastname:"
                     << p->lname << endl;
                cout << "sex:"
                    << p->sex << endl;
			    cout << "age:"
                     << p->age << endl;
               
                flag=1;
            }
            p = p->next;
        }

        if (flag == 0)
            cout << "No such Record "
                 << "Available\n";
       node*t=begin;
       flag=0;
       
       if (t == NULL) {
        cout << "No  student registered to course Record "
            << "Available\n";
    }
    else{
    	cout<<"student registered for a course"<<endl;
        cout<<"_______________________________________________________________"<<endl;
        cout<<left<<setw(14)<<"course title|"<<setw(14)<<"course number|"<<setw(14)
		<<"course hour|"<<setw(14)<<"grade|"<<endl;

        while(t!=NULL)
		{   if(t->id==id)
            cout<<left<<setw(14)<<t->coursetitle<<setw(14)<<t->courseno
			<<setw(14)<<t->crh<<setw(14)<<t->grade<<setw(14)<<endl;
      
            t=t->next;
               
       }

    }
       
    }
    system("pause");
    system("cls");
}
// to delete student record

 int Delete_Record(string id){
    student *prev=NULL;
    student *current=head;

    // Deletion at Begin
    if (current != NULL && current->id== id){
        	
            head = current->next;
            delete current;

            cout << "Record Deleted "
                 << "Successfully\n";
            return 0;
       }

    // Deletion Other than Begin
    while (current != NULL && current->id!= id){
    	
        prev = current;
        current= current->next;
    }
  
    if (current == NULL){
     	
        cout << "Record does not Exist\n";
        return -1; 
	 }
    prev->next = current->next;
    delete current;
    cout << "Record Deleted "
         << "Successfully\n";
     
    system("pause");
    system("cls");
    return 0;
}


// Function to display the Student's Record

void show_SRecord()
{
   //system("pause");
   student* p = head;
   node* t= begin;
    if (p == NULL) {
        cout << "No student Record "
            << "Available\n";
    }
    else {
    	cout<<"registered student"<<endl;
        cout<<"|________________________________________________________________"<<endl;
        cout<<left<<setw(14)<<"id|"<<setw(14)<<"frist name|"<<setw(14)<<"last name|"<<setw(14)
	    <<"age|"<<setw(14)<<"sex|"<<endl;
        	 
        while(p!=NULL){
          	
            cout<<left<<setw(14) <<p->id <<setw(14)<< p->fname<<setw(14)<< p->lname
    	    <<setw(14)<<p->age<<setw(14)<<p->sex<<setw(14)<<endl;
            p=p->next;
               
        }

    }
   
    if (t == NULL) {
        cout << "No  student registered to course Record "
            << "Available\n";
    }
    else{
    	cout<<"student registered for a course"<<endl;
        cout<<"_______________________________________________________________"<<endl;
        cout<<left<<setw(14)<<"id"<<setw(14)<<"course title|"<<setw(14)<<"course number|"<<setw(14)
		<<"course hour|"<<setw(14)<<"grade|"<<endl;

        while(t!=NULL)
		{
            cout<<left<<setw(14)<<t->id<<setw(14)<<t->coursetitle<<setw(14)<<t->courseno
			<<setw(14)<<t->crh<<setw(14)<<t->grade<<setw(14)<<endl;
      
            t=t->next;
               
       }

    }
	system("pause");
    system("cls");
   
}
// to count the number of student registered
void count_SRecord()
{
	int n=0;
	student* a=head;
	if(a==NULL){
		cout<<"no record"<<endl;
	}
	else{	
		while(a!=NULL){
		    a = a->next;
		    n++;
		}
	    cout<<"There are "<<n<<" number of students recorded until now"<<endl;
   }
   system("pause");
   system("cls");
}


// to insert course record
void Insert_CRecord(string coursetitle,int courseno,int crh)
{
    // if Record Already Exist
	if (check2(courseno)) {
		cout << "course with this  "
			<< "record Already Exists\n";
		return;
	}
	// Create new Node to Insert Record
	course* t = new course();
    t->coursetitle = coursetitle;
    t->courseno = courseno;
    t->crh = crh;
    t->next = NULL;

	// Insert at Begin
	if (start == NULL) {
		t->next = start;
		start = t;
	}

	// Insert at middle or End
	else {
		course* c = start;
		while (c->next != NULL) {
			c = c->next;
		}
		t->next = c->next;
		c->next = t;
	}

	cout << "Record Inserted "
		<< "Successfully\n";
    system("PAUSE");
    system("CLS");
}
// to search course record
void Search_CRecord(int courseno)
{
    // if head is NULL
    if (!start) {
        cout << "No such Record "
             << "Available\n";
        return;
    }

    // Otherwise
    else {
        course* p = start;
        int flag=0;
        while (p) {
            if (p->courseno == courseno) {
                cout << "course  Number :"
                     << p->courseno << endl;
                cout << "course title :"
                     << p->coursetitle<< endl;
                cout << "course hour :"
                     << p->crh << endl;
                flag=1;
            }
            p = p->next;
        }

        if (flag==0)
            cout << "No such Record "
                 << "Available\n";
    }
    system("pause");
    system("cls");
}
// to display course list
void show_course(){
	
   course* p = new course();
   p=start;
 
    if (p == NULL) {
        cout << "No course Record "
            << "Available\n";
    }
    else {
	    cout<<"|____________________________________________________________________"<<endl;
        cout<<left<<setw(14)<<"course title|"<<setw(14)<<"course number|"<<setw(14)<<"course hour|"<<endl;

        while(p!=NULL)
		{
            cout<<left<<setw(14)<<p->coursetitle<<setw(14)<<p->courseno<<setw(14)<<p->crh<<endl;
      
            //cout<<"|____________________________________________________________"<<endl;
            p=p->next;
               
           }


    }
    system("pause");
    system("cls");
}
// to delete course record

int  Delete_CRecord(int courseno)
{
    course * t = start;
    course * p = NULL;

    // Deletion at Begin
    if (t != NULL && t->courseno== courseno)
	{
        start = t->next;
        delete t;

        cout << "Record Deleted "
             << "Successfully\n";
        return 0;
    }

    // Deletion Other than Begin
    while (t != NULL && t->courseno!= courseno)
	{
        p = t;
        t = t->next;
    }
    if (t == NULL)
	{
    	cout << "Record does not Exist\n";
    	return -1;
	}
    p->next = t->next;
	delete t;
	cout << "Record Deleted "
         << "Successfully\n";
    
    system("pause");
    system("cls");
    return 0;
}

	
void asc_name_sorting ()//bubble sort
{
  student * temphead = head;
  int age;
  string id;
  string fname,lname,sex;
  int counter = 0;
  while (temphead)
  {
    temphead = temphead->next;
    counter++;
  }
  temphead = head;
  
  for (int j=0; j<counter; j++)
  {
  	
    while (temphead->next)
    {
    	string string1=temphead->fname +" " + temphead->lname;
    	string string2=temphead->next->fname +" " + temphead->next->lname;
    	
      if (string1 > string2)
      {
        id = temphead->id;
        temphead->id = temphead->next->id;
        temphead->next->id = id;

        fname = temphead->fname;
        temphead->fname = temphead->next->fname;
        temphead->next->fname = fname;
        
        lname = temphead->lname;
        temphead->lname = temphead->next->lname;
        temphead->next->lname = lname;
        
        sex = temphead->sex;
        temphead->sex = temphead->next->sex;
        temphead->next->sex = sex;
        
        age= temphead->age;
        temphead->age = temphead->next->age;
        temphead->next->age= age;
      }
      temphead = temphead->next;
    }  
    temphead = head;
  }
}
	
void show_grade(){
	string  id;
	cout<<"enter id of student to see grade"<<endl;
	cin>>id;
	node *t ;
	t=begin;
	 if (t == NULL) {
        cout << "No   Record "
            << "Available\n";
    }
    else { 
        cout<<"The grade of the student with id "<<id<<" is"<<endl;
        cout<<"|_________________________________________________________________________________________"<<endl;
        cout<<left<<setw(14)<<"course title|"<<setw(14)<<"course number|"<<setw(14)
         <<"course hour|"<<setw(14)<<"grade"<<endl;
          
        while(t!=NULL){
		    if(t->id==id)
			{
                cout<<left<<setw(14)<<t->coursetitle<<setw(14)<<t->courseno<<setw(14)
		    	<<t->crh<<setw(14)<<t->grade<<endl;
            }
            t=t->next;
		}
		
	}
    system("pause");
    system("cls");

}
//function to add student grade for a particular course
void addgrade(string id, int courseno, char grade)
{
    node* p=begin;
    int c=0;
	while (p)
	{
	    if (p->id == id && p->courseno==courseno)
		{
            p->grade =grade;
            c++;
            break;
        }
        p = p->next;	
	   
   }
   if(c==1){
   	cout<<"grade added successfuly"<<endl;
	   
   }
   else{
   	cout<<"no match"<<endl;
   }
   system("pause");
   system("cls");
}

// function to modify grade
void modifygrade(string id, int courseno, char grade)
{
    node* p=begin;
    int c=0;
	while (p){
		if (p->id == id && p->courseno==courseno)
		{
		    p->grade =grade;
            c++;
            break;
        }
            p = p->next;
   }
    if(c==1){
   	    cout<<"grade modified successfuly"<<endl;
	   
   }
   else{
   		cout<<"no match"<<endl;
   }
   system("pause");
   system("cls");
}
//function to delete grade of student 
void deletegrade(string id, int courseno){
	
    int c=0;
	node* p=begin;
	while (p)
	{
		
        if (p->id == id && p->courseno==courseno)
		{
			p->grade =NULL;
            c++;
            break;
        }
        p = p->next;
   }
    if(c==1)
	{
     	cout<<"grade deleted successfuly"<<endl;
	   
   }
   else
   {
	   cout<<"no match"<<endl;
   }
   system("pause");
   system("cls");
}

// function to maintain grade of student

void maintains_SRecord(){
    char grade;
    string id;
	int courseno;
	node* p=begin;
	int ch;
	cout<<"choice activities"<<endl;
	cout<<"1.Add grade"<<endl;
	cout<<"2.Modify grade"<<endl;
	cout<<"3.Delete grade"<<endl;
	cout<<"4.see grade of individual student "<<endl;
	cin>>ch;

	if(ch==1)
	{     
        system("cls"); 
		cout<<"enter the id of student you want to add his/her grade"<<endl;
        cin>>id;
        cout<<"enter the course number"<<endl;
        cin>>courseno;
        cout<<"enter the grade you want to maintain"<<endl;
        cin>>grade;
	    addgrade( id, courseno,grade);

	}

	else if(ch==2)
	{
         system("cls");
		 cout<<"enter the id of student you want to modiffy his grade"<<endl;
		 cin>>id;
		 cout<<"enter the course number"<<endl;
  	     cin>>courseno;
         cout<<"enter the grade you want to maintain"<<endl;
         cin>>grade;
	     modifygrade(id,  courseno, grade);
	}
	else if(ch==3)
	{
		system("cls");
		cout<<"enter the id of student you want to delete his grade"<<endl;
        cin>>id;
        cout<<"enter the course number"<<endl;
        cin>>courseno;
        deletegrade( id, courseno);
	}
	else if(ch==4)
	{
		system("cls");
        show_grade();
	}
	else
	{      
	  	cout<<"invalid choice";
        system("pause");
        system("cls");
	}

}

