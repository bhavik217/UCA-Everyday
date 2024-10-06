function hello(){
    console.log(this);
}
new hello();

hello = () => {
    console.log(this);
}
new hello();