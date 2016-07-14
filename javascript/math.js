var Constant = function(n) {
  this.n = n;
}
Constant.prototype.evaluate = function() {
  return this.n;
}

var Binary = function (left, right) {
  this.left = left;
  this.right = right;
}

var Sum = function (left, right) {
  Binary.call(this, left, right);
}
Sum.prototype.evaluate = function() {
  return this.left.evaluate() + this.right.evaluate();
}

var Difference = function (left, right) {
  Binary.call(this, left, right);
}
Difference.prototype.evaluate = function() {
  return this.left.evaluate() - this.right.evaluate();
}

var Product = function (left, right) {
  Binary.call(this, left, right);
}
Product.prototype.evaluate = function() {
  return this.left.evaluate() * this.right.evaluate();
}

var Quotient = function (left, right) {
  Binary.call(this, left, right);
}
Quotient.prototype.evaluate = function() {
  return Math.floor(this.left.evaluate() / this.right.evaluate());
}

var Modulo = function (left, right) {
  Binary.call(this, left, right);
}
Modulo.prototype.evaluate = function() {
  return this.left.evaluate() % this.right.evaluate();
}

var Power = function (left, right) {
  Binary.call(this, left, right);
}
Power.prototype.evaluate = function() {
  return Math.pow(this.left.evaluate(), this.right.evaluate());
}

module.exports = {
  Constant: Constant,
  '+': Sum,
  '-': Difference,
  '*': Product,
  '/': Quotient,
  '%': Modulo,
  '^': Power
}