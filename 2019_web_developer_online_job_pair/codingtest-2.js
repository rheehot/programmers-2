/*
체스에서 비숍(Bishop)은 아래 그림과 같이 대각선 방향으로 몇 칸이든 한 번에 이동할 수 있습니다. 만약, 한 번에 이동 가능한 칸에 체스 말이 놓여있다면 그 체스 말을 잡을 수 있습니다.
￼
8 x 8 크기의 체스판 위에 여러 개의 비숍(Bishop)이 놓여있습니다. 이때, 비숍(Bishop)들에게 한 번에 잡히지 않도록 새로운 말을 놓을 수 있는 빈칸의 개수를 구하려고 합니다.
위 그림에서 원이 그려진 칸은 비숍에게 한 번에 잡히는 칸들이며, 따라서 체스 말을 놓을 수 있는 빈칸 개수는 50개입니다.
8 x 8 체스판에 놓인 비숍의 위치 bishops가 매개변수로 주어질 때, 비숍에게 한 번에 잡히지 않도록 새로운 체스 말을 놓을 수 있는 빈칸 개수를 return 하도록 solution 함수를 완성해주세요.
제한 조건
체스판에 놓인 비숍의 위치 bishops가 solution 함수의 매개변수로 주어집니다.
* bishops는 비숍의 위치가 문자열 형태로 들어있는 배열입니다.
* bishops의 길이는 1 이상 64 이하입니다.
* 비숍이 놓인 위치는 알파벳 대문자와 숫자로 표기합니다.
    * 알파벳 대문자는 가로 방향, 숫자는 세로 방향 좌표를 나타냅니다.
    * 예를 들어 위 그림에서 비숍이 있는 칸은 “D5”라고 표현합니다.
* 한 칸에 여러 비숍이 놓이거나, 잘못된 위치가 주어지는 경우는 없습니다.
입출력 예
bishops	return
[“D5”]	50
[“D5”, “E8”, “G2”]	42
입출력 예 설명
입출력 예 #1문제에 나온 예시와 같습니다.
입출력 예 #2
￼
그림과 같이 원이 그려진 칸은 비숍에게 한 번에 잡히는 칸들이며, 따라서 체스 말을 놓을 수 있는 빈칸 개수는 42개입니다.
*/

function solution2(bishops) {    
    const board = [ 
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0]
    ];

    const boardXSize = 8, boardYSize = 8;
    const convertX = { 'A': 0, 'B': 1, 'C': 2, 'D': 3, 'E': 4, 'F': 5, 'G' : 6, 'H' : 7 };
    const dirY = [ -1, -1, 1, 1 ];
    const dirX = [ -1, 1, -1, 1 ];
    
    for (let i = 0; i < bishops.length; i++) {
        const pos = bishops[i];
        let y = boardYSize - parseInt(pos.substr(1, 2)); 
        let x = convertX[pos.substr(0, 1)];
        
        board[y][x] = 1;
        for (let d = 0; d < 4; d++) {
            let ny = y + dirY[d];
            let nx = x + dirX[d];

            while (0 <= ny && ny < boardYSize && 0 <= nx && nx < boardXSize) {
                board[ny][nx] = 1;
                ny = ny + dirY[d];
                nx = nx + dirX[d];
            }
        }
    }
    
    let answer = 0;
    for (let y = 0; y < boardYSize; y++) {
        for (let x = 0; x < boardXSize; x++) {
            if (!board[y][x]) answer++;
        }
    }
    return answer;
}

console.log(solution2(['D5']));
console.log(solution2(["D5", "E8", "G2"]));