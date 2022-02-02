/* This class tests the functionality of the SelectionSort class.
 * 
 * @author Matthew Boyea
 * @version Feb 2, 2022
*/
public class SelectionSort
{
    static void sort(int[] array) {
        int temp;
        // for every index from 0 to size-2 inclusive
        for (int i = 0; i < array.length - 1; i++) {
            // find index of smallest element from i to size-1 inclusive
            int indexSmallest = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[j] < array[indexSmallest]) {
                    indexSmallest = j;
                }
            }
            // swap i with the smallest element
            temp = array[i];
            array[i] = array[indexSmallest];
            array[indexSmallest] = temp;
        }
    }
}
