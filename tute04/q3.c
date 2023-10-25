// C function to find the largest element in an array, recursively.
// Returns the value of the largest element in the array.
// 
// array:  Array to search
// length: Number of elements in the array
int max(int array[], int length) { // int array = $a0, int length = $a1

    int first_element = array[0];

    if (length != 1) goto else_case;
        // Handle the base-case of the recursion, at the end of the array.
    return first_element;
else_case: 
        // Recurse on the rest of the array.
        // Finds the largest element after first_element in the array.
    int max_so_far = max(&array[1], length - 1);

        // Compare this element with the largest element after it in the array.
    if (first_element <= max_so_far) goto else_case2
    max_so_far = first_element;
else_case2:
        return max_so_far;

}