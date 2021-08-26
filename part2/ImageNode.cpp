//
// Created by Linoy on 8/26/2021.
//
#include "ImageNode.h"

ImageNode::ImageNode(int imageID, int segNum) : imageID(imageID), segNum(segNum) {
    this.segments = new int[segNum];
    for(int i=0; i<segNum;i++)
    {
        segments[i] = 0;
        SegNode temp = new SegNode(i);
        uninitSegments.insertEnd(temp);
    }
}

void ImageNode::addLabel(int label, int segment) {
    if (this.segments[segment])
    {
        throw new Failure();
    }
    this.segments[segment] = label;
    uninitSegments.remove(segment);
}

void ImageNode::removeLabel(int label, int segment) {
    if (!this.segments[segment])
    {
        throw new Failure();
    }
    this->segments[segment] = 0;
    SegNode temp = new SegNode(segment);
    this->uninitSegments.insertEnd(temp);
}

int ImageNode::getLabel(int segment) {
    if(!segments[segment])
    {
        throw new Failure();
    }
    return this->segments[segment];
}
void ImageNode::GetAllUnLabeledSegments(int **segments, int *numOfSegments) {
    //TODO: do it in the list class
}
void ImageNode::getAllSegmentsByLabel(int label, int **images, int **segments, int *numOfSegments) {
    for(int i = 0; i < this->segNum; i++)
    {
        if(segments[i] == label)
        {
            (*images)[numOfSegments] = this->imageID;
            (*segments)[numOfSegments] = i;
            (*numOfSegments)++;
        }
    }
}
