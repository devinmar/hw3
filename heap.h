// heap.h

#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

	std::vector<T> items; // Vector to store heap elements
  int arity;           // Arity of the heap
  PComparator comp;    // Comparator function or functor for item priority
	// for maintaining the heap property
	void bubbleUp(int index);
	void bubbleDown(int index);



};

// Add implementation of member functions here

// Constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : arity(m), comp(c) {}

// Destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

// Push an item onto the heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
    items.push_back(item);
    bubbleUp(items.size() - 1);
}

// Check if the heap is empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return items.empty();
}

// Get the size of the heap
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return items.size();
}

// Move an item up the heap to maintain the heap property
template <typename T, typename PComparator>
void Heap<T, PComparator>::bubbleUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / arity;
        if (comp(items[index], items[parent])) {
            std::swap(items[index], items[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

// Move an item down the heap to maintain the heap property
template <typename T, typename PComparator>
void Heap<T, PComparator>::bubbleDown(int index) {
    size_t firstChild = static_cast<size_t>(arity) * index + 1;
    while (firstChild < items.size()) {
        size_t smallest = firstChild;
        for (size_t i = 1; i < static_cast<size_t>(arity) && firstChild + i < items.size(); ++i) {
            if (comp(items[firstChild + i], items[smallest])) {
                smallest = firstChild + i;
            }
        }
        if (comp(items[smallest], items[index])) {
            std::swap(items[index], items[smallest]);
            index = static_cast<int>(smallest);
            firstChild = static_cast<size_t>(arity) * index + 1;
        } else {
            break;
        }
    }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return items[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Heap is empty");
  }
	// Replace the top element with the last element
	items[0] = items.back();
  items.pop_back();  
	// Move the new top element down to maintain the heap property
  bubbleDown(0);
}

#endif // HEAP_H