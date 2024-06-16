# Write your MySQL query statement below

WITH CTE AS (
    SELECT A1.machine_id,
        A1.process_id,
        A1.timestamp AS START_TIME,
        A2.timestamp AS END_TIME
    FROM
        Activity A1 
    JOIN
        Activity A2
    ON A1.machine_id = A2.machine_id AND A1.process_id = A2.process_id
    AND A1.activity_type = 'start' AND A2.activity_type = 'end'
)

SELECT 
    machine_id,
    (ROUND(AVG(END_TIME - START_TIME), 3)) as processing_time
FROM 
    CTE
GROUP BY 
    machine_id
