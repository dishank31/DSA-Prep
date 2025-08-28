#include<iostream>

using namespace std;

class graph
{
    int cost[20][20];
    int tcities;

    public:
        graph()
        {
            cout << "Enter nnumber of cities : ";
            cin >> tcities;

            for(int i=0 ; i<tcities ; i++)
            {
                for(int j=0 ; j<tcities ; j++)
                {
                    cost[i][j] = 999;
                }
            }
        }

    void create_adj_matrix(); 
    void display();
    int prims(int);
};

void graph :: create_adj_matrix()
{
    char choice;
    for(int i=0 ; i<tcities ; i++)
    {
        for(int j=0 ; j<tcities ; j++)
        {
            if((i!=j) && cost[i][j] == 999 )
            {
                cout << "Is there a conncetion between city " << i << j << "?(Y/N)";
                cin >> choice;

                if(choice == 'Y' || choice == 'y')
                {
                    cout << "Enter cost of connection : ";
                    cin >> cost[i][j];
                    cost[j][i] = cost [i][j];
                }
            }
        }
    }
}

void graph :: display()
{
    cout << "Cost adjancency matrix : " << endl;
    for(int i=0 ; i<tcities ; i++)
    {
        for(int j=0 ; j<tcities ; j++)
        {
            if(cost[i][j] != 999) cout << "\t" << cost[i][j];
            else cout << "\t999";
        }
        cout << endl;
    }
    cout << endl;
}

int graph :: prims(int start_v)
{
    int st[tcities-1][3];
    int mincost = 0;
    int nearest[tcities];
    int r, j;

    nearest[start_v] = -1;
    for(int i=1 ; i<tcities ; i++)
    {
        if(i != start_v)
        {
            nearest[i] = start_v;
        }
    }

    for(int i=1 ; i<tcities ; i++)
    {
        int min = 999;
        for(int k=0 ; k<tcities ; k++)
        {
            if((nearest[k] != 1) && (cost[k][nearest[k]] < min))
            {
                j = k;
                min = cost[k][nearest[k]];
            }
        }
        st[r][0] = nearest[j];
        st[r][1] = j;
        st[r][2] = min;
        r++;

        mincost += cost[j][nearest[j]];
        nearest[j] = -1;

        for(int k=0 ; k<tcities ; k++)
        {
            if((nearest[k] != -1) && cost[k][nearest[k]] > cost[j][k])
                nearest[k] = j;
        }
    }

    cout << endl << "MST is : ";
    for(int a=0 ; a<tcities ; a++)
    {
        for(int b=0 ; b<3 ; b++)
        {
            cout << st[a][b] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    return mincost;
}

int main()
{
    int v;
    graph city;
    city.create_adj_matrix();
    city.display();
    char choice;

    do
    {
        cout << "Enter starting vertex : ";
        cin >> v;
        int mincost = city.prims(v);    
    } 
    while (choice == 'y' || choice == 'Y');
    
    return 0;
}