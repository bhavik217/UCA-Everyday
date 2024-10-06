function foo(){          // Normal function but it use function declaration
    console.log("Hello");
}

var hello = () => {      // Arrow function but it use functional expression
    console.log("Hello");
}

() => {                  // Anonymous function and it can be anonymous function
    console.log("Hello");
}