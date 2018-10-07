import java.util.Arrays;
import java.util.Collections;

class CountSort {
 /**
  * Function to get maximum number in an array of integers.
  * @param arr the array from which maximum number is to be obtained.
  */
 static int getMax(int[] arr) {
  int max = Integer.MIN_VALUE;
  for (int each_num: arr) {
   if (each_num > max) {
    max = each_num;
   }
  }
  return max;
 }

 static int[] countSort(int[] arr) {
  /**
   * Function to sort the arrays based on the Counting sort alogrithm.
   * This algorithm works by maintaining the count of each number from the array
   * and then placing it at the right position in the resulting array
   * @param arr the array to be sorted.
   */
  int maximum_number = getMax(arr); // get the max number in the array in order to declare count array.
  int[] count_arr = new int[maximum_number + 1]; // maximum_number + 1 as we need to correctly map each index with the number in the array

  for (int i = 0; i < count_arr.length; i++) {
   count_arr[i] = 0;
  }

  for (int each_number: arr) {
   count_arr[each_number] += 1; // get the count of each number in the original array.
  }

  for (int i = 1; i < count_arr.length; i++) {
   count_arr[i] += count_arr[i - 1]; // rolling sum gets count of numbers less than current index in the original array
  }

  int[] sorted_arr = new int[arr.length]; // declare and initialize sorted array.
  for (int i = 0; i < sorted_arr.length; i++) {
   sorted_arr[i] = 0;
  }

  for (int each_num: arr) {
   sorted_arr[count_arr[each_num] - 1] = each_num; //place the arrays at apt position on the basis of value in count array
   count_arr[each_num] -= 1;
  }
  return sorted_arr;
 }

 public static void main(String[] args) {
  int[] array = {
   4,
   2,
   1,
   55,
   22,
   1,
   77
  }; // tester code
  int[] sorted_arr = countSort(array);
  for (int each_num: sorted_arr) {
   System.out.print(each_num + " ");
  }
 }
}
