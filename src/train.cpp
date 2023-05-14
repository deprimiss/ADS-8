// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() :  first(nullptr), countOp(0) {}

void Train::addCage(bool light) {
    Cage* curr = nullptr;
    if (!first) {
        first = new Cage;
        first->prev = first;
        first->next = first;
        first->light = light;
    } else {
        curr = new Cage;
        curr->next=first;
        curr->prev = first->prev;
        curr->light = light;
        first->prev = curr;
        curr->prev->next = curr;
    }
}

int Train::getLength() {
    int  count = 1;
    Cage* tmp = first;
    if (!tmp) return 0;
    tmp->light = true;
    while (true) {
        tmp = tmp->next;
        if (tmp->light == false) {
            count++;
            countOp++;
        } else {
            tmp->light = false;
            for (int i = 0; i < count; i++) {
                tmp = tmp->prev;
                countOp++;
            }
            if (tmp->light == false) {
                return count;
            }
            else {
                count = 1;;
            }
        }
    }
    return 0;
}

int Train::getOpCount() {
    return countOp;
}
