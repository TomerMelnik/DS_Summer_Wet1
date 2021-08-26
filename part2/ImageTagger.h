//
// Created by Linoy on 8/26/2021.
//

#ifndef DS_SUMMER_WET1_IMAGETAGGER_H
#define DS_SUMMER_WET1_IMAGETAGGER_H

#include "avlTree.h"
#include "ImageNode.h"
#include <exception>



class ImageTagger {
    AVLTree<ImageNode> *imageTagger;
    int number_of_segments;

public:
     ImageTagger(int segnum);
    void addImage(int imageID);

};


#endif //DS_SUMMER_WET1_IMAGETAGGER_H
