-- EMPLOYEES 테이블은 보험 회사 직원의 정보를 담고 있는 테이블입니다. EMPLOYEES테이블 구조는 다음과 같으며, ID, NAME, SALARY, BRANCH_ID는 각각 직원의 아이디, 이름, 월급, 근무하는 대리점 아이디를 나타냅니다.
-- NAME	TYPE	NULLABLE
-- ID	INT	FALSE
-- NAME	VARCHAR(N)	FALSE
-- SALARY	NUMERIC(N,M)	FALSE
-- BRANCH_ID	INT	FALSE
-- SELLINGS 테이블은 자동차 보험 판매 기록을 담고 있는 테이블입니다. SELLINGS 테이블 구조는 다음과 같으며, CAR_ID, EMPLOYEE_ID, CREATED_AT, PRICE는 각각 보험 대상 자동차 ID, 보험 설계사 사원 ID, 계약일, 보험료를 나타냅니다.
-- NAME	TYPE	NULLABLE
-- CAR_ID	INT	FALSE
-- EMPLOYEE_ID	INT	FALSE
-- CREATED_AT	DATETIME	FALSE
-- PRICE	NUMERIC(N,M)	FALSE
-- EMPLOYEES 테이블과 SELLINGS 테이블을 이용해 각 대리점의 매출액을 조회하는 SQL 문을 작성해주세요. 단, 매출이 높은 대리점이 먼저 조회되어야 합니다.
-- 예시
-- 예를 들어 EMPLOYEES 테이블과 SELLINGS 테이블이 다음과 같다면
-- EMPLOYEES:
-- ID	NAME	SALARY	BRANCH_ID
-- 4603	Alayna	180	15
-- 4651	Juliet	300	15
-- 864	Holly	330	17
-- 2842	Kyra	280	16
-- 4521	Margaret	400	16
-- SELLINGS:
-- CAR_ID	EMPLOYEE_ID	CREATED_AT	PRICE
-- 306	4603	20160905223752	5200
-- 309	2455	20160905223752	5000
-- 305	864	20160905223752	5100
-- 307	4521	20160905223752	5000
-- 310	4651	20160905223752	5500
-- 388	4603	20160905223752	5700
-- 15번 대리점의 매출액은 16400원 * 4651번, 4603번 직원이 각각 [5500], [5200, 5700] 원 16번 대리점의 매출액은 5000원 * 2842번, 4521번 직원은 [0], [5000] 원 17번 대리점의 매출액은 5100원 * 864번 직원이 [5100] 원
-- 입니다. 따라서 SQL을 실행하면 다음과 같이 출력되어야 합니다.
-- BRANCH_ID	매출액
-- 15	16400
-- 17	5100
-- 16	

-- 결과
select employees.branch_id, sum(sellings.price)
from employees, sellings
where employees.id = sellings.employee_id
group by employees.branch_id
order by sum(sellings.price) desc