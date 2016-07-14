var Constant = function(n) {
  this.n = n;
}
Constant.prototype.evaluate = function() {
  return this.n;
}

var Sum = function (left, right) {
  this.left = left;
  this.right = right;
}

Sum.prototype.evaluate = function() {
  return this.left.evaluate() + this.right.evaluate();
}

var c = new Constant(2);
console.log(c.evaluate());

var s = new Sum(c, c);
console.log(s.evaluate());

s = new Sum(s, c);
console.log(s.evaluate());