#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            this->next = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        LinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }

        bool is_list_empty(){
            return(this->length == 0);
        }
        
        Node* return_head(){
            return(this->head);
        }

        Node* return_tail(){
            return(this->tail);
        }

        int return_length(){
            return(this->length);
        }

        void print_list(){
            if(this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                Node* temp = this->head;
                cout << "List Items: " << endl;
                while(temp != nullptr){
                    cout << temp->value << " ";
                    temp = temp->next;
                }
                cout << endl;   
            }
        }

        Node* get_node_by_value(int value){
            if(this->is_list_empty()){
                return nullptr;
            }else{
                Node* temp = this->head;
                while(temp != nullptr){
                    if(temp->value == value){
                        return temp;
                    }else{
                        temp = temp->next;
                    }
                }
                return nullptr;
            }
        }

        Node* get_node_by_index(int index){
            if(this->is_list_empty()){
                return nullptr;
            }else{
                Node* temp = this->head;
                for(int i = 0 ; i < index ; i++){
                    temp = temp->next;
                }
                return temp;
            }
        }

        bool append_node(int value){
            Node* new_node = new Node(value);
            if(this->is_list_empty()){
                this->head = new_node;
                this->tail = new_node;
            }else{
                this->tail->next = new_node;
                this->tail = new_node;
            }
            this->length++;
            return true;
        }

        bool prepend_node(int value){
            Node* new_node = new Node(value);
            if(this->is_list_empty()){
                this->head = new_node;
                this->tail = new_node;
            }else{
                new_node->next = this->head;
                this->head = new_node;
            }
            this->length++;
            return true;
        }

        bool insert_node(int value, int index){
            if(index < 0 || index > this->length){
                return false;
            }else{
                if(index == 0){
                    this->prepend_node(value);
                    return true;
                }else if(index == this->length){
                    this->append_node(value);
                    return true;
                }else{
                    Node* new_node = new Node(value);
                    Node* previous_node = this->get_node_by_index(index - 1);
                    new_node->next = previous_node->next;
                    previous_node->next = new_node;
                    this->length++;
                    return true;
                }
                return false;
            }
        }

        bool delete_first_node(){
            if(this->is_list_empty()){
                return false;
            }else{
                Node* temp = this->head;
                if(this->length == 1){
                    this->head = nullptr;
                    this->tail = nullptr;
                    this->length--;
                    delete temp;
                    return true;
                }else{
                    this->head = temp->next;
                    this->length--;
                    delete temp;
                    return true;
                }
                return false;
            }
        }

        bool delete_last_node(){
            if(this->is_list_empty()){
                return false;
            }else{
                Node* temp = this->tail;
                if(this->length == 1){
                    this->head = nullptr;
                    this->tail = nullptr;
                    this->length--;
                    delete temp;
                    return true;
                }else{
                    Node* previous_node = this->get_node_by_index(this->length - 2);
                    previous_node->next = nullptr;
                    this->head = previous_node;
                    this->length--;
                    delete temp;
                    return true;
                }
                return false;
            }
        }

        bool delete_node(int index){
            if(this->is_list_empty()){
                return false;
            }else{
                if(index > 0 || index >= this->length){
                    return false;
                }else if (index == 0){
                    this->delete_first_node();
                    return true;
                }else if (index = this->length - 1){
                    this->delete_last_node();
                    return true;
                }else{
                    Node* temp = this->get_node_by_index(index);
                    Node* previous_node = this->get_node_by_index(index - 1);
                    previous_node->next = temp->next;
                    this->length--;
                    delete temp;
                    return true;
                }
                return false;
            }
        }
};