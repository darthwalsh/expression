var fs = require('fs');
var math = require("./math.js");
var parser = require("./parser.js");

console.log(new math.Constant(2).evaluate());

fs.readFile('..\\test.txt', 'utf8', function (err,data) {
  if (err) {
    return console.log(err);
  }
  var lines = data.split('\r\n');
  for (var i = 0; i < lines.length; i += 3) {
    var line = lines[i];
    console.log(line);

    var expected = +lines[i+1].substring(1);

    var e = parser.parse(line);
    var actual = e.evaluate();

    if (expected !== actual) {
      console.log("expected: " + expected + " != actual: " + actual);
      return;
    }

    console.log('= ' + expected);
  }
});