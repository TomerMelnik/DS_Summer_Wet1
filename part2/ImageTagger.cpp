//
// Created by Linoy on 8/26/2021.
//

#include "ImageTagger.h"

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
