template <typename T, int N>
T max_element(const FixedArray<N, T>& arr) {
    if (arr.size() == 0) {
        throw IndexError("Array is empty");
    }

    T max_val = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}
