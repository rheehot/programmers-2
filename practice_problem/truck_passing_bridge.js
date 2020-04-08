function solution(bridge_length, weight, truck_weights) {
  const truckCount = truck_weights.length;
  const passingbridgeQueue = [];
  const bridgeQueue = [];

  let sec = 1;

  while (truck_weights.length || passingbridgeQueue.length < truckCount) {
    if (!bridgeQueue.length && truck_weights.length) {
      bridgeQueue.push([truck_weights[0], sec]);
      truck_weights.shift();
    }

    if (bridgeQueue.length) {
      const [truckWeight, enteredSec] = bridgeQueue[0];

      if (bridge_length <= sec - enteredSec) {
        passingbridgeQueue.push(truckWeight);
        bridgeQueue.shift();
      }

      const totalWeight = bridgeQueue.reduce((acc, [w]) => acc + w, 0);

      if (truck_weights.length && truck_weights[0] + totalWeight <= weight) {
        bridgeQueue.push([truck_weights[0], sec]);
        truck_weights.shift();
      }
    }

    if (bridgeQueue.length || truck_weights.length) ++sec;
  }

  return sec;
}

console.log(solution(2, 10, [7, 4, 5, 6]));
console.log(solution(100, 100, [10]));
console.log(solution(100, 100, [10, 10, 10, 10, 10, 10, 10, 10, 10, 10]));
