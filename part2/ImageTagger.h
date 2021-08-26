//
// Created by Linoy on 8/26/2021.
//

#ifndef DS_SUMMER_WET1_IMAGETAGGER_H
#define DS_SUMMER_WET1_IMAGETAGGER_H

#include "avlTree.h"
#include "ImageNode.h"
#include <exception>



class ImageTagger {
    AVLTree<ImageNode> *imageTree;
    int number_of_segments;

public:
    ImageTagger(int segnum);
    void addImage(int imageID);
    void deleteImage(int imageID);
    void addLabel(int imageID,int segmentID,int label);
    void getLabel(int imageID,int segmentID,int* label);
    void deleteLabel(int imageID,int segmentID);
    void getAllUnLabeledSegments(int imageID,int** segments,int* numOfSegments);
    void getAllSegmentsByLabel(int label,int** images,int** segments,int* numOfSegments);
};


#endif //DS_SUMMER_WET1_IMAGETAGGER_H
