//
// Created by Tomer Melnik on 2021/08/23.
//

#include "library1.h"
#include "LinkedList.h"

struct simple_node{
int key;
void* value;
int id(){return key;}

};


void *Init(){
    LinkedList<simple_node> *DS = new LinkedList<simple_node>;
    return (void *) DS;
}



StatusType Add(void *DS, int key, void* value, void** node){
    if(DS == nullptr || node == nullptr)
        return INVALID_INPUT;


        simple_node* sn = new simple_node;
        sn->key = key;
        sn->value = value;

    ((LinkedList<simple_node>*) DS)->insertFront(sn);
    *node = sn;
    return SUCCESS;

}

StatusType Find(void *DS, int key, void** value){
    if(DS == nullptr || value == nullptr)
        return INVALID_INPUT;

    simple_node* sn =  ((LinkedList<simple_node>*) DS)->find(key);

    if(sn == nullptr)
        return FAILURE;

    *value = sn;

    return SUCCESS;

}

StatusType Delete(void *DS, int key){
    if(DS == nullptr )
        return INVALID_INPUT;

    simple_node* sn =  ((LinkedList<simple_node>*) DS)->find(key);

    if(sn == nullptr)
        return FAILURE;

    ((LinkedList<simple_node>*) DS)->remove(key);

    return SUCCESS;


}

StatusType Size(void *DS, int *n){
    if(DS == nullptr || n == nullptr)
        return INVALID_INPUT;

    *n = ((LinkedList<simple_node>*) DS)->getSize();

    return SUCCESS;
}

void Quit(void** DS){

    auto ll = (LinkedList<simple_node>*)(* DS);
    delete ll;
    *DS = nullptr;
}