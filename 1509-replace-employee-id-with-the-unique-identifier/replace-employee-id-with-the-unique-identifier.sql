# Write your MySQL query statement below
SELECT e2.unique_id, e1.name FROM Employees e1
Left Join EmployeeUNI e2
on e1.id = e2.id;