#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Node_{
    public:
        long key;
        int status;
        std::string value;
        Node_();
        void set(long k, std::string v);
};

class Hash_oa{
    private:
        int size;
        int counter;
        std::vector <Node_> table;
    public:
        Hash_oa(int sz);
        int hfunc1(long k);
        int hfunc2(long k);
        bool _insert_(long k, std::string v);
        bool _search_(long k, bool pr);
        bool _delete_(long k);
};

Node_::Node_(){
    //status 0 = empty
    //status 1 = occupied
    //status 2 = delete
    status = 0;
}

void Node_::set(long k, std::string v){
    key = k;
    value = v;
}

Hash_oa::Hash_oa(int sz){
    size = sz;
    table = std::vector <Node_>(size);
    counter = 0;
    std::cout << "success" << std::endl;
}

int Hash_oa::hfunc1(long k){
    int h1 = k % size;
    return h1;
}

int Hash_oa::hfunc2(long k){
    int h2 = (k % size) % size;
    if (h2 % 2 == 0)    h2 += 1;
    return h2;
}

bool Hash_oa::_insert_(long k, std::string v){
    int probe;
    int offset;
    int edge;
    if(_search_(k, false) == false){
        if(size == counter){
            std::cout << "failure" << std::endl;
            return false;
        }
        else{
            probe = hfunc1(k);
            offset = hfunc2(k);
            edge = probe;
            while (table[probe].status == 1){
                if (table[probe].key == k){
                    std::cout << "failure" << std::endl;
                    return false;
                }
                probe = ((probe+offset) % size);
                if(probe == edge){
                    std::cout << "failure" << std::endl;
                    return false;
                }
            }
            table[probe].set(k, v);
            counter += 1;
            table[probe].status = 1;
            std::cout << "success" << std::endl;
            return true;
        }
    }
    else return false;
}

bool Hash_oa::_search_(long k, bool pr){
    int probe;
    int offset;
    int edge;
    probe = hfunc1(k);
    offset = hfunc2(k);
    edge = probe;
    while (table[probe].status == 1 || table[probe].status == 2){
    	if(table[probe].key == k && table[probe].status == 1){
            if (pr == true){
			    std::cout << "found " << table[probe].value << " in " << probe << std::endl;
            }
            return true;
		}
        probe = ((probe+offset) % size);
        if(probe == edge){
            if (pr == true){
            std::cout << "failure" << std::endl;
            }
            return false;
        }

    }
    if (pr == true){
        std::cout << "not found" << std::endl;
    }
    return false;
}

bool Hash_oa::_delete_(long k){
    int probe;
    int offset;
    int edge;
    probe = hfunc1(k);
    offset = hfunc2(k);
    edge = probe;
    while (table[probe].status == 1 || table[probe].status == 2){
    	 if(table[probe].key == k && table[probe].status == 1){
			table[probe].status = 2;
			counter -= 1;
			std::cout << "success" << std::endl;
			return true;
		}
        probe = ((probe+offset) % size);
        if(probe == edge){
            std::cout << "failure" << std::endl;
            return false;
        }
    }
    std::cout << "failure" << std::endl;
    return false;
}

