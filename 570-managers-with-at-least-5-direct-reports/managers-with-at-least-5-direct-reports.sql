SELECT e1.name
FROM Employee e1
JOIN Employee e2 ON e2.managerId = e1.id
group by e1.name,e2.managerId
HAVING COUNT(e2.managerId)>= 5;