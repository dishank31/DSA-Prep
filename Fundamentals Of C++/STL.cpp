#include<iostream>
#include<vector>
#include<array>
#include<string.h>
#include<utility>
#include<iterator>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include<unordered_set>
#include<map>
#include<cstdio>
#include<algorithm>

using namespace std;

/*Different format of for Loop : 
for(int i = 0; i < n; i++)
{
    cin >> arr[i];
}
for(int i : arr )
{
    cout << i << " ";
}
for(auto i : arr)
{
    cout << i << " ";
}
for(auto it = v.begin(); it != v.end(); it++)
{
    cout << *it << " ";
}
*/

void StringExplained()
{
    string s = "Hello World";          // Decalaration of String
    
    //Methods
    cout << s.length();
    cout << endl << s.size();

    cout << endl << s[1] << endl;
    cout << s.at(1) << endl;        // Also returns the same but throws out of range for invalid index

    string a = "Hello";
    string b = "World";
    a + b;
    a.append(b);

    s.insert(2, "#%");

    s.erase(5, 5);

    string k = "aslam";
    string p = "malekum";
    cout << k.compare(p) << endl;
}

void PairExplained()
{
    pair<int,int> p = {1,9};                    // Pairs stored two values of datatype specified
    cout << p.first << " " << p.second << endl;         // To access the elements of pairs

    //To store three or more values
    pair<int , pair<int,int> > p1 = {4 , {1,9}};
    cout << p1.first << " " << p1.second.first << " " << p1.second.second << endl;
    
    // To store pairs in an array
    pair<int,int> arr[] = { {1,8} , {5,4} , {6,4}};
    cout << arr[0].second << endl;
}

void ArrayExplained()
{    
    int basic[3] = {1,2,3};         //One way to declare array
    array<int,4> a = {1,2,3,4};    //Another way to declare array

    int size = a.size(); 
    cout << "Size of array : " << size << endl;           //To get the size of the array
    cout << "Element at second index : " << a.at(2) << endl;  //To get the element at a particular index
    cout << "Empty or not : " << a.empty() << endl;           //To check if the array is empty or not and it returns a boolean value
    cout << "First element : " << a.front() << endl;          //To get the first element of the array
    cout << "Last element : " << a.back() << endl;            //To get the last element of the array
    
}

void VectorExplained()
{
    vector<int> v2(4);      // It creates a vector of size 4 and initialize every element to 0 or some garbage values depending on the compiler 
    
    vector<int> v1(5,1);    //Another way of intializing the vector where 5 is the size of vector and every index in intialize with 1 at first
    cout << "Size of vector : " << v1.size() << endl;                //Gives the current size of the vector
    cout << "Capacity of vector : " << v1.capacity() << endl;        //Capacity always increases by 2 times of the previous capacity
    cout << "Max size of vector : " << v1.max_size() << endl;        //Theoratically max size of vector is 10^7

    vector<pair<int , int>> vec;
    vec.push_back({2,4});
    vec.emplace_back(4,9);
    cout << vec[1].first << endl;      

    vector<int> v;          // An empty vector is initialized
    v.emplace_back(1);                                        
    v.emplace_back(4);                                     
    cout << "Capacity of vector : " << v.capacity() << endl;               
    v.emplace_back(2);                                                           
    v.emplace_back(3);
    cout << "Capacity of vector : " << v.capacity() << endl;

    cout << "Second element of vector is : " << v.at(2) << endl;
    cout << v.front();
    cout << v.back();

    v.pop_back();                   // Returns an element
    cout << endl << "Capacity of vector after popping an element : " << v.capacity() << endl;

    v.shrink_to_fit();              //It decreases capacity of vector                                           
    cout << "Capacity of vector after shrinking the vector : " << v.capacity() << endl;

    // Iterations syntax :
    vector<int> :: iterator it = v.begin();
    it++;
    cout << *(it) << " ";

    vector<int> :: iterator it_end = v.end();       // It assigns the value after the last element in the array
    // vector<int> :: iterator rit_end = v.rend();     // end of a reverse array (Same concept as of end)
    // vector<int> :: iterator rit = v.rbegin();       // This both are never used

    for(vector<int> :: iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }

    for(auto it = v.begin() ; it != v.end() ; it++) {                       // Some different syntaxes of for loop to print a vector
        cout << *(it) << " ";
    }

    for(auto it : v) {
        cout << it << " ";
    }

    // Now to delete elements :-

    v.erase(v.begin() + 1);       // v.erase(address)
    v.erase(v.begin() + 2 , v.end() + 4);        // v.erase(start_add , end_add)

    // Insert Function :-

    vector<int> v4 (2 , 50);       //{50, 50}
    v.insert(v.begin(), 300);      //{300, 50, 50}
    v.insert(v.begin() + 1, 2, 10);     //{300, 10, 10, 50, 50}

    vector<int> copy (2, 100);      // {100, 100}
    v.insert(v.begin(), copy.begin(), copy.end());      // {100, 100, 300, 10, 10, 50, 50}

    // v1 -> {10, 20}
    // v2 -> {30, 40}
    v1.swap(v2);    // v1 -> {30, 40} and v2 -> {10, 20}

    // NOTE:-
    // emplace_back directly constructs the object inside the container
    // push_back creates the object first, then adds it to the container
    // emplace back is more faster and cleaner just use it whenever possible when using containers like vector deque etc}
    // Insert function takes a lot of time and are very costly

    //Whenever a vector is being emptied, its size becomes zero and not its capacity
}

