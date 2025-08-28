#include<iostream>
#include<cmath> 

using namespace std;

class queens
{
    int n;
    int *x;
    int count;

    public:
        queens()
        {
            cout << endl << "Enter number of queens : ";
            cin >> n;
            x = new int[n];
            count = 0;
        }
    
    void nqueen(int);
    bool place(int, int);
    void display();
    void printcount();
};

void queens::nqueen(int k)
{
	for (int i = 1; i <= n; i++)
		if (place(k, i)) {
			x[k] = i;
			if (k == n) display();
			else nqueen(k + 1);
		}
}

bool queens::place(int k, int i)
{
	for (int j = 1; j < k; j++)
		if (x[j] == i || abs(x[j] - i) == abs(j - k))
			return false;
	return true;
}

void queens :: display()
{
    count++;
    for(int i=1 ; i<=n ; i++)
    {
        cout << "\t";
        for(int j=1 ; j<=n ; j++)
        {
            if(x[i] == j)
            cout << "Q ";
            else
            cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void queens :: printcount()
{
    cout << "number of solutions : " << count << endl;
}

int main()
{
    queens q;
    q.nqueen(1);
    q.printcount();
    return 0;
}