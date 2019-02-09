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
}