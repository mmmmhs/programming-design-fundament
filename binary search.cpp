int BinarySearch(int AA[], int Key, 
                 int low, int high) {
    int middle = 0;
    while (low <= high) {
        middle = (low + high) / 2;
        if (Key == AA[middle])
            return middle;
        else if (Key < AA[middle])
            high = middle - 1;
        else
            low = middle + 1;
    }
    return -1;
}
