function rotated(key) {
  const keySize = key.length;
  const rotatedKey = Array.from(Array(keySize), () => Array());

  for (let r = 0; r < keySize; r++) {
    for (let c = 0; c < keySize; c++) {
      rotatedKey[c][keySize - 1 - r] = key[r][c];
    }
  }

  return rotatedKey;
}

function isUnlock(key, lock, r, c) {
  const keySize = key.length;
  const lockSize = lock.length;
  const boardSize = lockSize + keySize * 2 - 2;
  const board = Array.from(Array(boardSize), () => Array());

  for (let bR = 0; bR < board.length; bR++) {
    for (let bC = 0; bC < board.length; bC++) {
      const lR = bR - (keySize - 1);
      const lC = bC - (keySize - 1);

      if (0 <= lR && lR < lockSize && 0 <= lC && lC < lockSize) {
        board[bR][bC] = lock[lR][lC];
        continue;
      }

      board[bR][bC] = 0;
    }
  }

  for (let bR = r; bR < r + keySize; bR++) {
    for (let bC = c; bC < c + keySize; bC++) {
      board[bR][bC] += key[bR - r][bC - c];
    }
  }

  for (let lR = keySize - 1; lR <= boardSize - keySize; lR++) {
    for (let lC = keySize - 1; lC <= boardSize - keySize; lC++) {
      if (board[lR][lC] !== 1) return false;
    }
  }

  return true;
}

function solution(key, lock) {
  const keySize = key.length;
  const lockSize = lock.length;
  const boardSize = lockSize + keySize * 2 - 2;

  for (let rotate = 0; rotate < 4; rotate++) {
    for (let r = 0; r <= boardSize - keySize; r++) {
      for (let c = 0; c <= boardSize - keySize; c++) {
        if (isUnlock(key, lock, r, c)) return true;
      }
    }
    key = rotated(key);
  }

  return false;
}

const key = [
  [0, 0, 0],
  [1, 0, 0],
  [0, 1, 1],
];

const lock = [
  [1, 1, 1],
  [1, 1, 0],
  [1, 0, 1],
];

console.log(solution(key, lock));
