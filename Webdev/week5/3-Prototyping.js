function Person(name) {
    this.name = name;
}

// Add a method to the prototype
Person.prototype.greet = function() {
    return "Hello, my name is " + this.name;
};

var person1 = new Person("Alice");

// Access the prototype method through the instance
console.log(person1.greet());  // Output: "Hello, my name is Alice"

// Create another object that inherits from person1
var person2 = Object.create(person1);

// person2 now has access to the greet method from person1's prototype
console.log(person2.greet());  // Output: "Hello, my name is Alice"

// Modify the prototype property
Person.prototype.greet = function() {
    return "Hi, I'm " + this.name;
};

// The change is reflected in all instances and objects that share the prototype
console.log(person1.greet());  // Output: "Hi, I'm Alice"
console.log(person2.greet());  // Output: "Hi, I'm Alice"