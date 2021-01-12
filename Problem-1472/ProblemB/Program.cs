using System;
using System.Linq;

namespace ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            var testAmount = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < testAmount; i++)
            {
                var candyAmount = Int32.Parse(Console.ReadLine());
                var candyWeights = Console.ReadLine().Split(" ").Select(c => Int32.Parse(c)).ToArray();
                Console.WriteLine(Calculate(candyAmount, candyWeights));
            }
        }

        static string Calculate(int candyAmount, int[] candyWeights)
        {
            var oneGramCandies = candyWeights.Where(weight => weight == 1).Count();
            var twoGramCandies = candyWeights.Where(weight => weight == 2).Count();
            if (oneGramCandies % 2 == 0 && twoGramCandies % 2 == 0)
            {
                return "YES";
            }
            else if (oneGramCandies % 2 == 0 && oneGramCandies > 1 && twoGramCandies % 2 != 0)
            {
                return "YES";
            }
            else
            {
                return "NO";
            }
        }
    }
}
