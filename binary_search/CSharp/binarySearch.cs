using System;
using System.Linq;

namespace BinarySearch
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] array = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int itemIndex = BinarySearch(array, int.Parse(Console.ReadLine()));
            Console.WriteLine(itemIndex);
        }

        static int BinarySearch(int[] array, int item)
        {
            if (array[0] > item || array[array.Length - 1] < item) return -1;
            if (array[array.Length / 2] > item)
            {
                return BinarySearch(array.Take(array.Length / 2).ToArray(), item);
            }
            else if (array[array.Length / 2] > item)
            {
                return BinarySearch(array.Skip((array.Length / 2)+1).Take(array.Length / 2).ToArray(), item);
            }
            else return array.Length / 2;
        }
    }
}
