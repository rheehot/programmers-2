function solution(p) {
  if (!p.length) return "";

  let u, v;
  let cnt = 0;
  for (let i = 0; i < p.length; i++) {
    const value = p[i];
    value === "(" ? cnt++ : cnt--;
    if (cnt === 0) {
      u = p.slice(0, i + 1);
      v = p.slice(i + 1, p.length);
      break;
    }
  }

  cnt = 0;
  for (const ch of u) {
    if (cnt < 0) break;
    ch === "(" ? cnt++ : cnt--;
  }

  if (cnt === 0) return u + solution(v);

  let answer = `(${solution(v)})`;
  u = u.slice(1, u.length - 1);
  for (const ch of u) answer += ch === "(" ? ")" : "(";

  return answer;
}

console.log(solution("(()())()"));
console.log(solution(")("));
console.log(solution("()))((()"));
