# Write your MySQL query statement below
select a.user_id , 
round(coalesce(avg(b.action='confirmed'),0),2) as confirmation_rate
from Signups a
left join Confirmations b
on a.user_id = b.user_id
group by a.user_id;