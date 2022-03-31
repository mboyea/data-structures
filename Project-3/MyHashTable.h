//
//  MyHashTable.h
//  CSCI251ProjThree
//
//  Created by Hongbiao Zeng on 3/24/19.
//  Copyright © 2019 Hongbiao Zeng. All rights reserved.
//  Edited by Matthew Boyea for CSCI 251.
//
#include <string>
#include <functional>
using namespace std;

#ifndef MyHashTable_h
#define MyHashTable_h
template<class Data, class Key>
struct HashEntry {
    Key key;
    Data value;
    HashEntry* next;
    HashEntry(Key key, Data value)
        : key(key), value(value), next(nullptr) {}
};

template<class Key, class Data>
class MyHashTable {
private:
    HashEntry<Key, Data>** table;
    unsigned int numOfBuckets;
    unsigned int count; // how many elements in table
public:
    MyHashTable(unsigned int table_size = 10); // table_size is the number of buckets
    unsigned int size() const; // return how many elements in table
    Data get(Key key) const; // return the element with given key
    void insert(Key key, Data value); //insert (key, value) node to table
    Data remove(Key key); // remove and return the value with the key
    bool isEmpty() const; // return true if the table is empty
    template<class K, class D>
    friend void printTable(MyHashTable<K, D> table);
    // output hash table with spaces between buckets and arrows between entries
    // an empty bucket appears as an 'X'
    template<class K, class D>
    friend std::ostream& operator<<(std::ostream& os, const MyHashTable<K, D>& list);
};

template<typename T>
T GenerateEmpty() {
    return NULL;
}

template<>
std::string GenerateEmpty() {
    return "";
}

template<class Key>
unsigned int Hash(Key key, unsigned int numOfBuckets) {
    return key % numOfBuckets;
}

// std::string specification
template<>
unsigned int Hash(std::string key, unsigned int numOfBuckets) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < key.size(); i++) {
        sum += (unsigned int)key[i];
    }
    return Hash<unsigned int>(sum, numOfBuckets);
}

template<class Key, class Data>
MyHashTable<Key, Data>::MyHashTable(unsigned int table_size)
    : table(new HashEntry<Key, Data>*[table_size]), numOfBuckets(table_size), count(0) {
        for (unsigned int i = 0; i < numOfBuckets; i++) {
            table[i] = nullptr;
        }
    }

template<class Key, class Data>
unsigned int MyHashTable<Key, Data>::size() const {
    return count;
}

template<class Key, class Data>
Data MyHashTable<Key, Data>::get(Key key) const {
    unsigned int bucket = Hash<Key>(key, numOfBuckets);
    // for every hash entry in the bucket
    for (HashEntry<Key, Data>* entry = table[bucket]; entry != nullptr; entry = entry->next) {
        // if entry contains the key
        if (entry->key == key) {
            // return the entry's value
            return entry->value;
        }
    }
    return GenerateEmpty<Data>();
}

template<class Key, class Data>
void MyHashTable<Key, Data>::insert(Key key, Data value) {
    unsigned int bucket = Hash<Key>(key, numOfBuckets);
    // case: bucket is empty
    if (table[bucket] == nullptr) {
        table[bucket] = new HashEntry<Key, Data>(key, value);
        count++;
        return;
    }
    // find the last hash entry in the bucket
    HashEntry<Key, Data>* last = table[bucket];
    while (last->next != nullptr) {
        last = last->next;
    }
    // point the last hash entry to a new hash entry
    last->next = new HashEntry<Key, Data>(key, value);
    count++;
    return;
}

template<class Key, class Data>
Data MyHashTable<Key, Data>::remove(Key key) {
    unsigned int bucket = Hash<Key>(key, numOfBuckets);
    // case: bucket has 0 entries
    if (table[bucket] == nullptr) {
        return GenerateEmpty<Data>();
    }
    // case: bucket has 1 entry
    if (table[bucket]->next == nullptr) {
        // if the entry contains the key
        if (table[bucket]->key == key) {
            // delete the entry & return its value
            Data value = table[bucket]->value;
            delete table[bucket];
            table[bucket] = nullptr;
            count--;
            return value;
        }
        // case: no valid entry found
        return GenerateEmpty<Data>();
    }
    // for every remaining entry excluding the tail
    for (HashEntry<Key, Data>* entry = table[bucket]; entry->next != nullptr; entry = entry->next) {
        // if the following entry contains the right key
        if (entry->next->key == key) {
            // delete the following entry & return its value
            Data value = entry->next->value;
            delete entry->next;
            entry->next = entry->next->next;
            count--;
            return value;
        }
    }
    // case: no valid entry found
    return GenerateEmpty<Data>();
}

template<class Key, class Data>
bool MyHashTable<Key, Data>::isEmpty() const {
    return count == 0;
}

template<class Key, class Data>
std::ostream& operator<<(std::ostream& os, const MyHashTable<Key, Data>& list) {
    unsigned int bucket = 0;
    { // output the first bucket
		// case: bucket empty
		if (list.table[bucket] == nullptr) {
			os << 'X';
		} else {
            HashEntry<Key, Data>* entry = list.table[bucket];
			// output the first hash entry
            os << entry->value;
            // for every remaining entry
            for (entry = entry->next; entry != nullptr; entry = entry->next) {
                // output an arrow
                os << "->";
                // output the entry
                os << entry->value;
            }
		}
    }
    // for every remaining bucket
    for (bucket++; bucket < list.numOfBuckets; bucket++) {
        // output a whitespace
		os << ' ';
        // output the bucket
		// case: bucket empty
		if (list.table[bucket] == nullptr) {
			os << 'X';
		} else {
            HashEntry<Key, Data>* entry = list.table[bucket];
			// output the first hash entry
            os << entry->value;
            // for every remaining entry
            for (entry = entry->next; entry != nullptr; entry = entry->next) {
                // output an arrow
                os << "->";
                // output the entry
                os << entry->value;
            }
		}
    }
	return os;
}

template<class Key, class Data>
void printTable(MyHashTable<Key, Data> table) {
    std::cout << table << '\n';
}

#endif /* MyHashTable_h */
