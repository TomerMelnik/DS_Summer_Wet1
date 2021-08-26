//
// Created by Tomer Melnik on 2021/08/26.
//

#include "library2.h"
#include "ImageTagger.h"


void *Init(int segments){
    ImageTagger *DS = new ImageTagger(int segments);
    return (void *) DS;
}

StatusType AddImage(void *DS, int imageID){

    return (ImageTagger *DS)->AddImage(imageID);

}

StatusType DeleteImage(void *DS, int imageID){


}

StatusType AddLabel(void *DS, int imageID, int segmentID, int label){


}

StatusType GetLabel(void *DS, int imageID, int segmentID, int *label){


}

StatusType DeleteLabel(void *DS, int imageID, int segmentID){



}

StatusType GetAllUnLabeledSegments(void *DS, int imageID, int **segments, int *numOfSegments){


}

StatusType GetAllSegmentsByLabel(void *DS, int label, int **images, int **segments, int *numOfSegments){


}

void Quit(void** DS){

    auto image_tagger = (ImageTagger *)(* DS);
    delete image_tagger;
    *DS = nullptr;
}