void ListExplained()
{
    // Lists are doubly linked list.
    // Unlike vector, it allows fast insertion and deletion at any position (O(1) if you have the iterator).

    list<int> l = {1, 2, 3};

    // Add elements
    l.push_back(4);     // [1, 2, 3, 4]
    l.emplace_back(5);  // [1, 2, 3, 4, 5]
    l.push_front(0);    // [0, 1, 2, 3, 4, 5]
    l.emplace_front(2); // [2, 0, 1, 2, 3, 4, 5]

    // Remove elements
    l.pop_back();       // [2, 0, 1, 2, 3, 4]
    cout << l.back();   
    l.pop_front();      // [0, 1, 2, 3, 4]
    cout << l.front() << endl;  

    // Iteration
    for (int x : l)
    cout << endl << x << " ";   // 1 2 3
    cout << endl;

    // Size
    cout << endl << l.size();

    // Empty check
    cout << endl << l.empty();  // 0 means false

    // Clear list
    l.clear();

    // l.insert(it, value);      // insert value before iterator it
    // l.erase(it);              // erase element at iterator it
    // l.remove(val);            // removes all elements equal to val
    // l.sort();                 // sort the list
    // l.reverse();              // reverse the list
    // l.unique();               // remove consecutive duplicates
    // l.merge(other_list);      // merges sorted lists
}

void DequeExplained()
{
    deque<int> dq;  
    dq.push_back(1);        // {1}
    dq.emplace_back(4);     // {1, 4}
    dq.push_front(2);       // {2, 1, 4}
    dq.emplace_front(9);    // {9, 2, 1, 4}

    int poppedback = dq.back();
    dq.pop_back();          // {9, 2, 1}
    cout << poppedback << endl;         
    int poppedfront = dq.front();
    dq.pop_front();         // {2, 1}
    cout << poppedfront << endl;

    // rest functions same as vector 
}

void StackExplained()
{
    // A stack is a LIFO (Last In, First Out) data structure — like a stack of plates, where the last one you put on is the first one you take off.
    
    // NOTE:
    // pop() doesn’t return the popped element.
    // You should check empty() before calling top() or pop() to avoid undefined behavior.

    // When to use:
    // Balanced parentheses checking
    // Undo feature in text editors
    // Depth First Search (DFS)
    // Reversing data

    stack<int> st;
    st.push(2);     // {2}
    st.emplace(4);  // {4,2}
    st.push(1);     // {1,4,2}
    st.emplace(6);  // {6,1,4,2}

    cout << st.top() << endl;   // prints 6 " **st[2] is invalid **"

    st.pop();       // st = {1,4,2}
    cout << st.top() << endl;
    cout << st.size() << endl;
    cout << st.empty() << endl;

    stack<int> st1 , st2;
    st1.swap(st2);
}

void QueueExplained()
{
    // A queue is a FIFO (First In, First Out) data structure — like a real-world line: the first person to enter is the first to leave.
    
    // Properties:
    // Can’t use random access (e.g. q[2])
    // Useful when you need processing in the order of arrival.

    // When to use:
    // BFS (Breadth-First Search) in Graphs
    // Task scheduling
    // Printer queue simulation
    //Level order traversal in trees
    
    queue<int> q;
    q.push(2);       // {2}
    q.emplace(4);    // {2, 4}

    q.back() += 5;
    cout << q.back() << endl;   // prints 9

    cout << q.front() << endl;  // prints 2

    q.pop();
    cout << q.front() << endl;  // prints 9

    // other functions same as stack
}

