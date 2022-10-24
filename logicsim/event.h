#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
        bool operator()(struct Event *e1, struct Event *e2)
        {
            bool res = false;
            if(e1->time < e2->time)
            {
                res = true;
            }
            return res;//compare if e1 is less than e2's time
        }
} EventLess;
	
#endif