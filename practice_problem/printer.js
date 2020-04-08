function solution(priorities, location) {
  const objPriorities = priorities.map((v, i) => {
    return { v, i };
  });

  const prints = [];

  while (objPriorities.length) {
    const { v, i } = objPriorities.shift();
    const isExist = objPriorities.some(({ v: checkV }) => checkV > v);

    if (isExist) objPriorities.push({ v, i });
    else prints.push({ v, i });
  }

  return prints.findIndex(({ i }) => i === location) + 1;
}

console.log(solution([2, 1, 3, 2], 2));
console.log(solution([1, 1, 9, 1, 1, 1], 0));
