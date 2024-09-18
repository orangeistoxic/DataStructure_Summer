#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <iostream>
#include <list>

using namespace std;

template <class T>
class Link_List
{
public:
    // default constructor
    Link_List();
    // copy constructor
    Link_List(Link_List &);

    // get size of list
    std::size_t getSize() const;

    // inserts `value` at the beginning of list. always returns true.
    bool insert_node(T value);
    // inserts `value` before `index`. always returns true.
    bool insert_node(std::size_t index, T value);

    // removes element at the beginning of list. returns true if delete
    // successfully, otherwise returns false.
    bool delete_node();
    // removes element at `index`. returns true if delete successfully,
    // otherwise returns false.
    bool delete_node(std::size_t index);

    // checks whther the contents of two lists are equal.
    // that is, they have the same number of elements and each element
    // at the same position is equal
    bool operator==(const Link_List &) const;
    // get element at position
    const T &operator[](std::size_t) const;

    // Reads a list from an input stream. The first element represents the size of the list `N`,
    // followed by `N` elements.
    // Example input: 3 1 2 3
    // This represents a list of elements {1, 2, 3}
    template <class U>
    friend std::istream &operator>>(std::istream &, Link_List<U> &);

    // Outputs the list to an output stream. Each element in the list is output
    // separated by a single space character.
    // Example:
    // If the list contains {1, 2, 3}
    // cout << list; will print "1 2 3" to the console.
    template <class U>
    friend std::ostream &operator<<(std::ostream &, const Link_List<U> &);

// declare your own functions/variables
private:
    std::list<T> list_;
};

// implement Link_List's methods

template <class T>
Link_List<T>::Link_List(){}
template <class T>
Link_List<T>::Link_List(Link_List &linkList){
    list_ = linkList.list_;
}
template <class T>
size_t Link_List<T>::getSize() const{
    return list_.size();
}

template <class T>
bool Link_List<T>::insert_node(T value){
    list_.push_front(value);
    return true;
}
template <class T>
bool Link_List<T>::insert_node(size_t index, T value){
    if(index > list_.size()){
        list_.push_back(value);
        return true;
    }
    typename list<T>::iterator it = list_.begin();
    for(size_t i = 0; i < index; i++){
        ++it;
    }
    list_.insert(it, value);
    return true;
}

template <class T>
bool Link_List<T>::delete_node(){
    if(list_.empty()){
        return false;
    }
    list_.pop_front();
    return true;
}

template <class T>
bool Link_List<T>::delete_node(size_t index){
    if(index >= list_.size()){
        return false;
    }
    typename list<T>::iterator it = list_.begin();
    for(size_t i = 1; i < index; i++){
        ++it;
    }
    list_.erase(it);
    return true;
}

template <class T>
bool Link_List<T>::operator==(const Link_List &linkList) const{
    if(list_.size() != linkList.list_.size()){
        return false;
    }
    typename list<T>::const_iterator it1 = list_.begin();
    typename list<T>::const_iterator it2 = linkList.list_.begin();
    while(it1 != list_.end()){
        if(*it1 != *it2){
            return false;
        }
        ++it1;
        ++it2;
    }
    return true;
}

template <class T>
const T &Link_List<T>::operator[](size_t index) const{
    typename list<T>::const_iterator it = list_.begin();
    for(size_t i = 0; i < index; i++){
        ++it;
    }
    return *it;
}

template <class T>
std::istream &operator>>(std::istream &input, Link_List<T> &linkList){
    size_t size;
    input >> size;
    T value;
    for(size_t i = 0; i < size; i++){
        input >> value;
        linkList.list_.push_back(value);
    }
    return input;
}

template <class T>
std::ostream &operator<<(std::ostream &output, const Link_List<T> &linkList){
    typename list<T>::const_iterator it = linkList.list_.begin();
    while(it != linkList.list_.end()){
        output << *it << " ";
        ++it;
    }
    return output;
}

#endif

