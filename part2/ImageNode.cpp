//
// Created by Linoy on 8/26/2021.
//
#include "ImageNode.h"

ImageNode::ImageNode(int imageID, int segNum) : imageID(imageID) {
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
    uninitSegments.insertEnd(temp);
}

