class Queue {

    constructor() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    enqueu(new_node) {
        if (!this.empty()) {
            this.tail.next = new_node;
            this.tail = new_node;
        } else {
            this.tail = new_node;
            this.head = new_node;
            this.size++;
        }
        this.size++;
        return;
    }

    dequeue() {
        let dequeued_node = this.head;
        if (this.empty()) {
            return "no elements to dequeue";
        } else {
            dequeued_node = this.head;
            if (this.head == this.tail) {
                console.log("Single element in the queue");
                this.head = null;
                this.tail = null;
            } else {
                this.head = this.head.next;
            }
            this.size--;
            return dequeued_node.value.toString();
        }
    }

    empty() {
        return (this.head == null && this.tail == null) ? true : false;
    }

    print_queue() {
        process.stdout.write("Current queue: ");
        let current_node = this.head;
        while (current_node != null) {
            process.stdout.write(current_node.value + " ");
            current_node = current_node.next;
        }
        console.log("");
    }
}

class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

function test_queue() {
    let queue = new Queue();
    queue.print_queue();
    console.log("Is current queue empty : ", queue.empty());

    for (let i = 1; i < 10; i++) {
        let new_node = new Node(i);
        queue.enqueu(new_node);
    }
    queue.print_queue();
    console.log("Is current queue empty : ", queue.empty());


    for (let i = 1; i < 12; i++) {
        console.log("Dequeud value: ", queue.dequeue());
        queue.print_queue();

    }


}
test_queue();