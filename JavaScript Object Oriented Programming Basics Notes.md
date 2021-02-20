# JavaScript Object Orinted Programming Basics Notes
Video : (https://www.youtube.com/watch?v=vDJpGenyHaA)

## Primitive Types vs Object
* Primitive types are wrapped around to an object when a function is called on them
* Although strings are Primative type, they can also be created as object   
   ``` const str = new String("asd") ```

## Usage of __proto__
* When we define a method of a class and that method is not guaranteed to be used in every instance of that class, we can define that method in the prototype of that class. This way we will make use of the memory better since the object pointer will be smaller since function pointer, inside the object pointer doesn't come default in every object. 

## Inheritence
* We can inherit the a class and add additional fields of our choice in js
```javascript 
function Cloth (color,size,price ){
    this.color = color;
    this.size = size;
    this.price = price;
} 
//Tshirt inherits the Cloth object literal
function Tshirt(color,size,price,neck_type, brand){
    Cloth.call(this,color,size,price);
    this.neck_type = neck_type;
    this.brand = brand;
}
```
* Upon inheritence of the object literal we don't inherit the prototype. Thus, we need to inherit the protoype as well
```javascript
    Tshirt.prototype = Object.create(Cloth.prototype)
```

## Class Syntax
```javascript
    class class1{
        constructor(param1, param2){

        }
        //No "function" literal present before the func name
        func1(){ 

        }
        func2(){

        }
        //Callable on class, not on instance of the class
        static func3(){ 

        }
    }
```

## SubClasses
### Way of inheritance

```javascript
//This is used very commonly in React as well
    class class2 extends class1{
        constructor(param1,param2,param3){
            super(param1,param2);
            this.param3 = param3;
        }
    }
```