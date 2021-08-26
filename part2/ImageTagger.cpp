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
    temp2->deleteLabel(segmentID);
}

void ImageTagger::getAllSegmentsByLabel(int label, int **images, int **segments, int *numOfSegments) {
    if(label <= 0 || !images || !segments || !numOfSegments)
    {
        throw new Invalid_Input();
    }
    *images = malloc(sizeof(int)*imageTree->numOfNodes*number_of_segments);
    *segments = malloc(sizeof(int)*imageTree->numOfNodes*number_of_segments);
    //TODO
}
void ImageTagger::deleteImage(int imageID) {

    if(imageID <= 0) throw new Invalid_Input();
     ImageNode imageNode =ImageNode(imageID,number_of_segments);
     if(imageTree->find(imageNode)== nullptr) throw new Failure();

     imageTree->remove(&imageNode);
}

void ImageTagger::getLabel(int imageID, int segmentID, int *label) {
    if(imageID <= 0|| segmentID < 0 || segmentID>= number_of_segments || label == nullptr) throw new Invalid_Input();
    ImageNode imageNode = ImageNode(imageID,this->number_of_segments);

    if(imageTree->find(imageNode)== nullptr) throw new Failure();
    ImageNode* im = imageTree->find(imageNode)->data;
   *label = im->getLabel(segmentID);

}

ImageTagger::~ImageTagger() {
   delete imageTree;

}
