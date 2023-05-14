// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() :  first(nullptr), countOp(0) {}

void Train::addCage(bool light) {
    Cage* curr = nullptr;
    if (first == nullptr) {
        first = new Cage;
        first->next = first, first->prev = first;
        first->light = light;
    } else {
        curr = new Cage;
        curr->next = first;
        curr->prev = first->prev;
        curr->light = light;
        first->prev = curr;
        curr->prev->next = curr;
    }
}
int Train::getLength() {
    Cage* tmp = first;
    tmp->light = true;
    int count = 1;
    while (true) {
        tmp = tmp->next;
        if (tmp->light == false) {
            count++;
            countOp++;
        } else {
            tmp->light = false;
            for (int i = count; i > 0; i--) {
                tmp = tmp->prev;
                countOp++;
            }
            countOp++;
            if (tmp->light == false) {
                return count;
            } else {
                count = 1;
            }
        }
    }
}
int Train::getOpCount() {
    return countOp;
}
