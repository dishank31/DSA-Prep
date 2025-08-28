#include<iostream>

using namespace std;

void StarSquare()
{
    int n;
    cout << "Enter number of rows or columns : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void StarRectangle()
{
    int m , n;
    cout << "Enter number of rows : ";
    cin >> m;
    cout << "Enter number of coulumns : ";
    cin >> n;
    for(int i=1 ; i<=m ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void Numbersquare()
{
    int n;
    cout << "Enter number of rows or columns : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void NumberRectangle()
{
    int m , n;
    cout << "Enter number of rows : ";
    cin >> m;
    cout << "Enter number of coulumns : ";
    cin >> n;
    for(int i=1 ; i<=m ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void StarTriangle()
{
    int n;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=i ; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void StarTriangleUlta()
{
    int n;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n-i ; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void NumberTriangle()
{
    int n;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=i ; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void OddNumberTriangle()
{
    int n;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=i ; j++)
        {   
            cout << 2 * j - 1 << " ";
        }
        cout << endl;
    }
}

void Alphabetsquare()
{
    int n;
    cout << "Enter number of rows or columns : ";
    cin >> n;

    for(int i=1 ; i<=n ; i++)
    {
         char ch = 'A';
        for(int j=1 ; j<=n ; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}

void AlphabetTriangle()
{
    int n;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        char ch = 'A';
        for(int j=1 ; j<=i ; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}

void NumalphaTriangle()
{
    int n;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {   
        char ch = 'A';
        for(int j=1 ; j<=i ; j++)
        {
            if(i % 2 != 0) cout << j << " ";
            else
            { 
                cout << ch << " ";
                ch++;
            }
        }
        cout << endl;
    }

}

void StarPlus()
{
    int n;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
            for(int j=1 ; j<=n ; j++)
            {   
                if(j==(n/2)+1 || i==(n/2)+1) cout << "*";
                else cout << " ";
            }   
        cout << endl;
    } 
}

void HollowRectangle()
{
    int m , n;
    cout << "Enter number of rows : ";
    cin >> m;
    cout << "Enter number of coulumns : ";
    cin >> n;
    for(int i=1 ; i<=m ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            if ( i==1 || i==m ) cout << "*";
            else if ( j==1 || j==n ) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

void StarCross()
{
    int n;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
            for(int j=1 ; j<=n ; j++)
            {   
                if(i==j || i+j==n+1) cout << "*";
                else cout << " ";
            }   
        cout << endl;
    } 
}

void FlyodsTriangle()
{
    int n , a=1;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=i ; j++)
        {
            cout << a << " ";
            a++;
        }
        cout << endl;
    }
}

void ZeroAndOneTriangle()
{
    int n;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=i ; j++)
        {
            if( (i+j) % 2 == 0) cout << "1";
            else cout << "0";
        }
        cout << endl;
    }
}

void StarTriangleMast()
{
    int n;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            if((i+j) >= (n+1)) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

void Rhombus()
{
    int n;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n-i ; j++)
        {
            cout << " ";
        }

        for(int k=1 ; k<=n ; k++)
    {
        cout << "*";
    }
        cout << endl;
    }

    
}

void AlphabetTriangleMast()
{
    int n; 
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        char ch = 'A';
        for(int j=1 ; j<=n ; j++)
        {
            if((i+j) >= (n+1))
            {
                cout << ch;
                ch++;
            }
            else cout << " ";
        }
        cout << endl;
    }
}

void StarPyramid()
{
    int n , p=1 ;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n-i ; j++)
        {
            cout << " ";
        }

        for(int k=1 ; k<=p ; k++)
        {
            cout << "*";
        }
        p = p + 2;
        cout << endl;
    }
}

void NumberPyramid()
{
    int n , p=1 ;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n-i ; j++)
        {
            cout << " ";
        }

        for(int k=1 ; k<=p ; k++)
        {
            cout << k;
        }
        p = p + 2;
        cout << endl;
    }
}

void NumberPyramidMast()
{
    int n;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n-i ; j++)
        {
            cout << " ";
        }

        for(int k=1 ; k<=i ; k++)
        {
            cout << k;
        }

        for(int l=1 ; l<=i-1 ; l++)
        {
            cout << l;
        }
        cout << endl;
    }
}

void StarDiamond()
{
    int n;
    cout << "Enter number of rows : ";
    cin >> n;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n-i ; j++)
        {
            cout << " ";
        }

        for(int k=1 ; k<=i ; k++)
        {
            cout << "*";
        }

        for(int l=1 ; l<=i-1 ; l++)
        {
            cout << "*";
        }
        cout << endl;

        for(int m=1 ; m<=n-i ; m++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{   
    //StarSquare();
    //StarRectangle();
    //Numbersquare();
    //NumberRectangle();
    //StarTriangle();
    //StarTriangleUlta();
    //NumberTriangle();
    //OddNumberTriangle();
    //Alphabetsquare();
    //AlphabetTriangle();
    //NumalphaTriangle();
    //StarPlus();
    //HollowRectangle();
    //StarCross();
    //FlyodsTriangle();
    //ZeroAndOneTriangle();
    StarTriangleMast();
    //Rhombus();
    //AlphabetTriangleMast();
    //StarPyramid();
    //NumberPyramid();
    //NumberPyramidMast();
    // StarDiamond();
    return 0;
}