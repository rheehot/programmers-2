-- 보호소에서는 몇 시에 입양이 가장 활발하게 일어나는지 알아보려 합니다. 
-- 9시부터 19시까지, 각 시간대별로 입양이 몇 건이나 발생했는지 조회하는 SQL문을 작성해주세요. 
-- 이때 결과는 시간대 순으로 정렬해야 합니다.
SELECT HOUR(DATETIME) AS HOUR, COUNT(DATETIME)
FROM ANIMAL_OUTS
WHERE HOUR(DATETIME) >= 9 AND HOUR(DATETIME) <= 19
GROUP BY HOUR(DATETIME);


-- 9시부터 19시까지를 생각하면 WHERE절을 사용해서 해결할 생각을 해야하고,
-- HOUR라는 함수를 통해 DATETIME에서 시간만 추출해야 한다.
-- GROUP BY를 통해 시간대별로 정보를 구한다.