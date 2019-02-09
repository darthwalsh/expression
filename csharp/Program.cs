using System;
using System.IO;

namespace Math
{
    class Program
    {
        static void Main(string[] args)
        {
            var lines = File.ReadAllLines(Path.Join("..", "test.txt"));
            for (var i = 0; i < lines.Length; i += 3) {
                var line = lines[i];
                var actual = Parser.Parse(line).Value;
                Console.WriteLine($"{line} = {actual}");

                var expected = int.Parse(lines[i+1].Substring(1));
                if (expected != actual) {
                    Console.Error.WriteLine($"Expected {expected} but got {actual}");
                }
            }

            Console.WriteLine("Tests succeeded!");
        }
    }
}
