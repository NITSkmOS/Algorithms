class BubbleSort
{
  public static void main(String[] args)
  {
    //int arr[] = new int[10];
    int arr[] = {6,2,18,0,12,7,1,8,9,5};
    BubbleSort obj = new BubbleSort();
    obj.bubbleSort(arr);
  }

  void bubbleSort(int a[]) //function to sort and print any array passed in the ascending order
  {
    int t = 0;
    int n = a.length;
    for(int i = 0; i < n-1; i++)
      for(int j = 0; j < n-i-1; j++)
      {
        if(a[j] > a[j+1])
        {
          t = a[j];
          a[j] = a[j+1];
          a[j+1] = t;
        }
      }
      for(int i = 0; i < n; i++)
      {
        System.out.print(a[i] + ", ");
      }
  }
}
