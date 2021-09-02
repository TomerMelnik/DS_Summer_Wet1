//
// Created by Linoy on 8/26/2021.
//
#include "ImageNode.h"

ImageNode::ImageNode(int imageID, int segNum) : imageID(imageID), number_of_seg(segNum) {
    segments = new int[number_of_seg];
    uninitSegments = new LinkedList<SegNode>();
    for (int i = 0; i < number_of_seg; i++) {
        segments[i] = 0;
        SegNode *temp = new SegNode(i);
        uninitSegments->insertEnd(temp);
    }
}

ImageNode::~ImageNode() {
    delete[] segments;
    delete uninitSegments;
}


void ImageNode::addLabel(int segment, int label) {
    if (segments[segment] != 0) {
        throw Failure();
    }
    segments[segment] = label;
    uninitSegments->remove(segment);
}

void ImageNode::deleteLabel(int segment) {
    if (!segments[segment]) {
        throw Failure();
    }
    segments[segment] = 0;
    SegNode *temp = new SegNode(segment);
    uninitSegments->insertEnd(temp);
}

int ImageNode::getLabel(int segment) {
    if (!segments[segment]) throw Failure();
    return this->segments[segment];
}

void ImageNode::GetAllUnLabeledSegments(int **segments, int *numOfSegments) {
    *segments = uninitSegments->toIDArray(numOfSegments);
}

void ImageNode::getAllSegmentsByLabel(int label, int **images, int **segments, int *numOfSegments) {
    for (int i = 0; i < this->number_of_seg; i++) {
        if ((this->segments)[i] == label) {
            (*images)[*numOfSegments] = imageID;
            (*segments)[*numOfSegments] = i;
            (*numOfSegments)++;
        }
    }
}