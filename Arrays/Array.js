class Array_Class {
    constructor() {
        this.arr = [];
        this.capacity = 0;
    }

    size() {
        return this.arr.length;
    }

    capacity() {
        return this.capacity;
    }

    is_empty() {
        return this.arr.length == 0 ? true : false;
    }

    at(index) {
        try {
            return this.arr[index];
        } catch (error) {
            return error;
        }
    }

    push(item) {
        this.arr.push(item);
        return;
    }

    insert(index, item) {
        this.arr.splice(index, 0, item);
        return;
    }

    prepend(item) {
        this.arr.unshift(item);
        return;
    }

    pop() {
        return this.arr.pop();
    }

    delete(index) {
        this.arr.splice(index, 1);
        return
    }

    remove(item) {
        while (this.arr.indexOf(item)) {
            this.arr.splice(this.arr.indexOf(item), 1)
        }
        return
    }

    find(item) {
        return this.arr.indexOf(item)
    }

    resize(new_capacity) {
        //when you reach capacity, resize to double the size
        //when popping an item, if size is 1/4 of capacity, resize to half
        //Do nothing since not feasible in JS
        pass
    }

}

/*
let arr = new Array_Class();
arr.prepend(1);
arr.prepend(2);
arr.prepend(5);
arr.prepend(3);
console.log(arr);
*/