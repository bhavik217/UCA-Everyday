/* -------------------------------------------------------------------------------------- */
/*  Contructor Functions (Start)  */ 

// var maxMarks = 500;

// function student(fName, obtainedMarks) {
//     console.log(this); // this refers to the window object
    
//     return {
//         fName: fName, obt: obtainedMarks,
//         checkResults: function() {
//             console.log(this); // this refers to the object that is being created
            
//             let percentage = ( this.obt / maxMarks ) * 100; // this.obt is same as obtainedMarks
//             if(percentage >= 40) return "Passed";
//             else return "Failed";
//         }
//     }
// }
// var student1 = student("Harshit", 200); // this refers to the student 1 in this


function student(fName, obtainedMarks) {
    console.log(this); // this refers to the newly created object
    
    this.fNameObj = fName;
    this.obtMarksObj = obtainedMarks;
    this.checkResults =  function() {

        console.log(this); // this refers to the object that is being created
            
        let percentage = ( this.obtMarksObj / maxMarks ) * 100; // this.obt is same as obtainedMarks
            
        if(percentage >= 40) return "Passed";
        else return "Failed";
    }
}
var student1 = new student("Harshit", 200); 
// If used new keyword with a function
// this refers to the left hand side (student1 here) of the assignment operator

console.log(student1);
console.log(student1.checkResults());

/*  Contructor Functions (End)  */
/* -------------------------------------------------------------------------------------- */
