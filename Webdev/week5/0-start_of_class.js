var obj1 = { name : "Harshit Singla" } // Object Literal
var obj2 = new Object() // Object Constructor

var obj3 = Object.assign({}, obj2); // Deep Copy
var obj4 = Object.assign({name : "newName"}, obj2); // First It makes a copy then overwrites values

/**
 * 1 - Constructor Functions
 * 2 - Classes
 * 3 - Objects.create()
 */

// Prototypes javaScript object have a special property ProtoType which is either NULL or references to other object
// By protoTyping object share their properties
/* -------------------------------------------------------------------------------------- */
/* _proto_ (starts) */


// *    *    *    *    *    *

var obj1 = {
    name : "bhavik",
};
// console(obj.roll); it will give error because roll is not defined

var obj2 = {
    roll : 217
}

console.log(obj1.__proto__); // It will give empty if we haven't created a prototype

obj1.__proto__ = obj2;
console.log(obj1.roll);

// *    *    *    *    *    *
 
obj2.college = "Chitkara";    // To add properties and methods to the object
obj2.maxMarks = 500;        // Now We don't need to create a maxMarks variable in the function

console.log(obj1.college);
console.log(obj1.maxMarks);
console.log(obj1.__proto__);
console.log(obj2.__proto__);    // It will be NULL
