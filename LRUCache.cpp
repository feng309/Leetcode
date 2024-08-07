#include<iostream>
#include<unordered_map>
#include<vector>

struct Node{
    int key, value;
    Node* prev;
    Node* next;
    Node(int key, int value):key(key), value(value), prev(nullptr), next(nullptr){};
};

class LRUCache{
public:
    LRUCache(int capacity):_capacity(capacity){
        _head = new Node(0, 0);
        _tail = new Node(0, 0);
        _head->next = _tail;
        _tail->prev = _head;
    }
    ~LRUCache(){
        Node* curr = _head;
        while(curr){
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    void put(int key, int value){
        auto it = _cache.find(key);
        if(it != _cache.end()){
            moveToFront(it->second);
            it->second->value;
        }else{
            if(_size == _capacity){
                Node* last = _tail->prev;
                remove(last);
                delete last;
                _size--;
            }
            Node* newNode = new Node(key, value);
            addFront(newNode);
            _cache[key] = newNode;
            ++_size;
        }

    }

    int get(int key){
        auto it = _cache.find(key);
        if(it == _cache.end()){
            return -1;
        }
        moveToFront(it->second);
        return it->second->value;
    }
private:
    int _capacity;
    int _size;
    Node* _head;
    Node* _tail;
    std::unordered_map<int, Node*>  _cache; // key -> Node*

    void addFront(Node* node){
        node->next = _head->next;
        node->prev = _head;
        _head->next->prev = node;
        _head->next = node;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToFront(Node* node){
        remove(node);
        addFront(node);
    }
;

};
