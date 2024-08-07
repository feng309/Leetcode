#include<stdio.h>
#include "LRUCache.cpp"

int main(){
    LRUCache* lru = new LRUCache(10);
    lru->put(1,2);
    return 0;
}