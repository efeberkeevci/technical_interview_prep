function findLargest(arr, begin, end) {
    if (begin == end) return arr[0];
    else {
        mid = Math.floor((end - begin) / 2) + begin;
        let leftLargest = findLargest(arr, begin, mid);
        let rightLargest = findLargest(arr, mid + 1, end);
        return Math.max(leftLargest, rightLargest);
    }
}
let arr = [9, 6, 2, 4, 1, 7, 3, 5, 8];
console.log(findLargest(arr));