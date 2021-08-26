//
// Created by Linoy on 8/26/2021.
//

#ifndef DS_SUMMER_WET1_IMAGENODE_H
#define DS_SUMMER_WET1_IMAGENODE_H


class ImageNode {
    int imageID;
    int* segements;
    LinkedList<int> uninitSegments;
public:
    ImageNode(int imageID, int snum);
    ~ImageNode();
    void addLabel(int label, int segment);
    void removeLabel(int label);
    const int getLabel(int segment);
    const int getImageID()
    {
        return imageID;
    }
    bool operator>(ImageNode* n){
        return this.imageID > n->getImageID();
    }
    bool operator<(ImageNode* n){
        return this.imageID < n->getImageID();
    }
};


#endif //DS_SUMMER_WET1_IMAGENODE_H
