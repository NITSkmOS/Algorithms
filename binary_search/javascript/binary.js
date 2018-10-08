function main(){
  var arr[10],i,e;
    for(i=0;i<10;i++)
        arr[i]=i;
    e=5;
    var found = binarySearch(arr,e);
    window.console(found);
}
function binarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;
    while (left <= right) {
        const mid = left + Math.floor((right - left) / 2);
        if (arr[mid] === target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
