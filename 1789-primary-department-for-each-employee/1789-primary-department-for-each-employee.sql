# Write your MySQL query statement below
SELECT e1.employee_id, e1.department_id
FROM Employee e1
WHERE primary_flag = 'Y'
   OR (e1.employee_id, e1.department_id) IN (
        SELECT e2.employee_id, e2.department_id
        FROM Employee e2
        GROUP BY e2.employee_id
        HAVING COUNT(DISTINCT e2.department_id) = 1
   );