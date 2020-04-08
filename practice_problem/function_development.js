function solution(progresses, speeds) {
  const answer = [];

  while (progresses.length) {
    let deployCount = 0;

    while (progresses[0] >= 100) {
      progresses.shift();
      speeds.shift();
      deployCount++;
    }

    if (deployCount) answer.push(deployCount);

    for (let i = 0; i < progresses.length; i++) {
      progresses[i] += speeds[i];
    }
  }

  return answer;
}

console.log(solution([93, 30, 44], [1, 30, 5]));
