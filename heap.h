#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

using namespace std;

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
  void printArray() const;

private:
  /// Add whatever helper functions and data members you need below
  T *items;
  /// @brief Stores the size of elements in the heap
  int size_; 

  int m;
  PComparator c;
  void heapify(T arr[], int n, int i);
  void swap(T arr[], int i, int j);
  void heapify_del(T arr[], int n, int i);

};

// Add implementation of member functions here


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
    throw std::underflow_error("No elements in the heap!");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return items[size_ - 1];
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
    throw std::underflow_error("Heap is empty already!");

  }

  //remove the top priority item in the heap
  // Get the last element
  T lastElement = items[size_ - 1];
  // overtake the root w/ ele at the end
  items[0] = ele_end;
  // lower heap size
  size_ --;
  // heapify the root node
  heapify_del(items, size_, 0);
}
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
  this->m = m;
  this->c = c;
  this->items = new T[m];
  this->size_ = 0;
}
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) 
{
  if(m >= size_+1) //ensure the array has right size
  {
    //std::cout<<"Adding: "<<item<<std::endl;
    this->items[size_] = item;//add at last slot
    this->size_ ++;//inrease the size
    //now heapify
    heapify(this->items, size_, size_ - 1);
  }
  
}
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  bool res = this->size_ == 0;
  return res;
}
template <typename T, typename PComparator>
void Heap<T, PComparator>::swap(T arr[], int i, int j)
{
  T swap_ = arr[i];
  arr[i] = arr[j];
  arr[j] = swap_;
}
template <typename T, typename PComparator>
void Heap<T,PComparator> ::heapify(T arr[], int n, int i)
{
// find top element
    int ele_top = (i - 1) / 2;
 
    if (size_ >0) {
        // if curr node > source node
        // swap each & call then heapify 
        if (c(arr[i], arr[ele_top]) == true) {
            swap(arr[i] ele_top);
            // Use recursion for heapifying top node
            heapify(arr, n, ele_top);
        }
    }
}
template <typename T, typename PComparator>
void Heap<T,PComparator>::printArray() const
{
    for (int i = 0; i < this->size_; i++)
        std::cout << items[i] << " ";
 
    std::cout << "\n";
}
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{
  delete[] this->items; //free the array memory
}
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify_del(T arr[], int n, int i)
{
    //  make the root the biggest element
   int size_big = i;
    // initializing the left element
    int ele_l = 2 * i + 1; 
    // initializing the right element
    int ele_r = 2 * i + 2; 
 
    // If ele_l > than root
    if (ele_l < size_ && c(items[ele_l], items[size_big]) == true)
        size_big = ele_l;
 
    // If ele_r is larger than largest
    if (ele_r < n && c(items[r], items[size_big]) ==true)
        size_big = size_big;
 
    // If size_big != root
    if (size_big != i) {
        swap(items[i], size_big);

        // Use recursion to heapify the sub-tree touched on
        heapify_del(items[n], size_big);
    }
}
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return this->size_;
}
#endif


