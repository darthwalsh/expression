namespace Math
{
    public interface Expression {
        int Value { get; }
    }

    public sealed class Constant : Expression {
        public int Value { get; set; }
    }

    public abstract class BinaryOp : Expression {
        Expression x;
        Expression y;

        public BinaryOp(Expression x, Expression y) {
            this.x = x;
            this.y = y;
        }

        public int Value => Op(x.Value, y.Value);

        protected abstract int Op(int x, int y);
    }

    public sealed class Sum : BinaryOp {
        public Sum(Expression x, Expression y)
        : base(x, y) {
        }

        protected override int Op(int x, int y) => x + y;
    }

    public sealed class Difference : BinaryOp {
        public Difference(Expression x, Expression y)
        : base(x, y) {
        }

        protected override int Op(int x, int y) => x - y;
    }

    public sealed class Product : BinaryOp {
        public Product(Expression x, Expression y)
        : base(x, y) {
        }

        protected override int Op(int x, int y) => x * y;
    }

    public sealed class Quotient : BinaryOp {
        public Quotient(Expression x, Expression y)
        : base(x, y) {
        }

        protected override int Op(int x, int y) => x / y;
    }

    public sealed class Power : BinaryOp {
        public Power(Expression x, Expression y)
        : base(x, y) {
        }

        protected override int Op(int x, int y) => (int)System.Math.Pow(x, y);
    }

    public sealed class Modulo : BinaryOp {
        public Modulo(Expression x, Expression y)
        : base(x, y) {
        }

        protected override int Op(int x, int y) => x % y;
    }
}