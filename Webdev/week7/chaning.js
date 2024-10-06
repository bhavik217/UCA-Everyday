var foo1 = () => {
    console.log("Inside foo1");
    return function foo2(){
        console.log("Inside foo2");
    }
}
foo1()();   

var x = "str1";
var str = x.concat("str2").concat("str3").concat("str4");
console.log(str);



// Infinite concat

// function infiniteConcat(initialString){
//     this.initialString = initialString;
//     this.result = intialString;

//     return {

//     }
// }