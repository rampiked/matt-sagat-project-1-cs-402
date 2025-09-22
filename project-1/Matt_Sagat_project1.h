#include <vector>
#include <random>
#include <concepts>
#include <type_traits>
#include <iostream>


#ifndef Matt_Sagat_PROJECT1
#define Matt_Sagat_PROJECT1

using namespace std;



/*** Helper Functions ***/
unsigned int get_rand_index(unsigned int len) {
    std::srand(std::time({}));
    return static_cast<unsigned int>(std::rand() % len);
}


/*** STUDENT HELPER FUNCTIONS HERE ***/
template<typename T>
void printList(vector<T> &list, string sortType){
    std::cout << "Printing entire list with " << sortType << ":" << std::endl;
    for(int i = 0; i < list.size(); i++){
        std::cout << list[i] << std::endl;        
    }
}


/*** END STUDENT HELPER FUNCTIONS ***/





/*** DO NOT MODIFY BELOW ***/
/*** Main Functions for Students to Implement ***/

/** Helper type for integrals only **/
template<class T>
concept Integral = is_integral<T>::value;


/* Bubble Sort */
template<typename T>
void bubble_sort(vector<T> &list, bool descending = false);

/* Selection Sort */
template<typename T>
void selection_sort(vector<T> &list, bool descending = false);

/* Insertion Sort */
template<typename T>
void insertion_sort(vector<T> &list, bool descending = false); 

/* Quick Sort */
template<typename T>
vector<T>& quick_partition(vector<T> &list, bool descending = false);

template<typename T>
void quicksort(vector<T> &list, bool descending = false);


/* Merge Sort */
template<typename T>
void merge_sort(vector<T> &list, bool descending = false);

/* Bucket Merge Sort  */
template<typename T>
void bucket_merge_sort(vector<T> &list, bool descending = false);


/* Binary Radix Sort */
template<Integral T>
void binary_radix_sort(vector<T> &list, bool descending = false);


/* Your Hybrid Sort */
template<typename T>
void my_hybrid_sort(vector<T> &list, bool descending = false);


/* Base B Radix Sort */
template<Integral T> 
void radix_sort(vector<T> &list, unsigned int base = 10, bool descending = false);



#endif
