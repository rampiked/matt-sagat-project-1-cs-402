
#include "Matt_Sagat_project1.h"
#include "testing.h"

#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

/****************
 * INSTRUCTIONS *
 ****************
 *
 * - Replace all instances of "Firstname_Lastname" with your firstname and
 *   your last name. This include the .h and .cpp files, along with the
 *   header guards at the top of the .h file.
 *
 * - Implement the appropriate algorithms as described below.
 *   You must follow the specifications as written
 *   below (e.g., stability, in-place, etc.).
 *
 * - DO NOT MODIFY THE FUNCTION SIGNATURES!!!
 *
 * - You are allowed to add helper functions. Be sure to add the appropriate
 *   function prototypes in "Fistname_Lastname_project1.h".
 *
 * - The file "testing.cpp" has various functions you can utilize to test
 *   your code. You can also add your own tests!
 *
 * - If you are working in a group, please modify the comments directly below.
 *
 */

/*** GROUP PROJECT ***/
// Please list ALL of your other group members as comments below.
//   Member 1
//   Member 2

/* Bubble Sort 
 *
 * 5 points
 * 
 * Algorithm: Continuously compare adjacent elements and swap them if necessary.
 *            This is a stable, in-place sorting algorithm. Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void bubble_sort(vector<T> &list, bool descending) {
    T temp;
    for(int i = 0; i < list.size() - 1; i++){
        //With each pass of this internal loop, the greatest value in the list will rise to the top, so 'i' is keeping track of how many times this has happened, since the end of the list is already sorted.
        for(int j = 0; j < list.size() - 1 - i; j++){
            if(list[j] > list[j+1]){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }

    if(descending){
        std::reverse(list.begin(), list.end());
    }
}

/* Selection Sort 
 *
 * 5 points
 * 
 * Algorithm: Continuously finds the minimium (or maximum) element in the list, 
 *            then swaps it with the first non-sorted element of the list.
 *            This is an unstable, in-place sorting algorithm. Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void selection_sort(vector<T> &list, bool descending) {
    int listLength = list.size();

    for(int i = 0; i < listLength - 1; i++){
        int minIndex = i;
        //Find the lowest value in the unsorted chunk.
        for(int j = i + 1; j < listLength; j++){
            if(list[j] < list[minIndex]){
                minIndex = j;
            }
        }
        //Perform swap if minIndex is no longer i (meaning we have a swap to make).
        if (minIndex != i) {
            T temp = list[i];
            list[i] = list[minIndex];
            list[minIndex] = temp;
        }
    }

    if(descending){
        std::reverse(list.begin(), list.end());
    }
}

/* Insertion Sort 
 *
 * 5 points
 * 
 * Algorithm: Iterates through the list and inserts the current element into
 *            the correct sorted position of the prefix of the list.
 *            This is a stable, in-place sorting algorithm. Your implementation
 *            does not need to be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void insertion_sort(vector<T> &list, bool descending) {
    int listLength = list.size();

    //Loop starts at second elements since first element is already deemed "sorted".
    for(int i = 1; i < listLength; i++){
        T currentVal = list[i];
        int j = i - 1;

        //Scan right to left to find appropriate place to put value from unsorted portion.
        while (j >= 0 && list[j] > currentVal) {
            list[j + 1] = list[j];
            j--;
        }
        //Insert currentVal in its correct position
        list[j + 1] = currentVal;
    }

    if(descending){
        std::reverse(list.begin(), list.end());
    }
}

/* Quicksort 
 *
 * 10 points
 * 
 * Algorithm: Sorts by first choosing a random pivot from the list, then 
 *            partitioning the list into two halves with respect to the 
 *            pivot, then recursing on each half.
 *            This is an unstable sorting algorithm. Not required to be
 *            implemented as an in-place sort.
 *            
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
template<typename T>
void quicksort(vector<T> &list, bool descending) {
    unsigned int listLength = list.size();
    if (listLength <= 1) return;
    //Pick random element in the list as pivot.
    T pivot = list[get_rand_index(listLength)];
    vector<T> lessThanList;
    vector<T> equalList;
    vector<T> greaterThanList;

    for (unsigned int i = 0; i < listLength; i++) {
        if (list[i] < pivot) {
            lessThanList.push_back(list[i]);
        } else if (list[i] > pivot) {
            greaterThanList.push_back(list[i]);
        } else {
            equalList.push_back(list[i]);
        }
    }
    quicksort(lessThanList, descending);
    quicksort(greaterThanList, descending);

    list.clear();
    if (!descending) {
        //Ascending: less -> equal -> greater
        list.insert(list.end(), lessThanList.begin(), lessThanList.end());
        list.insert(list.end(), equalList.begin(), equalList.end());
        list.insert(list.end(), greaterThanList.begin(), greaterThanList.end());
    } else {
        //Descending: greater -> equal -> less
        list.insert(list.end(), greaterThanList.begin(), greaterThanList.end());
        list.insert(list.end(), equalList.begin(), equalList.end());
        list.insert(list.end(), lessThanList.begin(), lessThanList.end());
    }
}

/* Quick Partition
 *
 * Helper function for Quicksort. You will implement this to help with your
 * quicksort algorithm above.
 *
 */
