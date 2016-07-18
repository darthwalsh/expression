/// <reference path="maths.ts" />

declare var require: any;

console.log(new Maths.Sum(
  new Maths.Constant(3), 
  new Maths.Constant(2)).evaluate());

var fs = require("fs");

fs.readFile('..\\test.txt', 'utf8', function (err,data) {
  if (err) {
    return console.log(err);
  }
  var lines = data.split('\r\n');
  for (var i = 0; i < lines.length; i += 3) {
    var line = lines[i];
    console.log(line);

    var expected = +lines[i+1].substring(1);

    //TODO var e = parser.parse(line);
    var actual = 2 //TODO e.evaluate();

    if (expected !== actual) {
      console.log("expected: " + expected + " != actual: " + actual);
      return;
    }

    console.log('= ' + expected);
  }
});