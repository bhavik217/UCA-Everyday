// Promise

// Promise is an object created using Promise() constructor function and have two properties
// - State
// - Value

// There are 3 states
// - pending  - initial state
// - fulfilled
// - rejected

// Value - Possible value
//  - Undefined  -  intial state
//  - return value or error


function promiseExecuter(resolve, reject){
    setTimeout(() => {
        resolve({response : "responseValue"});
        console.log("Inside promise executor function");
    }, 5000);
}

var promise1 = new Promise(promiseExecuter);
promise1.then((someValue) => {    // .then works on method chaining basically its implementation contains method chaining
    responseValue = someValue;
});


function promiseExecuter(resolve, reject){
    setTimeout(() => {
        reject({response : "responseValue"});
        console.log("Inside promise executor function");
    }, 5000);
}

var promise1 = new Promise(promiseExecuter);
promise1.catch((someValue) => {    // .then works on method chaining basically its implementation contains method chaining
    responseValue = someValue;
});