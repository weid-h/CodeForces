using System;
using System.Linq;

namespace ProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            var testAmount = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < testAmount; i++)
            {
                var arrayLength = Int32.Parse(Console.ReadLine());
                var arrayElements = Console.ReadLine().Split(" ").Select(c => Int32.Parse(c)).ToArray();
                var max = 0;

                for (int j = arrayLength - 1; j >= 0; j--)
                {
                    if (j + arrayElements[j] < arrayLength)
                    {
                        var value = arrayElements[j + arrayElements[j]];
                        arrayElements[j] += value;
                    }
                    max = (max > arrayElements[j]) ? max : arrayElements[j];
                }

                Console.WriteLine(max);
            }
        }
    }
}