// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() :  first(nullptr), countOp(0) {}

void Train::addCage(bool light) {
    Cage* curr = new Cage;
    curr->light = light;
    curr->next = nullptr;
    curr->prev = nullptr;
    if (!first) {
        first = curr;
        first->prev = curr;
        first->next = curr;
    }
    else {
        curr->next = first;
        curr->prev = first->prev;
        first->prev->next = curr;
        first->prev = curr;
    }
}

int Train::getLength() {
    int  count = 1;
    Cage* tmp = first;
    if (!tmp) return 0;
    tmp->light = true;
    while (tmp) {
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
                countOp++
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
