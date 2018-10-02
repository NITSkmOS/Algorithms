class BinarySearch
{
  public static void main(String[] args)
  {
    int a[] = {1,2,3,4,5,6,7,8,9, 0};
    int n = 5;
    if(binarySearch(a, n) == true)
      System.out.println("Element found!");
    else
      System.out.println("Element not found");

  }

  static boolean binarySearch(int arr[], int n)
  {
    int len = arr.length;
    int l = 0;
    int u = len-1;
    int m = (l + u)/2;
    boolean flag = false;
    while(u >= l)
    {
      if(arr[m] == n)
        flag = true;
      if(arr[m] > n)
        u = m - 1;
      else
        l = m + 1;
      m = (l + u)/2;

    }
    return flag;
  }
}
