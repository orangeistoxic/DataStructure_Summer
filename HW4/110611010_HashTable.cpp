#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "110611010_HashTable.h"

using namespace std;

const int prime=5003;


HashTable::HashTable() {
    table.resize(prime);
}



int HashTable::HashFunction(string key){
    const int p = 31;
    int hashValue = 0;
    for(int i = 2; i < key.size(); i++){  //Ignore the first two zeros
        hashValue = (hashValue * p + key[i]);
    }

    return abs(hashValue % prime);
}

void HashTable::addItem(string key, string gender, int height, int weight) {
    int index = HashFunction(key);
    
    table[index].push_back(make_pair(key, PersonalInfo(gender, height, weight)));
}

PersonalInfo HashTable::operator[](string key){
    int index = HashFunction(key);
    // first element is the key
    // second element is PersonalInfo
    for(auto it = table[index].begin(); it != table[index].end(); it++){
        if(it->first == key){
            return it->second;
        }
    }
    return PersonalInfo("", 0, 0);
}


PersonalInfo::PersonalInfo(string g, int h, int w):gender(g), height(h), weight(w){

}

string PersonalInfo::getGender(){
    return gender;
}

int PersonalInfo::getHeight(){
    return height;
}

int PersonalInfo::getWeight(){
    return weight;
}



#endif

