# Write your MySQL query statement below
SELECT name FROM Customer 
WHERE 
referee_id!=2
OR
referee_id IS null
-- referee_id IS NOT 2
