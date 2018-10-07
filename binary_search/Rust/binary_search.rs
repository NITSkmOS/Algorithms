fn binary_search(array: &[i64], length: usize, target: i64) -> i64 {
    let mut left = 0;
    let mut right = length-1;

    while left <= right {
        let middle = (left + right) / 2;
        if array[middle] < target {
            left = middle + 1;
        } else if array[middle] > target {
            right = middle - 1;
        } else {
            return middle as i64;
        }
    }

    return -1;
}

fn main() {
    let array = [1, 4, 16, 21, 109];
    let length = array.len();
    let target = 4;
    
    let index = binary_search(&array, length, target);
    
    println!("Index of {} in array is: {}", target, index);
}
