let a = 3;
let b = (4, "Hello", 'A', true, 3.14);
type person = {
  age: int,
  name: string,
};
let c = {age: 5, name: "Bob"};
Js.log(c.age);

type myvariant1 =
  | Yes
  | No
  | Maybe;

type myvariant2 =
  | Yes
  | Super;

let isThisCool: myvariant1 = Yes;

let msg =
  switch (isThisCool) {
  | Yes => "noice"
  | No => "sweet"
  | Maybe => "really?!?"
  };

Js.log(msg);