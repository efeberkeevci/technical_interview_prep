class point {
    constructor(x, y) {
        this.x = x;
        this.y = y;
    }
}

function maximalPoints(P) {
    if (P.length <= 1) {
        return P[0];
    }
    P.sort((a, b) => {
        return a.x - b.x;
    })
    maximalPointsHelper(0, P.length - 1, P);
}


function maximalPointsHelper(first, last, P) {
    if (first == last) {
        return [P[0]];
    }
    let mid = Math.floor((first + last) / 2);
    let left_undominated_points = maximalPointsHelper(first, mid, P.slice(first, mid + 1));
    let right_undominated_points = maximalPointsHelper(mid + 1, last, P.slice(mid + 1, last + 1));
    let q = find_point_with_highest_y(right_undominated_points);

    return find_undominated_points(left_undominated_points, q).concat(right_undominated_points);
}

function find_point_with_highest_y(P) {
    if (P.length == 1) {
        return P[0];
    }
    P.sort((a, b) => {
        return a.y - b.y;
    });
    return P[P.length - 1];
}

function find_undominated_points(P, q) {
    let undominated_points = [];
    P.forEach(element => {
        if (element.y >= q.y) {
            undominated_points.push(element);
        }
    });
    return undominated_points;
}

let P = [new point(0, 2), new point(3, 4), new point(0, 9), new point(6, -3), new point(5, -9), new point(0, 0)];
console.log(maximalPoints(P));