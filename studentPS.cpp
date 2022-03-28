//Student Mangement System
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
using namespace std;

class student
    {
        private:
        string name,enrollment_no,course,branch,contact_no,email_id,address;
        public:
        void menu();
        void insert();
        void display();
        void modify();
        void search();
        void deleted();
    };
void student::menu()  //menu
{
    menustart:
    int choice;
    char x;
    system ("cls");
    
    cout<<"\t\t\t------------------------------"<<endl;
    cout<<"\t\t\t| STUDENT MANAGEMENT SYSTEM |"<<endl;
    cout<<"\t\t\t------------------------------"<<endl;
    cout<<"\t\t\t 1. Enter new record"<<endl;
    cout<<"\t\t\t 2. Display record"<<endl;
    cout<<"\t\t\t 3. Modify record"<<endl;
    cout<<"\t\t\t 4. Search record"<<endl;
    cout<<"\t\t\t 5. Delete record"<<endl;
    cout<<"\t\t\t 6. Exit"<<endl;

    cout<<"\t\t\t--------------------------------"<<endl;
    cout<<"\t\t\t|Choose your Option|1,2,3,4,5,6|"<<endl;
    cout<<"\t\t\t--------------------------------"<<endl;
    cout<<"\t\t\tEnter your choose: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
    do
   {
        insert();
        cout<<"\n\t\t\t Add Another Student Record (Y,N): ";
        cin>>x;
   }    while (x =='y' || x =='Y');  
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
            exit(0);
    default:
        cout<<"\n\t\t\t Invalid Choice....Please Try Again....";
    }
    getch();
    goto menustart;
}
void student::insert()  //insertion of student details
    {
        system("cls");
        fstream file;
        cout<<"\t\t\t--------------------------------------------------------"<<endl;
        cout<<"\t\t\t-------------------Add Student Details------------------"<<endl;
        cout<<"\t\t\t--------------------------------------------------------"<<endl;
        cout<<"\n\t\t\t Enter Name: ";
        cin>>name;
        cout<<"\n\t\t\t Enter Enrollment_no: ";
        cin>>enrollment_no;
        cout<<"\n\t\t\t Enter Course: ";
        cin>>course;
        cout<<"\n\t\t\t Enter Branch: ";
        cin>>branch;
        cout<<"\n\t\t\t Enter Contact_no: ";
        cin>>contact_no;
        cout<<"\n\t\t\t Enter Email_id: ";
        cin>>email_id; 
        cout<<"\n\t\t\t Enter Address: ";
        cin>>address;
        file.open("StudentRecords.txt",ios::app | ios::out);
        file<<" "<<name<<" "<<enrollment_no<<" "<<course<<" "<<branch<<" "<<contact_no<<" "<<email_id<<" "<<address<<"\n";
        file.close();
    }
