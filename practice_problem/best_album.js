function solution(genres, plays) {
  const hash = {};
  for (let i = 0; i < genres.length; i++) {
    const genre = genres[i];
    if (!hash[genre]) hash[genre] = { ids: [] };
    const { ids } = hash[genre];
    ids.push(i);
  }

  const arr = Object.keys(hash).map(genre => {
    const { ids } = hash[genre];

    const totalPlay = ids.reduce((acc, i) => acc + plays[i], 0);

    const infos = ids.reduce((acc, i) => {
      acc.push({ i, play: plays[i] });
      return acc;
    }, []);

    return { totalPlay, infos };
  });

  arr.sort((a, b) => b.totalPlay - a.totalPlay);

  const answer = arr.reduce((acc, { infos }) => {
    infos.sort((a, b) => b.play - a.play);

    const [first, second] = infos;

    if (!second) {
      const { i } = first;
      acc.push(i);
      return acc;
    }

    const { i: fi } = first;
    const { i: si } = second;
    acc.push(fi);
    acc.push(si);

    return acc;
  }, []);

  return answer;
}
