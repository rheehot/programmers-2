function solution(arrangement) {
  const stack = [];
  let answer = 0;

  for (let i = 0; i < arrangement.length; i++) {
    if (arrangement[i] === "(") {
      stack.push("(");
      continue;
    }

    stack.pop();

    if (arrangement[i - 1] === ")") {
      answer += 1;
      continue;
    }

    answer += stack.length;
  }

  return answer;
}

console.log(solution("()(((()())(())()))(())"));
