//
// Created by Linoy on 8/26/2021.
//
#include "ImageNode.h"

ImageNode::ImageNode(int imageID, int segNum) : imageID(imageID) {
    this.segments = new int[segNum];
    for(int i=0; i<segNum;i++)
    {
        segments[i] = 0;

        uninitSegments.insertEnd(i);
    }
}
ImageNode::~ImageNode() {
    delete(segments);

}

StatusType ImageNode::addLabel(int label, int segment) {
    if
}