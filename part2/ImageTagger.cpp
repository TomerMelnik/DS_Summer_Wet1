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


void ImageTagger::addLabel(int imageID, int segmentID, int label){
    if(imageID <=0 || segmentID <=0 || segmentID >= this->number_of_segments || label <=0)
    {
        throw new Invalid_Input();
    }
    ImageNode* temp = new ImageNode(imageID, this->number_of_segments);
    ImageNode* temp2 = findNode(temp&);
    if(!temp2)
    {
        throw new Failure();
    }
    temp2->addLabel(segmentID, label);
}

void ImageTagger::deleteLabel(int imageID, int segmentID) {
    if(imageID <=0 || segmentID <=0 || segmentID >= this->number_of_segments)
    {
        throw new Invalid_Input();
    }
    ImageNode* temp = new ImageNode(imageID, this->number_of_segments);
    ImageNode* temp2 = findNode(temp&);
    if(!temp2)
    {
        throw new Failure();
    }
    temp2->removeLabel()
}