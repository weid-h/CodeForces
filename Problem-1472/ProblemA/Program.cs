using System;
using System.Linq;

namespace Problem_1472
{
    class Program
    {
        static void Main(string[] args)
        {
            var tests = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < tests; i++)
            {
                var input = Console.ReadLine().Split(" ").Select(p => Int32.Parse(p)).ToArray();
                var w = input[0];
                var h = input[1];
                var n = input[2];

                if (n == 1)
                {
                    Console.WriteLine("YES");
                }
                else if (MaximumPieces(w, h) >= n)
                {
                    Console.WriteLine("YES");
                }
                else
                {
                    Console.WriteLine("NO");
                }
            }
        }

        private static int MaximumPieces(int w, int h, int sheets = 0)
        {
            if (w % 2 == 0)
            {
                return MaximumPieces(w / 2, h, sheets > 0 ? sheets * 2 : 2);
            }
            else if (h % 2 == 0)
            {
                return MaximumPieces(w, h / 2, sheets > 0 ? sheets * 2 : 2);
            }
            else
            {
                return sheets;
            }
        }
    }
}
