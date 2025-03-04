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
};