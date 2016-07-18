/// <reference path="maths.ts" />
/// <reference path="parser.ts" />

declare var require: any;
var fs = require("fs");

fs.readFile('..\\test.txt', 'utf8', (err,data) => {
  if (err) {
    return console.log(err);
  }
  var lines = data.split('\r\n');
  for (var i = 0; i < lines.length; i += 3) {
    var line = lines[i];
    console.log(line);

    var expected = +lines[i+1].substring(1);

    var e = Parser.parse(line);
    var actual = e.evaluate();

    if (expected !== actual) {
      console.log("expected: " + expected + " != actual: " + actual);
      return;
    }

    console.log('= ' + expected);
  }
});