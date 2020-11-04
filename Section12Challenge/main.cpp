#include <iostream>

using namespace std;

void print(int const *arr, size_t size);
int *applyAll(const int *const array1, size_t array1_size, const int *const array2, size_t array2_size);

void print(const int *const arr, size_t size){
    cout << "[ ";
    for(size_t i {}; i < size; ++i)
        cout << *(arr + i) << " ";
        //cout << arr[i] << " ";
    cout << "]" << endl;
}

int * applyAll(const int *const array1, size_t array1_size, const int *const array2, size_t array2_size){
    int *storage {nullptr};
    storage = new int[array1_size * array2_size];
    int cr {};
    for (size_t i {}; i < array2_size; ++i) {
        for (size_t j {}; j < array1_size; ++j){
            storage[cr] = array1[j] * array2[i];
            ++cr;
        }
    }
        
        return storage;
}


int main(){
    
    const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1[] {1,2,3,4,5};
    int array2[] {10, 20, 30};
    
    cout << "Array 1: ";
    print(array1, array1_size);
    
    cout << "Array 2: ";
    print(array2, array2_size);
    
    int *results = applyAll(array1, array1_size, array2, array2_size);
    constexpr size_t resultsSize {array1_size * array2_size};
    
    cout << "Result; ";
    print(results, resultsSize);
    
    delete [] results;
    return 0;
}