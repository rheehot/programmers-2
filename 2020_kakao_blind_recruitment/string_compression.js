function solution(s) {
  if (s.length === 1) return 1;

  let answer = -1;

  const unitCount = parseInt(s.length / 2);

  for (let unit = 1; unit <= unitCount; unit++) {
    let tempString = "";

    let index = 0;
    while (index < s.length) {
      const char = s.slice(index, index + unit);

      index += unit;

      let charCount = 0;
      while (s.slice(index, index + unit) === char) {
        charCount++;
        index += unit;
      }

      tempString += !charCount ? `${char}` : `${charCount + 1}${char}`;
    }

    if (answer === -1 || answer > tempString.length) {
      answer = tempString.length;
    }
  }

  return answer;
}

console.log(solution("aabbaccc"));
console.log(solution("ababcdcdababcdcd"));
console.log(solution("abcabcdede"));
console.log(solution("abcabcabcabcdededededede"));
console.log(solution("xababcdcdababcdcd"));

// "aabbaccc"	7
// "ababcdcdababcdcd"	9
// "abcabcdede"	8
// "abcabcabcabcdededededede"	14
// "xababcdcdababcdcd"	17