void PriorityQueueExplained()
{
    // A priority_queue is a special type of queue where the largest (by default) element comes out first — not the one that was added first.

    // NOTE:
    // Internally uses a binary heap.
    // No direct access to middle elements like pq[2] — only top() is accessible

    // When to use:
    // Dijkstra’s shortest path algorithm (min-heap)
    // Task scheduling by priority
    // A* search in pathfinding
    // Anytime you need quick access to the largest/smallest item

    // Push = O(logn)
    // Top = O(1)
    // Pop =O(logn)

    priority_queue<int> pq;

    pq.push(5);         // {5}
    pq.emplace(2);      // {5,2}
    pq.push(8);         // {8,5,2}
    pq.emplace(10);     // {10,8,5,2}

    cout << pq.top() << endl;   // prints 10

    pq.pop();       // {8,5,2}                                          
    cout << pq.top() << endl;

    // size swap empty same as others

    // Want to maintain a minimum heap?
    priority_queue<int , vector<int> , greater<int>> pq1;
    pq1.push(5);         // {5}
    pq1.emplace(2);      // {2,5}
    pq1.push(8);         // {2,5,8}
    pq1.emplace(10);     // {2,5,8,10}

    cout << pq1.top() << endl;   // prints 2
}

void SetExplained()
{
    // A set is a container that stores unique elements in sorted order (ascending by default).

    // NOTE:
    // Elements are always sorted (by default: ascending).
    // Duplicate values are automatically removed.
    // Internally implemented using balanced binary search trees (like Red-Black tree).
    
    // Used cases:
    // Store unique elements only.
    // Quickly check existence (O(log N) time).
    // Auto-sorting a collection of values.

    //     | Operation   | Code            | Description                              |
    // | ----------- | --------------- | ---------------------------------------- |
    // | `insert(x)` | `s.insert(10);` | Adds an element to the set               |
    // | `erase(x)`  | `s.erase(10);`  | Removes an element if it exists          |
    // | `count(x)`  | `s.count(10);`  | Returns 1 if present, 0 otherwise        |
    // | `find(x)`   | `s.find(10);`   | Returns iterator to the element (or end) |
    // | `size()`    | `s.size();`     | Returns number of elements               |
    // | `empty()`   | `s.empty();`    | Checks if set is empty                   |
    // | `clear()`   | `s.clear();`    | Removes all elements                     |

    set<int> st;
    st.insert(1);       // {1}
    st.emplace(2);      // {1,2}
    st.insert(2);       // {1,2}
    st.emplace(3);      // {1,2,3}
    st.insert(4);       // {1,2,3,4}
    
    // Functionality of vector can also be used but it only increases efficiency.

    auto it = st.find(2);
    auto it1 = st.find(6);      // if the element is not present in set it points towards set ka end (index after the last element).

    for(auto it1 : st)
    {
        cout << it1 << " ";
    }

    cout << endl;

    st.erase(1);        // erase 1 // takes logarithmic of time

    int cnt = st.count(2);      // either gives 1 or 0
    cout << cnt << endl;

    auto it2 = st.find(2);
    auto it3 = st.find(4);
    st.erase(it2 , it3);        // after erase {4} [first, last)

    for(auto it5 : st)
    {
        cout << "{" << it5 << "}" << " ";
    }

    // Lower bound and Upper bound works in the same way as in vector
    auto it4 = st.lower_bound(2);
    auto it5 = st.upper_bound(4);
}

void MultiSetExplained()
{
    // A multiset is like a set, but allows duplicate values.
    // All elements are stored in sorted order (ascending by default).
    // Unlike set, multiple instances of the same value are allowed.

    //     | Operation   | Code                    | Description                                     |
    // | ----------- | ----------------------- | ----------------------------------------------- |
    // | `insert(x)` | `ms.insert(5);`         | Adds element `x` (even if it already exists)    |
    // | `erase(x)`  | `ms.erase(5);`          | Removes **all instances** of `5`                |
    // | `erase(it)` | `ms.erase(ms.find(5));` | Removes **only one instance**                   |
    // | `count(x)`  | `ms.count(5);`          | Returns how many times `x` appears              |
    // | `find(x)`   | `ms.find(5);`           | Returns iterator to first instance of `x`       |
    // | `size()`    | `ms.size();`            | Total number of elements (including duplicates) |
    // | `empty()`   | `ms.empty();`           | Checks if multiset is empty                     |
    // | `clear()`   | `ms.clear();`           | Removes all elements                            |

    // When to use:
    // When you want sorted elements and allow duplicates.
    // Counting frequencies while maintaining sorted order.
    // Useful in problems like:
    //      Sliding window max/min with duplicate values
    //      Multiset-based greedy algorithms

    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

    for(auto it1 : ms)
    {
        cout << "{" << it1 << "}" << " ";
    }

    ms.erase(1);    // all 1's are erased

    for(auto it2 : ms)
    {
        cout << "{" << it2 << "}" << " ";
    }

    cout << endl;

    int cnt = ms.count(1);
    cout << cnt << endl;
    
    // only a single one erased
    ms.erase(ms.find(1));

    // Rest all function same as set

}

