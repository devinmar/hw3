#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

// Helper function for the recursive implementation of llpivot
// this function handles the recursive logic of partitioning the list
void llpivotHelper(Node*& current, Node*& smaller, Node*& larger, int pivot, Node*& smallerLast, Node*& largerLast) {
    // base case: if the current node is NULL, end recursion
		if (!current) {
        return;
    }

		// store the next node, as the current node will be moved to one of the output lists
    Node* next = current->next;
    current->next = nullptr;

    // If current node's value is less than or equal to the pivot, add it to the 'smaller' list.
    if (current->val <= pivot) {
				// if the smaller list is empty, initialize it with the current node
        if (!smaller) {
            smaller = smallerLast = current;  
        } else {
					// otherwise, append the current node to the end of the smaller list 
            smallerLast->next = current;
            smallerLast = current;
        }
		// if current node's value is greater than the pivot, add it to the 'larger' list
    } else {
        if (!larger) {
					// if the larger list is empty, initialize it with the current node
            larger = largerLast = current;
        } else {
					  // otherwise, append the current node to the end of the 'larger' list
            largerLast->next = current;
            largerLast = current;
        }
    }
		// recursive call for the next node in the list
    llpivotHelper(next, smaller, larger, pivot, smallerLast, largerLast);
}

// the llpivot function splits a linked list into two lists based on a pivot value
// one list contains elements less than or equal to the pivot and the other contains elements greater
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    Node *smallerLast = nullptr, *largerLast = nullptr;
		
		// making a call to the helper function to perform the actual list partitioning
    llpivotHelper(head, smaller, larger, pivot, smallerLast, largerLast);
		// after partitioning, the original list is empty. Set head to nullptr.
    head = nullptr;
}