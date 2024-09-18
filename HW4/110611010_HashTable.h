#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<iostream>
#include<list>
#include<string>
#include<vector>

using namespace std;

class PersonalInfo;

class HashTable {
    private:
        // store data in the follg format:
        // key(str), gender(str), height(int), weight(int)
        vector<list<pair<string, PersonalInfo>>> table;
        int HashFunction(string key);

    public:
        HashTable();

        void addItem(string key, string gender, int height, int weight);

        PersonalInfo operator[](string key);

        
};

class PersonalInfo {
    private:
        string gender;
        int height;
        int weight;

    public:
        PersonalInfo(string gender, int height, int weight);

        string getGender();
        int getHeight();
        int getWeight();

};

#endif