void UnorderedSetExplained()
{
    // lower_bound and upper_bound function does not work
    // Rest all functions are same as above
    // It does not store in any particular order so it has better time complexity then set in most cases, except some when collision happens

    unordered_set<int> ust;
}

void MapExplained()
{
    // A map is a container that stores key-value pairs, with unique keys in sorted order (ascending by default).
    // Think of it like a dictionary:   (In python)
    // You search using the key, and it returns the value.

    //     | Operation       | Code                      | Description                     |
    // | --------------- | ------------------------- | ------------------------------- |
    // | Insert/Update   | `m[key] = value;`         | Adds or updates key             |
    // | Insert (pair)   | `m.insert({key, value});` | Adds only if key doesn't exist  |
    // | Access value    | `m[key]`                  | Returns value for key           |
    // | Erase by key    | `m.erase(key);`           | Deletes key and value           |
    // | Size            | `m.size();`               | Number of key-value pairs       |
    // | Find            | `m.find(key);`            | Returns iterator or `m.end()`   |
    // | Check existence | `m.count(key);`           | Returns 1 if key exists, else 0 |
    // | Clear           | `m.clear();`              | Deletes all elements            |

    // Key Features:
    // Keys are unique ✅
    // Stored in sorted order (by key) ✅
    // Based on Red-Black Tree (log N operations)

    // NOTE:
    // m[key] creates key if it doesn’t exist (with default value).
    // To avoid accidental insertion, use find() or count().

    map <int, int> mpp;                     // Declaration of map :- map <datatype1, datatype2> name;
    map <int, pair<int, int>> mpp1;
    map <pair<int, int>, pair<int, int>> mpp2;

    mpp[1] = 2;
    mpp.insert({2, 4});
    mpp.emplace(3, 1); 
    
    for (auto it : mpp)
    {
        cout << it.first << " => " << it.second << endl;
    }

    // OR with iterator
    for (auto it = mpp.begin(); it != mpp.end(); ++it) 
    {
        cout << it->first << " " << it->second << endl;
    }
}

void MultiMapExplained()
{
    // A multimap is just like a map, but it allows duplicate keys.
    // Keys are sorted (by default in ascending order).
    // Multiple pairs can have the same key.
    // Stored as a balanced BST (usually red-black tree).
    
    multimap<int, string> mpp;
    mpp.insert({1, "apple"});
    mpp.insert({2, "banana"});
    mpp.insert({1, "mango"}); // allowed (duplicate key)

    for (pair<int, string> it : mpp) {
    cout << it.first << " => " << it.second << endl;
    }
}

bool comp(pair<int, int> p1 , pair<int, int> p2)
    {
        if(p1.second < p2.second) return true;
        if(p1.second > p2.second) return false;
        // else they are same

        if(p1.first > p2.first) return true;
        else return false;   
    }

void ExtrasExplained()
{
    // vector<int> v = {4, 5, 1, 8};
    // sort(v.begin(), v.end());

    // for(int x : v) cout << x << " ";

    // pair<int,int> a[] = {{1,2}, {2,1}, {4,1}};
    // sort(a+2, a+4);
    
    // // Boolean Comparator:
    // // sort ir according to the second element
    // // if second element is same, then sort
    // // it according to first element but in descending

    // sort(a[1], a[3], comp);

    int num = 7;
    int cnt = __builtin_popcount(num);              // Returns the set bit (no. of 1s) of integer passed say (7 = 111)
    cout << cnt << endl;                            // so it prints 3
    
    long long num1 = 165254519241;              
    int cnt1 = __builtin_popcountll(num1);          // If the number is long long
    cout << cnt1 << endl;

    string s = "123";

    do {
        cout << s << endl;                          
    }
    while(next_permutation(s.begin(), s.end()));    // It gives all the possible combinations or permutations of string 

    // Eg:  the string is 123 so it will start from printing 123 then using dictionary order 132, 213, 231, 312, 321
    //      if the string was 231 so it gets started from printing 231 then 312 and 321 then it stops.
    //      so it is important in order to get all the possible combinations you must start from sorted order 
}

int main()
{
    // PairExplained();
    // ArrayExplained();
    // VectorExplained();
    // ListExplained();
    // DequeExplained();
    // StackExplained();
    // QueueExplained();
    // PriorityQueueExplained();
    // SetExplained();
    // MultiSetExplained();
    // UnorderedSetExplained();
    // MapExplained();
    // MultiMapExplained();
    // ExtrasExplained();
    return 0;
}


                                                // End of STL Study //                                                              