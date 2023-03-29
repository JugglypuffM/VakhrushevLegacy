//
// Created by Jugglyuser on 20.02.2023.
//

struct Node{
    Node() = default;
    explicit Node(int a){
        this->num = a;
    };

    int num = 0;
    Node* prev = nullptr;
};

typedef struct LinkedList{
    LinkedList() = default;

    void push(int num){
        Node *node = new Node(num);
        node->prev = this->root;
        this->root = node;
        this->length++;
    }

    int pop(int pos) {
        Node curr = *this->root;

        if(pos == this->length-1){
            this->root = curr.prev;
            this->length--;
            return curr.num;
        }

        for(int i = 0; i < this->length - 2 - pos; i++){
            curr = *curr.prev;
        }

        int res = (*curr.prev).num;

        if(pos == 0){
            curr.prev = nullptr;
        } else {
            curr.prev = (*curr.prev).prev;
        }

        this->length--;
        return res;
    }

    int operator [] (int n) const{
        Node curr = *this->root;
        for(int i = 0; i < this->length - 1 - n; i++){
            curr = *curr.prev;
        }
        return curr.num;
    };

    Node* root = nullptr;
    int length = 0;
} llist;

