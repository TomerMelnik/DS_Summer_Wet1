//
// Created by Linoy on 8/26/2021.
//

#ifndef DS_SUMMER_WET1_IMAGENODE_H
#define DS_SUMMER_WET1_IMAGENODE_H

#include "library2.h"
#include "LinkedList.h"
#include <exception>





class Success: public std::exception{};
class Failure: public std::exception{};
class Invalid_Input: public std::exception{};

struct SegNode{

    int n;
    int id(){return n;}
    SegNode(int n) : n(n) {}
};



class ImageNode {
    int imageID;
    int* segments;
    LinkedList<SegNode> uninitSegments;
public:
    ImageNode(int imageID, int segNum);
    ~ImageNode() = default;
    void addLabel(int label, int segment);
    void removeLabel(int label, int segment);
    void getAllSegmentsByLabel(int label, int** images, int** segments, int* numOfSegments);
    const int getLabel(int segment);
    const int getImageID()
    {
        return imageID;
    }
    bool operator>(ImageNode* n){
        return this->imageID > n->getImageID();
    }
    bool operator<(ImageNode* n){
        return this->imageID < n->getImageID();
    }
};


#endif //DS_SUMMER_WET1_IMAGENODE_H
