SELECT e1.name
FROM Employee e1
JOIN (
    SELECT managerID
    FROM Employee
    GROUP BY managerID
    HAVING COUNT(*) >= 5
) e2 ON e1.id = e2.managerID;
