# Write your MySQL query statement below
WITH ranked as(
    select score, DENSE_RANK() OVER(order by score desc) as 'rank' from Scores
)
select * from ranked;