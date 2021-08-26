//
// Created by Linoy on 8/26/2021.
//
#include "ImageTagger.h"


void ImageTagger::addImage(int imageID) {
    if(imageID <= 0)
    {
        throw new Invalid_Input();
    }
    ImageNode* temp = new ImageNode(imageID, this->number_of_segments);
    if(imageTree->find(temp&))
    {
        throw new Failure();
    }
    imageTree->insert(temp);
}