template<typename T>
vector<T>& quick_partition(vector<T> &list, bool descending) {
    // Your code here!
    // Did not end up using helper :)
    // You can use the helper function 
    //      unsigned int get_rand_index(unsigned int len)
}

/* Merge Sort 
 *
 * 10 points
 * 
 * Algorithm: Sorts the list by recursively sorting the left and right
 *            halves, then merging the two left and right halves together.
 *            This is a stable sorting algorithm. Not required to be implemented
 *            as an in-place sort.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
template<typename T>
void merge_sort(vector<T> &list, bool descending) {
    unsigned int listSize = list.size();

    if (listSize <= 1)return;

    unsigned int middlePosition = listSize / 2;

    vector<T> leftList(list.begin(), list.begin() + middlePosition);
    vector<T> rightList(list.begin() + middlePosition, list.end());

    merge_sort(leftList, descending);
    merge_sort(rightList, descending);

    //Merge the two sorted halves
    list.clear();
    unsigned int i = 0, j = 0;

    while (i < leftList.size() && j < rightList.size()) {
        if (!descending) {
            if (leftList[i] <= rightList[j]) {
                list.push_back(leftList[i]);
                i++;
            } else {
                list.push_back(rightList[j]);
                j++;
            }
        } else {
            if (leftList[i] >= rightList[j]) {
                list.push_back(leftList[i]);
                i++;
            } else {
                list.push_back(rightList[j]);
                j++;
            }
        }
    }

    //Once previous while loop breaks, we copy remaining elements (only one of these following loops should iterate per function call).
    while (i < leftList.size()) {
        list.push_back(leftList[i]);
        i++;
    }
    while (j < rightList.size()) {
        list.push_back(rightList[j]);
        j++;
    }
}

/* Bucket Merge Sort
 *
 * 20 points
 * 
 * Algorithm: Bucket Merge Sort we discussed in class. Works by
 *            partitioning the input list into small, fixed-length segments,
 *            sorting each of those segments using some fast algorithm, then
 *            merging each of the segments together.
 *            This is a stable, in-place sorting algorithm.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 *
 */
template<typename T>
void bucket_merge_sort(vector<T> &list, bool descending) {
    unsigned int n = list.size();
    if (n <= 1) return;
    //Adjust for buckets of desired size.
    const unsigned int bucketSize = 5;
    vector<vector<T>> buckets;

    //Partition list into buckets and sort each with merge_sort.
    for (unsigned int i = 0; i < n; i += bucketSize) {
        unsigned int end = std::min(i + bucketSize, n);
        vector<T> bucket(list.begin() + i, list.begin() + end);
        merge_sort(bucket, descending);
        buckets.push_back(std::move(bucket));
    }

    //Keep merging buckets until one remains
    while (buckets.size() > 1) {
        vector<vector<T>> newBuckets;
        //Increment by 2 each time since we are merging 2 buckets.
        for (unsigned int i = 0; i < buckets.size(); i += 2) {
            if (i + 1 < buckets.size()) {
                vector<T> merged;
                //Resizes merged to fit all the elements in buckets[i] and buckets[i+1]
                merged.reserve(buckets[i].size() + buckets[i + 1].size());

                unsigned int leftItr = 0;
                unsigned int rightItr = 0;
                auto &leftBucket = buckets[i];
                auto &rightBucket = buckets[i + 1];
                //Add elements to merged vector in order.
                while (leftItr < leftBucket.size() && rightItr < rightBucket.size()) {
                    if (!descending) {
                        if (leftBucket[leftItr] <= rightBucket[rightItr]){
                            merged.push_back(leftBucket[leftItr++]);
                        }
                        else { 
                            merged.push_back(rightBucket[rightItr++]);
                        }
                    } 
                    else {
                        if (leftBucket[leftItr] >= rightBucket[rightItr]){
                            merged.push_back(leftBucket[leftItr++]);
                        }
                        else {
                            merged.push_back(rightBucket[rightItr++]);
                        }
                    }
                }

                //Copy what is left over.
                while (leftItr < leftBucket.size()){
                     merged.push_back(leftBucket[leftItr++]);
                }
                while (rightItr < rightBucket.size()){
                     merged.push_back(rightBucket[rightItr++]);
                }

                newBuckets.push_back(std::move(merged));
            } 
            else {
                //If there's a bucket left over, just move it forward
                newBuckets.push_back(std::move(buckets[i]));
            }
        }

        //Prepare for next merge pass by moving newBuckets into buckets.
        buckets = std::move(newBuckets);
    }

    //Final sorted result replaces original list
    list = std::move(buckets[0]);
}

