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

fs = require('fs')
fs.readFile('..\\test.txt', 'utf8', function (err,data) {
  if (err) {
    return console.log(err);
  }
  var lines = data.split('\r\n');
  for (var i = 0; i < lines.length; i += 3) {
    var line = lines[i];
    console.log(line);

    var expected = +lines[i+1].substring(1);

    var actual = expected; //TODO

    if (expected !== actual) {
      console.log("expected: " + expected + " != actual: " + actual);
      return;
    }

    console.log('= ' + expected);
  }
});