void student::display()   //Display of student details
    {
       system("cls");
       int total=1;
       fstream file; 
       cout<<"\t\t\t--------------------------------------------------------"<<endl;
       cout<<"\t\t\t-------------------Student Record Table------------------"<<endl;
       cout<<"\t\t\t--------------------------------------------------------"<<endl;
       file.open("StudentRecords.txt",ios::in);
       if(!file)
       {
            cout<<"\n\t\t\tNo Data Is Present....";
            file.close();
       }
       else
       {
           file>> name >> enrollment_no >> course >> branch >> contact_no >> email_id >> address;
           while(!file.eof())
           {
               cout<<"\n\n\t\t\t Student No.: "<< total++ << endl;
               cout<<"\t\t\t Student Name: "<< name << endl;
               cout<<"\t\t\t Student Enrollment No.: "<< enrollment_no << endl;
               cout<<"\t\t\t Student Course: "<< course << endl;
               cout<<"\t\t\t Student Branch: "<< branch << endl;
               cout<<"\t\t\t Student Contact No.: "<< contact_no << endl;
               cout<<"\t\t\t Student Email Id: "<< email_id << endl;
               cout<<"\t\t\t Student Address: "<< address << endl;
               file>> name >> enrollment_no >> course >> branch >> contact_no >> email_id >> address;
           }
       if(total == 0)
       {
          cout<<"\n\t\t\tNo Data Is Present...."; 
       } 
    }
    file.close();
}
void student::modify()   // Modify of student Details
{
    system("cls");
    string enrollmentno;
    fstream file,file1;
    int found=0;
    cout<<"\t\t\t--------------------------------------------------------"<<endl;
    cout<<"\t\t\t-----------------Student Modify Details-----------------"<<endl;
    cout<<"\t\t\t--------------------------------------------------------"<<endl;
    file.open("StudentRecords.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\t\tNo Data Is Present....";
    }
   else
   {
       cout<<"\n\t\t\t Enter Enrollment No. of Student which you want to Modify: ";
       cin>>enrollmentno;
       file1.open("Records.txt",ios::app | ios::out);
       file>> name >> enrollment_no >> course >> branch >> contact_no >> email_id >> address;
        while (!file.eof())
        {
            if(enrollmentno != enrollment_no)
            {
            file1<<" "<<name<<" "<<enrollment_no<<" "<<course<<" "<<branch<<" "<<contact_no<<" "<<email_id<<" "<<address<<"\n";
            }
            else
            {
                cout<<"\t\t\t Enter Name: ";
                cin>>name;
                cout<<"\t\t\t Enter Enrollment_no: ";
                cin>>enrollment_no;
                cout<<"\t\t\t Enter Course: ";
                cin>>course;
                cout<<"\t\t\t Enter Branch: ";
                cin>>branch;
                cout<<"\t\t\t Enter Contact_no: ";
                cin>>contact_no;
                cout<<"\t\t\t Enter Email_id: ";
                cin>>email_id; 
                cout<<"\t\t\t Enter Address: ";
                cin>>address;
                file1<<" "<<name<<" "<<enrollment_no<<" "<<course<<" "<<branch<<" "<<contact_no<<" "<<email_id<<" "<<address<<"\n";
                found++;
            }
            file>> name >> enrollment_no >> course >> branch >> contact_no >> email_id >> address;
            if(found==0)
            {
               cout<<"\n\t\t\t Student Enrollment No Not Found....";
            }  
        }
        file1.close();
        file.close();
        remove("StudentRecords.txt");
        rename("Records.txt","StudentRecords.txt");
    }
}
void student::search()  //Search of Student Data
{
    system("cls");
    int found=0;
    fstream file;
    file.open("StudentRecords.txt",ios::in);
    if(!file)
    {
        cout<<"\t\t\t--------------------------------------------------------"<<endl;
        cout<<"\t\t\t-------------------Student Data Search------------------"<<endl;
        cout<<"\t\t\t--------------------------------------------------------"<<endl;
        cout<<"\n\t\t\tNo Data Is Present....";
    }
    else
    {
        string enrollmentno;
        cout<<"\t\t\t--------------------------------------------------------"<<endl;
        cout<<"\t\t\t-------------------Student Data Search------------------"<<endl;
        cout<<"\t\t\t--------------------------------------------------------"<<endl;
        cout<<"\n\t\t\t Enter Enrollment No. of Student which you want to Search: ";
        cin>>enrollmentno;
        file>> name >> enrollment_no >> course >> branch >> contact_no >> email_id >> address;
        while (!file.eof())
        {
            if(enrollmentno == enrollment_no)
            {
                cout<<"\n\t\t\t Student Name: "<< name << endl;
                cout<<"\t\t\t Student Enrollment No.: "<< enrollment_no << endl;
                cout<<"\t\t\t Student Course: "<< course << endl;
                cout<<"\t\t\t Student Branch: "<< branch << endl;
                cout<<"\t\t\t Student Contact No.: "<< contact_no << endl;
                cout<<"\t\t\t Student Email Id: "<< email_id << endl;
                cout<<"\t\t\t Student Address: "<< address << endl;
                found++;
            }
        file>> name >> enrollment_no >> course >> branch >> contact_no >> email_id >> address;
        }
        if(found==0)
        {
            cout<<"\n\t\t\t Student Enrollment No Not Found....";
        }
        file.close();
    }
}
void student::deleted()
{
    system("cls");
    int found=0;
    string enrollmentno;
    fstream file,file1;
    cout<<"\t\t\t--------------------------------------------------------"<<endl;
    cout<<"\t\t\t-----------------Delete Student Details-----------------"<<endl;
    cout<<"\t\t\t--------------------------------------------------------"<<endl;
    file.open("StudentRecords.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\t\tNo Data Is Present....";
    }
    else
    {
        cout<<"\n\t\t\t Enter Enrollment No. of Student which you want to Search: ";
        cin>>enrollmentno;
        file1.open("Records.txt",ios::app | ios::out);
        file>> name >> enrollment_no >> course >> branch >> contact_no >> email_id >> address;
        while(!file.eof())
        {
            if(enrollmentno != enrollment_no)
            {
                file1<<" "<<name<<" "<<enrollment_no<<" "<<course<<" "<<branch<<" "<<contact_no<<" "<<email_id<<" "<<address<<"\n";
            }
            file>> name >> enrollment_no >> course >> branch >> contact_no >> email_id >> address;
        }
        if(found==0)
        {
            cout<<"\n\t\t\t Student Data deleted....";
        }
        file1.close();
        file.close();
        remove("StudentRecords.txt");
        rename("Records.txt","StudentRecords.txt");
    }
}
main()
{
    student project;
    project.menu();

    return 0;
}

