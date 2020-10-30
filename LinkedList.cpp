#include <iostream>
#include <string>

class Node{
    public:
        Node *next_node;
        long key;
        std::string value;
        Node(long k, std::string v);
        ~Node(){
            next_node = NULL;
            delete next_node;
        }
};

class Linked_list{
    private:
        Node *head;
        Node *tail;
    public:
        Linked_list(){
            head = NULL;
            tail = NULL;
        }
        ~Linked_list(){
            Node *p = head;
            while (p != NULL){
                head = head ->next_node;
                delete p;
                p = head;
            }            
        }
        Node* get_head();
        bool insert_back(Node *x);
        bool insert_sort(Node *use);
        bool delete_specific(long x);
        void ascending_sort();
        Node *search(long k);
        static void display(Node *head);
};

Node::Node(long k, std::string v){
    key = k;
    value = v;
    next_node = NULL;
}

Node *Linked_list::get_head(){
    return head;
}

bool Linked_list::insert_sort(Node *use){
    if(!insert_back(use)) return false;
    insert_back(use);
    ascending_sort();
    return true;
}

Node *Linked_list::search(long k){
    Node *temp = head;
    if (temp == NULL){
        return NULL;
    }
    else{
        while(temp->key != k){
            temp = temp->next_node;
            if (temp == NULL){
                return NULL;
            }
        }
        return temp;
    }
    return 0;
}

bool Linked_list::insert_back(Node *x){
    Node *add_this_node;
    if(search(x->key) != NULL){
         return false;
    }
    else{
        add_this_node = x;
        add_this_node->next_node = NULL;
        if (head == NULL){
            head = add_this_node;
            tail = add_this_node;
        }
        else{
            tail->next_node = add_this_node;
            tail = tail->next_node;
        }
            return true;
    }
}

bool Linked_list::delete_specific(long x){
    if(search(x) != NULL){
        Node *temp;
        if(head == NULL){
            return false;
        }
        else if(head->key == x){
            temp = head->next_node;
            delete (head);
            head = temp;
        }
        else if(head->next_node->key == x){
            temp = head->next_node->next_node;
            delete (head->next_node);
            head->next_node = temp;
        }
        else if(head->next_node == NULL){
            return false;
        }
        else{
            temp = head;
            while(temp->next_node->next_node->key != x){
                temp = temp->next_node;
            }
            Node *del = temp->next_node->next_node;
            temp->next_node->next_node = temp->next_node->next_node->next_node;
            delete(del);
        }
        return true;
    }
    else {
        return false;
    }
}

void Linked_list::ascending_sort(){
    if(head == NULL){
        return;
    }
    if(head->next_node == NULL){
    	return;
    }
    Node *temp = head;
    Node *lowest;
    Node *trail = NULL;
    Node *new_head = head;
    head = NULL;
    tail = NULL;
    while (temp != NULL){
        long k = temp->key;
        lowest = temp;
        while (temp->next_node != NULL){
            if (temp->next_node->key < k){
                trail = temp;
                lowest = temp->next_node;
                k = lowest->key;
            }
            temp = temp->next_node;
        }
        if (lowest == new_head){
            temp = new_head->next_node;
            new_head = new_head->next_node;
            lowest->next_node = NULL;
            insert_back(lowest);
        }
        else {
            trail->next_node = trail->next_node->next_node;
            lowest->next_node = NULL;
            insert_back(lowest);
            temp = new_head;
            trail = NULL;
        }
    }
}


void Linked_list::display(Node *head){
    if(head == NULL){
        return;
    }
    else{
    	Node *temp = head;
    	while (temp != NULL){
        std::cout << temp->key << "  ";
        temp = temp->next_node;
    	}
    	std::cout << std::endl;
    }
}
