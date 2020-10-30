#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "hash.cpp"

int main(){
    std::string cmdline;
    getline(std::cin,cmdline);
    Hash *HT = NULL;
    while (!std::cin.eof()){
        if (cmdline == "exit") {
            delete HT;
            return 0;
        }
        std::string command = cmdline.substr(0, cmdline.find(" "));
        if (command == "n"){
            std::string sz = cmdline.substr(2);
            delete HT;
            HT = new Hash(stoi(sz));
        }
        if (command == "i"){
            std::string key = cmdline.substr(2, 10);
            std::string value = cmdline.substr(cmdline.find(";")+1);
            Node *ins = new Node(std::stol(key), value);
            HT->_insert(ins);
        }
        if (command == "s"){
            std::string key = cmdline.substr(2, 10);
            HT->_search(std::stol(key));
        }
        if (command == "d"){
            std::string key = cmdline.substr(2, 10);
            HT->_delete(std::stol(key));
        }
        if (command == "p"){
        	std::string index = cmdline.substr(2);
        	HT->_print(stoi(index));
        }
        getline(std::cin,cmdline);
    }

}
