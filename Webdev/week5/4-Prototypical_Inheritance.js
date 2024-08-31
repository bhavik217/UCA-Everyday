function Student(name, obtainedMarks) {
    this.name = name;
    this.obtainedMarks = obtainedMarks;
    
    this.checkResults = function(maxMarks) {
        let percentage = (this.obtainedMarks / maxMarks) * 100;
        
        if (percentage >= 40) {
            return "Passed";
        } else {
            return "Failed";
        }
    };
}
var student1 = new Student("Harshit", 200);

// Creating another object that inherits from student1
var student2 = Object.create(student1);
console.log(student2.checkResults(100));    // `student2` can access all properties and methods of `student1`

student2.Id = 101;
console.log(student1.Id);   // `student1` can't access properties and methods of `student2`

/* Explanation:
 * - `student2` is an object that inherits from `student1`. It means `student2` can access all properties and methods of `student1`.
 * - If you define a property in `student1`, `student2` will have access to it due to inheritance.
 * - However, if you define a property in `student2`, it won't be available in `student1`.
 */
