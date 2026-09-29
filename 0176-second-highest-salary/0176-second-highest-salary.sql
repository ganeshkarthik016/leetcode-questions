# Write your MySQL query statement below
select max(salary) as SecondHighestSalary from
Employee where Employee.salary < (select max(salary) from Employee)