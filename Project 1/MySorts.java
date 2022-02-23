
/**
 * MySorts implements a collection of 4 different
 * sorting algorithms which I was taught in CSCI 251.
 * They are static methods which may be called to sort
 * an array of integers.
 *
 * @author Matthew Boyea
 * @version 2022.2.8
 */
public class MySorts
{
  public static void selectSort(int[] array) {
    int temp;
    // i ranges from the first to the second-to-last element
    for (int i = 0; i < array.length - 1; i++) {
      // FIND SMALLEST FROM i+1 TO size
      int indexSmallest = i;
      // j ranges from the second to the last element
      for (int j = i + 1; j < array.length; j++) {
        // if element j is less than the current known smallest element
        if (array[j] < array[indexSmallest]) {
          // set the smallest known element to j
          indexSmallest = j;
        }
      }
      // SWAP THE SMALLEST KNOWN INDEX WITH i
      temp = array[i];
      array[i] = array[indexSmallest];
      array[indexSmallest] = temp;
    }
  }
  public static void insertSort(int[] array) {
    int temp;
    // i ranges from the second to the high element
    for (int i = 1; i < array.length; i++) {
      // INSERT i AT THE SORTED POSITION TO THE LEFT
      for (int j = i; j > 0 && array[j] < array[j-1]; j--) {
        // swap j and j-1
        temp = array[j];
        array[j] = array[j - 1];
        array[j - 1] = temp;
      }
    }
  }
  private static void merge(int[] array, int leftFirst, int leftLast, int rightLast) {
    int mergedSize = rightLast + 1 - leftFirst; // Size of merged partition
    int mergePos = 0;                           // Position to insert merged number
    int leftPos = leftFirst;                    // Position of elements in left partition
    int rightPos = leftLast + 1;                // Position of elements in right partition
    int[] mergedNumbers = new int[mergedSize];  // Dynamically allocates temporary array
                                                // for merged array
    // Add smallest element from left or right partition to merged array
    while (leftPos <= leftLast && rightPos <= rightLast) {
      if (array[leftPos] <= array[rightPos]) {
        mergedNumbers[mergePos] = array[leftPos];
        leftPos++;
      } else {
        mergedNumbers[mergePos] = array[rightPos];
        rightPos++;
      }
      mergePos++;
    }
    // If left partition is not empty, add remaining elements to merged array
    while (leftPos <= leftLast) {
      mergedNumbers[mergePos] = array[leftPos];
      leftPos++;
      mergePos++;
    }
    // If right partition is not empty, add remaining elements to merged array
    while (rightPos <= rightLast) {
      mergedNumbers[mergePos] = array[rightPos];
      rightPos++;
      mergePos++;
    }
    // Copy merge number back to array
    for (mergePos = 0; mergePos < mergedSize; mergePos++) {
      array[leftFirst + mergePos] = mergedNumbers[mergePos];
    }
  }
  private static void mergeSortRecursive(int[] array, int low, int high) {
    if (low < high) {
      int leftLast = (low + high) / 2;
      // Recursively sort left and right partitions
      mergeSortRecursive(array, low, leftLast);
      mergeSortRecursive(array, leftLast + 1, high);
      // Merge left and right partition in sorted order
      merge(array, low, leftLast, high);
    }
  }
  public static void mergeSort(int[] array) {
    mergeSortRecursive(array, 0, array.length - 1);
  }
  private static int pivot(int[] array, int low, int high) {
    int mid = low + (high - low) / 2;
    int pivot = array[mid];
    int temp;
    while (true) {
      // set low to equal the farthest index to the left
      // at which the element is greater than pivot
      while (array[low] < pivot) {
        low += 1;
      }
      // set high to equal the farthest index to the right
      // at which the element is less than pivot
      while (array[high] > pivot) {
        high -= 1;        
      }
      if (low >= high) {
        // low has met or past high, so the pivot is in the correct position
        break;
      }
      // swap elements at low and high
      temp = array[low];
      array[low] = array[high];
      array[high] = temp;
      // increment low and high
      low += 1;
      high -= 1;
    }
    return high;
  }
  private static void quickSortRecursive(int[] array, int low, int high) {
    if (low < high) {
      // partition the data in the array;
      // place the pivot element into the correct index;
      // return the high element of the left partition
      int leftLast = pivot(array, low, high);
      // recursively call on the left and right partitions
      quickSortRecursive(array, low, leftLast);
      quickSortRecursive(array, leftLast + 1, high);
    }
    
  }
  public static void quickSort(int[] array) {
    quickSortRecursive(array, 0, array.length - 1);
  }
}
