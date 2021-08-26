//
// Created by Linoy on 8/26/2021.
//
#include "ImageNode.h"

ImageNode::ImageNode(int imageID, int snum) {
    this.segements = new int[snum];
    for(int i=0; i<snum;i++)
    {
        segements[i] = 0;
        uninitSegments.insertEnd(i);
    }
}

void ImageNode::addLabel(int label, int segment) {

}