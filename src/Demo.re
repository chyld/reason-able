// ---------------------------------------------------------- //
// ---------------------------------------------------------- //
// ---------------------------------------------------------- //
Js.log("Hello World");
let a = 3;
let b = "hello";
let c = true;
let d = 3.14;

// ---------------------------------------------------------- //
// ---------------------------------------------------------- //
// ---------------------------------------------------------- //
[@bs.val] external pi: float = "Math.PI";
[@bs.val] external pow: (float, float) => float = "Math.pow";
let food = BsFaker.Image.food();

// ---------------------------------------------------------- //
// ---------------------------------------------------------- //
// ---------------------------------------------------------- //
[%bs.raw "console.log('food is:', food)"];
[%bs.raw {dog| console.log("pi is:", pi)  |dog}];
let f: int = [%bs.raw "3 ** 2"];