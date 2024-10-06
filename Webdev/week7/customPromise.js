function customPromiseExecutor(resolve, reject){
    setTimeout(() => {
        resolve("Sample value");
        console.log("Inside promise executor function");
    }, 5000);
}

function PromiseCustom(executorFuncArg){
    this.state = 'pending',

    executorFuncArg(
        (responseArg) => {
            this.state = "fulfilled";
            console.log("Inside resolve function with return value as: ", responseArg);
        },
        (errArg) => {
            this.state = "rejected";
            console.log("Inside reject function with return vale as: ", errArg);
        }
    );
}
var promise1 = new PromiseCustom(customPromiseExecutor);