/* Binary Radix Sort
 *
 * 20 points
 *
 * Algorithm:
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 */
template<Integral T> 
void binary_radix_sort(vector<T> &list, bool descending) {
    if (list.size() <= 1) return;
    //Stores the number of bits depending on T.
    const int BITS = sizeof(T) * 8;
    //Temporary vector for stable partitioning
    vector<T> temp(list.size());

    //Sort by least valuable bit first.
    for (int bit = 0; bit < BITS; ++bit) {
        size_t zeroCount = 0;

        //Count how many numbers have current bit = 0
        for (size_t i = 0; i < list.size(); ++i) {
            //Perform left shift of the amount of bits we're currently on and see if the value is 1.
            if (((list[i] >> bit) & 1) == 0)
                zeroCount++;
        }

        //Partition into temp array, stable
        size_t zeroIndex = 0;
        size_t oneIndex = zeroCount;

        //Figures out where in the order for the current bit's pass each element should go.
        //As we make more passes, the bits become more valuable, so we will have a correct sorting in the end, even if low value bits match up.
        for (size_t i = 0; i < list.size(); ++i) {
            if (((list[i] >> bit) & 1) == 0)
                temp[zeroIndex++] = list[i];
            else
                temp[oneIndex++] = list[i];
        }

        //Copy back to list for next pass
        list = temp;
    }

    //If descending, reverse the list.
    if (descending) {
        reverse(list.begin(), list.end());
    }
}

/* Your Hybrid Sort
 *
 * 25 points
 *
 * Algorithm: Your own custom Hybrid Sorting algorithm! Remember, a hybrid
 *            sort tries to take advantage of two (or more) sorting algorithms
 *            to speed up data processing.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 */
template<typename T>
void my_hybrid_sort(vector<T> &list, bool descending) {
    //Quicksort/insertion sort hybrid.
    //If the number of list elements exceeds THRESHOLD, we use quicksort, otherwise we use insertion sort.
    const int THRESHOLD = 10;

    //Lambda to perform recursive hybrid sorting. [&] allows the lambda to access the entire scope of my_hybrid_sort by reference.
    function<void(int, int)> hybrid_quick = [&](int left, int right) {
        if (right - left + 1 <= THRESHOLD) {
            //For small ranges, use insertion sort
            for (int i = left + 1; i <= right; i++) {
                T currentVal = list[i];
                int j = i - 1;
                while (j >= left && list[j] > currentVal) {
                    list[j + 1] = list[j];
                    j--;
                }
                list[j + 1] = currentVal;
            }
            return;
        }

        //For larger ranges, we use a quicksort.
        T pivot = list[left + get_rand_index(right - left + 1)];
        int i = left;
        int j = right;
        while (i <= j) {
            while (list[i] < pivot){ 
                i++;
            }
            while (list[j] > pivot){
                j--;
            }
            if (i <= j) {
                std::swap(list[i], list[j]);
                i++;
                j--;
            }
        }
        //Recurse around the pivot.
        if (left < j) hybrid_quick(left, j);
        if (i < right) hybrid_quick(i, right);
    };

    //Call the recursive hybrid quicksort
    hybrid_quick(0, list.size() - 1);

    //Reverse at the end if descending.
    if (descending) {
        reverse(list.begin(), list.end());
    }
}

/* Base B Radix Sort 
 *
 * 25 Points
 *
 * Algorithm: Implement Radix Sort as discussed in class, but with
 *            respect to any unspecified base.
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 *
 *   unsigned int base: the base with which to implement the radix sort. 
 *                      Note that base should be at least 2. The default
 *                      base is 10.
 *
 *   bool decending: if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default).
 *
 *
 * Additional Information:
 *   - If you are enrolled in the graduate section of this course, you MUST
 *     implement this function (i.e., it counts towards your total grade).
 *
 *   - If you are enrolled in the undergraduate section of this course, this
 *     function is optional and worth extra credit.
 *
 *
 */
template<Integral T>
void radix_sort(vector<T> &list, unsigned int base, bool descending) {
    // Your code here!
}






int main() {
    /**** STUDENT CODE HERE ****/ 
    //vector<int> test_list {33, 51, 42, 19, 21, 83, 31, 31, 99, 9, 11};
    vector<int> test_list;
    for(int i = 0; i < 10000; i++){
        test_list.push_back(rand() % 10000);
    }
    printList(test_list, "No Sort");
    /***** DO NOT MODIFY BELOW THIS LINE *****/
    /*** INSTRUCTIONS ***
     *
     * Before submitting your code: 
     *   - remove all code within the main function that you have written above the `do-not-modify` line;
     *   - uncomment all lines below that begin with "//".
     *
     */
    vector<int> test_list {1, 2, 3, 4, 5};
    bubble_sort(test_list);
    selection_sort(test_list);
    insertion_sort(test_list);
    quicksort(test_list);
    merge_sort(test_list);
    bucket_merge_sort(test_list);
    binary_radix_sort(test_list);
    my_hybrid_sort(test_list);
    radix_sort(test_list);


    return 0;
}









