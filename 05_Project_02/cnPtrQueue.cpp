/*  bool cnPtrQueue::empty() const{} -> Returns true if BOTH inStack and outStack are empty
 *  cnPtrQueue::size_type cnPtrQueue::size() const{} will return numItems for that given queue
 *  CNode* cnPtrQueue::front(){} will send a node to the front of a given stack
 */
#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace CS3358_FA2021_A5P2
{

    // Constructor
    cnPtrQueue::cnPtrQueue() : numItems(0) {}
    // Checks if both stacks are empty, returns T/F
     bool cnPtrQueue::empty() const {
        return inStack.empty() && outStack.empty();
    }
    // Returns size (number of items) for that given queue
    cnPtrQueue::size_type cnPtrQueue::size() const {
        return numItems;
    }
    // Takes a node from inStack and sends it to the front of outStack
    CNode* cnPtrQueue::front() {
        assert(!inStack.empty() || !outStack.empty());
        if (outStack.empty()){
            while (!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }
    // Adds an element at top of the queue and increases size by 1
    void cnPtrQueue::push(CNode* cnPtr) {
        inStack.push(cnPtr);
        numItems++;
    }
    // Removes top element from queue and reduces size by 1
    void cnPtrQueue::pop() {
        assert(!inStack.empty() || !outStack.empty());
        if (outStack.empty()){
            while (!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        outStack.pop();
        numItems--; // Decrease item by 1 for the given queue
    }
}
