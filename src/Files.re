Js.logMany([|"hello", "io"|]);

let y = 7;
let x = {
  let a = 3;
  let b = 4;
  a + b + y;
};

Util.printDir(~padding=0, ~ignore="Demo.re", "./");
Js.log("----------------------------------------");
Util.printDir(~padding=0, "./");