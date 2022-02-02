/* This class tests the functionality of the SelectionSort class.
 * 
 * @author Matthew Boyea
 * @version Feb 2, 2022
*/

public class main
{
    public static void main(String[] args) {
        // show title
        System.out.println("SELECTION SORT (JAVA)");
        System.out.println("---");
        // prepare numbers
        int[] numbers = { 4, 10, 7, 87, 45, 11, 32, 2 };
        // show numbers before sort
        System.out.println("NUMBERS BEFORE SORT: ");
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(Integer.toString(numbers[i]));
            System.out.print(" ");
        }
        System.out.println();
        // sort array
        SelectionSort.sort(numbers);
        // show numbers after sort
        System.out.println("NUMBERS AFTER SORT: ");
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(Integer.toString(numbers[i]));
            System.out.print(" ");
        }
        System.out.println();
    }
}
