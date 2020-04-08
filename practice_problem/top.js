function solution(heights) {
  return heights.map((value, index) => {
    while (index--) {
      if (heights[index] > value) return index + 1;
    }
    return 0;
  });
}

console.log(solution([6, 9, 5, 7, 4]));
console.log(solution([3, 9, 9, 3, 5, 7, 2]));
console.log(solution([1, 5, 3, 6, 7, 6, 5]));
