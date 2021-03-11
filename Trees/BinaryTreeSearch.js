class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
    constructor() {
        this.value = undefined;
        this.left = null;
        this.right = null;
    }
}

class Tree {
    constructor() {
        this.root = null;
    }
    constructor(node) {
        this.root = node;
    }
}

function binary_tree_search(root, val) {
    if (root == null) {
        return -1;
    }
    if (root.val == val) {
        return root;
    } else if (root.val > val) {
        return binarySearch(root.left, val);
    } else if (root.val < val) {
        return binarySearch(root.right, val);
    }
}

function test_binary_search() {

}