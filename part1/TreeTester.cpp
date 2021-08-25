//
// Created by Tomer Melnik on 2021/08/23.
//

#include "library1.h"
#include "avlTree.h"

struct simple_node{
int key;
void* value;
int id(){return key;}

};


void *Init(){
    AVLTree<simple_node> *DS = new AVLTree<simple_node>;
    return (void *) DS;
}



StatusType Add(void *DS, int key, void* value, void** node){
    if(DS == nullptr || node == nullptr)
        return INVALID_INPUT;


        simple_node* sn = new simple_node;
        sn->key = key;
        sn->value = value;

    ((AVLTree<simple_node>*) DS)->insert(sn);
    *node = sn;
    return SUCCESS;

}

StatusType Find(void *DS, int key, void** value){
    if(DS == nullptr || value == nullptr)
        return INVALID_INPUT;

    simple_node snt;
    snt.key=key;
    simple_node& ref= snt;
    simple_node* sn =  ( ((AVLTree<simple_node>*) DS)->find(ref))->data;

    if(sn == nullptr)
        return FAILURE;

    *value = sn;

    return SUCCESS;

}

StatusType Delete(void *DS, int key){
    if(DS == nullptr )
        return INVALID_INPUT;

    simple_node snt;
    snt.key=key;
    simple_node& ref= snt;
    simple_node* sn =  ( ((AVLTree<simple_node>*) DS)->find(ref))->data;

    if(sn == nullptr)
        return FAILURE;

    ((AVLTree<simple_node>*) DS)->remove(sn);

    return SUCCESS;


}

StatusType Size(void *DS, int *n){
    if(DS == nullptr || n == nullptr)
        return INVALID_INPUT;

    *n = ((AVLTree<simple_node>*) DS)->numOfNodes;

    return SUCCESS;
}

void Quit(void** DS){

    auto ll = (AVLTree<simple_node>*)(* DS);
    delete ll;
    *DS = nullptr;
}