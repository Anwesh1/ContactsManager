#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "linked_list.cpp"

class Hash{
    private:
        int size;
    public:
        std::vector <Linked_list> table;
        Hash(int sz);
        int get_table_size();
        int hfunc1(long k);
        bool _insert(Node *use);
        bool _search(long k);
        bool _delete(long k);
        void _print(int i);
};

Hash::Hash(int sz){
    size = sz;
    table = std::vector<Linked_list>(size);
    std::cout << "success" << std::endl;
}

int Hash::get_table_size(){
    return size;
}

int Hash::hfunc1(long k){
    int sz = get_table_size();
    int h1 = k % sz;
    return h1;
}

bool Hash::_insert(Node *use){
    if (table[hfunc1(use->key)].insert_sort(use)){
    	std::cout << "success" << std::endl;
    	return true;
    }
    else {
    	std::cout << "failure" << std::endl;
        delete use;
    	return false;
    }
}

bool Hash::_search(long k){
    if (table[hfunc1(k)].search(k)) {
        std::cout << "found " << (table[hfunc1(k)].search(k))->value << " in " << hfunc1(k) << std::endl;
        return true;
    }
    else {
    	std::cout << "not found" << std::endl;
    	return false;
    }
}

bool Hash::_delete(long k){
    if(table[hfunc1(k)].delete_specific(k)) {
    	std::cout << "success" << std::endl;
    	return true;
    }
    else {
    	std::cout << "failure" << std::endl;
    	return false;
    }
}

void Hash::_print(int i){
	table[i].display(table[i].get_head());
}

