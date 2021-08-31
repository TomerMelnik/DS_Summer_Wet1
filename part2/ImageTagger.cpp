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
    if(imageTree->find(*temp))
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
    ImageNode* temp2 = imageTree->find(*temp)->data;
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
    ImageNode *temp = new ImageNode(imageID, this->number_of_segments);
    ImageNode *temp2 = imageTree->find(temp)->data;
    if (!temp2) {
        throw new Failure();
    }
    temp2->deleteLabel(segmentID);
}

void ImageTagger::getAllUnLabeledSegments(int imageID, int **segments, int *numOfSegments) {
    if (imageID <= 0 || !segments || !numOfSegments) {
        throw new Invalid_Input();
    }
    ImageNode *temp = new ImageNode(imageID, this->number_of_segments);
    ImageNode *temp2 = imageTree->find(temp)->data;
    if (!temp2) {
        throw new Failure();
    }
    temp2->GetAllUnLabeledSegments(segments, numOfSegments);
}

void ImageTagger::getAllSegmentsByLabel(int label, int **images, int **segments, int *numOfSegments) {
    if (label <= 0 || !images || !segments || !numOfSegments) {
        throw new Invalid_Input();
    }
    *numOfSegments = 0;
    *images = (int *) malloc(sizeof(int) * imageTree->numOfNodes * number_of_segments);
    *segments = (int *) malloc(sizeof(int) * imageTree->numOfNodes * number_of_segments);
    getAllSegmentsByLabelRec(imageTree->root, label, images, segments, numOfSegments);
    if(!numOfSegments) {
        images = NULL;
        segments = NULL;
    }
    else
    {
        *images = (int*)realloc((*images),sizeof(int) * (*numOfSegments));
        *segments = (int*)realloc((*segments),sizeof(int)*(*numOfSegments));
    }
}

void ImageTagger::getAllSegmentsByLabelRec(Node<ImageNode>* current, int label, int **images, int **segments,
                                           int *numOfSegments) {
    if(!current) return;
    getAllSegmentsByLabelRec(current->left, label, images, segments, numOfSegments);
    current->data->getAllSegmentsByLabel(label, images, segments, numOfSegments);
    getAllSegmentsByLabelRec(current->right, label, images, segments, numOfSegments);
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
