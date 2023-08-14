// improve the space using rehashing technique (implement it as a hashMap)
/*
Rehashing is the process of creating a new hash table with a larger capacity and then re-inserting all of the key-value pairs into the new hash table. This is done to prevent collisions, which can occur when the hash table is too full.

The load factor is a measure of how full the hash table is. The load factor is calculated by dividing the size of the hash table by its capacity. A load factor of 0.75 is considered to be a high load factor, so the hash table is rehashed when the load factor reaches this value.

The reason for rehashing when the load factor reaches 0.75 is to prevent collisions. When the hash table is too full, collisions become more likely. Collisions occur when two keys have the same hash value and are therefore hashed to the same bucket. When this happens, the key-value pairs are stored in a linked list in the bucket. If the bucket becomes too full, then the linked list can become slow to traverse.

Rehashing the hash table when the load factor reaches 0.75 helps to prevent collisions by increasing the capacity of the hash table. This ensures that the keys are more evenly distributed across the buckets, which reduces the number of collisions.
*/
#include <iostream>
#include <list>
#include <utility>
#include <cassert>
using namespace std;
template <typename K, typename V>
class HashTable
{
private:
    list<pair<K, V>> *buckets;
    int size;     // the number of elements in hash table
    int capacity; // the capacity of hash table
    int hash(K key)
    {
        return key % capacity;
    }
    void rehash()
    {
        // Create a new hash table with twice the capacity of the old hash table.
        int oldCapacity = capacity;
        capacity *= 2;
        list<pair<K, V>> *oldBuckets = buckets;
        buckets = new list<pair<K, V>>[capacity]; // reintialize the space to double of itself
        for (int i = 0; i < oldCapacity; i++)
        {
            for (pair<K, V> it : oldBuckets[i])
                insert(it.first, it.second); // add the values to the new capacity hash table
        }
        // Delete the old hash table.
        delete[] oldBuckets;
    }

public:
    // Constructs a new hash table with the default capacity of 10.
    HashTable()
    {
        this->capacity = 10;
        this->size = 0;
        this->buckets = new list<pair<K, V>>[capacity];
    }
    HashTable(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;                                 // the hashTable firstly don't have any element
        this->buckets = new list<pair<K, V>>[capacity]; // Allocates a new array of lists, each of which will store the key-value pairs for a bucket.
    }

    // Inserts a key-value pair into the hash table.
    void insert(K key, V value)
    {
        // gets the bucket index for the given key by hashing the key and then using the modulo operator to ensure that the bucket index is between 0 and the capacity of the hash table, inclusive.
        int bucket = hash(key) % capacity;
        buckets[bucket].push_back(make_pair(key, value));

        // increase the size of the hash
        size++;

        /// rehashing step

        // If the load factor is greater than a certain threshold, rehash the hash table.

        if (size > capacity * 0.75) // if the size of the hash table is greater than 75% of its capacity. If it is, then the hash table is rehashed.
            rehash();
    }

    V get(K key)
    {
        int bucket = hash(key) % capacity;
        // Iterate through the bucket to find the key-value pair with the given key.

        for (pair<K, V> it : buckets[bucket])
        {
            if (it.first == key)
                // Return the value of the key-value pair.

                return it.second;
        }
        // The key was not found.
        return V();
    }
    // Removes the key-value pair with the given key from the hash table.
    void remove(K key)
    {
        // Get the bucket for the given key.
        int bucket = hash(key) % capacity;

        // Remove the key-value pair from the bucket.
        buckets[bucket].remove(make_pair(key, V()));

        // Decrease the size of the hash table.
        size--;
    }
    int sizeOfHaSH()
    {
        return this->size;
    }
    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            for (pair<int, int> it : buckets[i])
            {
                cout << it.first << " " << it.second << endl;
            }
        }
    }
    ~HashTable()
    {
        delete[] buckets;
    }
};

int main()
{
    HashTable<int, int> hashTable;

    // Insert some key-value pairs into the hash table.
    hashTable.insert(1, 10);
    hashTable.insert(2, 0);
    hashTable.insert(3, 30);

    // Print all the values in the hash table.
    hashTable.print();

    // Insert more values into the hash table.
    hashTable.insert(4, 40);
    hashTable.insert(5, 50);
    hashTable.insert(6, 60);

    // Print the hash table again to see if the rehashing happened.
    hashTable.print();

    // Check the size of the hash table to see if it has increased.
    int size = hashTable.sizeOfHaSH();
    assert(size == 6); // The size of the hash table should be 6 after the rehashing.
    cout << size << endl;
    return 0;
}