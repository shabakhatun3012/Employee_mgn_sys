// Employee Management System With File Handling in C++.
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<fstream>
#include<windows.h>
using namespace std;
class emp
{
	private:
		int emp_id,sal,group_id;
		string name,address;//variable declaration
	public:
		void menu();
		void insert();
		void display();
		void search();
		void modify();
		void del();
		void group();
		void search_group();
		void show_group();
};
	void login()
	{
		p:
		system("cls");
		char ch;
		string user,pass;
		cout<<"\n\n\n\n\n";
		cout<<"\t\t\t==============================";
		cout<<"\n\n\t\t\t\tLogin Process";
		cout<<"\n\n\t\t\t==============================";
		cout<<"\n\n\n Enter User Name : ";
		cin>>user;
		cout<<"\n\n Enter Password : ";
		for(int i=1;i<=4;i++)
		{
			ch = getch();
			pass += ch;
			cout<<"*";
		}
		if(user == "shaba" && pass == "khan")
		{
			cout<<"\n\n\n\t\t\tCongratulation Login Successfully...";
			cout<<"\n\n\n\t\t\t\t\tLoading";
			for(int i=1;i<=6;i++)
			{
				Sleep(500);
				cout<<".";
			}
		}
		else if(user != "shaba" && pass == "khan")
		{
			cout<<"\n\n\n Your User Name is Wrong....";
			getch();
			goto p;
		}
		else if(user == "shaba" && pass != "khan")
		{
			cout<<"\n\n\n Your Password is Wrong....";
			getch();
			goto p;
		}
		else
		{
			cout<<"\n\n\n User Name & Password Both are Wrong....";
			getch();
			exit(0);
		}
	}
	void intro()
	{
		system("cls");
		cout<<"\n\n\n\n\n";
		cout<<"\t\t\t==============================";
		cout<<"\n\t\t\t==============================";
		cout<<"\n\n\t\t\t\tWELCOME";
		cout<<"\n\n\n\t\t\tIt is possible for ordinary people to choose to be extraordinary" ;
		cout<<"\n\n\t\t\t-Elon Musk" ;
		cout<<"\n\n\t\t\t==============================";
		cout<<"\n\t\t\t==============================";
		getch();
		system("cls");
		cout<<"\n\n\n\n\n\n\n";
		cout<<"\t\t\t==============================";
		cout<<"\n\t\t\t==============================";
		cout<<"\n\n\t\t\t  Employee Management System";
		cout<<"\n\n\n\t\t\t\tVersion : 1.1";
		cout<<"\n\n\t\t\t==============================";
		cout<<"\n\t\t\t==============================";
		getch();
		system("cls");
		cout<<"\n\n\n";
		cout<<"\t\t\t====================================";
		cout<<"\n\t\t\t====================================";
		cout<<"\n\n\t\t\t\t    Introduction";
		cout<<"\n\n\t\t\t====================================";
		cout<<"\n\t\t\t====================================";
		cout<<"\n\n\t\t\t Name :		Shaba Khatun";
		cout<<"\n\t\t\t Class :	Btech Computer Science And Engg.";
		cout<<"\n\t\t\t Section :	K18SJ";
		cout<<"\n\t\t\t Roll No. :	11802407";
		cout<<"\n\t\t\t Course Code:	CSE202";
		cout<<"\n\t\t\t Institute :	Lovely Professional University";
		cout<<"\n\n\t\t\t====================================";
		cout<<"\n\t\t\t====================================";
		getch();
	}
	void emp::menu()
	{
		p:
		system("cls");
		int x;
		cout<<"\n\n\t\t\t\tControl Panel";
		cout<<"\n\n\n 1. Insert Record";
		cout<<"\n 2. Display Record";
		cout<<"\n 3. Search Record";
		cout<<"\n 4. Modify Record";
		cout<<"\n 5. Delete Record";
		cout<<"\n 6. Group Record";
		cout<<"\n 7. Search Group";
		cout<<"\n 8. Show All Groups";
		cout<<"\n 9. Exit";
		cout<<"\n\n Your Choice : ";
		cin>>x;
		switch(x)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				search();
				break;
			case 4:
				modify();
				break;
			case 5:
				del();
				break;
			case 6:
				group();
				break;
			case 7:
				search_group();
				break;
			case 8:
				show_group();
				break;
			case 9:
				exit(0);
			default:
				cout<<"\n\n Invalid Value...Please try Again...";
		}
		getch();//back to control pannel 
		goto p;//we have to give label from where we want to start
	}
	void emp::insert()
	{
		system("cls");
		int test_id,found=0;
		fstream file,file1;//fstream for read write.employee record -file ,group record-file1
		cout<<"\n\n\t\t\t\tInsert Record";
		cout<<"\n\n\n Employee ID : ";
		cin>>emp_id;
		cout<<"\n\n\t\tEmployee Name : ";
		cin>>name;
		cout<<"\n\n Employee Salary : ";
		cin>>sal;
		cout<<"\n\n\t\tEmployee Address : ";
		cin>>address;
		cout<<"\n\n Employee Group ID : ";
		cin>>group_id;
		//employe data store in file
		file.open("emp.txt",ios::out|ios::app);//file name,file write mode ios::out||to save parmnanet data in file along with previous data ios::append
		file<<" "<<emp_id<<" "<<name<<" "<<sal<<" "<<address<<" "<<group_id<<"\n";
		file.close();
		//group data store in file
		file1.open("group.txt",ios::out|ios::app);
		file1<<" "<<group_id<<" "<<emp_id<<" "<<sal<<"\n";
		file1.close();
		
		file.open("groupid.txt",ios::in); 
		if(!file)
		{
			file1.open("groupid.txt",ios::app|ios::out);
			file1<<" "<<group_id<<"\n";
			file1.close();
		}
		else
		{
			file>>test_id;
			while(!file.eof())
			{
				if(test_id == group_id)
				found++;
				file>>test_id;
			}
			file.close();
			if(found == 0)
			{
				file1.open("groupid.txt",ios::app|ios::out);
				file1<<" "<<group_id<<"\n";
				file1.close();
			}
		}
		cout<<"\n\n\n\t\t\tNew Record Inserted Successfully...";
	}
	void emp::display()
	{
		system("cls");
		fstream file;
		cout<<"\n\n\t\t\t\tDisplay Record";
		file.open("emp.txt",ios::in);//access employe data file for input reading 
		if(!file)//when file not found
		{
			cout<<"\n\n File Openning Error...";
			getch();//wait for command
			menu();
		}
		//data got parmanently save in file
		file>>emp_id>>name>>sal>>address>>group_id;
		//for whole data print we use while loop
		while(!file.eof())//eof -end of file
		{
			cout<<"\n\n\n\n Employee ID : "<<emp_id;
			cout<<"\n\n\t\tEmployee Name : "<<name;
			cout<<"\n\n Employee Salary : "<<sal;
			cout<<"\n\n\t\tEmloyee Address : "<<address;
			cout<<"\n\n Group ID : "<<group_id;
			file>>emp_id>>name>>sal>>address>>group_id;
		}
		file.close();
	}
	void emp::search()
	{
		system("cls");
		fstream file;
		int emp_idd,found=0;
		cout<<"\n\n\t\t\t\tSearch Record";
		file.open("emp.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
			getch();
			menu();
		}
		cout<<"\n\n Employee ID For Search : ";
		cin>>emp_idd;
		file>>emp_id>>name>>sal>>address>>group_id;
		while(!file.eof())
		{
			if(emp_idd == emp_id)
			{
			system("cls");
			cout<<"\n\n\t\t\t\tSearch Record";
			cout<<"\n\n Employee ID : "<<emp_id;
			cout<<"\n\n\t\tEmployee Name : "<<name;
			cout<<"\n\n Employee Salary : "<<sal;
			cout<<"\n\n\t\tEmloyee Address : "<<address;
			cout<<"\n\n Group ID : "<<group_id;
			found++;
			}
			file>>emp_id>>name>>sal>>address>>group_id;
		}
		file.close();
		if(found == 0)
		cout<<"\n\n Employee ID Can't Found...";
	}
	void emp::modify()
	{
		system("cls");
		int sall,test_id,found=0;//new values which we want to add
		string name1,address1;
		fstream file,file1,file2,file3;//we have to create one new file when we want to add or delete our record and then we can manage our details
		/*in file handling first we have to create new file then put that data in this new file which we dont want to modify
		and keep that old data or data which we want to modify in old file only 
		now add new data on new file and delete the old file
		*/
		cout<<"\n\n\t\t\t\tModify Record";
		file.open("emp.txt",ios::in);
		file1.open("group.txt",ios::in);
		if(!file || !file1)
		{
			cout<<"\n\n File Openning Error...";
			getch();
			menu();
		}
		cout<<"\n\n Employee ID For Modify : ";
		cin>>test_id;
		file2.open("emp1.txt",ios::app|ios::out);
		file>>emp_id>>name>>sal>>address>>group_id;//for fetching the data
		while(!file.eof())
		{//employee id will be same as previous
			if(test_id == emp_id)
			{//now we can modify the values
				system("cls");
				cout<<"\n\n\t\t\t\tModify Record";
				cout<<"\n\n\n Employee Name : ";
				cin>>name1;
				cout<<"\n\n\t\tEmployee Salary : ";
				cin>>sall;
				cout<<"\n\n Employee Address : ";
				cin>>address1;
				//send data to new file that is file2
				file2<<" "<<emp_id<<" "<<name1<<" "<<sall<<" "<<address1<<" "<<group_id<<"\n";
				found++;
			}
			else
			{
				file2<<" "<<emp_id<<" "<<name<<" "<<sal<<" "<<address<<" "<<group_id<<"\n";
			}
			file>>emp_id>>name>>sal>>address>>group_id;
		}
		file.close();
		file2.close();
		remove("emp.txt");//deleting old file
		rename("emp1.txt","emp.txt");//rename new file
		file3.open("group1.txt",ios::app|ios::out);
		file1>>group_id>>emp_id>>sal;
		while(!file1.eof())
		{
			if(test_id == emp_id)//we dont have to modify all data 
				file3<<" "<<group_id<<" "<<emp_id<<" "<<sall<<"\n";
			else
				file3<<" "<<group_id<<" "<<emp_id<<" "<<sal<<"\n";
			file1>>group_id>>emp_id>>sal;//fetch old record
		}
		file1.close();
		file3.close();
		remove("group.txt");
		rename("group1.txt","group.txt");
		if(found == 0)
		cout<<"\n\n Employee ID Can't Found...";
		else
		cout<<"\n\n\t\t\t Record Modify Successfully...";
	}
	void emp::del()
	{
		system("cls");
		int test_id,found=0;
		fstream file,file1,file2,file3;
		cout<<"\n\n\t\t\t\tDelete Record";
		file.open("emp.txt",ios::in);
		file1.open("group.txt",ios::in);
		if(!file || !file1)
		{
			cout<<"\n\n File Openning Error...";
			getch();
			menu();
		}
		cout<<"\n\n Employee ID For Delete : ";
		cin>>test_id;
		file2.open("emp1.txt",ios::app|ios::out);
		file>>emp_id>>name>>sal>>address>>group_id;
		while(!file.eof())
		{
			if(test_id == emp_id)
			{
				cout<<"\n\n Record Deleted Successfully...";
				found++;
			}
			else
			{
				file2<<" "<<emp_id<<" "<<name<<" "<<sal<<" "<<address<<" "<<group_id<<"\n";
			}
			file>>emp_id>>name>>sal>>address>>group_id;
		}
		file.close();
		file2.close();
		remove("emp.txt");
		rename("emp1.txt","emp.txt");
		//for grup data
		file3.open("group1.txt",ios::app|ios::out);
		file1>>group_id>>emp_id>>sal;
		while(!file1.eof())
		{
			if(test_id != emp_id)
				file3<<" "<<group_id<<" "<<emp_id<<" "<<sal<<"\n";
			file1>>group_id>>emp_id>>sal;
		}
		file1.close();
		file3.close();
		remove("group.txt");
		rename("group1.txt","group.txt");
		if(found == 0)
		cout<<"\n\n Employee ID Can't Found...";
	}
	void emp::group()
	{
		system("cls");
		fstream file;
		cout<<"\n\n\t\t\t\tGroup Record";
		file.open("group.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
			getch();
			menu();
		}
		file>>group_id>>emp_id>>sal;
		while(!file.eof())
		{
			cout<<"\n\n\n\n Group ID : "<<group_id;
			cout<<"\n\n\t\t Employee ID : "<<emp_id;
			cout<<"\n\n Employee Salary : "<<sal;
			file>>group_id>>emp_id>>sal;
		}
		file.close();
	}
	void emp::search_group()
	{
		system("cls");
		int test_id,found=0,emp_count=0,sal_count=0;
		fstream file;
		cout<<"\n\n\t\t\t\tSearch Group Record";
		file.open("group.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
			getch();
			menu();
		}
		cout<<"\n\n Group ID For Search : ";
		cin>>test_id;
		system("cls");
		cout<<"\n\n\t\t\t\tSearch Group Record";
		file>>group_id>>emp_id>>sal;
		while(!file.eof())
		{
			if(test_id == group_id)
			{
				cout<<"\n\n\n Group ID : "<<group_id;
				cout<<"\n\n\t\tEmployee ID : "<<emp_id;
				cout<<"\n\n Employee Salary : "<<sal;
				found++;
				emp_count++;
				sal_count = sal_count + sal;
			}
			file>>group_id>>emp_id>>sal;
		}
		file.close();
		if(found != 0)
		{
			cout<<"\n\n\n Group ID : "<<test_id;
			cout<<"\n\n\t\tTotal Employee : "<<emp_count;
			cout<<"\n\n Total Salary : "<<sal_count;
		}
		else
		cout<<"\n\n Group ID Can't Found...";
	}
	void emp::show_group()
	{
		system("cls");
		int test_id,emp_count=0,sal_count=0,emp_total=0,sal_total=0;
		fstream file,file1;
		cout<<"\n\n\t\t\t\tShow All Groups";
		file.open("groupid.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
			getch();
			menu();
		}
		file>>test_id;
		while(!file.eof())
		{
			file1.open("group.txt",ios::in);
			file1>>group_id>>emp_id>>sal;
			while(!file1.eof())
			{
				if(test_id == group_id)
				{
					emp_count++;
					sal_count += sal;
					emp_total++;
					sal_total += sal;
				}
				file1>>group_id>>emp_id>>sal;
			}
			file1.close();
			cout<<"\n\n\n\n Group ID : "<<test_id;
			cout<<"\n\n\t\t Total Employee : "<<emp_count;
			cout<<"\n\n Total Salary : "<<sal_count;
			emp_count=0;
			sal_count=0;
			file>>test_id;
		}
		file.close();
		cout<<"\n\n\n\n Over All Employee : "<<emp_total;
		cout<<"\n\n\t\tOver All Salary : "<<sal_total;
	}
main()
{
	emp e;
	login();
	intro();
	e.menu();
}
