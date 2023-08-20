#include<iostream>
#include<list>
using namespace std;

class HashTable
{
    private:
    list<int>*table;
    int total_elements;
    // function to hash the keys
    int hash(int key)
    {
        return  key %total_elements;
    }
    public:
    // default constructor
        HashTable()
        {
        total_elements = 10;
        table = new list<int>[total_elements];
        }
    // constructor to create hashTables with n indices
        HashTable(int total_elements)
        {
            this->total_elements=total_elements;
            table = new list<int>[total_elements]; // Create a new array of lists of integers. The size of the array is equal to the total number of buckets in the hash table.
        }
        // insert data into hash tables
        void add(int key)
        {
            if (contains(key)) // A hash set is a data structure that is used to store unique elements. This means that (no two elements in a hash set can have the same value). If we allow duplicate elements in the hash set, then it will no longer be a hash set.
            {
                return;
            }
            table[hash(key)].push_back(key);
        }

        // remove element from the hash table 
        void remove(int key)
        {
            //get the index of the element we want to remove using hash function
            int x = hash(key);
            
            list<int>::iterator i = find(key);
            if (i != table[x].end())
                table[x].erase(i);//erase the ith bucket
         }
         // search for a key in the hashSet
         bool contains(int key){
             int x = hash(key);
             list<int>::iterator i=find(key);
             return i != table[x].end();
             }

         list<int>::iterator find(int key)
         {
            int x = hash(key);
            list<int>::iterator i;
            i = table[x].begin(); // point to the beginning of the table
            while (i != table[x].end())
            {
                if (*i == key) // if I found the element in the bucket
                {
                break;
                }
                i++;
            }
            
            return i;
         }
    // printing all the elements in each index 
    void print()
    {
        for (int i = 0;i<total_elements;i++)
        {
                cout << "Index " << i << ": ";
                // traverse the list of the current index 
                for(int j :table[i])
                    cout<<j<<"->";
                cout<<endl;
        }
    }
    ~HashTable()
    {
        // deallocate the memory for the table:
        delete[] table;
    }
};
int main()
{
     // Create a hash table with 3 indices:
  HashTable ht(3);

  // Declare the data to be stored in the hash table:
  int arr[] = {2, 4, 6, 8, 10};

  // Insert the whole data into the hash table:
  for(int i = 0; i < 5; i++)
    ht.add(arr[i]);

  cout << "..:: Hash Table ::.." << endl;
  ht.print();
  
  ht.remove(4);
  cout << endl << "..:: After deleting 4 ::.." << endl;
  ht.print();

}