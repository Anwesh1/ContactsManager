#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "hash_oa.cpp"

int main(){
    std::string cmdline;
    getline(std::cin,cmdline);
    Hash_oa *HT = NULL;
    while (!std::cin.eof()){
        if (cmdline == "exit") {
            delete HT;
            return 0;
        }
        std::string command = cmdline.substr(0, cmdline.find(" "));
        if (command == "n"){
            std::string sz = cmdline.substr(2);
            delete HT;
            HT = new Hash_oa(stoi(sz));
        }
        if (command == "i"){
            std::string key = cmdline.substr(2, 10);
            std::string value = cmdline.substr(cmdline.find(";")+1);
            HT->_insert_(std::stol(key), value);
        }
        if (command == "s"){
            std::string key = cmdline.substr(2, 10);
            HT->_search_(std::stol(key), true);
        }
        if (command == "d"){
            std::string key = cmdline.substr(2, 10);
            HT->_delete_(std::stol(key));
        }
        getline(std::cin,cmdline);
    }

}
