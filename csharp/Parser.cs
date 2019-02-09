using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Math
{
    static class Parser
    {
        static Regex lexer = new Regex(@"-?\d+|[-+*/^%]", RegexOptions.Compiled);
        public static Expression Parse(string s) {
            var tokens = Lex(s).ToList();
            var (e, end) = ParseHelper(tokens, 0);
            if (end != tokens.Count) {
                throw new InvalidOperationException("Expected EOF");
            }
            return e;
        }

        private static IEnumerable<string> Lex(string s) {
            foreach (Match match in lexer.Matches(s)) {
                yield return match.Value;
            }
        }

        private static (Expression, int) ParseHelper(List<string> tokens, int start) {
            var s = tokens[start];

            if("-+*/^%".Contains(s)) {
                var (x, next) = ParseHelper(tokens, start + 1);
                var (y, end) = ParseHelper(tokens, next);

                switch(s) {
                    case "+": return (new Sum(x, y), end);
                    case "-": return (new Difference(x, y), end);
                    case "*": return (new Product(x, y), end);
                    case "/": return (new Quotient(x, y), end);
                    case "^": return (new Power(x, y), end);
                    case "%": return (new Modulo(x, y), end);
                    default: throw new InvalidOperationException($"Unknown op {s}");
                }
            }

            if (int.TryParse(s, out var n)) {
                return (new Constant { Value = n }, start + 1);
            }

            throw new InvalidOperationException($"Unknown at: {s} #{start}");
        }
    }
}