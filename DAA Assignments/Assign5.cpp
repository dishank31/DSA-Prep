#include <iostream>

using namespace std;

#define MAX 10

class record
{
	int roll, marks;
	string name;
	
public:

	friend class student;
};

class hashing
{
	int roll, pos;
	
public:
	hashing()
	{
		roll = -1;
		pos = -1;
	}
	
	friend class student;
};

class student
{
	record rec[MAX];
	hashing h[MAX];
	int relt;
	
public:
	student()
	{
		relt = 0;
	}
	
	void create_wor();
	void create_wr();
	void modify();
	void retrieve();
	void display();
	void displayall();
};

void student::create_wor()
{
	char choice;
	int loc;
	record r1;
	do {
		cout << endl
			 << "Enter roll no.: ";
		cin >> r1.roll;
		cout << "Enter name: ";
		cin >> r1.name;
		cout << "Enter marks: ";
		cin >> r1.marks;
		
		loc = r1.roll % MAX;
		
		while (h[loc].roll != -1) {
			loc = (loc + 1) % MAX;
			if (loc == r1.roll % MAX) {
				cout << endl
					 << "Hash table is full!" << endl;
				return;
			}
		}
		
		rec[relt].roll = r1.roll;
		rec[relt].marks = r1.marks;
		rec[relt].name = r1.name;
		
		cout << endl
			 << "Do you wish to add more records? (Y/n): ";
		cin >> choice;
		
		h[loc].roll = rec[relt].roll;
		h[loc].pos = relt++;
	} while (choice == 'Y' || choice == 'y');
	displayall();
}

void student::create_wr()
{
	char choice;
	int loc;
	record r1;
	do {
		int old_pos = relt;
		cout << endl
			 << "Enter roll no.: ";
		cin >> r1.roll;
		cout << "Enter name: ";
		cin >> r1.name;
		cout << "Enter marks: ";
		cin >> r1.marks;
		
		rec[relt].roll = r1.roll;
		rec[relt].marks = r1.marks;
		rec[relt].name = r1.name;
		
		loc = r1.roll % MAX;
		
		while (h[loc].roll != -1) {
			if (h[loc].roll % MAX != loc) {
				hashing temp;
				temp.roll = h[loc].roll;
				temp.pos = h[loc].pos;
				h[loc].roll = r1.roll;
				h[loc].pos = relt;
				r1.roll = temp.roll;
				old_pos = temp.pos;
			}
			loc = (loc + 1) % MAX;
			if (loc == r1.roll % MAX) {
				cout << endl
					 << "Hash table is full!" << endl;
				return;
			}
		}
		
		h[loc].roll = r1.roll;
		h[loc].pos = old_pos;
		
		relt++;
		
		displayall();
		
		cout << endl
			 << "Do you wish to add more records? (Y/n): ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');
}

void student::displayall()
{
	cout << endl
		 << "Displaying hash table:" << endl
		 << endl
		 << "Index\tRoll no.\tPosition" << endl;
	for (int i = 0; i < MAX; i++)
		cout << i << "\t" << h[i].roll << "\t\t" << h[i].pos << endl;
		
	cout << endl
		 << "Records in order of insertion:" << endl
		 << endl
		 << "Roll no.\tName\tMarks" << endl;
	for (int i = 0; i < relt; i++)
		cout << rec[i].roll << "\t\t" << rec[i].name << "\t" << rec[i].marks << endl;
		
	cout << endl;
}

int main()
{
	student stu;
	stu.create_wr();
	stu.displayall();
	return 0;
}