//
//  sortings.hpp
//  Algorithms
//
//  Created by Manish Patidar on 22/01/24.
//

#ifndef sortings_hpp
#define sortings_hpp

#include "iostream"
#include "vector"

using namespace std;

template <typename T>
void bubbleSort(vector<T> &arr) {
    bool flag = false;
    for (int i = 0; i < arr.size(); i++) {
        for(int j = 1; j < arr.size() - i; j++) {
            if (arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
                flag = true;
            }
        }
        if (flag == false) {
            cout<<"FYI, Array is already sorted!";
            break;
        }
    }
}



#endif /* sortings_hpp */
