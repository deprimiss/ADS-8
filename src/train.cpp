// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() :  fst(nullptr), countOp=0 {}

void Train::addCage(bool light) {
    Cage* curr = new Cage;
    curr->light = light;
    curr->next = nullptr;
    curr->prev = nullptr;
    if (!fst) {
        fst = curr;
        fst->prev = curr;
        fst->next = curr;
    }
    else {
        curr->next = fst;
        curr->prev = fst->prev;
        fst->prev->next = curr;
        fst->prev = curr;
    }
}

int Train::getLength() {
    int  count = 0;
    Cage* tmp = fst;
    if (!tmp) return 0;
    tmp->light = true;
    countOp++;
    tmp = tmp->next;
    while (tmp) {
        tmp = tmp->next;
        if (tmp->light == false) {
            count++;
            countOp++;
        } else {
            tmp->light = false;
            for (int i = 1; i < count; i++) {
                tmp = tmp->prev;
                countOp++;
            }
            if (tmp->light == false) {
                return count;
            }
            else {
                count = 1;
                countOp++;
            }
        }
    }
    return 0;
}

int Train::getOpCount() {
    return countOp;
}
