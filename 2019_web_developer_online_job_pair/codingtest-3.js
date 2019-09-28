// 5분만 더 있었으면 풀었을텐데 ㅠㅠㅠㅠ

function solution3(sticker) {
    const dp = [[], []];
    const stickerLength = sticker.length;
    for (let i = 0; i < 2; i++) {
        for (let j = 0; j < stickerLength; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = sticker[0];
    dp[1][0] = 0;

    for (let i = 1; i < stickerLength; i++) {
        dp[0][i] = dp[1][i-1] + sticker[i];
        dp[1][i] = Math.max(dp[0][i-1], dp[1][i-1]);
    }

    return Math.max(dp[0][stickerLength-1], dp[1][stickerLength-1]);
}

console.log(solution3([12, 12, 12, 12, 12]));
console.log(solution3([12, 80, 14, 22, 100]));