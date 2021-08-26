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
    try{
        ((ImageTagger *)DS)->addImage(imageID);
       return SUCCESS;
    }
    catch(Success &e) {return SUCCESS;}
    catch (Failure &e) { return FAILURE;}
    catch (Invalid_Input &e) { return INVALID_INPUT;}


}

StatusType DeleteImage(void *DS, int imageID){
    if(DS == nullptr) return INVALID_INPUT;
    try{
        ((ImageTagger *)DS)->deleteImage(imageID);
        return SUCCESS;
    }
    catch(Success &e) {return SUCCESS;}
    catch (Failure &e) { return FAILURE;}
    catch (Invalid_Input &e) { return INVALID_INPUT;}
}

StatusType AddLabel(void *DS, int imageID, int segmentID, int label){
    if(DS == nullptr) return INVALID_INPUT;
    try{
        ((ImageTagger *)DS)->addLabel(imageID,segmentID,label);
        return SUCCESS;
    }
    catch(Success &e) {return SUCCESS;}
    catch (Failure &e) { return FAILURE;}
    catch (Invalid_Input &e) { return INVALID_INPUT;}
}

StatusType GetLabel(void *DS, int imageID, int segmentID, int *label){
    if(DS == nullptr) return INVALID_INPUT;

    try{
        ((ImageTagger *)DS)->getLabel(imageID,segmentID,label);
        return SUCCESS;
    }
    catch(Success &e) {return SUCCESS;}
    catch (Failure &e) { return FAILURE;}
    catch (Invalid_Input &e) { return INVALID_INPUT;}
}

StatusType DeleteLabel(void *DS, int imageID, int segmentID){
    if(DS == nullptr) return INVALID_INPUT;


    try{
        ((ImageTagger *)DS)->deleteLabel(imageID,segmentID);
        return SUCCESS;
    }
    catch(Success &e) {return SUCCESS;}
    catch (Failure &e) { return FAILURE;}
    catch (Invalid_Input &e) { return INVALID_INPUT;}
}

StatusType GetAllUnLabeledSegments(void *DS, int imageID, int **segments, int *numOfSegments){
    if(DS == nullptr) return INVALID_INPUT;
    try{
        ((ImageTagger *)DS)->getAllUnLabeledSegments( imageID, segments, numOfSegments);
        return SUCCESS;
    }
    catch(Success &e) {return SUCCESS;}
    catch (Failure &e) { return FAILURE;}
    catch (Invalid_Input &e) { return INVALID_INPUT;}
}

StatusType GetAllSegmentsByLabel(void *DS, int label, int **images, int **segments, int *numOfSegments){
    if(DS == nullptr) return INVALID_INPUT;

    try{
        ((ImageTagger *)DS)->getAllSegmentsByLabel( label, images, segments, numOfSegments);
        return SUCCESS;
    }
    catch(Success &e) {return SUCCESS;}
    catch (Failure &e) { return FAILURE;}
    catch (Invalid_Input &e) { return INVALID_INPUT;}

}

void Quit(void** DS){

    auto image_tagger = (ImageTagger *)(* DS);
    delete image_tagger;
    *DS = nullptr;
}
