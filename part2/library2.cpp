//
// Created by Tomer Melnik on 2021/08/26.
//

#include "library2.h"
#include "ImageTagger.h"


void *Init(int segments){
    ImageTagger *DS = new ImageTagger(segments);
    return (void *) DS;
}

StatusType AddImage(void *DS, int imageID){
    if(DS == nullptr) return INVALID_INPUT;
    return (ImageTagger *DS)->addImage(imageID);

}

StatusType DeleteImage(void *DS, int imageID){
    if(DS == nullptr) return INVALID_INPUT;
    return (ImageTagger *DS)->deleteImage(imageID);
}

StatusType AddLabel(void *DS, int imageID, int segmentID, int label){
    if(DS == nullptr) return INVALID_INPUT;
    return (ImageTagger *DS)->addLabel(imageID,segmentID,label);
}

StatusType GetLabel(void *DS, int imageID, int segmentID, int *label){
    if(DS == nullptr) return INVALID_INPUT;
    return (ImageTagger *DS)->getLabel(imageID,segmentID,label);
}

StatusType DeleteLabel(void *DS, int imageID, int segmentID){
    if(DS == nullptr) return INVALID_INPUT;

    return (ImageTagger *DS)->deletetLabel(imageID,segmentID);
}

StatusType GetAllUnLabeledSegments(void *DS, int imageID, int **segments, int *numOfSegments){
    if(DS == nullptr) return INVALID_INPUT;
    return (ImageTagger *DS)->getAllUnLabeledSegments( imageID, segments, numOfSegments)
}

StatusType GetAllSegmentsByLabel(void *DS, int label, int **images, int **segments, int *numOfSegments){
    if(DS == nullptr) return INVALID_INPUT;
    return (ImageTagger *DS)->getAllSegmentsByLabel( label, images, segments, numOfSegments)
}

void Quit(void** DS){

    auto image_tagger = (ImageTagger *)(* DS);
    delete image_tagger;
    *DS = nullptr;
}
