#include<iostream>
#define MAX 10

using namespace std;

class user
{
    long long mobile_no;
    string name;
    double bill_amt;

    public:     
        user()          //calling constructor and initializing values
        {               //Avoiding garbage values
            mobile_no = 987654321;
            name = "John The Don";
            bill_amt = 0;
        }
        
        friend class record;
};

class record
{
    user u[15];

    public:
        int size;

    record()
    {
        size = 0;
    }

    void accept();
    void display();
    void heapsort();
    void adjust(int, int);
    void lin_search(long long);
    void bin_search_nonrec(long long);
    int bin_search_rec(int, int, long long);
    int partition(int, int);
    void quicksort(int, int);
};

void record :: accept()
{
    user temp;
    char choice = 'y';
    while((choice == 'y' || choice == 'Y') && (size < MAX))
    {
        cout << "Enter details of the user : " << size + 1 << endl;
        cout << "Enter mobile number : ";
        cin >> temp.mobile_no;
        cout << endl << "Enter name : ";
        cin >> temp.name;
        cout << endl << "Enter bill amount : ";
        cin >> temp.bill_amt;
        u[size++] = temp;

        cout << endl << "Number of users : " << size << endl << endl;

        if(size >= MAX)
        {
            cout << "Maximum users registered No more capacity !";
            break;
        }

        cout << endl << "Do you want to add more nodes (Y/N) : ";
        cin >> choice;
    }
}

void record :: display()
{
    cout << endl << "Registered users are : " << endl;
    cout << endl << "Name\tMobileNo\tBillAmount" << endl;
    for(int i=0 ; i < size ; i++)
    {
        cout << u[i].name << u[i].mobile_no << u[i].bill_amt << endl;
    }
}

void record :: lin_search(long long key)
{
    int i;
    for(i=0 ; i<size ; i++)
    {
        if(u[i].mobile_no == key)
        {
            cout << "Match Found : " << endl
            << "Mobile Number : " << u[i].mobile_no << endl
            << "Name : " << u[i].name << endl 
            << "Bill Amount : " << u[i].bill_amt << endl;
        }
        break;
    }

    if(i >= size)
    cout << "No data found for given input" << endl;
}

void record :: bin_search_nonrec(long long key)
{
    int l = 0 , h = size , mid;
    while(l <= h)
    {
        mid = (l + h) / 2;
        if(u[mid].mobile_no == key) cout << "Match Found!";
        else if(key < mid) h = mid - 1;
        else l = mid + 1;
    }
}

int record :: bin_search_rec(int low, int high, long long key)
{
    if(low <= high)
    {
        int mid = (low + high) / 2;
        if(u[mid].mobile_no == key) return mid;
        else if(key < u[mid].mobile_no) return bin_search_rec(low , mid-1 , key);
        else return bin_search_rec(mid+1 , high , key);
    }
}

void record :: adjust(int n , int i)
{
	while((2 * i + 1) <= n)
	{
		int j = 2 * i + 1;
		if(((j+1) <= n) && u[j+1].bill_amt > u[j].bill_amt) j++;
		else if(u[j].bill_amt <= u[i].bill_amt) break;
		else {
			user temp = u[i];
			u[i] = u[j];
            u[j] = temp;
            i = j;
		}
	}
}

void record :: heapsort()
{
    int n = size;
    for(int i=n/2 ; i>=0 ; i--) adjust(n-1,i);

    while(n>0)
    {
        user temp = u[0];
        u[0] = u[n-1];
        u[n-1] = temp;
        n--;
        adjust(n-1 , 0);
    }
}

int record :: partition(int p , int r)
{
    int i = p-1;
    user temp , x = u[r];
    for(int j = p ; j < r ; j++)
    {
        if(u[j].mobile_no <= x.mobile_no)
        {
            i++;
            temp = u[i];
            u[i] = u[j];
            u[j] = temp;
        }
    }

    temp = u[i+1];
    u[i] = u[r];
    u[r] = temp;

    return i;
}

void record :: quicksort(int p , int r)
{
    if(p < r)
    {
        int q = partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
}

int main()
{
    long long key;
    record r;
    cout << "Lets start by adding records of the user : " << endl;  
    r.accept();
    r.display();

    cout << "Enter mobile number to search : ";
    cin >> key;
    r.lin_search(key);
    return 0;
}